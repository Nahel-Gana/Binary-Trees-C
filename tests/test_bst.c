#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void test_bst_insertion(void) {
    printf("Vérification insertion.\n") ;

    // Création d'un nœud racine
    Node * root = NULL ;
    // Création de valeurs à insérer
    int values[] = {10, 5, 15, 3, 7, 12, 18} ;
    // Calcul du nombre de valeurs à insérer
    int n = sizeof(values) / sizeof(int) ;
    // Insertion de toutes les valeurs via la fonction insert_bst
    for (int i = 0 ; i < n ; i++) {
        root = insert_bst(root, values[i]) ;
    }

    printf("Parcours infixe attendu : 3 5 7 10 12 15 18\n") ;
    printf("Parcours infixe obtenu  : ") ;
    // Affichage du parcours infixe
    inorder_print(root) ;
    printf("\n") ;
}

void test_bst_verification(void) {
    // Création d'un nœud racine
    Node * root = NULL ;
    // Création de valeurs à insérer
    int values[] = {10, 5, 15, 3, 7, 12, 18} ;
    // Calcul du nombre de valeurs à insérer
    int n = sizeof(values) / sizeof(int) ;
    // Insertion de toutes les valeurs via la fonction insert_bst
    for (int i = 0 ; i < n ; i++) {
        root = insert_bst(root, values[i]) ;
    }

    printf("Vérification is_bst arbre normal : ");
    // Mise à jour des hauteurs
    update_heights(root);
    // Affichage de l'arbre
    print_tree(root, 0);
    // Vérification de l'arbre
    if (is_bst(root)) {
        printf("PASS\n") ; // ABR => PASS
    }
    else {
        printf("FAIL\n") ; // Non-ABR => FAIL
    }

    // Création d'un nouvel arbre (dysfonctionnel)
    Node * bad = malloc(sizeof(Node)) ;
    bad->key = 10 ;
    bad->left = malloc(sizeof(Node)) ;
    // Ajout d'une clé à un endroit invalide pour un ABR (20 > 10)
    bad->left->key = 20 ;
    bad->left->left = NULL ;
    bad->left->right = NULL ;
    bad->right = NULL ;

    printf("Vérification is_bst arbre anormal : ") ;
    // Mise à jour des hauteurs
    update_heights(bad) ;
    // Affichage de l'arbre
    print_tree(bad, 0) ;
    // Vérification de l'arbre
    if (!is_bst(bad)) {
        printf("PASS\n") ; // Non-ABR => PASS
    }
    else {
        printf("FAIL\n") ; // ABR => FAIL
    }
}
