#include <stdio.h>

void addAbs(int a, int b, int *sum) {
    (*sum) = a + b;
    if ((*sum) < 0) {
        (*sum) = -(*sum);
    }
    return;
}

void testPass(int x, int *y) { //  5,  &2
    x++;
    (*y)++;

    printf("%d, %d\n", x, *y); // 6, 3
}

void fun(int n) {
    printf("%d", n);
    for (int i = 0; i < 2; i++) {
        if (n > 0) fun(n - 1);
    }
}

void x(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", n);
        x(n - 1);
    }
}

void myFunc(int x, int *y, int *z) {
    x = *y + 3;
    *y = x + *z;
    *z = *y + x;
}

int foo(int i) {
    i = i + 2;
    return i;
}

int main(void){
    printf("Hello, world\n");
    fun(2);
    printf("\n");
    x(2);
    printf("\n");

    int a = 1, b = 2, c = 3;
    myFunc(a, &b, &c);
    printf("a=%d, b=%d, c=%d\n", a, b, c); // 1, 8, 13

    int m = 5, n = 15;
    int *p1, *p2;
    p1 = &m;
    p2 =  &n;

    *p1 = 10;
    *p2 = *p1;
    p1 = p2; // this is imp point
    *p1 = *p2 + 10;

    printf("m=%d, n=%d\n", m, n);

    int var1 = 2;
    int *ptr = &var1;
    foo(*ptr);
    foo(*ptr);
    printf("%d\n", var1);

    int num;
    addAbs(1, -12, &num);
    printf("num = %d", num);

    int u = 5, v = 2;
    printf("\n%d, %d\n", u, v); // 5, 2
    testPass(u, &v); // 6, 3
    printf("%d, %d\n", u, v); // 5, 3
    return 0;
}