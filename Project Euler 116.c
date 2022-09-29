#include <stdio.h>

int main(){

    long long cache[3][51];
    long long retangulo(int n, int comprimento) {
    long long resultado = 0;
    int i;

    if (cache[n-2][comprimento] != -1)
    return cache[n - 2][comprimento];

    for (i = 0; i <= comprimento - n; i++){
        resultado += 1 + retangulo(n, comprimento - i - n);
      }
      cache[n-2][comprimento] = resultado;
      return resultado;
    }
      int i;
      for (i = 0; i < 51; i++) {cache[0][i] = -1; cache[1][i]= -1; cache[2][i] = -1;}

    printf("\nVoce pode preencher de %lli maneiras\n\n", retangulo(2, 50) + retangulo(3, 50) + retangulo(4,50));
    system("pause");
    return 0;
}
