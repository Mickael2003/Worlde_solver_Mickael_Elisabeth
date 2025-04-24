


// Fonction principale (main)
int main() {
    char mots[MAX_WORDS][WORD_LENGTH];
    char motsFiltres[MAX_WORDS][WORD_LENGTH];
    const char* fichier_chemin = "ressource/bdd_wordle.txt";

    int total = load_wordle_words(fichier_chemin, mots);
    if (total <= 0) {
        printf("Aucun mot n'a été chargé.\n");
        return -1;
    }

    // Exemple d'utilisation des filtres
    char lettre = 'A';
    int nbMotsFiltres = filtrer_par_lettre(mots, total, lettre, motsFiltres);
    printf("Mots contenant la lettre '%c' :\n", lettre);
    afficher_mots(motsFiltres, nbMotsFiltres);

    // Exemple : Filtrer les mots contenant les lettres A et B
    const char* lettres = "AB";
    nbMotsFiltres = filtrer_par_lettres(mots, total, lettres, motsFiltres);
    printf("\nMots contenant les lettres '%s' :\n", lettres);
    afficher_mots(motsFiltres, nbMotsFiltres);

    // Exemple : Exclure les mots contenant la lettre A
    const char* exclure = "A";
    nbMotsFiltres = exclure_par_lettres(mots, total, exclure, motsFiltres);
    printf("\nMots ne contenant pas la lettre '%s' :\n", exclure);
    afficher_mots(motsFiltres, nbMotsFiltres);

    // Exemple : Filtrer les mots contenant un sous-mot spécifique
    const char* sousMot = "ane";
    nbMotsFiltres = filtrer_par_sous_mot(mots, total, sousMot, motsFiltres);
    printf("\nMots contenant le sous-mot '%s' :\n", sousMot);
    afficher_mots(motsFiltres, nbMotsFiltres);

    return 0;
}
