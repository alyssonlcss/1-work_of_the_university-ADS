void dropHeap(int i, long int , int n) {
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

void buildHeap(long int , int n) {
    int i;
    for (i = n/2; i >= 1; i--)
        dropHeap(i, vec, n);
}

void heapSort(long int , int n) {
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