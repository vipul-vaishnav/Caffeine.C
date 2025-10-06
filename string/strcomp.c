#include <stdio.h>

int my_strcomp(char *s1, char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    if (*s1 == *s2) return 0;         // both reached '\0'
    else if (*s1 < *s2) return -1;
    else return 1;
}


int main(void){
    char name1[] = "Vipul";
    char name2[] = "Vipul";
    char name3[] = "Vipuz";

    printf("%d\n", my_strcomp(name1, name2)); // 0
    printf("%d\n", my_strcomp(name3, name2)); // -1
    printf("%d\n", my_strcomp(name1, name3)); // 1

    return 0;
}