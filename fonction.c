#include <stdio.h>
#include <stdlib.h>

double scalaire(int taille, double* v1, double* v2);
double* somme(int taille, double* v1, double* v2);
void entree(int taille, double* v1, double* v2);
void entree_taille(int* taille);
void resultat(int taille, double produit, double* sum);

int main(void){
  int taille;
  double* temp;
  double produit;
  double* v1;
  double* v2;
  
  entree_taille(&taille);
  
  if(taille == 0){
    printf("La taille des vecteurs ne peut pas etre 0\n");
    return 0;
  }
  
  v1 = malloc(taille * sizeof(double));
  v2 = malloc(taille * sizeof(double));
  
  if(v1 == NULL || v2 == NULL){
    printf("Erreur: L allocation de memoir pour les vecteur ont echoue\n");
    return 0;
  }
  
  entree(taille, v1, v2);
  
  temp = somme(taille, v1, v2);
  produit = scalaire(taille, v1, v2);
  
  resultat(taille, produit, temp);

  free(temp);
  free(v1);
  free(v2);
  return 0;
}

double scalaire(int taille, double* v1, double* v2){
  double result;
  result = 0;
  for(int i = 0; i < taille; i++){
    result += v1[i] * v2[i];
  }
  return result;
}

double* somme(int taille, double* v1, double* v2){
  double* result = malloc(taille * sizeof(double));
  if(result == NULL) return NULL;
  for(int i = 0; i < taille; i++){
    result[i] = v1[i] + v2[i];
  }
  return result;
}
void entree_taille(int* taille){
  printf("Entrez la taille des vecteurs: ");
  scanf("%d", taille);
}
void entree(int taille, double* v1, double* v2){
  printf("Entrez les element du vecteur V1:\n");
  for(int i = 0; i < taille; i++){
    printf("x%d = ", i);
    scanf("%lf", &v1[i]);
  }
  
  printf("Entrez les element du vecteur V2:\n");
  for(int i = 0; i < taille; i++){
    printf("x%d = ", i);
    scanf("%lf", &v2[i]);
  }
}

void resultat(int taille, double produit, double* sum){
  printf("Le scalaire des deux vecteur est %.0lf\n", produit);
  
  printf("la somme des deux vecteurs est (");
  
  for(int i = 0; i < taille-1; i++){
    printf("%.0lf, ", sum[i]);
  }
  printf("%.0lf)\n", sum[taille-1]);
}
