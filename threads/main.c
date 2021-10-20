#include <pthread.h>
#include <stdio.h>

int a = 0;
int b = 0;
int c = 0;
int d = 0;

void* tfunc0(void* p) {

    a = 42;

    a = a + 1;
    a = a + 2;
    a = a + 3;
    a = a + 4;

    printf("Thread 0 done!\n");
}

void* tfunc1(void* p) {

    b = 42;

    b = b + 1;
    b = b + 2;
    b = b + 3;
    b = b + 4;
    printf("Thread 1 done!\n");
}

void* tfunc2(void* p) {

    c = 42;

    c = c + 1;
    c = c + 2;
    c = c + 3;
    c = c + 4;
    printf("Thread 2 done!\n");
}

void* tfunc3(void* p) {

    d = 42;

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

    pthread_create( &thread0, NULL, tfunc0, (void*) 0);
    pthread_create( &thread1, NULL, tfunc1, (void*) 0);
    pthread_create( &thread2, NULL, tfunc2, (void*) 0);
    pthread_create( &thread3, NULL, tfunc3, (void*) 0);

    pthread_join( thread0, NULL);
    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL);
    pthread_join( thread3, NULL);

    printf("All threads done! a: %d, b: %d, c:%d, d:%d\n", a, b, c, d);
    return 0;
}

