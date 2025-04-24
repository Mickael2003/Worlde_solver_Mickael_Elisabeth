# Jeu de Wordle avec Filtres

Ce projet implémente une version du jeu Wordle en C, offrant des fonctionnalités de filtrage de la liste des mots pour aider à trouver la solution.

## Fonctionnalités

Le programme permet de :

* **Charger une liste de mots de 5 lettres** depuis un fichier texte (`bdd_wordle.txt`).
* **Filtrer la liste des mots** en fonction de différents critères :
    * **Présence d'une ou plusieurs lettres spécifiques.**
    * **Absence d'une ou plusieurs lettres spécifiques.**
    * **Présence d'un sous-mot spécifique.**

L'objectif est d'utiliser ces filtres de manière interactive pour réduire progressivement la liste des mots possibles et découvrir le mot Wordle caché.

## Fichiers inclus

* `BDesMots.h`: Fichier d'en-tête contenant les définitions des constantes (comme `MAX_WORDS`, `WORD_LENGTH`, `LINE_SIZE`) et les déclarations des fonctions.
* `fonctions_wordle.c`: Fichier source contenant l'implémentation des fonctions de chargement et de filtrage des mots.
* `bdd_wordle.txt`: Fichier texte contenant la liste des mots de 5 lettres (un mot par ligne ou plusieurs mots séparés par des espaces, des tabulations ou des sauts de ligne).
* `main.c`: Fichier source contenant la fonction `main` qui gère l'interaction avec l'utilisateur et l'application des filtres.
* `README.md`: Ce fichier, fournissant des informations sur le projet.

## Utilisation

1.  **Compilation :** Compilez les fichiers sources `main.c` et `fonctions_wordle.c` en utilisant un compilateur C (par exemple, GCC) et liez-les pour créer un exécutable. Assurez-vous que le fichier `BDesMots.h` est dans le même répertoire ou dans un chemin d'inclusion connu.

    ```bash
    gcc main.c fonctions_wordle.c -o wordle
    ```

2.  **Exécution :** Exécutez le programme.

    ```bash
    ./wordle
    ```

3.  **Interaction :** Le programme affichera des options pour appliquer différents filtres à la liste des mots. Suivez les instructions à l'écran pour :
    * Afficher les mots contenant certaines lettres.
    * Exclure les mots contenant certaines lettres.
    * Rechercher des mots contenant un sous-mot.

    En appliquant ces filtres de manière séquentielle, vous pourrez réduire la liste des candidats jusqu'à trouver le mot Wordle.

## Structure du code

Le code est organisé en plusieurs fonctions pour une meilleure modularité :

* `load_wordle_words()`: Charge les mots depuis le fichier `bdd_wordle.txt`.
* `filtrer_par_lettres_presentes()`: Sélectionne les mots contenant toutes les lettres spécifiées.
* `exclure_par_lettres()`: Supprime les mots contenant au moins une des lettres spécifiées.
* `filtrer_par_sous_mot()`: Sélectionne les mots contenant le sous-mot spécifié.

La fonction `main` gère la boucle principale du jeu, permettant à l'utilisateur d'entrer des critères de filtrage et d'afficher la liste des mots correspondants à chaque étape.

## Améliorations possibles

* Implémenter une logique de jeu Wordle complète avec des tentatives limitées et un retour d'information sur la position des lettres.
* Permettre des filtres plus avancés, par exemple, spécifier la position exacte d'une lettre.
* Ajouter une interface utilisateur plus conviviale.
* Gérer les erreurs de saisie de l'utilisateur de manière plus robuste.
* Optimiser le chargement et le filtrage de la liste des mots pour de très grands fichiers.
