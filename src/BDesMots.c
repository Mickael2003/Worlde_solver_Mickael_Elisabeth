// Fonction pour charger les mots depuis le fichier
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <BDesMots.h>"

int load_wordle_words(const char* chemin, char mots[MAX_WORDS][WORD_LENGTH]) {
    FILE* fichier = fopen(chemin, "r");
    if (!fichier) {
        printf("Erreur : impossible d'ouvrir le fichier %s\n", chemin);
        return -1;
    }

    char ligne[LINE_SIZE];
    int nbMots = 0;

    while (fgets(ligne, LINE_SIZE, fichier) != NULL) {
        if (strlen(ligne) > 1) {  // Si la ligne contient des mots
            char* mot = strtok(ligne, " \t\n");
            while (mot != NULL && nbMots < MAX_WORDS) {
                if (strlen(mot) == 5) {  // Seuls les mots de 5 lettres
                    strcpy(mots[nbMots++], mot);
                }
                mot = strtok(NULL, " \t\n");
            }
        }
    }

    fclose(fichier);
    return nbMots;
}
