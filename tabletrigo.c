#include <stdio.h>
#include <math.h>

// Définition de PI si elle n'existe pas dans math.h
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// --- Prototypes des fonctions ---
double deg_en_rad(int degres);
void ecrire_ligne_angles(FILE *fichier, const char* etiquettes[], int taille);
void ecrire_ligne_trigo(FILE *fichier, const char* nom_fonction, int degres[], int taille, double (*func)(double));
void ecrire_ligne_tangente(FILE *fichier, int degres[], int taille);

int main() {
    // Données du tableau (Valeurs remarquables)
    const char* etiquettes[] = {"0", "pi/6", "pi/4", "pi/3", "pi/2", "2pi/3", "3pi/4", "5pi/6", "pi"};
    int degres[] = {0, 30, 45, 60, 90, 120, 135, 150, 180};
    int nb_valeurs = sizeof(degres) / sizeof(degres[0]);

    // Ouverture du fichier
    FILE *fichier = fopen("valeurs_remarquables.txt", "w");
    if (fichier == NULL) {
        printf("Erreur : Impossible de créer le fichier.\n");
        return 1;
    }

    // Génération du tableau ligne par ligne
    ecrire_ligne_angles(fichier, etiquettes, nb_valeurs);
    ecrire_ligne_trigo(fichier, " sinx", degres, nb_valeurs, sin);
    ecrire_ligne_trigo(fichier, " cosx", degres, nb_valeurs, cos);
    ecrire_ligne_tangente(fichier, degres, nb_valeurs);

    fclose(fichier);
    printf("Succès : Le tableau 'valeurs_remarquables.txt' a été généré.\n");

    return 0;
}

// --- Implémentation des fonctions ---

// Convertit les degrés en radians pour les fonctions de math.h
double deg_en_rad(int degres) {
    return degres * (M_PI / 180.0);
}

// Ecrit la première ligne du tableau (les valeurs de x)
void ecrire_ligne_angles(FILE *fichier, const char* etiquettes[], int taille) {
    fprintf(fichier, "%-6s |", "   x");
    for (int i = 0; i < taille; i++) {
        fprintf(fichier, " %-8s |", etiquettes[i]);
    }
    fprintf(fichier, "\n-------|");
    for (int i = 0; i < taille; i++) fprintf(fichier, "----------|");
    fprintf(fichier, "\n");
}

// Fonction générique pour Sinus et Cosinus
// Note : on passe un pointeur de fonction 'func' en paramètre
void ecrire_ligne_trigo(FILE *fichier, const char* nom_fonction, int degres[], int taille, double (*func)(double)) {
    fprintf(fichier, "%-6s |", nom_fonction);
    for (int i = 0; i < taille; i++) {
        fprintf(fichier, " %-8.4f |", func(deg_en_rad(degres[i])));
    }
    fprintf(fichier, "\n");
}

// Fonction spécifique pour la tangente à cause de la valeur indéfinie à 90°
void ecrire_ligne_tangente(FILE *fichier, int degres[], int taille) {
    fprintf(fichier, "%-6s |", " tanx");
    for (int i = 0; i < taille; i++) {
        if (degres[i] == 90) {
            fprintf(fichier, " %-8s |", "Indéf.");
        } else {
            fprintf(fichier, " %-8.4f |", tan(deg_en_rad(degres[i])));
        }
    }
    fprintf(fichier, "\n");
}
