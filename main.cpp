#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <array>
#include "sorts/BubbleSort.h"
#include "sorts/SelectionSort.h"
#include "sorts/InsertionSort.h"
#include "sorts/MergeSort.h"
#include "sorts/QuickSort.h"
#include "Structures/AVL_Tree.h"
#include "Structures/Binary_STree.h"
#include "Structures/LinkedList.h"
void calcularTiempo(int array[],int n){
    int cpyArr[n];
    timespec tiempo1, tiempo2,tiempoTardado;
    std::copy(std::begin(array),std::end(array),std::begin(cpyArr));
    clock_gettime(CLOCK_REALTIME,&tiempo1);
    bubbleSort(cpyArr,n);
    clock_gettime(CLOCK_REALTIME,&tiempo2);
    tiempoTardado.tv_nsec = tiempo2.tv_nsec - tiempo1.tv_nsec;
    cout<<tiempoTardado.tv_nsec<<endl;

    std::copy(std::begin(array),std::end(array),std::begin(cpyArr));
    clock_gettime(CLOCK_REALTIME,&tiempo1);
    insertionSort(cpyArr,n);
    clock_gettime(CLOCK_REALTIME,&tiempo2);
    tiempoTardado.tv_nsec = tiempo2.tv_nsec - tiempo1.tv_nsec;
    cout<<tiempoTardado.tv_nsec<<endl;

    std::copy(std::begin(array),std::end(array),std::begin(cpyArr));
    clock_gettime(CLOCK_REALTIME,&tiempo1);
    mergeSort(cpyArr,0,n);
    clock_gettime(CLOCK_REALTIME,&tiempo2);
    tiempoTardado.tv_nsec = tiempo2.tv_nsec - tiempo1.tv_nsec;
    cout<<tiempoTardado.tv_nsec<<endl;

    std::copy(std::begin(array),std::end(array),std::begin(cpyArr));
    clock_gettime(CLOCK_REALTIME,&tiempo1);
    selectionSort(cpyArr,n);
    clock_gettime(CLOCK_REALTIME,&tiempo2);
    tiempoTardado.tv_nsec = tiempo2.tv_nsec - tiempo1.tv_nsec;
    cout<<tiempoTardado.tv_nsec<<endl;
}
int main() {
    for(int i = 2; i<30; i+=2){
        int array[i];
        calcularTiempo(array,i);
    }
    return 0;
}
