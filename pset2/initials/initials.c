#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool isLetter(char letter);
void printfLetter(char letter);

int main(void)
{
    string name = get_string();
    int len = strlen(name);
    bool get=true;
    for(int i=0;i<len;i++){
        char letter = name[i];
        if(get && isLetter(letter)){
            printfLetter(letter);
            get=false;
        } else if(letter == 32){
            get=true;
        }
    }
    printf("\n");
}

bool isLetter(char letter)
{
    return (letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122);
}

void printfLetter(char letter)
{
    if(letter >= 97){
        letter-=32;
    }
    printf("%c", letter);
}