#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// --- Prototypes ---
double conversion_rad(int deg);
void csv_ligne_entete(FILE *f, const char* etiquettes[], int taille);
void csv_ligne_trigo(FILE *f, const char* nom, int degres[], int taille, double (*func)(double));
void csv_ligne_tangente(FILE *f, int degres[], int taille);

int main() {
    // Configuration des données
    const char* labels[] = {"0", "pi/6", "pi/4", "pi/3", "pi/2", "2pi/3", "3pi/4", "5pi/6", "pi"};
    int angles[] = {0, 30, 45, 60, 90, 120, 135, 150, 180};
    int n = sizeof(angles) / sizeof(angles[0]);

    // Tentative d'ouverture du fichier
    FILE *fichier = fopen("tableau_trigo.csv", "w");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier CSV.\n");
        return 1;
    }

    // Construction du CSV par appels de fonctions
    csv_ligne_entete(fichier, labels, n);
    csv_ligne_trigo(fichier, "sin(x)", angles, n, sin);
    csv_ligne_trigo(fichier, "cos(x)", angles, n, cos);
    csv_ligne_tangente(fichier, angles, n);

    fclose(fichier);
    printf("Le fichier 'tableau_trigo.csv' a été généré avec succès.\n");

    return 0;
}

// --- Fonctions ---

// Transforme les degrés en radians
double conversion_rad(int deg) {
    return deg * (M_PI / 180.0);
}

// Génère la ligne des x (ex: x,0,pi/6,...)
void csv_ligne_entete(FILE *f, const char* etiquettes[], int taille) {
    fprintf(f, "x");
    for (int i = 0; i < taille; i++) {
        fprintf(f, ",%s", etiquettes[i]);
    }
    fprintf(f, "\n");
}

// Génère une ligne de calcul (Sinus ou Cosinus)
void csv_ligne_trigo(FILE *f, const char* nom, int degres[], int taille, double (*func)(double)) {
    fprintf(f, "%s", nom);
    for (int i = 0; i < taille; i++) {
        fprintf(f, ",%.4f", func(conversion_rad(degres[i])));
    }
    fprintf(f, "\n");
}

// Génère la ligne tangente avec gestion de l'indéfini
void csv_ligne_tangente(FILE *f, int degres[], int taille) {
    fprintf(f, "tan(x)");
    for (int i = 0; i < taille; i++) {
        if (degres[i] == 90) {
            fprintf(f, ",Indefini");
        } else {
            fprintf(f, ",%.4f", tan(conversion_rad(degres[i])));
        }
    }
    fprintf(f, "\n");
}
