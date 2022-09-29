#include <stdio.h>

int main(){
    int r = 0;
    int a = 3;
    for(a; a<= 1000; a++){
        r += 2 * a * ((a - 1) / 2);
    }
    printf("\nA soma maxima e de: %d\n\n", r);
    system("pause");
    return 0;
}
