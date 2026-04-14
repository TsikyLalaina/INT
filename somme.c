#include <stdio.h>
#include <stdlib.h>

void entree(int* entier1, int* entier2);
int somme(int entier1, int entier2);
void resultat(int entier);

int main(void){
  int entier1;
  int entier2;
  int entier;
    
  entree(&entier1, &entier2);
  
  entier = somme(entier1, entier2);
  
  resultat(entier);
  return 0;
}

void entree(int* entier1, int* entier2){
  printf("Entrez entier1:\n");
  printf("x1 = ");
  scanf("%d", entier1);
  
  printf("Entrez entier2:\n");
  printf("x2 = ");
  scanf("%d", entier2);
}

int somme(int entier1, int entier2){
  int resultat;
  resultat = entier1 + entier2;
  return resultat;
}

void resultat(int entier){
  printf("la somme des deux entiers est %d \n", entier);
}
