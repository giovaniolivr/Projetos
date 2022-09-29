#include <stdio.h>
#include <math.h>

int main(){

    int answer1;

    printf("Do you want to calculate both functions? (1 = yes, 0 = no) ");
    scanf("%d", &answer1);

    if(answer1 == 1){

        #define n(x) 1/x
        #define m(x) sqrt(1 - pow(x, 2))

        float x, n, m;

        printf("\nChoose a value of x to calculate both functions: ");
        scanf("%f", &x);

        n = n(x);
        m = m(x);

        printf("\nThe value of the function n(x) is: %f", n);
        printf("\nThe value of the function m(x) is: %f\n\n", m);

    }else{
        printf("\n");
    }
    int answer2;

    printf("Choose which function do you want to calculate the integral (1 = n(x), 2 = m(x)): ");
    scanf("%d", &answer2);

    if(answer2 == 1){

        #define  f(x) 1/x

        double inf, sup, h, integ, i;
        int div;

        printf("\nChoose the number of divisions: ");
        scanf("%d", &div);
        printf("\nChoose the lower limit of the integral: ");
        scanf("%lf", &inf);
        printf("\nChoose the upper limit of the integral: ");
        scanf("%lf", &sup);

        h = (sup - inf)/div;
        integ = integ + f(inf) + f(sup);

        for(i = inf + h; i < sup;){
            integ = integ + (2 * f(i));
            i = i + h;
        }
        integ = integ * (h / 2);

        printf("\nO valor aproximado da integral e de: %lf\n\n", integ);
        }else{

            #define f(x) sqrt((1 - pow(x, 2)))

            double inf, sup, h, integ, i;
            int div;

            printf("\nChoose the number of divisions: ");
            scanf("%d", &div);
            printf("\nChoose the lower limit of the integral: ");
            scanf("%lf", &inf);
            printf("\nChoose the upper limit of the integral: ");
            scanf("%lf", &sup);

            h = (sup - inf)/div;
            integ = integ + f(inf) + f(sup);

            for(i = inf + h; i < sup;){
                integ = integ + (2 * f(i));
                i = i + h;
            }
            integ = integ * (h / 2);

            printf("\nThe approximate value of the integral is: %lf\n\n", integ);
        }
    system("pause");
    return 0;
}
