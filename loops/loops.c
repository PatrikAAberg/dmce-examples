int loops(int a, int* b) {

    int c = 0;
    int d = 0;

    int i;

    for (i = 0; i < a; i++) {

        c += i * 100 + 10 * a;

        c += *b;
    };

    for (i = 0; i < a; i++) {

        d += i * 1000 + 100 * a;

        d += *b * 10;
    };

    return c + d;
}

