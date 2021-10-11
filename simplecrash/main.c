#include "simplecrash.h"

int main() {

    int a = 0;
    int b = 0;
    int c;

    c = simple(a, &b);
    c += simple(a, &b);
    c += simple(a, &b);

    return c;
}

