#include <stdio.h>
#include <string.h>

// --- MODULE 1 : TRADUCTION DES DONNÉES ---

/**
 * Traduit uniquement le nom du mois.
 */
const char* traduire_mois(const char *mois_fr) {
    if (strcasecmp(mois_fr, "janvier") == 0)   return "janoary";
    if (strcasecmp(mois_fr, "février") == 0)   return "febroary";
    if (strcasecmp(mois_fr, "mars") == 0)      return "martsa";
    if (strcasecmp(mois_fr, "avril") == 0)     return "aprily";
    if (strcasecmp(mois_fr, "mai") == 0)       return "mey";
    if (strcasecmp(mois_fr, "juin") == 0)      return "jona";
    if (strcasecmp(mois_fr, "juillet") == 0)   return "jolay";
    if (strcasecmp(mois_fr, "août") == 0)      return "aogositra";
    if (strcasecmp(mois_fr, "septembre") == 0) return "septambra";
    if (strcasecmp(mois_fr, "octobre") == 0)   return "oktobra";
    if (strcasecmp(mois_fr, "novembre") == 0)  return "novambra";
    if (strcasecmp(mois_fr, "décembre") == 0)  return "desambra";
    return mois_fr; 
}

// --- MODULE 2 : TRAITEMENT DE LA CHAÎNE ---

/**
 * Gère le découpage (strtok) et la reconstruction (strcat).
 */
void transformer_date(char *date_source, char *resultat) {
    char *jour, *mois_fr, *annee;

    jour = strtok(date_source, " ");
    mois_fr = strtok(NULL, " ");
    annee = strtok(NULL, " ");

    if (jour && mois_fr && annee) {
        const char *mois_mg = traduire_mois(mois_fr);
        
        strcpy(resultat, jour);
        strcat(resultat, " ");
        strcat(resultat, mois_mg);
        strcat(resultat, " ");
        strcat(resultat, annee);
    } else {
        strcpy(resultat, "[Erreur : Format de date invalide]");
    }
}

// --- MODULE 3 : GESTION DE L'ENTRÉE (USER INPUT) ---

/**
 * Récupère proprement la saisie et nettoie le '\n' de fin.
 */
void recuperer_saisie(char *buffer, int taille) {
    printf("Veuillez entrer une date (ex: 26 juin 1960) : ");
    if (fgets(buffer, taille, stdin)) {
        // Remplace le saut de ligne par un fin de chaîne
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

// --- MODULE 4 : POINT D'ENTRÉE PRINCIPAL ---

int main() {
    char date_utilisateur[100];
    char date_traduite[100] = "";

    // Utilisation des fonctions modulaires
    recuperer_saisie(date_utilisateur, sizeof(date_utilisateur));
    
    transformer_date(date_utilisateur, date_traduite);

    printf("\n--- Résultat de la traduction ---\n");
    printf("Français : (Saisie utilisateur)\n");
    printf("Malagasy : %s\n", date_traduite);

    return 0;
}
