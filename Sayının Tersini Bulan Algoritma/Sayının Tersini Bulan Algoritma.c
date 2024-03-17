#include <stdio.h>

long findModularInverse(long a, long n) {
    long t = 0, newt = 1;
    long r = n, newr = a;

    while (newr != 0) {
        long quotient = r / newr;

        long tempt = t;
        t = newt;
        newt = tempt - quotient * newt;

        long tempr = r;
        r = newr;
        newr = tempr - quotient * newr;
    }

    if (r > 1) {
        printf("Hata: Girdi modüler tersi yok.");
        return -1; // Ters yok
    }

    if (t < 0) {
        t = t + n;
    }

    return t;
}

int main() {
    long x, n; // Input

    printf("x sayisi: ");
    scanf("%ld", &x);

    printf("n modu: ");
    scanf("%ld", &n);

    long inverse = findModularInverse(x, n);

    if (inverse != -1) {
        printf("x'in mod %ld'e gore tersi: %ld\n", n, inverse);
    }

    return 0;
}

