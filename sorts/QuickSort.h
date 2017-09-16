//
// Created by luis on 15/09/17.
//

#ifndef TAREA_CORTA_QUICKSORT_H
#define TAREA_CORTA_QUICKSORT_H

int partition (int arr[], int low, int high);
/**
 * Swaps number 'a' with number 'b'
 * @param a a number to be swapped
 * @param b a number to be swapped
 */
void swap2(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * Sorts an array via the quicksort sort
 * @param arr array to be sorted
 * @param low the lowest number should be 0 (at start)
 * @param high could be the size of the array (at start)
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
/**
 * Pivots around putting all number higher than itself right and all lower left,
 * high would be the pivot at which it starts
 * @param arr array passed from quicksort, its going to be sorted
 * @param low the lowest unsorted number
 * @param high the pivot
 * @return the new pivot
 */
int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++){
        if (arr[j] <= pivot){ //check weather j is smaller than pivot, and swaps it
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap2(&arr[i + 1], &arr[high]);
    return (i + 1);
}
#endif //TAREA_CORTA_QUICKSORT_H
