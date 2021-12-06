#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stddef.h>

#define NONE -77777

void upHeap(int i, int *vec);
void dropHeap(int i, int *vec, int n);
void insertHeap(int new, int *vec, int *n);
void removeHeap(int *vec, int *n);
void buildHeap(int *vec, int size);
void output(int *vec, int n);
void heapSort(int *vec, int n);
void insertionSort(int *vec, int n);
void exercise_1();
void exercise_2();
void exercise_3();



#endif
