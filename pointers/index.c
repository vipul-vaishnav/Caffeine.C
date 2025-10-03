#include <stdio.h>

int main(void){
    int x = 5, y = 2;
    int *p1, *p2;
    p1 = &x;
    p2 = &y;
    *p1 = 10;
    *p2 = *p1;
    p1 = p2;
    *p2 = 20;
    printf("x=%d, y=%d", x, y);
    return 0;
}