#include <stdio.h>

int main(){
  int i,j,contador;
  for (i = 10; i < 1000000000; i++){
    contador = 0;
    for (j = 11; j < 21; j++){
    if (i % j == 0)
      contador++;
    }
    if (contador == 10){
      printf("\nO menor numero e: %d\n\n",i);
      break;
    }
  }
  system("pause");
  return 0;
}
