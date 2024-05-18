#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// void method_1();
// void method_2();
void method_3();

/* void method_1(int i) {
    clock_t start = clock();

    int numeros[i];
    numeros[0] = 2;
    int n = 1, latest = 3;
    while (i > n) {
        bool div = false;
        int k = 0;
        while (k < n) {
            div = latest % numeros[k] == 0;
            if (div) {
                latest++;
                k = 0;
                break;
            }
            k++;
        }
        if (!div) {
            numeros[n] = latest;
            n++;
            latest++;
        }
    }
    printf("1: El número primo en la posición %d es: %d\n", i, numeros[i-1]);

    clock_t end = clock();
    printf("%.2f ms\n", (double) (end - start) / (CLOCKS_PER_SEC/1000));
}

void method_2(int i) {
    clock_t start = clock();

    int numeros[i];
    numeros[0] = 2;
    int n = 1, latest = 3;
    while (i > n) {
        bool div = false;
        int k = 0;
        while (k < n) {
            div = latest % numeros[k] == 0;
            if (div) {
                latest+=2;
                k = 0;
                break;
            }
            k++;
        }
        if (!div) {
            numeros[n] = latest;
            n++;
            latest+=2;
        }
    }
    printf("2: El número primo en la posición %d es: %d\n", i, numeros[i-1]);

    clock_t end = clock();
    printf("%.2f ms\n", (double) (end - start) / (CLOCKS_PER_SEC/1000));
} */

void method_3(int i) {
    clock_t start = clock();

    int numeros[i];
    numeros[0] = 2;
    int n = 1, latest = 3;
    while (i > n) {
        bool div = false;
        int k = 0;
        while (k < n) {
            div = latest % numeros[k] == 0;
            if (div) {
                latest+=2;
                k = 0;
                break;
            }
            if (numeros[k]*numeros[k] > latest) {
                k = 0;
                break;
            }
            k++;
        }
        if (!div) {
            numeros[n] = latest;
            n++;
            latest+=2;
        }
    }
    printf("3: El número primo en la posición %d es: %d\n", i, numeros[i-1]);

    clock_t end = clock();
    printf("%.2f ms\n", (double) (end - start) / (CLOCKS_PER_SEC/1000));
}




void main(int argc, char *argv[]) {
    int i = atoi(argv[1]);

    method_3(i);
    // method_2(i);
    // method_1(i);
}

