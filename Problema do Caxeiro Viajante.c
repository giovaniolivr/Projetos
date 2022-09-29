#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int n, i, j, ind, g, r, v, passos = 0, passos2 = 0, lim, p = 1, mapa;
    float x, y, aux, valor, dif, coord[10000][3], L, Loi, Lo = 0, Li = 0, T = 10;

    printf("Escolha o numero de cidades: ");
    scanf("%d", &n);
    printf("\nEscolha a quantidade de passos MC/Metropolis: ");
    scanf("%d", &lim);
    printf("\nEscolha o tipo de mapa (0 para normal, 1 para perimetro): ");
    scanf("%d", &mapa);
    lim = lim+1;

    srand(time(NULL));

    FILE *fp;
    FILE *tp;
    tp = fopen ("distxtemp.txt", "w");
    fp = fopen ("coordenadas.txt", "w");

    /*--Gerador de coordenadas aleatórias--*/

    if(mapa == 0){

    for(i=0; i<n; i++){
            coord[i][0] = i+1;
        for(j=1; j<3; j++){
            x = rand()%1001;
            x = x/1000;
            coord[i][j] = x;
        }
    }
        for(i=0; i<n; i++){
            printf("%.f %.3f %.3f", coord[i][0], coord[i][1], coord[i][2]);
            printf("\n");
            fprintf(fp, "%.f %.3f %.3f", coord[i][0], coord[i][1], coord[i][2]);
            fprintf(fp, "\n");
    }
    }

    if(mapa == 1){
        for(i=0; i<n/2; i++){
            x = rand()%1001;
            x = x/1000;
            v = rand()%2;
            coord[2*i][0] = (2*i)+1;
            coord[2*i][1] = x;
            coord[2*i][2] = v;
        }
        for(i=1; i<(n/2)+1; i++){
            x = rand()%1001;
            x = x/1000;
            v = rand()%2;
            coord[(2*i)-1][0] = 2*i;
            coord[(2*i)-1][1] = v;
            coord[(2*i)-1][2] = x;
        }
        for(i=0; i<n; i++){
            printf("%.f %.3f %.3f", coord[i][0], coord[i][1], coord[i][2]);
            printf("\n");
            fprintf(fp, "%.f %.3f %.3f", coord[i][0], coord[i][1], coord[i][2]);
            fprintf(fp, "\n");
    }
    }

    system("pause");

    fclose (fp);

    /*--Método Monte Carlo--*/

    for(i=0; i<n-1; i++){
        L = sqrt(pow((coord[i+1][1] - coord[i][1]), 2) + pow((coord[i+1][2] - coord[i][2]), 2));
        Lo = L + Lo;
        L = Lo;
    }
        L = sqrt(pow((coord[0][1] - coord[n-1][1]), 2) + pow((coord[0][2] - coord[n-1][2]), 2));
        Lo = L + Lo;
        Loi = Lo;

    do{

    do{

    ind = rand()%n;

    if(ind == n-1){
        for(j=0;j<3;j++){
            aux = coord[ind][j];
            coord[ind][j] = coord[1][j];
            coord[1][j] = aux;
          }
    }else{
        for(j=0;j<3;j++){
            aux = coord[ind][j];
            coord[ind][j] = coord[ind+1][j];
            coord[ind+1][j] = aux;
          }
    }

    for(i=0; i<n-1; i++){
        L = sqrt(pow((coord[i+1][1] - coord[i][1]), 2) + pow((coord[i+1][2] - coord[i][2]), 2));
        Li = L + Li;
        L = Li;
    }
        L = sqrt(pow((coord[0][1] - coord[n-1][1]), 2) + pow((coord[0][2] - coord[n-1][2]), 2));
        Li = L + Li;

        dif = Li - Lo;

    if(dif < 0){
        Lo = Li;
    }if(dif > 0){
        valor = rand()%1001;
        valor = valor/1000;
        if(valor < exp(-(dif)/T)){
            Lo = Li;
        }
        if(valor > exp(-(dif)/T)){
            Li = 0;
        }
    }
    passos++;

    passos2++;

    if(T < 0.1 && Li == Lo){
        fp = fopen ("coordenadas2.txt", "w");
        for(i=0; i<n; i++){
            fprintf(fp, "%.f %.3f %.3f", coord[i][0], coord[i][1], coord[i][2]);
            fprintf(fp, "\n");
    }
    fclose (fp);
    }

    Li = 0;
    }while(passos < lim);

    fprintf(tp, "%.3f %.3f", T, Lo);
    fprintf(tp, "\n");


    passos = 0;

    printf("\nTemperatura: %f\n", T);

    T = T -((0.1/100) * T);

    }while(T > 0.0001);
    fclose (tp);
    printf("\nLo inicial: %.3f\n", Loi);
    printf("\nLo final: %.3f\n", Lo);

    system("pause");
    return 0;
}

