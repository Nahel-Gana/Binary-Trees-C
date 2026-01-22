#include <stdio.h>
#include "avl.h"
#include "bst.h"

void test_avl_rotations(void) {
    printf("Vérification rotations.\n") ;

    // Création d'un arbre déséquilibré (Gauche-Gauche)
    Node * root = create_node(10) ;
    root->left = create_node(5) ;
    root->left->left = create_node(2) ;
    // Mise à jour des hauteurs
    update_heights(root) ;

    // Affichage de l'arbre avant rotation
    printf("Avant rotation droite :\n") ;
    print_tree(root, 0) ;

    // Rotation droite de l'arbre
    root = rotate_right(root) ;

    // Affichage de l'arbre après rotation
    printf("Après rotation droite :\n") ;
    print_tree(root, 0) ;

    // Création d'un arbre déséquilibré (Droite-Gauche)
    root = create_node(2) ;
    root->right = create_node(10) ;
    root->right->left = create_node(5) ;
    // Mise à jour des hauteurs
    update_heights(root) ;

    // Affichage de l'arbre avant rotation
    printf("Avant rotation droite :\n") ;
    print_tree(root, 0) ;

    // Rotation droite de l'arbre
    root = rotate_right(root) ;

    // Affichage de l'arbre après rotation
    printf("Après rotation droite :\n") ;
    print_tree(root, 0) ;

    // Création d'un arbre déséquilibré (Droite-Droite)
    root = create_node(10) ;
    root->right = create_node(15) ;
    root->right->right = create_node(20) ;
    // Mise à jour des hauteurs
    update_heights(root) ;

    // Affichage de l'arbre avant rotation
    printf("Avant rotation gauche :\n") ;
    print_tree(root, 0) ;

    // Rotation gauche de l'arbre
    root = rotate_left(root) ;

    // Affichage de l'arbre après rotation
    printf("Après rotation gauche :\n") ;
    print_tree(root, 0) ;

    // Création d'un arbre déséquilibré (Gauche-Droite)
    root = create_node(20) ;
    root->left = create_node(10) ;
    root->left->right = create_node(15) ;
    // Mise à jour des hauteurs
    update_heights(root) ;

    // Affichage de l'arbre avant rotation
    printf("Avant rotation gauche :\n") ;
    print_tree(root, 0) ;

    // Rotation gauche de l'arbre
    root = rotate_left(root) ;

    // Affichage de l'arbre après rotation
    printf("Après rotation gauche :\n") ;
    print_tree(root, 0) ;
}

void test_avl_insertion(void) {
    printf("Tests AVL insertions.\n") ;

    // Création d'une racine vide
    Node * root = NULL ;

    printf("\nCas LL (10, 5, 2) :\n") ;
    // Création des différentes valeurs à insérer
    int vals_ll[] = {10, 5, 2} ;
    // Insertion des différentes valeurs
    for (int i = 0 ; i < 3 ; i++) {
        root = insert_avl(root, vals_ll[i]) ;
    }
    // Mise à jour des hauteurs
    update_heights(root) ;
    // Affichage de l'arbre
    print_tree(root, 0) ;

    // Réinitialisation de l'arbre
    root = NULL ;

    printf("\nCas RR (10, 15, 20) :\n") ;
    // Création des différentes valeurs à insérer
    int vals_rr[] = {10, 15, 20} ;
    // Insertion des différentes valeurs
    for (int i = 0 ; i < 3 ; i++) {
        root = insert_avl(root, vals_rr[i]) ;
    }
    // Mise à jour des hauteurs
    update_heights(root) ;
    // Affichage de l'arbre
    print_tree(root, 0) ;

    // Réinitialisation de l'arbre
    root = NULL ;

    printf("\nCas LR (10, 2, 5) :\n") ;
    // Création des différentes valeurs à insérer
    int vals_lr[] = {10, 2, 5} ;
    // Insertion des différentes valeurs
    for (int i = 0 ; i < 3 ; i++) {
        root = insert_avl(root, vals_lr[i]) ;
    }
    // Mise à jour des hauteurs
    update_heights(root) ;
    // Affichage de l'arbre
    print_tree(root, 0) ;

    // Réinitialisation de l'arbre
    root = NULL ;

    printf("\nCas RL (10, 20, 15) :\n") ;
    // Création des différentes valeurs à insérer
    int vals_rl[] = {10, 20, 15} ;
    // Insertion des différentes valeurs
    for (int i = 0 ; i < 3 ; i++) {
        root = insert_avl(root, vals_rl[i]) ;
    }
    // Mise à jour des hauteurs
    update_heights(root) ;
    // Affichage de l'arbre
    print_tree(root, 0) ;
}

void test_avl_verification(void) {
    printf("Vérification AVL :\n") ;

    // Création d'une racine vide
    Node * root = NULL ;

    // Création des différentes valeurs à insérer
    int vals[] = {10, 5, 15, 3, 7, 12, 18} ;
    // Insertion des différentes valeurs
    for (int i = 0 ; i < 7 ; i++) {
        root = insert_avl(root, vals[i]) ;
    }
    // Mise à jour des hauteurs
    update_heights(root) ;

    printf("\nArbre AVL valide :\n") ;
    // Affichage de l'arbre
    print_tree(root, 0) ;
    // Vérification de l'arbre
    if (is_avl(root)) {
        printf("PASS\n") ; // AVL => PASS
    }
    else {
        printf("FAIL\n") ; // Non-AVL => FAIL
    }

    // Création d'un AVL invalide (Gauche-Gauche)
    Node * bad_root = create_node(10) ;
    bad_root->left = create_node(5) ;
    bad_root->left->left = create_node(2) ;
    // Mise à jour des hauteurs
    update_heights(bad_root) ;

    printf("\nArbre non AVL (déséquilibré gauche) :\n") ;
    // Affichage de l'arbre
    print_tree(bad_root, 0) ;
    // Vérification de l'arbre
    if (!is_avl(bad_root)) {
        printf("PASS\n") ; // Non-AVL => PASS
    }
    else {
        printf("FAIL\n") ; // AVL => FAIL
    }

    // Création d'un AVL invalide (Non-ABR <= 15 > 10)
    Node * bad_bst = create_node(10) ;
    bad_bst->left = create_node(15) ;
    // Mise à jour des hauteurs
    update_heights(bad_bst) ;

    printf("\nArbre non AVL (violation ABR) :\n") ;
    // Affichage de l'arbre
    print_tree(bad_bst, 0) ;
    // Vérification de l'arbre
    if (!is_avl(bad_bst)) {
        printf("PASS\n") ; // Non-AVL => PASS
    }
    else {
        printf("FAIL\n") ; // AVL => FAIL
    }
}
