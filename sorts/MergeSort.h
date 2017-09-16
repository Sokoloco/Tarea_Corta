//
// Created by luis on 15/09/17.
//

#ifndef TAREA_CORTA_MERGESORT_H
#define TAREA_CORTA_MERGESORT_H

void merge(int arr[], int left, int middle, int right);
/**
 * Sorts an array of type integer via the method merge sort
 * @param arr THe array to be sorted
 * @param l is the left most index that is being considered, in the begining is 0
 * @param r is the right-most index that is being considered, in the beginning is
 * the array size
 */
void mergeSort(int arr[], int l, int r)
{
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
/**
 *merges two sub-arrays of the first array
 * @param arr the array itself
 * @param left the left most index of the first array
 * @param middle the right most index of the first array,
 * m+1 is the left-most index of the second array
 * @param right the right most index of the scond array
 */
void merge(int arr[], int left, int middle, int right){
    int i, j, k;
    int sizeArr1 = middle - left + 1;
    int sizeArr2 =  right - middle;

    int lArr[sizeArr1], rArr[sizeArr2]; //Temporary arrays

    for (i = 0; i < sizeArr1; i++)
        lArr[i] = arr[left + i];
    for (j = 0; j < sizeArr2; j++)
        rArr[j] = arr[middle + 1+ j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < sizeArr1 && j < sizeArr2)
    {
        if (lArr[i] <= rArr[j]){ //Adds smaller value to new array
            arr[k] = lArr[i];
            i++;
        }
        else{
            arr[k] = rArr[j];
            j++;
        }
        k++;
    }//adds reamining values
    while (i < sizeArr1) {
        arr[k] = lArr[i];
        i++;
        k++;
    }
    while (j < sizeArr2){
        arr[k] = rArr[j];
        j++;
        k++;
    }
}
#endif //TAREA_CORTA_MERGESORT_H
