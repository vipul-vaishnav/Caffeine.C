#include <stdio.h>

void q1() {
    int a[4] = {1,2,4,8};
    int *b = a + 2;
    int *c = b-- + 1;
    printf("%d, %d\n", *b, *c);
}

void q2() {
    int a[] = {1, 10, 20}, *p = a, i = 1, j = 2;
    for (i = 0, p = a; i < 2; i++) {
        int j = *p; p++; *p = *p + j;
    }
    printf("i=%d, j=%d, a=%d, %d, %d\n", i, j, a[0], a[1], a[2]);
}

void q3() {
    int num1 = 8, num2 = 9;
    int *p = &num1, *q = &num2;
    char a[] = {'T', 'A', 'G', '?', '\0'};

    printf("%d, %d, %s\n", num1, num2, a);

    *q = 33;
    q = p;

    char *r = a;
    int sizeOfA = sizeof(a) / sizeof(a[0]);
    // printf("%d\t", sizeOfA);
    a[sizeOfA - 2] = 'C';

    printf("%d, %d, %s\n", num1, num2, a);
}

int main(void){
    q3();

    printf("\n");
    q1(); // 2, 
    q2();
    printf("Hello, world\n");
    int a[5] = {2, 4, 6, 8, 10};
    int *p;
    p = &a[1];
    printf("%d, %d\n", a[0], p[-1]);
    return 0;
}