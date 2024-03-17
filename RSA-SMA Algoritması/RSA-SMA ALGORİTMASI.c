#include <stdio.h>
#include <stdlib.h>

long sma(long x, long H, long n) {
    long h;
    unsigned long long r;
    int bin[32];
    int i;

    r = x;
    i = 0;

    /* Converts H in Binary */
    while (H > 0) {
        if (H % 2 == 0) {
            bin[i] = 0;
        } else {
            bin[i] = 1;
        }

        H = H / 2;
        i++;
    }

    i--; //t-1

    while (i > 0) {
        r = (r * r) % n;

        if (bin[--i] == 1) {
            r = (r * x) % n;
        }
    }

    return r;
}

int main() {
    long X, k, N; // input
    long Y;       // output
    printf("X sayisi: ");
    scanf("%ld", &X); // reading
    printf("k us: ");
    scanf("%ld", &k);
    printf("(mod n): ");
    scanf("%ld", &N);

    Y = sma(X, k, N); // Square-and-Multiply modular Exponentation

    printf("sonuc: %ld\n", Y);

    return 0;
}

