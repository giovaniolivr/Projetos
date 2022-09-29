#include <stdio.h>

int main(){

    long numeroinicial, resposta;
    long long numero;
    int termos;
    int termossalvos = 0;

    for(numeroinicial = 2; numeroinicial < 1000000; numeroinicial++){
        termos = 1;
        numero = numeroinicial;
        while(numero > 1){
            while(numero % 2 == 0){
                numero /= 2;
                termos++;
            }
            if(numero > 1){
                numero = (numero*3) + 1;
                termos++;
            }
        }
        if(termos > termossalvos){
            termossalvos = termos;
            resposta = numeroinicial;
        }
    }
    printf("\nA maior corrente e de: %d\n\nO numero inicial foi: %ld\n\n", termossalvos, resposta);

    system("pause");
    return 0;
}
