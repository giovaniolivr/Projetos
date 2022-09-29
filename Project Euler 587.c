#include <math.h>
#include <stdio.h>

int main() {

double areatriangconc(int n);

    double seccaoarea = 1 - 3.14159 / 4;
    int n = 2;
    while(1){
        if (areatriangconc(n) / seccaoarea < 0.001) {
            printf("\nO menor valor seria de: %d\n", n);
            break;
        }
        n++;
    }
}
double areatriangconc(int n) {
    double h = (n + 1 - sqrt(2 * n)) / (n * n + 1);
    double angulorad = acos((1 - h) / 1);
    double areacirc = angulorad / 2;
    double areasup = (sqrt(1 - (1 - h) * (1 - h))) * (1 - 1.0 / n) / 2;
    double areatriang = 1.0 * (1.0 / n) / 2;
    return areatriang + areasup - areacirc;
}
