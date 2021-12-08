#include "../Headers/exercises.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fileWrite2(unsigned int n, char *name) {
    unsigned int i;
    unsigned int num;
    FILE *file = fopen(name, "wb");

    srand(time(NULL));
    for(i = 0; i < n; i++) {
        num = rand() % 2000000001;
        fwrite(&num, sizeof(num), 1, file);
    }
    fclose(file);
}

void fileRead2(unsigned int *vec, unsigned int n) {
    unsigned int i = 0;
    unsigned int num;
    FILE *file;

    if(n == 200000)
        file = fopen(_200K, "rb");
    else if(n == 400000)
        file = fopen(_400K, "rb");
    else if(n == 600000)
        file = fopen(_600K, "rb");
    else if(n == 800000)
        file = fopen(_800K, "rb");
    else
        file = fopen(_1M, "rb");

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

unsigned int multMethod(unsigned int * keys, unsigned int *table, unsigned int n) {
    unsigned int i, count = 0;

    for(i = 0; i < 100000; i++) {
        table[i] = 0;
    }

    for(i = 0; i < n; i++) {
        table[(keys[i]*keys[i]) % 100000] += 1;
    }
    
    for(i = 0; i < 100000; i++) {
        if(table[i] != 0)
            count += table[i]-1;
    }
    printf("Collisions(%d): %d\n", n, count);
}

void divMethod(unsigned int * keys, unsigned int *table, unsigned int n) {
    unsigned int i, count = 0;

    for(i = 0; i < 100000; i++) {
        table[i] = 0;
    }

    for(i = 0; i < n; i++) {
        table[keys[i] % (100000)] += 1;
    }
    
    for(i = 0; i < 100000; i++) {
        if(table[i] != 0)
            count += table[i]-1;
    }
    printf("Collisions(%d): %d\n", n, count);
}

unsigned int countDigit(unsigned int n) {
    unsigned int count = 0;

    if(n == 0)
        return 1;
    while(n != 0) {
        n = n/10;
        count += 1;
    }
    return count;
}

void addVector(unsigned int * vec, unsigned int key, unsigned int size) {
    unsigned int i;
    for(i = size; i > -1; i--) {
        vec[i-1] = key % 10;
        key /= 10;
    }

}

unsigned int sumDigits(unsigned int one, unsigned int two) {
    unsigned int sum = one + two;
    if(sum > 9){
        return sum % 10;
    }
    return sum;
}

unsigned int fold(unsigned int * vec, unsigned int size) {
    unsigned int i, k;
    for(i = 0; i < size-2; i++) {
        k = i % 2 == 0 ? 3 : 1; //
        vec[i+k] = sumDigits(vec[i], vec[i+k]);
    }
    
    return vec[size-2]*10+vec[size-1];
}

void foldMethod(unsigned int * keys, unsigned int *table, unsigned int n) {
    unsigned int i, size, count = 0;

    for(i = 0; i < 100000; i++) {
        table[i] = 0;
    }

    for(i = 0; i < n; i++) {
        unsigned int *vec;
        size = countDigit(keys[i]);
        if(size % 2 != 0) size += 1;
        vec = (unsigned int*) malloc(sizeof(unsigned int)*size);
        addVector(vec, keys[i], size);
        table[fold(vec, size)] += 1;
        free(vec);
    }

    for(i = 0; i < 100000; i++) {
        if(table[i] != 0)
            count += table[i]-1;
    }
    printf("Collisions(%d): %d\n", n, count);
}

void hashTable() {
    unsigned int i, *table = (unsigned int*) malloc(sizeof(unsigned int)*100000);

    printf("\n\tDivision Method\n");
    for (i = 200000; i <= 1000000; i+= 200000) {
        unsigned int *keys = (unsigned int*) malloc(sizeof(unsigned int)*i);
        fileRead2(keys, i);
        divMethod(keys, table, i);
        free(keys);
    }

    printf("\n\tMultiplication Method\n");
    for (i = 200000; i <= 1000000; i+= 200000) {
        unsigned int *keys = (unsigned int*) malloc(sizeof(unsigned int)*i);
        fileRead2(keys, i);
        multMethod(keys, table, i);
        free(keys);
    }

    printf("\n\tFold Method\n");
    for (i = 200000; i <= 1000000; i+= 200000) {
        unsigned int *keys = (unsigned int*) malloc(sizeof(unsigned int)*i);
        fileRead2(keys, i);
        foldMethod(keys, table, i);
        free(keys);
    }


}
