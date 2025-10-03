#include <stdio.h>
#include <stdbool.h>

bool evenOdd(int num) {
    int res = num & 1;
    if (res) return false;
    else return true;
}

int q() {
    int a = 10, b = 20, c = 30;
    if (a < b < c) { // 1 < 30 True
        printf("True\n");
    } else {
        printf("False\n");
    }

    if (c > b > a) { // 1 > 10 false
        printf("True\n");
    } else {
        printf("False\n");
    }
}

int main(void) {
    int a = 9 - 12 / 3 + 3 * 2 - 1;
    printf("%d\n", a);
    q();
    printf(evenOdd(12) ? "True\n" : "False\n" );
    printf(evenOdd(15) ? "True\n" : "False\n");
    return 0;
}