#include <stdio.h>

int main(int argc, char** argv) {

    int a = 0;

    if (argc > 1) {

        for (int i = 0; i < 10; i++) {

            a = a + 1;
        }

        for (int i = 1; i < 10; i++) {

            a = a + 1;
        }

        for (int i = 2; i < 10; i++) {

            a = a + 1;
        }

        for (int i = 3; i < 10; i++) {

            a = a + 1;
        }

        for (int i = 4; i < 10; i++) {

            a = a + 1;
        }

        for (int i = 5; i < 10; i++) {

            a = a + 1;
        }

        for (int i = 6; i < 10; i++) {

            a = a + 1;
        }

        for (int i = 7; i < 10; i++) {

            a = a + 1;
        }


    }
    else {

        for (int j = 5; j < 10; j++) {

            a = a + 2;
        }

        for (int j = 6; j < 10; j++) {

            a = a + 2;
        }

        for (int j = 7; j < 10; j++) {

            a = a + 2;
        }

        for (int j = 8; j < 10; j++) {

            a = a + 2;
        }

        for (int j = 9; j < 10; j++) {

            a = a + 2;
        }
    }

    printf("a = %d\n", a);
}
