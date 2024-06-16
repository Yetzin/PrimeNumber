#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void method_3();
void verify();

void method_3(int i) {
    clock_t start = clock();

    int numeros[i];
    numeros[0] = 2;
    int n = 1, latest = 3;
    // printf("1: 2\n");
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
            // printf("%d: %d\n", n, latest);
            latest+=2;
        }
    }
    printf("El número primo en la posición %d es: %d\n", i, numeros[i-1]);

    clock_t end = clock();
    printf("%.2f ms\n", (double) (end - start) / (CLOCKS_PER_SEC/1000));
}

void verify(int i) {
    clock_t start = clock();

    bool div = false;
    int k = 3;
    // double r;

    div = (
        i % 2 == 0 &&
        i != 2
    ) || (
        i == 1
    );

    while(k*k < i && !div) {
        div = i % k == 0;
        // r = (double) i / k;
        // printf("%d / %d = %.4f\n", i, k, r);
        k+=2;
    };

    if(!div) {
        div = (
            i % k == 0 &&
            i != k
        );
        // r = (double) i / k;
        // printf("%d / %d = %.4f\n", i, k, r);
    }

    if(div) {
        // if(k > 3) {
        //     printf("\n");
        // }
        printf("El número %d no es\n", i);
    } else {
        printf("El número %d sí es un número primo\n", i);
    }

    clock_t end = clock();
    printf("%.2f ms\n", (double) (end - start) / (CLOCKS_PER_SEC/1000));
}




int main(int argc, char *argv[]) {
    if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        printf("Uso: primos <arg> <number>");
        printf("\n\n Ejemplo: primos check 5");
        printf("\n El número 5 sí es un número primo");
        printf("\n-----------------------------------");
        printf("\n\n  -h, --help\t\tMuestra ayuda con el programa");
        printf("\n  <number>\t\tMuestra el número primo que esté en la posición indicada");
        printf("\n  check <number>\tVerifica si el número especficado es o no un número primo\n");
    } else if(strcmp(argv[1], "check") == 0) {
        int i = atoi(argv[2]);
        verify(i);
    } else {
        int i = atoi(argv[1]);
        method_3(i);
    }

    return 0;
}
