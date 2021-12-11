#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stddef.h>

#define NONE -77777

#define _1K "../bin/first_part/1K.bin"
#define _10M "../bin/first_part/10M.bin"
#define _100K "../bin/first_part/100K.bin"
#define _1B "../bin/first_part/1B.bin"

#define _200K "../bin/second_part/200K.bin"
#define _400K "../bin/second_part/400K.bin"
#define _600K "../bin/second_part/600K.bin"
#define _800K "../bin/second_part/800K.bin"
#define _1M "../bin/second_part/1M.bin"

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
void fileWrite2(unsigned int n, char *name);
void fileRead2(unsigned int *vec, unsigned int n);
void createFiles();
void testHeapSort(int n, char *name);
void testInsertionSort(int n, char *name);
void divMethod(unsigned int * keys, unsigned int *table, unsigned int n);
void hashTable();
void exercise_1();
void exercise_2();
void exercise_3();



#endif
