#include <stdio.h>

int main(){

    int limite = 12000;
    int a = 1;
    int b = 3;
    int c = 4000;
    int d = 11999;

    int resultado = 0;

    while(!(c == 1 && d == 2)){
        resultado++;
        int k = (limite + b) / d;
        int e = k * c - a;
        int f = k * d - b;
        a = c;
        b = d;
        c = e;
        d = f;
    }
    printf("\no Resultado e de: %d\n\n", resultado);
    system("pause");
    return 0;
}
