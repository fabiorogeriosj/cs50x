#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Enter your first name: ");
    string name = get_string();
    
    printf("Enter your age: ");
    int age = get_int();
    
    printf("Name:, %s\n", name);
    printf("Age:, %i\n", age);
}
