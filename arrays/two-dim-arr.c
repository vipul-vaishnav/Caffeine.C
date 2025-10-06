#include <stdio.h>

void q() {
    unsigned int x[4][3] = {{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}};
    printf("%u, %u, %u\n", x + 3, *(x + 3), *(x + 2) + 3); // 2036, 2036, 2036
}

// Given:
// unsigned int x[4][3];
// → 4 rows, 3 columns, each element = 4 bytes.

// So:

// Row size = 3 * 4 = 12 bytes

// Base address of x = 2000

// Now compute each term:

// x + 3
// x is of type unsigned int (*)[3].
// Adding 3 moves ahead by 3 * sizeof(row) = 3 * 12 = 36 bytes.
// → Address = 2000 + 36 = 2036.

// *(x + 3)
// Dereferencing gives you the 4th row, which itself is an array of 3 unsigned ints.
// The address of that row (i.e., the address of x[3][0]) = 2036.

// *(x + 2) + 3
// x + 2 points to the 3rd row (x[2]) starting at 2000 + 2×12 = 2024.
// Adding 3 moves forward by 3 * 4 = 12 bytes.
// 2024 + 12 = 2036.

// So all three point to the same address — 2036.

int main(void){
    q();
    printf("Hello, world\n");
    int arr[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    printf("%d\n", arr[1][2]);
    printf("%d\n", *(*(arr + 1) + 2));
    printf("%d\n", *(*(arr) + 6));
    printf("%d\n", *(*(arr + 2) - 2));
    printf("%d\n", arr[2][-2]);
    return 0;
}