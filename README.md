# Hesaplama-Algoritmalari-

Bu GitHub deposu, RSA ve SMA algoritmalarını içeren ve ayrıca bir sayının tersini bulan algoritmayı içeren bir kütüphaneyi barındırmaktadır. Bu algoritmalar, şifreleme sistemlerini analiz etmek ve geliştirmek için kullanılan önemli kriptografik araçlardır. Bu kodlar, bu algoritmaların temel prensiplerini anlamak ve uygulamak isteyenler için bir kaynak olarak tasarlanmıştır. Ayrıca, kriptografi alanında çalışma yapmak isteyen araştırmacılar ve geliştiriciler için öğrenme ve deney yapma amacıyla da uygun bir ortam sağlar. Bu repo, açık kaynaklı toplulukla paylaşılan bilgi ve deneyimlerin bir birleşimi olarak gelişmeye açıktır. Katkıda bulunmak veya projeyi çeşitli platformlarda kullanmak isteyen herkesi bekliyoruz.

RSA-SMA Algoritması

```c
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

```
