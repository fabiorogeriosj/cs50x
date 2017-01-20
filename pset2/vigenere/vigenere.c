#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool isArgValid(int count, string args[]);
bool isLetter(char letter);
string getKeyword(string arg);
string getCiphertext(string plaintext, string key);
char cripty(char letter, char key);
char getUpperLatter(char letter);

int main(int count, string args[])
{
    if(!isArgValid(count, args))
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    printf("plaintext: ");
    string plaintext = get_string();
    string key = getKeyword(args[1]);
    string ciphertext = getCiphertext(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

bool isArgValid(int count, string args[])
{
    if(count != 2){
        return false;
    }
    bool valid=true;
    for(int i=0, n=strlen(args[1]);i<n;i++){
        if(!isLetter(args[1][i])){
            valid=false;
        }
    }
    return valid;
}

bool isLetter(char letter)
{
    return (letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122);
}

string getKeyword(string arg)
{
    int len = strlen(arg);
    for(int i=0;i<len;i++)
    {
        arg[i] = getUpperLatter(arg[i]);
    }
    return arg;
}

string getCiphertext(string plaintext, string key)
{
    int pLeng = strlen(plaintext);
    int kLeng = strlen(key);
    int iKey = 0;
    for(int i=0;i<pLeng;i++)
    {
        if(isLetter(plaintext[i])){
            if(iKey > kLeng-1){
                iKey=0;
            }
            plaintext[i] = cripty(plaintext[i], key[iKey]);
            iKey++;
        }
    }
    return plaintext;
}

char cripty(char letter, char key)
{
    key -= 65;
    char upperLetter = getUpperLatter(letter);
    if(upperLetter+key > 90){
      int diff = 90-upperLetter;
      key -= diff+1;
      if(letter > 90){
          letter=97;
      } else {
          letter=65;
      }
    }
    return letter+key;
}

char getUpperLatter(char letter)
{
    if(letter >= 97){
        letter -= 32;
    }
    return letter;
}