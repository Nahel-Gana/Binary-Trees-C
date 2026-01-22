#include <stdio.h>
#include "rbt.h"
#include "bst.h"

void test_rbt_verification(void) {
    printf("Vérification ARN\n") ;

    // Création d'un ARN valide
    Node * root_valid = create_node(10) ;
    root_valid->color = NOIR ;
    root_valid->left = create_node(5) ;
    root_valid->left->color = ROUGE ;
    root_valid->right = create_node(15) ;
    root_valid->right->color = ROUGE ;
    root_valid->left->left = create_node(2) ;
    root_valid->left->left->color = NOIR ;
    root_valid->left->right = create_node(7) ;
    root_valid->left->right->color = NOIR ;
    root_valid->right->left = create_node(12) ;
    root_valid->right->left->color = NOIR ;
    root_valid->right->right = create_node(18) ;
    root_valid->right->right->color = NOIR ;

    printf("\nArbre RBT valide :\n") ;
    // Mise à jour des hauteurs
    update_heights(root_valid) ;
    // Affichage de l'arbre
    print_tree(root_valid, 0) ;
    // Vérification de l'arbre
    if (is_red_black(root_valid)) {
        printf("PASS\n") ; // ARN => PASS
    }
    else {
        printf("FAIL\n") ; // Non-ARN => FAIL
    }

    // Création d'un ARN invalide (rouge -> rouge)
    Node * root_double_red = create_node(10) ;
    root_double_red->color = NOIR ;
    root_double_red->left = create_node(5) ;
    root_double_red->left->color = ROUGE ;
    root_double_red->left->left = create_node(2) ;
    root_double_red->left->left->color = ROUGE ;

    printf("\nArbre avec double rouge :\n") ;
    // Mise à jour des hauteurs
    update_heights(root_double_red) ;
    // Affichage de l'arbre
    print_tree(root_double_red, 0) ;
    // Vérification de l'arbre
    if (!is_red_black(root_double_red)) {
        printf("PASS\n") ; // Non-ARN => PASS
    }
    else {
        printf("FAIL\n") ; // ARN => FAIL
    }

    // Création d'un ARN invalide (hauteur noire gauche > hauteur noire droite)
    Node* root_bad_black_height = create_node(10) ;
    root_bad_black_height->color = NOIR ;
    root_bad_black_height->left = create_node(5) ;
    root_bad_black_height->left->color = NOIR ;
    root_bad_black_height->left->left = create_node(2) ;
    root_bad_black_height->left->left->color = NOIR ;

    printf("\nArbre avec hauteur noire inégale :\n") ;
    // Mise à jour des hauteurs
    update_heights(root_bad_black_height) ;
    // Affichage de l'arbre
    print_tree(root_bad_black_height, 0) ;
    // Vérification de l'arbre
    if (!is_red_black(root_bad_black_height)) {
        printf("PASS\n") ; // Non-ARN => PASS
    }
    else {
        printf("FAIL\n") ; // ARN => FAIL
    }

    // Création d'un ARN invalide (Non-ABR <= 15 > 10)
    Node* root_bad_bst = create_node(10) ;
    root_bad_bst->color = NOIR ;
    root_bad_bst->left = create_node(15) ;

    printf("\nArbre non ARN (violation ABR) :\n") ;
    // Mise à jour des hauteurs
    update_heights(root_bad_bst) ;
    // Affichage de l'arbre
    print_tree(root_bad_bst, 0) ;
    // Vérification de l'arbre
    if (!is_red_black(root_bad_bst)) {
        printf("PASS\n") ; // Non-ARN => PASS
    }
    else {
        printf("FAIL\n") ; // ARN => FAIL
    }
}
