#include <stdio.h>

void q1() {
    int i, j, k = 0;
    j = 2 * 3 / 4 + 2.0 / 5 + 8 / 5;
    k -= --j;

    for (i = 0; i < 5; i++) {
        switch(i + k) {
            case 1:
            case 2: printf("\n%d", i + k);
            case 3: printf("\n%d", i + k);
            default: printf("\n%d", i + k);
        }
    }
}

void q2() {
    int i, j, count;
    count = 0;
    i = 0;
    for (j = -3; j <= 3; j++) {
        if ((j >= 0) && (i++))
            count = count + j;
    }
    count = count + i;
    printf("\n%d\n", count); // 10
}

void q3() {
    int i = 0, j = 1, k = 2, m;
    m = i++ || j++ || k++;
    printf("%d, %d, %d, %d\n", m, i, j, k); // 1,1,2,2
}

int main(void) {
    q1();
    q2();
    q3();
    return  0;
}

// j = 1 + 0.4 + 1 // 2.4 but j is int so j = 2;
// k = k - (--j) => 0 - (1) = -1
// printf runs 10 times now