#include <cs50.h>
#include <stdio.h>

float calc(int minutes);

int main(void)
{
    printf("Minutes: ");
    int min = get_int();
    int bottles = calc(min);
    printf("Bottles: %i\n", bottles);
    
}

float calc(int minutes)
{
    float gallon = 1.5 * minutes;
    int ounce = 128;
    float ounce_per_minute = gallon * ounce;
    float bottle = 16;
    return ounce_per_minute / bottle;
}
