#include <stdio.h>

int main(void) {
    char a = 30, b = 40;
    char d = a * b;
    printf("%d: \n", d); // truncation -80
    printf("%d: \n", a * b); // 1200

    signed char f = -65;
    printf("%d: \n", f); // -65 11111....10111111 (because source is signed)
    printf("%u: \n", f); // huge number

    unsigned char f1 = -65;
    printf("%d: \n", f1); // 191 000000....10111111 (because source is unsigned)
    printf("%u: \n", f1); // 191
    return 0;
}