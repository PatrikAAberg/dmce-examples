#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int num_loops = 1;
int num_cores = 4;

volatile int a = 0;
volatile int b = 0;
volatile int c = 0;
volatile int d = 0;

int buf[128 * 128];

void wait(float time) {

    sleep(time);
}

int add_same10(int n) {

    int b = n;

    b = b + n;
    usleep(10);
    return b;
}

int add_same9(int n) {

    int b = n;

    b = b + add_same10(n);
    usleep(10);

    return b;
}

int add_same8(int n) {

    int b = n;

    b = b + add_same9(n);
    usleep(10);

    return b;
}

int add_same7(int n) {

    int b = n;

    b = b + add_same8(n);
    usleep(10);

    return b;
}

int add_same6(int n) {

    int b = n;

    b = b + add_same7(n);
    usleep(10);

    return b;
}

int add_same5(int n) {

    int b = n;

    b = b + add_same6(n);
    usleep(10);

    return b;
}

int add_same4(int n) {

    int b = n;

    b = b + add_same5(n);
    usleep(10);

    return b;
}

int add_same3(int n) {

    int b = n;

    b = b + add_same4(n);
    usleep(10);

    return b;
}

int add_same2(int n) {

    int b = n;

    b = b + add_same3(n);
    usleep(10);

    return b;
}

int add_same1(int n) {

    int b = n;

    b = b + add_same2(n);

    return b;
}

void* tfunc0(void* p) {

    int i;

    a = 42;

    for (i = 0; i < 2 * num_loops; i++) {

        a = a + 1;
        a = add_same1(a);
        wait(0.2);
    }
    a = a + 2;
    a = a + 3;
    a = a + 4;
}

void* tfunc1(void* p) {

    int i;

    b = 42;

    b = add_same1(b);

    for (i = 0; i < 6 * num_loops; i++) {
        b = b + 1;
        wait(0.15);
    }
    b = b + 2;
    b = b + 3;
    b = b + 4;
}

void* tfunc2(void* p) {

    int i;

    c = 42;
    for (i = 0; i < 8 * num_loops; i++) {
        c = c + 1;
        wait(0.1);
    }
    c = c + 2;
    c = c + 3;
    c = c + 4;
    c = add_same1(c);
}

void* tfunc3(void* p) {

    int i;

    d = 42;

    for (i = 0; i < 10 * num_loops; i++) {
        d = d + 1;
        wait(0.05);
    }
    d = d + 2;
    d = d + 3;
    d = d + 4;
}

void fill(int* p) {

    for (int i = 0; i < 10; i++) {

        p[i] = i;
    }
}

int main(int argc, char *argv[]) {

    float dummy = 0;

    if(argc > 1 ) {
        num_loops = atoi(argv[1]); 
        if (num_loops == 0) {

            printf("Please provide a number of loops larger than 0\n");
            return 1;
        }
    }

    if(argc > 2 ) {
        num_cores = atoi(argv[2]); 
        if (num_cores == 0) {

            printf("Please provide a number of cores larger than 0\n");
            return 1;
        }
    }

    pthread_t* threads = malloc(num_cores * sizeof(pthread_t));

    for (int i = 0; i < num_cores; i++) {

        int whichfunc = i % 4;

        switch (whichfunc) {
            case 0:
                pthread_create( &threads[i], 0, tfunc0, (void*) 0);
                break;
            case 1:
                pthread_create( &threads[i], 0, tfunc1, (void*) 0);
                break;
            case 2:
                pthread_create( &threads[i], 0, tfunc2, (void*) 0);
                break;
            case 3:
                pthread_create( &threads[i], 0, tfunc3, (void*) 0);
                break;
         }
    }

    for (int i = 0; i < num_cores; i++) {

        pthread_join( threads[i], 0);
        printf("Thread %d done\n", i);
    }

    printf("All threads done! a: %d, b: %d, c:%d, d:%d\n", a, b, c, d);

    fill(&buf[0]);

//    DMCE_HEXDUMP(&buf[0], 15);

    fill(&buf[10]);

    fill(&buf[20]);

    dummy = 0.1;
    wait(dummy);

    dummy = 0.2;

    for (int i = 0; i < 40; i++)
        printf("%d\n", buf[i]);

    return dummy + 1;
}

