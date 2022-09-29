#include <stdio.h>

#define N 50000000

int contador[N] = {0};

int main(){

    long d;
    long prod;
    long x = 1;
    for (x; x < N; x++) {
        d = x / 4 + 1;
        while ((d < x) && (prod = (4 * d - x) * x) < N) {
            contador[prod]++;
            d++;
        }
    }
    long valores = 0;
    long n = 1;
    for (n; n < N; n++) {
        if (contador[n] == 1) {
            valores++;
        }
    }
    printf("\n%ld valores possuem essa propriedade\n\n", valores);
    system("pause");
    return 0;
}
