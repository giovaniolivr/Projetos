#include <stdio.h>

int main(){
    int diasdomes[12] = {
       31,
       29,
       31,
       30,
       31,
       30,
       31,
       31,
       30,
       31,
       30,
       31
    };
    int contadorsol = 0;
    int mes;
    int ano;
    int diadasemana = 1;

    for(mes = 1; mes <= 12; mes++){
        diadasemana += (diasdomes[mes - 1] % 7);
        if(diadasemana > 7)
            diadasemana = (0 + diadasemana % 7);
    }
    for (ano = 1901; ano <= 2000; ano++){
        if (((ano % 100 == 0)&&(ano % 400 == 0)) || (ano % 4 == 0)){
            diasdomes[1] = 29;
        } else{
        diasdomes[1] = 28;
        }
        for (mes = 1; mes <= 12; mes++){
            diadasemana += (diasdomes[mes - 1] % 7);
            if (diadasemana > 7){
                diadasemana = (0 + diadasemana % 7);
            } else if(diadasemana == 7){
            contadorsol++;
            }
        }
    }
    printf("\nPassaram-se %d domingos\n\n", contadorsol);
    system("pause");
    return 0;
}
