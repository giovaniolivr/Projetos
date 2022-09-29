#include <stdio.h>
#include <math.h>

/* Defina a função desejada em f(x) e sua derivada em df(x) */

#define f(x)  exp(2 * x) - x - 6
#define df(x) 2 * exp(2 * x) - 1

int main(){
    float x, f, df, x0, f0, erro;
    int iteracoes = 0, num;
    printf("Digite o chute inicial: ");
    scanf("%f", &x);
    printf("\nDigite o erro associado: ");
    scanf("%f", &erro);
    printf("\nDigite o numero de iteracoes: ");
    scanf("%d", &num);
    printf("\nNumero interacao\tRaiz\t\tValor da funcao\n");

    do{
        f = f(x);
        df = df(x);
        x0 = x - (f/df);
        f0 = f(x0);
        x = x0;
        iteracoes++;
        if(iteracoes > num){
            printf("A funcao nao e convergente\n");
            return 0;
        }
        printf("%d\t\t\t%f\t%f\n\n", iteracoes, x0, f0);
    }while(f0 > erro);

    printf("A raiz encontrada foi de: %f\n\n", x0);
    system("pause");
    return 0;
}
