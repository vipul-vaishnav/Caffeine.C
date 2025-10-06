#include <stdio.h>

void reverseString(char* s, int sSize) {
    char *p = s;
    char *q = p + sSize - 1;

    while (p < q) {
        char temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
}

int main(void){
    char str[] = "C lang is the best!";
    reverseString(str, sizeof(str) / sizeof(str[0]) - 1); // subtracting 1 because otherwise \0 will be at the start and it wont print anything
    printf("%s", str);
    return 0;
}