#include <stdio.h>

void q1() {
    int x, y, *p1, **p2;

    x = 100;
    y = 200;

    p1 = &x; // *p1 = x = 100
    p2 = &p1; // *p2 = p1 => **p2 = x = 100

    printf("%d ", **p2); // 100
    *p2 = &y; // p2 -> p1 but p1 -> y
    printf("%d \n", **p2); // 200
}

void q2() {
    int k, x[3] = {5, 7, 9};
    int *myPtr, **ourPtr;
    myPtr = x;
    ourPtr = &myPtr;
    k = *myPtr; // k = ?
    printf("%d ", k); // 5
    k = (**ourPtr) + 1; // k = ?
    printf("%d ", k); // 6
    // k = *(**ourPtr + 1); // k = ? // *(6) undefined wrong
    k = *(*ourPtr + 1); // k = ?
    printf("%d \n", k); // 7
}

int q3(int x, int *p, int **q) {
    int y, z;
    // x = 4

    **q += 1; // c = 5
    z = **q; // z = 5
    *p += 2; // c = 7
    y = *p; // y = 7
    x+=3; // x = 4 + 3 = 7

    return x + y + z; // 7 + 7 + 5 = 19;
}

void q4() {
    long A[3] = {1, 2, 3};
    long *p;
    long **q;
    p = A;
    p++;
    q = &p; // pointing to p not where p is pointing to not q = p its q = &p;
    p++;
    (*p) = (**q) + 2;

    for (int i = 0; i < 3; i++) {
        printf("%ld, ", *(A + i)); // 1.2.5
    }
    printf("\n");
}

void q5(int **h) {
    *h = *h + 1;
}

void q6() {
    int x[] = {2, 4, 6, 8, 10};
    int *p = x;
    int **pp = &p;
    (*pp)++; // moving p 1 ahead
    (*(*pp))++; // incrementing value by 1 where p is pointing to
    printf("%d\n", *p); // 5
}

void q7(int **p) {
    int j = 11;
    *p = &j;
    printf("%d ", **p);
}

void q8() {
    int i = 10;
    int *p;
    int **q;
    int ***r;
    p = &i;
    *p = 15; // i = 15
    q = &p;
    **q = 20; // i = 20
    r = &q;
    ***r = (*p) + 1; // 21
    printf("i: %d \n", i);
}

void q9() {
    int a = 4, b = 6, c = 9;
    int *p = &a;
    int *q = p;
    p = &b;
    a++;
    (*q)++;
    b = *q + 2;
    c = *q + *p;

    printf("a=%d, b=%d, c=%d\n", a, b, c); // 6, 8, 14
}

int** q10(float*, char**);

void q11(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}

int* q12(int **p, int **q) {
    // &curr, &next
    printf("**p=%d\n", **p); // arr[0] = 4

    (*p)++; // curr++ => curr->arr[1]
    *q = *p + 1; // next -> arr[2]

    printf("**p=%d\n", **p); // arr[1] = 2
    printf("**q=%d\n", **q); // arr[2] = 0

    **q = **p - (*p)[-1]; 
    // arr[2] = arr[1] - curr[-1] -> curr[1 - 1 = 0] = arr[0]
    // arr[2] = 2 - 4 = -2

    int **temp = p;
    p = q;
    q = temp;
    // swapping p and q here does not swap the caller’s variables curr and next. p and q are local copies of the addresses &curr and &next.

    // q -> &curr and p -> &next now
    

    return *q - 1; // curr - 1, return pointer to arr[0];
}

int main(void){
    printf("Hello, world\n\n");

    q1();
    q2();

    int c, *b, **a;
    c = 4; b = &c; a = &b;
    printf("%d\n", q3(c, b, a));

    q4();

    int A[3] = {50, 60, 70};
    int *q = A;
    q5(&q);
    printf("*q = %d\n", *q); // 60

    q6();

    int i = 10;
    int *p = &i;
    q7(&p);
    printf("%d\n", *p); // 11 11

    q8();
    q9();

    int x = 11, y = 9;
    int *u = &x;
    int *v = &y;
    int **aa = &u;
    int **bb = &v;
    q11(aa, bb);// v and u are now pointing to different 
    printf("%d,%d\n", *u, *v); // 9, 11

    int arr[3];

    for (int i = 0; i < 3; i++) {
        arr[2 - i] = 2 * i;
        printf("arr[%u]=%u\n", 2 - i, 2 * i);
    }
    // arr[2] = 0
    // arr[1] = 2
    // arr[0] = 4

    int *curr = &arr[0];
    int *next = NULL;

    curr = q12(&curr, &next); // return pointer to arr[0] so now curr is pointing to arr[0]

    printf("*curr=%d\n", *curr); // 4
    printf("*next=%d\n", *next); // arr[2] = -2

    for (size_t i = 0; i < 3; i++) {
        printf("arr[%u]=%d\n", i, arr[i]);
    }
    // arr[0] = 4
    // arr[1] = 2
    // arr[2] = -2

    return 0;
}