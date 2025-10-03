#include <stdio.h>

int main(void) {
    int p = 10;
    for(;p >= 0;) {
        p--;
        printf(
            "Value of p: %d\n",
            p
        );
    }

    for (int k = 0; k < 10; k++){
       
        printf("Value of k: %d\n", k);
    }

    return  0;
}