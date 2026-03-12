#include <stdio.h>

int main(void){
  int somme[2][2];
  int m1[2][2];
  int m2[2][2];
  int temp = 0;
  
  printf("Veuillez entrez les element de M1: \n");
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      printf("Veuillez entrez la ligne %d colonne %d: ", i, j);
      scanf("%d", &m1[i][j]);
    }
  }
  printf("Veuillez entrez les element de M2: \n");
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      printf("Veuillez entrez la ligne %d colonne %d: ", i, j);
      scanf("%d", &m2[i][j]);
    }
  }
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      for(int k = 0; k < 2; k++){
        temp += m1[i][k] * m2[k][j];
      }
      somme[i][j] = temp;
      temp = 0;
    }
  }
  printf("Le produit des deux matrices M1 et M2 est: \n");
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      printf("ligne %d colonne %d: %d\n", i, j, somme[i][j]);
    }
  }
  
  return 0;
}
