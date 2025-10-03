#include <stdio.h>

void swap(int*, int*);

int main(void){
    int a = 3, b = 5;
    swap(&a, &b);
    printf("a=%d, b=%d\n", a, b);
    return 0;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}