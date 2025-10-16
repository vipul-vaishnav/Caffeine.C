#include <stdio.h>

void q1() {
    int i = -3;
    unsigned short u;
    u = i;

    printf("%d\n", u);
    printf("%u\n", u);
}

void q2() {
    signed short int ix = -3;

    printf("%d\n", ix);
    printf("%u\n", ix);
}

void q3() {
    signed char a = 100; // 100
    signed char b = 200; // 200 - 256 = -56
    signed char c = a + b; // 100 - 56 = 44 
    printf("%d, %d, %d\n", a, b, c);
}

void q4() {
    signed char a = 100; 
    signed char b = 3;
    signed char c = 4;
    signed char r = a * b / c;
    printf("%d\n", r);
}

void q5(void) {
    signed char a = 100;
    unsigned char b = 200;
    unsigned char c = a + b; // 44
    printf("%d, %d, %d, %d\n", a, b, a + b, c); // 100, 200, 300, 44
}

void q6() {
    int k, i=50, j=100, l;
    
    i = i | (j && 100); 
    
    k = i || (j || 100);
    
    l = i & (j && 100);
    
    printf("%d %d\n", i, j);
    printf("%d %d", k, l);
}

int main(void) {
    q1();
    q2();
    q3();
    q4();
    q5();
    q6();
    return 0;
}