
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "../Headers/exercises.h"

int main() {

    //Implementation of 1-3
    exercise_1();
    exercise_2();
    exercise_3();

    //Test to Heap Sort
    testHeapSort(1000, _1K); // 0,00 sec
    testHeapSort(100000, _100K); // 0,02 sec
    testHeapSort(10000000, _10M); // 3,31 sec
    //testHeapSort(1000000000, _1B); // 382,08 sec == 6:36 min
    printf("\nHeap Sort(1000000000): Demora 6:36 min\n");

    //Test to Heap Sort
    testInsertionSort(1000, _1K); // 0,00 sec
    testInsertionSort(100000, _100K); // 5,75 sec
    //testInsertionSort(10000000, _10M); // 64.618,35 sec == 17.94 h
    //testInsertionSort(1000000000, _10M); // +∞ demora talvez anos
    printf("\nInsertion Sort(10000000): Demora 17:56h\n");
    printf("\nInsertion Sort(1000000000): +∞ demora talvez anos\n");
    
    hashTable();
    

    return 0;
}
