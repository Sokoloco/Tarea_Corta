//
// Created by luis on 15/09/17.
//

#ifndef TAREA_CORTA_SELECTIONSORT_H
#define TAREA_CORTA_SELECTIONSORT_H
#include <stdio.h>

/**Swaps the placement of two intergers in an array,
 * a minimun for a bigger one.
 *
 * @param min is the minimun int found
 * @param big replaces the min
 */
void swap1(int *min, int *big)
{
    int temp = *min;
    *min = *big;
    *big = temp;
}
/**
 * Recieves an array to be sorted via selection sort
 *
 * @param arr the array to be sorted
 * @param n the size of a single int in the array
 */
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap1(&arr[min_idx], &arr[i]);
    }
}

#endif //TAREA_CORTA_SELECTIONSORT_H
