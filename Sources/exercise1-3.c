#include "../Headers/exercises.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

#include <stdlib.h>

void upHeap(int i, int *vec) {
    int j = i/2, temp;

    if(j > 0) {
        if(vec[i] > vec[j]) {
            temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            upHeap(j, vec);
        }
    }
}

void dropHeap(int i, int *vec, int n) {
    int j = 2*i, temp;

    if (j <= n) {
        if (j < n) {
            if(vec[j+1] > vec[j])
                j++;
        }
        if(vec[i] < vec[j]) {
            temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            dropHeap(j, vec, n);
        }
    
    }
}

void insertHeap(int new, int *vec, int *n) {
    if (*n < vec[0]) {
        vec[*n+1] = new;
        *n+=1;
        upHeap(*n, vec);
    }
    else
        printf("Overflow :/\n");
}

void removeHeap(int *vec, int *n) {
    if(n != 0) {
        vec[1] = vec[*n];
        vec[*n] = NONE;
        *n-=1;
        dropHeap(1, vec, *n);
    }
    else
        printf("Underflow :/\n");
}

void buildHeap(int *vec, int n) {
    int i;
    for (i = n/2; i >= 1; i--)
        dropHeap(i, vec, n);
}

void output(int *vec, int n) {
    int i;
    for(i = 1; i <= n; i++)
         printf("%d, ", vec[i]);
}

void heapSort(int *vec, int n) {
    int i = n, temp;
    buildHeap(vec, n);
    while(i >= 2){
        temp = vec[i];
        vec[i] = vec[1];
        vec[1] = temp;
        i--;
        dropHeap(1, vec, i);
    }
}

void insertionSort(int *vec, int n) {
    int i, j, key;

    for(j = 2; j < n; j++) {
        key = vec[j];
        i = j - 1;
        while(vec[i] > key && i > 0) {
            vec[i+1] = vec[i];
            i--;
        }
        vec[i+1] = key;
    }
}

void fileWrite(int n, char *name) {
    int i;
    int num;
    FILE *file = fopen(name, "wb");

    srand(time(NULL));
    for(i = 0; i < n; i++) {
        num = rand() % 1001;
        fwrite(&num, sizeof(num), 1, file);
    }
    fclose(file);
}

void fileRead(int *vec, char *name) {
    int i = 1;
    int num;
    FILE *file = fopen(name, "rb");
    if(!file) {
        puts("Error: Couldn't open random");
        exit(1);
    }
    while(fread(&num, sizeof(num), 1, file)) {
        vec[i] = num;
        i++;
    }
    fclose(file);
}

void testHeapSort(int n, char *name) {
    int *vec = (int*) malloc((n+1) * sizeof(int));
    clock_t start, end;
    fileRead(vec, name);
    start = clock();
    heapSort(vec, n);
    end = clock();

    if(!strcmp(name, _1K)) {
        printf("\n\n\tTESTES DO HEAP SORT");
        printf("\nHeap Sort (%s): %.5f sec\n", "1K", (float)(end - start) / CLOCKS_PER_SEC);
    }
    else if(!strcmp(name, _100K))
        printf("\nHeap Sort (%s): %.5f sec\n", "100K", (float)(end - start) / CLOCKS_PER_SEC);
    else if(!strcmp(name, _10M))
        printf("\nHeap Sort (%s): %.5f sec\n", "10M", (float)(end - start) / CLOCKS_PER_SEC);
    else
        printf("\nHeap Sort (%s): %.5f sec\n", "1B", (float)(end - start) / CLOCKS_PER_SEC);
    free(vec);
}

void testInsertionSort(int n, char *name) {
    int i, *vec = (int*) malloc((n+1) * sizeof(int));
    clock_t start, end;
    fileRead(vec, name);
    start = clock();
    insertionSort(vec, n);
    end = clock();
    if(!strcmp(name, _1K)) {
        printf("\n\tTESTES DO INSERTION SORT\n");
        printf("Insertion Sort (%s): %.5f sec\n", "1K", (float)(end - start) / CLOCKS_PER_SEC);
    }
    else if(!strcmp(name, _100K))
        printf("\nInsertion Sort (%s): %.5f sec\n", "100K", (float)(end - start) / CLOCKS_PER_SEC);
    else if(!strcmp(name, _10M))
        printf("\nInsertion Sort (%s): %.5f sec\n", "10M", (float)(end - start) / CLOCKS_PER_SEC);
    else
        printf("\nInsertion Sort (%s): %.5f sec\n", "1B", (float)(end - start) / CLOCKS_PER_SEC);

    free(vec);
}

void exercise_1() {
    int i, vec[] = {0,33,78,39,28,95,70,60,66};
    int n = sizeof(vec)/sizeof(vec[0])-1;
    
    vec[0] = n;
    puts("\n\t# EXERCISE 1\nInput:");
    output(vec, n);
    buildHeap(vec, vec[0]);
    puts("\nbuildHeap:");
    output(vec, n);
    removeHeap(vec, &n);
    puts("\nremoveHeap:");
    output(vec, n);
    insertHeap(23, vec, &n);
    puts("\ninsertHeap(23):");
    output(vec, n);
}

void exercise_2(){
    int i, vec[] = {0,33,78,39,28,95,70,60,66};
    
    vec[0] = sizeof(vec)/sizeof(vec[0])-1;
    puts("\n\n\t# EXERCISE 2\nInput:");
    output(vec, vec[0]);
    puts("\nHeap Sort: ");
    heapSort(vec, vec[0]);
    output(vec, vec[0]);
}

void exercise_3(){
    int i, vec[] = {33,78,39,28,95,70,60,66};
    int n = sizeof(vec)/sizeof(vec[0]);
    puts("\n\n\t# EXERCISE 3\nInput:");
    output(vec, n);
    puts("\nInsertion Sort:");
    insertionSort(vec, n);
    output(vec, n);
}

void createFiles() {
    fileWrite(1000, _1K);
    fileWrite(100000, _100K);
    fileWrite(10000000, _10M);
    fileWrite2(200000, _200K);
    fileWrite2(400000, _400K);
    fileWrite2(600000, _600K);
    fileWrite2(800000, _800K);
    fileWrite2(1000000, _1M);
}
