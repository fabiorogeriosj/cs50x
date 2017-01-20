#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int ht = 0;
    //gets prompt from user
    do {
        printf("Height:");
        ht = get_int();
        //check to see if int is between 1 and 23 
    } while (ht < 0 || ht > 23);
        
    for (int i = 1; i <= ht; i++)
    {
        printf("line %i\n", i);
        //create col with spaces and hashes here :)
    }
    
    return 0;
}