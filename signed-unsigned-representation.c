#include <stdio.h>

void printBinary(int num) {
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
        if (i % 8 == 0) printf(" ");
    }
    printf("\n\n");
}

int main(void) {
    int a = 9;
    int b = -9;

    printf("%d in binary: \n", a);
    printBinary(a);

    printf("%d in binary: \n", b);
    printBinary(b);


    // asking printf to treat the binary representation as 
    printf("%d\n", b);
    printf("%u\n", b);

    unsigned int c = -12; //
    printBinary(c);
    // asking printf to treat the binary representation as 
    printf("%d\n", c);
    printf("%u\n", c);

    return 0;
}