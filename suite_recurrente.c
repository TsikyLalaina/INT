#include <stdio.h>

int main(void) {
    // Utilisation de long long pour éviter le débordement (64 bits)
    double prev1 = 1;  // U0
    double prev2 = -4; // U1
    double current;
    double somme = prev1 + prev2; // On commence avec U0 + U1

    // On commence le calcul à partir de i = 2
    for(int i = 2; i <= 70; i++) {
        current = 2 * prev1 + 3 * prev2;
        printf("U%d: %e\n", i, current);
        
        // Calcul de la somme pour les 30 premiers (U0 à U29)
        if(i < 30) {
            somme += current;
        }

        // Mise à jour pour le prochain tour
        prev1 = prev2;
        prev2 = current;
    }

    printf("La valeur de U70 est : %e\n", current);
    printf("La somme des 30 premiers (U0 a U29) est : %.0f\n", somme);

    return 0;
}
