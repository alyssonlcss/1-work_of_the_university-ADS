#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stddef.h>

#define NONE -77777
#define _1K "../bin/1K.bin"
#define _10M "../bin/10M.bin"
#define _100K "../bin/100K.bin"
#define _1B "../bin/1B.bin"

void upHeap(int i, int *vec);
void dropHeap(int i, int *vec, int n);
void insertHeap(int new, int *vec, int *n);
void removeHeap(int *vec, int *n);
void buildHeap(int *vec, int size);
void output(int *vec, int n);
void heapSort(int *vec, int n);
void insertionSort(int *vec, int n);
void fileWrite(int n, char *name);
void fileRead(int *vec, char *name);
void testHeapSort(int n, char *name);
void testInsertionSort(int n, char *name);
void exercise_1();
void exercise_2();
void exercise_3();



#endif
