#include <stdio.h>
int main(void){
    int prev1, prev2, current, somme;
    prev1 = 1;
    prev2 = -4;
    current = 2 * prev1 + 3 * prev2;
    somme = prev1 + prev2 + current;
    for(int i = 3; i <= 70; i++){
      prev1 = prev2;
      prev2 = prev1;
      current = 2 * prev1 + 3 * prev2;
      if(i <= 30){
        somme += current;
      }
    }
    printf("La valeur de la 70eme element est %d\nLa somme des 30 premier element est %d\n", current, somme);
    return 0;
}


