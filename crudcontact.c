#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FICHIER_CONTACTS "annuaire.csv"
#define TAILLE_MAX 100

typedef struct {
    char prenom[TAILLE_MAX];
    char nom[TAILLE_MAX];
    char telephone[TAILLE_MAX];
    char genre[20];
} Contact;

// --- Prototypes ---
void ajouter_contact();
void afficher_contacts();
void rechercher_contact(const char *nom_cible);
void mettre_a_jour_contact(const char *nom_cible);
void supprimer_contact(const char *nom_cible);
void nettoyer_newline(char *chaine);

int main() {
    int choix;
    char nom_recherche[TAILLE_MAX];

    do {
        printf("\n--- GESTIONNAIRE DE CONTACTS ---\n");
        printf("1. Ajouter\n2. Afficher\n3. Rechercher\n4. Modifier\n5. Supprimer\n6. Quitter\n");
        printf("Votre choix : ");
        if (scanf("%d", &choix) != 1) break;
        getchar(); 

        switch (choix) {
            case 1: ajouter_contact(); break;
            case 2: afficher_contacts(); break;
            case 3:
                printf("Nom : "); fgets(nom_recherche, sizeof(nom_recherche), stdin);
                nettoyer_newline(nom_recherche);
                rechercher_contact(nom_recherche);
                break;
            case 4:
                printf("Nom à modifier : "); fgets(nom_recherche, sizeof(nom_recherche), stdin);
                nettoyer_newline(nom_recherche);
                mettre_a_jour_contact(nom_recherche);
                break;
            case 5:
                printf("Nom à supprimer : "); fgets(nom_recherche, sizeof(nom_recherche), stdin);
                nettoyer_newline(nom_recherche);
                supprimer_contact(nom_recherche);
                break;
        }
    } while (choix != 6);

    return 0;
}

void nettoyer_newline(char *chaine) {
    chaine[strcspn(chaine, "\n")] = 0;
}

void ajouter_contact() {
    FILE *f = fopen(FICHIER_CONTACTS, "a");
    if (!f) return;

    Contact c;
    printf("Prénom : "); fgets(c.prenom, sizeof(c.prenom), stdin); nettoyer_newline(c.prenom);
    printf("Nom : ");    fgets(c.nom, sizeof(c.nom), stdin);       nettoyer_newline(c.nom);
    printf("Tel : ");    fgets(c.telephone, sizeof(c.telephone), stdin); nettoyer_newline(c.telephone);
    printf("Genre : ");  fgets(c.genre, sizeof(c.genre), stdin);   nettoyer_newline(c.genre);

    fprintf(f, "%s,%s,%s,%s\n", c.prenom, c.nom, c.telephone, c.genre);
    fclose(f);
    printf("Contact ajouté.\n");
}

void afficher_contacts() {
    FILE *f = fopen(FICHIER_CONTACTS, "r");
    if (!f) return;
    char ligne[400];
    while (fgets(ligne, sizeof(ligne), f)) {
        char *p = strtok(ligne, ",");
        char *n = strtok(NULL, ",");
        char *t = strtok(NULL, ",");
        char *g = strtok(NULL, ",");
        if (g) nettoyer_newline(g);
        printf("%s %s | %s | %s\n", p, n, t, g);
    }
    fclose(f);
}

void rechercher_contact(const char *nom_cible) {
    FILE *f = fopen(FICHIER_CONTACTS, "r");
    if (!f) return;
    char ligne[400];
    while (fgets(ligne, sizeof(ligne), f)) {
        char copie[400]; strcpy(copie, ligne);
        strtok(ligne, ",");
        char *n = strtok(NULL, ",");
        if (n && strcmp(n, nom_cible) == 0) printf("Trouvé : %s", copie);
    }
    fclose(f);
}

void mettre_a_jour_contact(const char *nom_cible) {
    FILE *f = fopen(FICHIER_CONTACTS, "r");
    FILE *temp = fopen("temp.csv", "w");
    if (!f || !temp) return;

    char ligne[400];
    int trouve = 0;
    while (fgets(ligne, sizeof(ligne), f)) {
        char copie[400]; strcpy(copie, ligne);
        char *p_t = strtok(ligne, ",");
        char *n_t = strtok(NULL, ",");

        if (n_t && strcmp(n_t, nom_cible) == 0) {
            trouve = 1;
            Contact c;
            printf("Nouveau Prénom : "); fgets(c.prenom, sizeof(c.prenom), stdin); nettoyer_newline(c.prenom);
            printf("Nouveau Nom : ");    fgets(c.nom, sizeof(c.nom), stdin);       nettoyer_newline(c.nom);
            printf("Nouveau Tel : ");    fgets(c.telephone, sizeof(c.telephone), stdin); nettoyer_newline(c.telephone);
            // CORRECTION ICI : sizeof(c.genre)
            printf("Nouveau Genre : ");  fgets(c.genre, sizeof(c.genre), stdin);   nettoyer_newline(c.genre);
            fprintf(temp, "%s,%s,%s,%s\n", c.prenom, c.nom, c.telephone, c.genre);
        } else {
            fprintf(temp, "%s", copie);
        }
    }
    fclose(f); fclose(temp);
    remove(FICHIER_CONTACTS); rename("temp.csv", FICHIER_CONTACTS);
}

void supprimer_contact(const char *nom_cible) {
    FILE *f = fopen(FICHIER_CONTACTS, "r");
    FILE *temp = fopen("temp.csv", "w");
    if (!f || !temp) return;
    char ligne[400];
    while (fgets(ligne, sizeof(ligne), f)) {
        char copie[400]; strcpy(copie, ligne);
        strtok(ligne, ",");
        char *n = strtok(NULL, ",");
        if (!(n && strcmp(n, nom_cible) == 0)) fprintf(temp, "%s", copie);
    }
    fclose(f); fclose(temp);
    remove(FICHIER_CONTACTS); rename("temp.csv", FICHIER_CONTACTS);
}
