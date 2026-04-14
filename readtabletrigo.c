#include <stdio.h>
#include <string.h>

// --- Prototypes ---
void afficher_ligne_csv(char *ligne);
void traiter_fichier_csv(const char *nom_fichier);

int main() {
    printf("--- Affichage du Tableau Trigonométrique (depuis le CSV) ---\n\n");

    // On délègue tout le travail à une fonction dédiée
    traiter_fichier_csv("tableau_trigo.csv");

    return 0;
}

// --- Implémentation des fonctions ---

/**
 * Lit le fichier ligne par ligne et gère les erreurs d'ouverture.
 */
void traiter_fichier_csv(const char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "r");
    char tampon[1024];

    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier '%s'.\n", nom_fichier);
        printf("Assurez-vous d'avoir généré le fichier CSV auparavant.\n");
        return;
    }

    // Boucle de lecture : tant qu'il y a une ligne à lire
    while (fgets(tampon, sizeof(tampon), fichier)) {
        afficher_ligne_csv(tampon);
    }

    fclose(fichier);
}

/**
 * Découpe une ligne CSV en "jetons" (tokens) et les affiche proprement.
 */
void afficher_ligne_csv(char *ligne) {
    // Nettoyage : on enlève le caractère de saut de ligne '\n' à la fin
    ligne[strcspn(ligne, "\n")] = 0;

    // Premier jeton (avant la première virgule)
    char *jeton = strtok(ligne, ",");

    while (jeton != NULL) {
        // Affichage aligné à gauche sur 12 caractères
        printf("%-12s", jeton);

        // Jeton suivant (NULL indique à strtok de continuer sur la même ligne)
        jeton = strtok(NULL, ",");
    }
    
    // Une fois la ligne finie, on passe à la ligne suivante dans la console
    printf("\n");
}
