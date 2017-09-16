//
// Created by luis on 15/09/17.
//

#ifndef TAREA_CORTA_INSERTIONSORT_H
#define TAREA_CORTA_INSERTIONSORT_H

/**
 * Sorts an int array with insertion sort
 * @param arr the array of ints to be sorted
 * @param n the size of a single int in the array
 */
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

#endif //TAREA_CORTA_INSERTIONSORT_H
