//
// Created by luis on 15/09/17.
//

#ifndef TAREA_CORTA_BUBBLESORT_H
#define TAREA_CORTA_BUBBLESORT_H
#include <stdio.h>
/** Does theswap function of interchanging two integers
 *
 * @param first the first integer
 * @param second the second interger
 */
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

/** Sorts an integer array using bubble sort
 *
 * @param arr the array to sort
 * @param sizeOfint the size of a single int
 */
void bubbleSort(int arr[], int sizeOfint){
    int i, j;
    for (i = 0; i < sizeOfint; i++){
        for (j = 0; j < sizeOfint-i; j++){
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

#endif //TAREA_CORTA_BUBBLESORT_H
