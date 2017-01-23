/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if(n < 1){
        return false;   
    } else {
        int first = 0;
        int last = n;
        int middle = (first+last)/2;
        
        bool found=false;
        while (first <= last) {
            if (values[middle] < value){
                first = middle + 1;       
            } else if (values[middle] == value) {
                found=true;
                break;
            } else {
                last = middle - 1;   
            }
            middle = (first + last)/2;
        }
        return found;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for(int i=0;i<n;i++){
        for(int x=i;x<n;x++){
            if(values[i] > values[x]){
                int aux = values[i];
                values[i] = values[x];
                values[x]=aux;
            }
        }
    }
    
    return;
}
