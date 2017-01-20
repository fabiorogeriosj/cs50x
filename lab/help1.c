#include <cs50.h>
#include <stdio.h>

void space(int n);
void hash(int n);
int main(void)
{
    int h;
    do
    {
        printf("No of Steps: ");
        h = get_int();
    }
    while ( h < 0 || h > 23 );
    int s = h-1;
    int d = 2;
    
    for (int i = 0; i < h; i++)
    {
        space(s);
        hash(d);
        printf("\n");
        d++;
        s=s-1;
    }
}

void space(int n)
{
    for(int i=0;i<n;i++)
    {
        printf(" ");    
    }
}
void hash(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("#");  
    }
    
}