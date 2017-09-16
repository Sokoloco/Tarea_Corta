cmake_minimum_required(VERSION 3.8)
project(Tarea_Corta)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp sorts/BubbleSort.h sorts/SelectionSort.h sorts/InsertionSort.h sorts/MergeSort.h sorts/QuickSort.h Structures/LinkedList.h Structures/Binary_STree.h Structures/AVL_Tree.h Structures/BinaryNode.h Structures/llNode.h)
add_executable(Tarea_Corta ${SOURCE_FILES})