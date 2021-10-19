#include <stdio.h>

int foo(int);
int bar(int);

int main() {

    int a = 1;

    /* Test code: */
    /* If foo is doing smth else than adding 1 to it's inparam, we fail */
    /* Lets not care about bar for now, I will fix a test for bar later ;) */

    if (foo(a) ==  2)     
        printf("Success!\n");
    else
        printf("Fail!\n");
}
