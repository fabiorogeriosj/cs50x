/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX], one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // if arguments send the program not is 2 or 3 printf the help about params.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // convert first argument to integer
    int n = atoi(argv[1]);

    // if second argument exist then it is necessary convert argument to integer
    // and send to function srand48()
    // srand48() - It is called before the function that will generate the random 
    // numbers. In this case, the numbers are the same each time you run!
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    // will generate [n] random numbers
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
