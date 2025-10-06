#include <stdio.h>

int main(void){
    char arr[] = "Vipul";
    char *p;
    p = &arr[0];

    for (;p < arr + 5; p++) {
        printf("%c ", *p);
    }
    return 0;
}