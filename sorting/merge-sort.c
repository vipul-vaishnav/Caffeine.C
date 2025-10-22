#include <stdio.h>

#define ARR_SIZE(x) (sizeof(x) / sizeof((x)[0]))

int minHelper(int *arr, int start, int end) {
    if (start >= end) return arr[start];

    int mid = start + (end - start) / 2;

    int u = minHelper(arr, start, mid);
    int v = minHelper(arr, mid + 1, end);

    return u < v ? u : v;
}

int maxHelper(int *arr, int start, int end) {
    if (start >= end) return arr[start];

    int mid = start + (end - start) / 2;

    int u = maxHelper(arr, start, mid);
    int v = maxHelper(arr, mid + 1, end);

    return u > v ? u : v;
}

int max(int *arr, int size) {
    int start = 0, end = size - 1;
    return maxHelper(arr, start, end);
}

int min(int *arr, int size) {
    return minHelper(arr, 0, size - 1);
}

void printArr(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", *(arr + i));
        if (i != size - 1) printf(", ");
    }
    printf("]\n");
}

void merge(int *arr, int start, int mid, int end) {
    // sizes of two subarrays
    int n1 = mid - start + 1;
    int n2 = end - mid; // end - (mid + 1) + 1

    // temp arrays
    int p[n1], q[n2];
    
    // copy data to temp arrays
    for (int i = 0; i < n1; i++) {
        p[i] = arr[start + i]; 
    }
    for (int i = 0; i < n2; i++) {
        q[i] = arr[mid + 1 + i];
    }

    // merge them in the original arr
    int k = start, l = 0, m = 0;
    while (l < n1 && m < n2) {
        if (p[l] < q[m]) {
            arr[k++] = p[l++];
        } else {
            arr[k++] = q[m++];
        }
    }

    while (l < n1) {
        arr[k++] = p[l++];
    }

    while (m < n2) {
        arr[k++] = q[m++];
    }
}

void mergeSortHelper(int *arr, int start, int end) {
    if (start >= end) return;
    int mid = start + (end - start) / 2;

    mergeSortHelper(arr, start, mid);
    mergeSortHelper(arr, mid + 1, end);

    merge(arr, start, mid, end);
}
 
void mergeSort(int *arr, int size) {
    int start = 0, end = size - 1;
    mergeSortHelper(arr, start, end);
}

int main(void){
    int arr[10] = {12, 7, 14, 9, 6, -6, 8, 2, 12, 10};
    // sorted => -6, 2, 6, 7, 8, 9, 10, 12, 12, 14
    printArr(arr, ARR_SIZE(arr));

    mergeSort(arr, ARR_SIZE(arr));

    printArr(arr, ARR_SIZE(arr));

    printf("MAX: %d, MIN: %d\n", max(arr, ARR_SIZE(arr)), min(arr, ARR_SIZE(arr)));
    return 0;
}