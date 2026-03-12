#include <stdio.h>

int main(void){
  double v1[2];
  double v2[2];
  double somme[2];
  double produit;
  
  printf("Entrez les element du vecteur V1:\n");
  printf("x1 = ");
  scanf("%lf", &v1[0]);
  printf("y1 = ");
  scanf("%lf", &v1[1]);
  
  printf("Entrez les element du vecteur V2:\n");
  printf("x2 = ");
  scanf("%lf", &v2[0]);
  printf("y2 = ");
  scanf("%lf", &v2[1]);
  
  somme[0] = v1[0] + v2[0];
  somme[1] = v1[1] + v2[1];
  
  produit = v1[0] * v2[0] + v1[1] * v2[1];
  
  printf("La somme de V1 et V2 est (%lf, %lf)\nLe produit scalaire de V1 et V2 est %lf\n", somme[0], somme[1], produit);
}
