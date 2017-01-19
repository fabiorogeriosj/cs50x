#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool validSize(long long number);
string convertToString(long long number);
string getType(long long number);
bool validCardNumber(long long number);

int main(void)
{
    printf("Number: ");
    long long number = get_long_long();
    if(!validSize(number))
    {
        printf("INVALID\n");
        return 0;
    }
    
    string type = getType(number);
    if(strlen(type) < 2)
    {
        printf("INVALID\n");
        return 0;
    }
    if(validCardNumber(number))
    {
        printf("%s\n", type);
    } else {
        printf("INVALID\n");
    }
}

bool validSize(long long number)
{
    char numberString[16];
    sprintf(numberString, "%lld", number);
    int length = strlen(numberString);
    
    return length == 13 || length == 15 || length == 16;
}

string getType(long long number)
{
    char numberString[16];
    sprintf(numberString, "%lld", number);
    char digits[3] = {numberString[0], numberString[1],'\0'};
    int digit = atoi(digits);
    
    if(numberString[0] == '4'){
        return "VISA";
    } else if(digit == 34 || digit == 37)
    {
        return "AMEX";
    } else if(digit > 50 && digit < 56)
    {
        return "MASTERCARD";
    } else {
        return "";
    }
}

bool validCardNumber(long long number)
{
    char numberString[16];
    sprintf(numberString, "%lld", number);
    char sum1[20]="\0";
    int totalSum1 = 0;
    for(int i=strlen(numberString)-2;i>=0;i=i-2)
    {
        int digit = numberString[i] - '0';
        char str[2];
        sprintf(str, "%d", digit*2);
        strcat(sum1, str);
    }
    for(int i=0;i<strlen(sum1);i++)
    {
        totalSum1 += sum1[i] - '0';
    }
    for(int i=strlen(numberString)-1;i>=0;i=i-2)
    {
        int digit = numberString[i] - '0';
        totalSum1 += digit;
    }
    return totalSum1 % 10 == 0;
}

