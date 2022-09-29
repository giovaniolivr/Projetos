#include <stdio.h>

int main(){

    int max = 100;
    long long ent[10][max + 2];
    long long seg[10][max + 2];
    long long aum(int prim, int comp){
    int i;
    long long res = 0;

      if (comp == 1)
      return 1;

      if (ent[prim][comp] != -1)
      return ent[prim][comp];

      for (i = prim; i <= 9; i++) {
        res += aum(i, comp-1);
      }
      ent[prim][comp] = res;
      return res;
    }
      long long dec(int prim, int comp){
      int i;
      long long res = 0;

      if (comp == 1)
      return 1;

      if (seg[prim][comp] != -1)
      return seg[prim][comp];

      for (i = 0; i <= prim; i++) {
        res += dec(i, comp-1);
      }
      seg[prim][comp]=res;
      return res;
    }
      long long res ;
      long long res2 = 0;
      int i, j;

      for (i=0; i<10; i++)
        for (j=0; j <= max+1; j++) {
          ent[i][j]=-1;
          seg[i][j]=-1;
        }
      res = aum(0, max + 1);
      for (i = 1; i <= max + 1; i++) res2 += (dec(9, i) -1);

      printf("\nExistem %lli numeros\n\n", res + res2 - max * 9 - 1);
      system("pause");
      return 0;
}
