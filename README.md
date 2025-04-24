# Bibliothèque de fonctions pour Wordle (BDesMots)

Cette bibliothèque en C fournit des fonctions pour charger, filtrer et manipuler une liste de mots de 5 lettres, utiles pour implémenter le jeu Wordle ou des applications similaires.

## Fonctions incluses

### `load_wordle_words(const char* chemin, char mots[MAX_WORDS][WORD_LENGTH])`

Charge les mots de 5 lettres depuis un fichier texte. Chaque ligne du fichier peut contenir un ou plusieurs mots séparés par des espaces, des tabulations ou des sauts de ligne. Seuls les mots de 5 lettres sont stockés dans le tableau `mots`.

**Paramètres :**

* `chemin`: Le chemin d'accès au fichier contenant la liste de mots.
* `mots`: Un tableau de chaînes de caractères où les mots chargés seront stockés. `MAX_WORDS` et `WORD_LENGTH` sont des constantes définies dans `BDesMots.h`.

**Valeur de retour :**

* Le nombre de mots de 5 lettres chargés avec succès.
* `-1` en cas d'erreur lors de l'ouverture du fichier.

### `filtrer_par_lettres_presentes(char mots[][WORD_LENGTH], int totalMots, const char* lettres, char motsFiltres[][WORD_LENGTH])`

Filtre un tableau de mots pour ne conserver que ceux qui contiennent toutes les lettres spécifiées. L'ordre des lettres dans le mot n'a pas d'importance.

**Paramètres :**

* `mots`: Le tableau de mots à filtrer.
* `totalMots`: Le nombre total de mots dans le tableau `mots`.
* `lettres`: Une chaîne de caractères contenant les lettres qui doivent être présentes dans les mots filtrés.
* `motsFiltres`: Un tableau de chaînes de caractères où les mots correspondants aux critères seront stockés.

**Valeur de retour :**

* Le nombre de mots filtrés qui contiennent toutes les lettres spécifiées.

### `exclure_par_lettres(char mots[][WORD_LENGTH], int totalMots, const char* exclure, char motsFiltres[][WORD_LENGTH])`

Filtre un tableau de mots pour exclure ceux qui contiennent au moins une des lettres spécifiées.

**Paramètres :**

* `mots`: Le tableau de mots à filtrer.
* `totalMots`: Le nombre total de mots dans le tableau `mots`.
* `exclure`: Une chaîne de caractères contenant les lettres dont la présence dans un mot entraînera son exclusion.
* `motsFiltres`: Un tableau de chaînes de caractères où les mots ne contenant aucune des lettres exclues seront stockés.

**Valeur de retour :**

* Le nombre de mots filtrés qui ne contiennent aucune des lettres spécifiées.

### `filtrer_par_sous_mot(char mots[][WORD_LENGTH], int totalMots, const char* sousMot, char motsFiltres[][WORD_LENGTH])`

Filtre un tableau de mots pour ne conserver que ceux qui contiennent le sous-mot spécifié.

**Paramètres :**

* `mots`: Le tableau de mots à filtrer.
* `totalMots`: Le nombre total de mots dans le tableau `mots`.
* `sousMot`: La chaîne de caractères représentant le sous-mot à rechercher.
* `motsFiltres`: Un tableau de chaînes de caractères où les mots contenant le sous-mot seront stockés.

**Valeur de retour :**

* Le nombre de mots filtrés qui contiennent le sous-mot spécifié.

## Utilisation

Pour utiliser ces fonctions, vous devez :

1.  Inclure le fichier d'en-tête `BDesMots.h` dans votre code source C. Ce fichier doit contenir les définitions des constantes `MAX_WORDS` et `WORD_LENGTH`.
2.  Compiler votre code source avec ces fonctions.
3.  Appeler les fonctions appropriées en passant les arguments nécessaires.

## Exemple d'utilisation

```c
#include <stdio.h>
#include <string.h>
#include "BDesMots.h"

int main() {
    char tousLesMots[MAX_WORDS][WORD_LENGTH];
    char motsFiltres1[MAX_WORDS][WORD_LENGTH];
    char motsFiltres2[MAX_WORDS][WORD_LENGTH];
    char motsFiltres3[MAX_WORDS][WORD_LENGTH];

    int nombreTotalMots = load_wordle_words("liste_mots.txt", tousLesMots);

    if (nombreTotalMots > 0) {
        printf("Nombre total de mots chargés : %d\n", nombreTotalMots);

        int nombreMotsAvecAE = filtrer_par_lettres_presentes(tousLesMots, nombreTotalMots, "ae", motsFiltres1);
        printf("Nombre de mots contenant 'a' et 'e' : %d\n", nombreMotsAvecAE);
        for (int i = 0; i < nombreMotsAvecAE && i < 10; i++) {
            printf("%s ", motsFiltres1[i]);
        }
        printf("...\n");

        int nombreMotsSansXYZ = exclure_par_lettres(tousLesMots, nombreTotalMots, "xyz", motsFiltres2);
        printf("Nombre de mots ne contenant pas 'x', 'y' ou 'z' : %d\n", nombreMotsSansXYZ);
        // ... (Affichage possible de ces mots)

        int nombreMotsAvecOUS = filtrer_par_sous_mot(tousLesMots, nombreTotalMots, "ous", motsFiltres3);
        printf("Nombre de mots contenant le sous-mot 'ous' : %d\n", nombreMotsAvecOUS);
        for (int i = 0; i < nombreMotsAvecOUS && i < 10; i++) {
            printf("%s ", motsFiltres3[i]);
        }
        printf("...\n");

    } else {
        printf("Aucun mot chargé.\n");
    }

    return 0;
}
