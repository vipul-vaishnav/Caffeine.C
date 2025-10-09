#include <stdio.h>

void q1() {
    char test_str[50] = "1010_fighting";
    char *str_ptr = &test_str[2];

    while (*str_ptr != '\0') {
        printf("%c", *(str_ptr++));
    }
    printf("\n");
}

char* q2(char *ptr) {
    ptr += 3;
    return ptr;
}

void changeit(char *val) {
    char *p;
    for (p = val; *p != '\0'; p++) {
        *p = ++(*p);
    }
    // Npoebz
    printf("%s\n", val);
}

void q3() { // matrix transpose
    int i, j;
    char a[2][3] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char b[3][2];
    char *p = *b;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            *(p + 2 * j + i) = a[i][j];
        }
    }

    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 2; l++) {
            printf("%c ", *(*(b + k) + l));
        }
        printf("\n");
    }
}

void q4() {
    char *str = "Stanford University";
    char a = str[1];
    char b = *(char*)((int*)str + 3);
    // str points to 'S' now we casted it to int pointer so moving 3 pos ahead in integer is 3 * 4 (int is 4 bytes) so 12 pos from 'S' is 'v' then again we cast it to char* then dereference will give 'v'
    printf("%c, %c\n", a, b); // t, v
}

void q5() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ip = arr + 2;
    int *p1, *p2;
    p1 = (int*)((short*) ip + 4); // ip is pointing to 3 and its cased to short* and moving 4 pos ahead = 8 bytes i.e. 2 pos ahead in int arr which is arr[5] = 5;
    p2 = (int*)((short*)(ip - 2) + 2); // ip - 2 = arr[0], moving 2 pos ahead = 4 bytes so arr[1] = 2;
    printf("%d, %d\n", *p1, *p2); // 5 and 2
}

void q6() {
    char *str = (char*)1000;
    long long *u_ptr = (long long*)str;
    int *i_ptr = (int *)(u_ptr + 1);
    char *c_ptr = (char *)(i_ptr + 2);

    printf("u_ptr = %p\n", u_ptr); //1000
    printf("i_ptr = %p\n", i_ptr); //1008
    printf("c_ptr = %p\n", c_ptr); // 1016
}

void q7() {
    int x[] = {12, -1, 3, 8, -4};
    long long *y = (long long *)x; // convert to 8 bytes pointer
    int *z = (int *) ((char *)(y+2)-sizeof(int)); // y + 2 => 0 + 16 = 16 bytes arr[4] - 4 => arr[3]
    printf("%d", z[-1]); // arr[3] - 1 = arr[2] = 3
}

int main(void){
    printf("Hello, world\n\n");

    char string[] = "BADGERS";
    char *ptr = string;
    *ptr = *ptr + 2; // DADGERS
    ptr = ptr + 2; // pointing to string[2];
    printf("%c ", *ptr); // D
    ptr--; // string[1]
    printf("%c ", *ptr); // A
    ptr = string;
    printf("%c \n", *ptr); // D

    char str[6] = "cat";
    printf("%s\n", str);

    q1(); // 10_fighting

    char amessage[] = "now is the time";   /* an array */
    char *pmessage = "now is the time";    /* a pointer */

    // amessage holds address to amessage[0],  it is stored in stack with \0 at the end, when used it decays to a char*, (mutable)

    // pmessage is a pointer that points to pmessage[0], pmessage is stored in the stack but the string literal "now is the time\0" gets stored in static (read only segment) of the memory you cant mutate this

    char *x, *y;
    x = "HELLO";
    y = q2(x); // return pointer to L

    printf("%s\n", y); // LO

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 5};
    int *ip = arr + 4;
    printf("%d\n", ip[1]); // 6

    char c[] = "GATE2011";
    char *p = c;
    printf("%s\n", p + p[3] - p[1]); // p + 4 = 2011

    
    char charrr[] = "Monday";
    changeit(charrr);

    int nums[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    printf("%d\n", nums[1][2]); // 7
    printf("%d\n", *(*(nums + 1) + 2)); // 7
    printf("%d\n", *(*nums + 6)); // 7
    printf("%d\n", *(*(nums + 2) - 2)); // 7

    q3();
    q4();
    q5();

    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int *qp = (int*)((short *)(a+5)+2);
    printf("%d\n", *qp);

    char strAlpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ax = strAlpha[0]; // A
    char cx = *(char*)((int *)strAlpha + 2); //str[8] = I 
    char dx = (strAlpha + 2)[3]; // F
    printf("%c, %c, %c\n", ax, cx, dx);

    int iarr[100];
    iarr[50] = 985;
    int *pq = iarr;
    printf("%d\n", *(int *)((char *)pq + 50 * sizeof(int))); // this is correct
    printf("%d\n", *(int *)(pq + 50 * sizeof(int *))); // 400 ints ahead
    printf("%d\n", ((int *)((char *)pq + 50))[0]); // 12.5 ints ahead
    printf("%d\n", *(char *)((int *)pq + 50)); // it points to &iarr[50] but since its char* it reads only 1 byte so not correct

    int testArr[4] = { 6, 7, 8, 9 };
    printf("%d\n", (int) (&testArr[2] - &testArr[0])); // 2
    printf("%d\n", (int) ((char *)&testArr[2] - (char *)&testArr[0])); // 2 * 4 = 8

    q6();
    q7();
    return 0;
}