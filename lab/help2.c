#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{ 
    float change;
    int counter = 0; //need declaration type of variable
    
    do {
        printf("change:");
        change=get_float();
    } while(change < 0);

    int i=change*100; //need declaration type of variable

    while (i >= 25; 25/i; counter++); //need ; end line code
}