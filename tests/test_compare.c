#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "bst.h"
#include "avl.h"

void test_comparison(void) {
    // Création de la constante N = 10 000
    const int N = 10000 ;
    
    // Création tableau pour stocker les entiers aléatoires
    int * values = malloc(N * sizeof(int)) ;
    // Si l'allocation échoue, arrête la procédure et indique une erreur
    if (!values) {
        printf("Erreur allocation mémoire\n") ;
        return ;
    }

    // Génération des entiers aléatoires via rand et time
    srand(time(NULL)) ;
    for (int i = 0; i < N; i++) {
        values[i] = rand() ;
    }

    // Création des racines des deux arbres
    Node * root_bst = NULL ;
    Node * root_avl = NULL ;

    // Insertion des valeurs aléatoires dans les deux arbres
    for (int i = 0 ; i < N ; i++) {
        root_bst = insert_bst(root_bst, values[i]) ;
        root_avl = insert_avl(root_avl, values[i]) ;
    }

    // Mise à jour des hauteurs
    update_heights(root_bst) ;
    update_heights(root_avl) ;

    // Calcul de la hauteur de l'ABR
    int height_bst ;
    // Si la racine existe, la hauteur de l'ABR est la hauteur de la racine
    if (root_bst) {
        height_bst = root_bst->height ;
    }
    // Si la racine n'existe pas, la hauteur de l'ABR est -1
    else {
        height_bst = -1 ;
    }

    // Calcul de la hauteur de l'AVL
    int height_avl ;
    // Si la racine existe, la hauteur de l'AVL est la hauteur de la racine
    if (root_avl) {
        height_avl = root_avl->height ;
    }
    // Si la racine n'existe pas, la hauteur de l'AVL est -1
    else {
        height_avl = -1 ;
    }

    // Affichage des résultats
    printf("Comparaison expérimentale.\n") ;
    printf("Nombre de nœuds : %d\n", N) ;
    printf("Hauteur ABR simple : %d\n", height_bst) ;
    printf("Hauteur AVL : %d\n", height_avl) ;

    // Vérification si l'AVL est bien un AVL
    int avl_check = is_avl(root_avl) ;
    printf("Vérification AVL : ") ;
    if (avl_check) {
        printf("PASS\n") ; // AVL => PASS
    }
    else {
        printf("FAIL\n") ; // Non-AVL => FAIL
    }

    // Vérification que hauteur AVL < c * log2(N) (avec c = hauteur_avl / log2n)
    double log2n = log2(N) ;
    double c = (double) height_avl / log2n ;
    printf("Hauteur AVL / log2(N) = %.2f (c = %.2f)\n", (double) height_avl / log2n, c) ;

    // Libération de la mémoire
    free(values) ;
}
