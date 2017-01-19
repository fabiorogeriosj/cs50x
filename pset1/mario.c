#include <cs50.h>
#include <stdio.h>

int getHeight();
void drawPyramid(int height);
void drawRow(int height, int row);
void drawInCol(int col, char pointer);

int main(void)
{
    int height = getHeight();
    drawPyramid(height);
    
}

int getHeight()
{
    int height = -1;
    do {
        printf("Height: ");
        height = get_int();
    } while(height < 0 || height > 23);
    
    return height;
}

void drawPyramid(int height)
{
    for(int row=1;row<=height;row++)
    {
        drawRow(height, row);
    }
}

void drawRow(int height, int row)
{
    drawInCol(height-row, ' ');
    drawInCol(row, '#');
    drawInCol(2, ' ');
    drawInCol(row, '#');
    printf("\n");
}

void drawInCol(int col, char pointer)
{
    for(int i=1;i<=col;i++)
    {
        printf("%c", pointer);
    }
}
