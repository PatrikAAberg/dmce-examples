#include <stdio.h>
#include "loops.h"

int main() {

    printf("Loops!\n");

    int a = 10;
    int b = 0;
    int c;

    c = loops(a, &b);

    a = a + 1;
    b = b + 1;

    c += loops(a, &b);

    a = a + 1;
    b = b + 1;

    c += loops(a, &b);
    c += loops(a, &b);
    c += loops(a, &b);
    c += loops(a, &b);
    c += loops(a, &b);
    c += loops(a, &b);
    c += loops(a, &b);
    c += loops(a, &b);
    c += loops(a, &b);
    c += loops(a, &b);

    printf("Done!\n");

    return c;
}

