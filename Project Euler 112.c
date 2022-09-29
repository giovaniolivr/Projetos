#include <stdio.h>

int main(){

int decres(int n){
  int ultimo = n % 10;
  n /= 10;

  while (n != 0){
    if (ultimo > n % 10)
    return 0;
    ultimo = n % 10;
    n /= 10;
  }
  return 1;
}

int aument(int n){
  int ultimo = n % 10;
  n /= 10;

  while (n != 0){
    if (ultimo < n % 10)
    return 0;
    ultimo = n % 10;
    n /= 10;
  }
  return 1;
}

int bouncy(int n){
  return !aument(n) && !decres(n);
}

  int nbouncy = 0;
  int nb = 0;
  int n = 0;

  do{
    if (bouncy(++n))
    nbouncy++;
    nb++;
  }

  while (nbouncy * 100 != nb * 99);
  printf("\nO menor numero a atingir essa proporcao e: %i\n\n", n);

  system("pause");
  return 0;
}
