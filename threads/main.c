#include <pthread.h>
#include <stdio.h>

int a = 0;
int b = 0;
int c = 0;
int d = 0;

void* tfunc0(void* p) {

    int i;

    a = 42;

    for (i = 0; i < 2; i++)
        a = a + 1;
    a = a + 2;
    a = a + 3;
    a = a + 4;

    printf("Thread 0 done!\n");
}

void* tfunc1(void* p) {

    int i;

    b = 42;

    for (i = 0; i < 6; i++)
        b = b + 1;
    b = b + 2;
    b = b + 3;
    b = b + 4;
    printf("Thread 1 done!\n");
}

void* tfunc2(void* p) {

    int i;

    c = 42;

    for (i = 0; i < 8; i++)
        c = c + 1;
    c = c + 2;
    c = c + 3;
    c = c + 4;
    printf("Thread 2 done!\n");
}

void* tfunc3(void* p) {

    int i;

    d = 42;

    for (i = 0; i < 10; i++)
        d = d + 1;
    d = d + 2;
    d = d + 3;
    d = d + 4;
    printf("Thread 3 done!\n");
}

int main() {

    pthread_t thread0;
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;

    pthread_create( &thread0, 0, tfunc0, (void*) 0);
    pthread_create( &thread1, 0, tfunc1, (void*) 0);
    pthread_create( &thread2, 0, tfunc2, (void*) 0);
    pthread_create( &thread3, 0, tfunc3, (void*) 0);

    pthread_join( thread0, 0);
    pthread_join( thread1, 0);
    pthread_join( thread2, 0);
    pthread_join( thread3, 0);

    printf("All threads done! a: %d, b: %d, c:%d, d:%d\n", a, b, c, d);
    return 0;
}

