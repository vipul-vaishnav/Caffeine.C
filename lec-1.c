// Structure of C program

#include <stdio.h>
#include <stdbool.h>

#define MAX_VAL 100
#define PI (22.0 / 7.0)
#define AREA_OF_SQUARE(s) ((s) * (s))
#define AREA_OF_RECT(a, b) ((a) * (b))

int side = 12;
int calcArea(int side);
int calcAreaRect(int a, int b);
void printArea(int area);
void printAreaRect(int a, int b, int area);
bool checkValidity(int area);

int main(void) {
    int area = calcArea(side);
    printArea(area);
    printAreaRect(6, 12, calcAreaRect(6, 12));

    if (checkValidity(area)) {
        printf("Area is valid!");
    } else {
        printf("Area is not valid!");
    }

    return 0;
}

int calcArea(int s) {
    int area = AREA_OF_SQUARE(s);
    return area;
}

int calcAreaRect(int a, int b) {
    return AREA_OF_RECT(a, b);
}

void printArea(int area) {
    printf("Area of square with side %d is %d sq. units\n\n", side, area);
}

void printAreaRect(int a,  int b, int area) {
    printf("Area of rectangle with length %d and width %d is %d sq. units\n\n", a, b, area);
}

bool checkValidity(int area) {
    return area < MAX_VAL;
}