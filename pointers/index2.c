#include <stdio.h>

void func(int *p) {
    *p = *p + 20;
}

int main(void){
    int x = 10;
    func(&x);
    printf("%d", x);
    return 0;
}

