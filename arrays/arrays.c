#include <stdio.h>

// int getSize(int arr[]) {
//     int totalSize = sizeof(arr);
//     int elementSize = sizeof(arr[0]);
//     return totalSize / elementSize;
// }

int main() {
    int k;
    printf("Please enter size of the arr\n");
    scanf("%d", &k);
    printf("Size of arr is: %d\n", k);
    int arr[k];
    printf("Enter arr elements\n");
    for (int i = 0; i < k; i++) {
        scanf("%d\n", &arr[i]);
    }
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}