#include "../Headers/functions.h"
#include <stdio.h>

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

void outputHeap(int *vec, int n) {
    int i;
    for(i = 1; i <= n; i++)
        printf("%d, ", vec[i]);
}

void exercise_1() {
    int i, vec[] = {0,33,78,39,28,95,70,60,66};
    int n = sizeof(vec)/sizeof(vec[0])-1;
    
    vec[0] = n;
    printf("Input vector:\n");
    outputHeap(vec, n);
    buildHeap(vec, vec[0]);
    printf("\nbuildHeap:\n");
    outputHeap(vec, n);
    removeHeap(vec, &n);
    printf("\nremoveHeap:\n");
    outputHeap(vec, n);
    insertHeap(23, vec, &n);
    printf("\ninsertHeap(23):\n");
    outputHeap(vec, n);
}
