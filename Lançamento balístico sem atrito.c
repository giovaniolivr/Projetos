#include <stdio.h>
#include <math.h>

#define pi 3.14159265358979324
#define g 9.80665
#define e 2.71828

int main(){

    float Vo, Vox, Voy, Vfy, Xo = 0, X = 0, Yo = 0, Y = 0, ang, t;

    FILE *fp;
    fp = fopen ("Dados.txt", "w");

    printf("Defina a velocidade inicial do projetil (m/s): ");
    scanf("%f", &Vo);

    printf("\nDefina o angulo do lancamento (Graus): ");
    scanf("%f", &ang);
    ang = (ang * pi)/180;

    printf("\nDefina o intervalo de tempo para cada medicao (s): ");
    scanf("%f", &t);

    Vox = Vo * cos(ang);
    Voy = Vo * sin(ang);

    printf("\nX\t\tY\n");
    printf("\n%f\t%f\n", Xo, Yo);
    fprintf(fp, "\n%f\t%f\n", Xo, Yo);
    do{
        X = Xo + Vox * t;
        Vfy = Voy - g * pow(e, -Y/10000) * t;
        Voy = Vfy;
        Y = Yo + Voy * t;

        printf("\n%f\t%f\t\n", X, Y);
        fprintf(fp, "\n%f\t%f\t\n", X, Y);

        Xo = X;
        Yo = Y;

    }while(Y >= 0);

    fclose (fp);

    system("pause");
    return 0;
}

