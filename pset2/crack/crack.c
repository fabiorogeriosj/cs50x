#define _XOPEN_SOURCE
#define _GNU_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

bool isArgValid(int count, string args[]);
bool crack(char *salt, char *pass, char *crackPass, int col, bool recursive);

int main(int count, string args[])
{
    if(!isArgValid(count, args))
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    string pass = args[1];
    char salt[2];
    salt[0] = (char)pass[0];
    salt[1] = (char)pass[1];
    //printf("%s\n\n", crypt("feibernet", salt));
    char crackPass[5];
    crack(salt, pass, crackPass, 0, false);
    return 0;
}

bool isArgValid(int count, string args[])
{
    if(count != 2){
        return false;
    }
    return true;
}

bool crack(char *salt, char *pass, char *crackPass, int col, bool recursive)
{
    bool cracked=false;
    for(int i=65;i<123;i++){
        if(i==90){
            i=97;
        }
        crackPass[col] = i;
        if(!recursive){
            crackPass[col+1] = '\0';
        }
        if(col>0){
            if(crack(salt, pass, crackPass, col-1, true)){
                cracked=true;
                break;
            }
        } else {
            string bind = crypt(crackPass, salt);
            if(!strcmp(pass,bind)){
                printf("%s\n", crackPass);
                cracked=true;
                break;
            }
        }
    }
    if(!cracked && !recursive){
        col++;
        if(col < 4){
            return crack(salt, pass, crackPass, col, false);   
        } else {
            printf("Not :)\n");
            return false;
        }
    } else {
        return cracked;
    }
}
