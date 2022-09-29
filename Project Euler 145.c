#include <stdio.h>

int main(){

    int reversivel(int n) {
      int numantigo = n;
      int numreverso = 0;
      int sum;

      if (n%10==0)
      return 0;

      while (n != 0) {
        numreverso *= 10;
        numreverso += n % 10;
        n /= 10;
      }
      sum = numantigo + numreverso;

      while (sum != 0) {
        if ((sum % 10) % 2 == 0)
        return 0;
        sum /= 10;
      }
      return 1;
    }
      int i;
      int nb = 0;
      for (i=1; i<1000000000; i++)
        if (reversivel(i)) nb++;
      printf("\nExistem %d numeros reversiveis abaixo de um bilhao\n\n", nb);
      system("pause");
      return 0;
}
