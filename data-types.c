#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int a = 4;
    short int b = 122;
    char c = 4;
    long d = 409827;
    long long e = 3;
    bool f = false;
    float g = 1.04;
    double h = 21.23;
    long double i = 422.09;

    int s = sizeof(a);
    printf("%d\n", s); // 4 bytes

    int s2 = sizeof(b);
    printf("%d\n", s2); // 2 bytes

    int s3 = sizeof(c);
    printf("%d\n", s3); // 1 byte

    int s4 = sizeof(d);
    printf("%d\n", s4); // 4 bytes

    int s5 = sizeof(e);
    printf("%d\n", s5); // 8 bytes

    int s6 = sizeof(f);
    printf("%d\n", s6); // 1 byte

    int s7 = sizeof(g);
    printf("%d\n", s7); // 4 bytes

    int s8 = sizeof(h);
    printf("%d\n", s8); // 8 bytes

    int s9 = sizeof(i);
    printf("%d\n", s9); // 16 bytes

    return 0;
}