#include <stdio.h>

void q1() {
    int i = 2, j = 3, k= 0;
    int p = (i, k, j);
    printf("%d\n", p); // 3;
}

void q2() {
    int ii = 10;
    ii <<= 1; // left shift assignment ii = 2 * 10 = 20
    printf("%d\n", ii);
}

void q3() {
    int var1 = 1, var2 = 12, var3 = 12;
    var1 = var2 == var3; // order of precedence relational then assignment
    printf("%d\n", var1); // 1
}

void q4() {
    int var = - -3;
    printf("var=%d\n", var); // 3
}

void q5() {
    int i = 15, j = 4, m, n;
    m = i > 9; // 1
    n = j > 2 && j != 2; // 1
    printf("m: %d, n: %d\n", m, n);
}

void q6() {
    int x = 7, y = 10, z = 5;
    int result = 0;

    result = ++y - 10 || z - 5 && x++; // y = 11, 11 - 10 = 1 => True || something so it will return 1 and exp after || will not execute because of short circuitting
    result += y++ - 11 || z++ - 5 && x++; // y = 12, 11 - 11 = 0 , z = 6, 5 - 5 = 0, false && something so it will return 0 and exp after && will not run
    result += y + 1 > 11 && (z++ >= 6 || x++); // 13 > 11, will return true, true && (z = 7, 6 >= 6 true, so x++ wont run, result += 1, -> 2);

    printf("result: %d\n", result); // 2
    printf("x: %d\n", x); // 7
    printf("y: %d\n", y); // 12
    printf("z: %d\n", z); // 7
}

void q7() {
    int a = 1, b = 3, c = 1;
    if ((a || c--) && (c && b--)) {
        printf("%d\n", b); // 2
    }
    printf("%d, %d, %d\n", a, b, c);

    // (1 || 1)  && (1 && 3) => (1 && 1) => 1 => True, => b = 2
    // c should have become 0 but since a is true and we have or operator therefore c-- will not execute c is still 1, b has become 2
    // 1, 2, 1
}

void q8() {
    int a = 0;
    if (0 && a++ == 0) { // False && something (something wont execute)
        printf("Inside if\n");
    } else {
        printf("else\n"); // else
    }

    printf("%d\n", a); // 0
}

void q9() {
    int i = 4, j = -1, k = 0, w, x, y, z;
    w = i || j || k; // 1
    x = i && j && k; // 0
    y = i || j && k; // 1 (shortcircuit wont let j && k execute)
    z = i && j || k; // 1

    printf("%d, %d, %d, %d\n", w, x, y, z);
}

void q10() {
    int i, j, k, l, m;
    // i = -1, j = -1, k = -1, l = 2;
    // i = -1, j = -1, k = 0, l = 2;
    i = 0, j = 2, k = 3, l = 2;
    m = (i++ && j++ && k++) || l++;
    printf("i=%d, j=%d, k=%d, l=%d, m=%d\n", i, j, k, l, m);

    // 0, 0, 0, 2, 1
    // 0, 0, 1, 3, 1
    // 1, 2, 3, 3, 1
}

void q11() {
    int a, b, c, d;
    a = 3, b = 5;
    c = a, b; // 3
    d = (a, b); // 5
    printf("c=%d, d=%d\n", c, d);
}

void q12() {
    int a, b = 2, c;
    a = 2 * (b++); // 2 * 2 = 4, b = 3
    c = 2 * (++b); // 2 * 4 = 8, b = 4
    printf("a=%d, b=%d, c=%d\n", a, b, c);
    // 4, 4, 8
}

void q13() {
    int x = 0, y = 2, z = 3;
    int a = x & y | z;
    printf("%d\n", a); // 3
}

void q14() {
    int a = 10, b = 5, c = 3;
    b != !a;
    c = !!a; // a -> true, !a -> false = 0, !!a -> true = 1; (~ and ! are different)
    printf("%d\t%d\n", b, c); // 5, 1
}

void q15() {
    int c = 2 ^ 3;
    printf("%d\n", c); // 1
}

void q16() {
    int i;
    // scanf("%d", &i); // values of i for which printf executes
    i = -1;
    if (!i == ~i) printf("same this time\n"); // i = -1
}

void q17() {
    int a = 2;
    if (a >> 1) {
        printf("%d\n", a); // 2
    }
}

void q18() {
    int i = 0, j = 1, k = 2, m;
    m = i++ || j++ || k++;
    printf("m=%d, i=%d, j=%d, k=%d\n", m, i, j, k);
    // 0 || 1 || 2  => 1
    // 1, 1, 2, 2
}

void q19() {
    int x = 1, y = 0, z = 5;
    int a = x && y || z++;
    printf("a=%d, z=%d\n", a, z); // 1, 6
}

void q20() {
    int x, i = 4, j = 7;
    x = j || i++ && 1; // 1 short circuit
    printf("x=%d, i=%d, j=%d\n", x,i,j);
    // 1, 4, 7
}

void q21() {
    int i = -3, j = 2, k= 0, m;
    m = ++i && ++j && ++k;
    printf("%d, %d, %d, %d\n", i, j, k, m);
    // -2 && 3 && 1 => 1;
    // -2, 3, 1, 1
}

void q22() {
    int i = -3, j = 2, k= 0, m;
    m = ++i || ++j && ++k;
    printf("%d, %d, %d, %d\n", i, j, k, m);
    // m = 1
    // -2, 2, 0
    // -2, 2, 0, 1
}

void q23() {
    int k, i = 50, j = 100, l;
    i = i | (j && 100); // 50 | 1 // 51 
    k = i || (j || 100); // 1
    l = i & (j && 100); // 51 & 1 // 1

    printf("%d, %d, %d, %d\n", i, j, k, l);
    // 51, 100, 1, 1
}

int main(void) {
    q1();
    q2();
    q3();
    q4();
    q5();
    q6();
    q7();
    q8();
    q9();
    q10();
    q11();
    q12();
    q13();
    q14();
    q15();
    q16();
    q17();
    q18();
    q19();
    q20();
    q21();
    q22();
    q23();
    return 0;
}