#include <stdio.h>

#define ARR_SIZE(x) (sizeof(x) / sizeof((x)[0]))

void printArr(int *a, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", *(a + i));
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf("]");
}

int main(void){
    int a[5] = {10, 20, 30};
    printArr(a, ARR_SIZE(a));
    return 0;
}