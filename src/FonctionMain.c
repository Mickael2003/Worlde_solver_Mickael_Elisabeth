#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <"BDesmots.h"> // Assurez-vous que ce fichier existe et est correct

int main() {
    char mots[MAX_WORDS][WORD_LENGTH];
    char motsFiltres[MAX_WORDS][WORD_LENGTH];
    const char* fichier_chemin = "ressource/bdd_wordle.txt";

    int totalMotsCharges = load_wordle_words(fichier_chemin, mots);

    if (totalMotsCharges <= 0) {
        printf("Erreur : Aucun mot n'a été chargé depuis '%s'.\n", fichier_chemin);
        return 1; // Indiquer une erreur
    }

    printf("%d mots chargés avec succès depuis '%s'.\n\n", totalMotsCharges, fichier_chemin);

    // Exemple d'utilisation des filtres

    // Filtrer par une lettre
    char lettre = 'E';
    int nbMotsFiltresLettre = filtrer_par_lettre(mots, totalMotsCharges, lettre, motsFiltres);
    printf("Mots contenant la lettre '%c' (%d):\n", lettre, nbMotsFiltresLettre);
    afficher_mots(motsFiltres, nbMotsFiltresLettre);
    printf("\n");

    // Filtrer par plusieurs lettres (toutes présentes)
    const char* lettresContenues = "AI";
    int nbMotsFiltresLettres = filtrer_par_lettres(mots, totalMotsCharges, lettresContenues, motsFiltres);
    printf("Mots contenant toutes les lettres '%s' (%d):\n", lettresContenues, nbMotsFiltresLettres);
    afficher_mots(motsFiltres, nbMotsFiltresLettres);
    printf("\n");

    // Exclure les mots contenant certaines lettres
    const char* lettresExclues = "XYZ";
    int nbMotsExclus = exclure_par_lettres(mots, totalMotsCharges, lettresExclues, motsFiltres);
    printf("Mots ne contenant aucune des lettres '%s' (%d):\n", lettresExclues, nbMotsExclus);
    afficher_mots(motsFiltres, nbMotsExclus);
    printf("\n");

    // Filtrer par un sous-mot
    const char* sousMotRecherche = "OU";
    int nbMotsSousMot = filtrer_par_sous_mot(mots, totalMotsCharges, sousMotRecherche, motsFiltres);
    printf("Mots contenant le sous-mot '%s' (%d):\n", sousMotRecherche, nbMotsSousMot);
    afficher_mots(motsFiltres, nbMotsSousMot);
    printf("\n");

    return 0; // Indiquer un succès
}

// Fonction pour filtrer les mots par la présence d'une lettre
int filtrer_par_lettre(char mots[][WORD_LENGTH], int totalMots, char lettre, char motsFiltres[][WORD_LENGTH]) {
    int nbMotsFiltres = 0;
    for (int i = 0; i < totalMots; i++) {
        if (strchr(mots[i], lettre) != NULL) {
            strcpy(motsFiltres[nbMotsFiltres++], mots[i]);
        }
    }
    return nbMotsFiltres;
}

// Fonction pour afficher un tableau de mots
void afficher_mots(char mots[][WORD_LENGTH], int nbMots) {
    for (int i = 0; i < nbMots; i++) {
        printf("%s\n", mots[i]);
    }
}

// Fonction pour filtrer les mots contenant toutes les lettres spécifiées
int filtrer_par_lettres(char mots[][WORD_LENGTH], int totalMots, const char* lettres, char motsFiltres[][WORD_LENGTH]) {
    int nbMotsFiltres = 0;
    for (int i = 0; i < totalMots; i++) {
        int toutesPresentes = 1;
        for (int j = 0; lettres[j] != '\0'; j++) {
            if (strchr(mots[i], lettres[j]) == NULL) {
                toutesPresentes = 0;
                break;
            }
        }
        if (toutesPresentes) {
            strcpy(motsFiltres[nbMotsFiltres++], mots[i]);
        }
    }
    return nbMotsFiltres;
}

// Fonction pour exclure les mots contenant l'une des lettres spécifiées
int exclure_par_lettres(char mots[][WORD_LENGTH], int totalMots, const char* exclure, char motsFiltres[][WORD_LENGTH]) {
    int nbMotsFiltres = 0;
    for (int i = 0; i < totalMots; i++) {
        int contientLettreExclue = 0;
        for (int j = 0; exclure[j] != '\0'; j++) {
            if (strchr(mots[i], exclure[j]) != NULL) {
                contientLettreExclue = 1;
                break;
            }
        }
        if (!contientLettreExclue) {
            strcpy(motsFiltres[nbMotsFiltres++], mots[i]);
        }
    }
    return nbMotsFiltres;
}

// Fonction pour filtrer les mots par la présence d'un sous-mot spécifique
int filtrer_par_sous_mot(char mots[][WORD_LENGTH], int totalMots, const char* sousMot, char motsFiltres[][WORD_LENGTH]) {
    int nbMotsFiltres = 0;
    int lenSousMot = strlen(sousMot);
    if (lenSousMot > 0 && lenSousMot <= WORD_LENGTH) {
        for (int i = 0; i < totalMots; i++) {
            if (strstr(mots[i], sousMot) != NULL) {
                strcpy(motsFiltres[nbMotsFiltres++], mots[i]);
            }
        }
    }
    return nbMotsFiltres;
}
