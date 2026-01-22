#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bst.h"

Node * create_node(int key) {
    // Initialisation du nœud
    Node * n = malloc(sizeof(Node)) ;

    // Si l'initialisation échoue, retourne NULL
    if (!n) {
        return NULL ;
    }

    // Initialisation des différentes valeurs reliés au nœud
    n->key = key ;
    n->left = NULL ;
    n->right = NULL ;
    n->height = 0 ;
    n->color = NOIR ;

    // Retourne le nœud
    return n ;
}

Node * insert_bst(Node * root, int key) {
    // Si la racine est vide, créé un nouveau nœud
    if (root == NULL) {
        return create_node(key) ;
    }

    // Si la clé est inférieure à la clé de la racine, aller dans le sous-arbre gauche
    if (key < root->key) {
        root->left = insert_bst(root->left, key) ;
    }
    else {
        // Si la clé est supérieure à la clé de la racine, aller dans le sous-arbre droit
        if (key > root->key) {
            root->right = insert_bst(root->right, key) ;
        }
    }

    // Retourne la racine
    return root ;
}

void inorder_print(Node * root) {
    // Si la racine est vide, arrête la procédure
    if (root == NULL) {
        return ;
    }

    // Parcours des clés du sous-arbre gauche
    inorder_print(root->left) ;
    // Affichage de la clé de la racine
    printf("%d ", root->key) ;
    // Parcours des clés du sous-arbre droit
    inorder_print(root->right) ;
}

/**
 * @brief Fonction utilitaire pour vérifier la validité d’un ABR.
 *
 * Vérifie que toutes les clés du sous-arbre gauche sont < root->key,
 * et que toutes les clés du sous-arbre droit sont > root->key.
 *
 * @param root Nœud courant.
 * @param min Valeur minimale autorisée.
 * @param max Valeur maximale autorisée.
 * @return int 1 si sous-arbre valide, 0 sinon.
 */
static int is_bst_util(Node * root, int min, int max) {
    // Si la racine est vide, retourne 1
    if (root == NULL) {
        return 1 ;
    }

    // Si la clé de la racine est inférieure à la valeur minimale autorisée ou si elle est supérieure à la valeur maximale autorisée, retourne 0
    if (root->key <= min || root->key >= max) {
        return 0 ;
    }

    // Analyse des sous-arbres gauche et droit
    return is_bst_util(root->left, min, root->key) && is_bst_util(root->right, root->key, max) ;
}

int is_bst(Node * root) {
    // Retourne 1 si l'arbre est un ABR et que la clé de la racine est un int valide, et 0 sinon (en s'aidant de la fonction is_bst_util)
    return is_bst_util(root, INT_MIN, INT_MAX) ;
}

void print_tree(Node * root, int space) {
    // Si la racine est vide, arrête la procédure
    if (root == NULL) {
        return ;
    }

    // Administration des espaces entre la racine et ses fils
    int COUNT = 5 ;
    space += COUNT ;

    // Affichage du sous-arbre droit
    print_tree(root->right, space) ;

    // Affichage de la racine, compte-tenu de l'indentation, de la hauteur (h), et de la couleur (c)
    printf("\n") ;
    for (int i = COUNT ; i < space ; i++) {
        printf(" ") ;
    }
    printf(" %d(h=%d, c=%s)\n", root->key, root->height, root->color == ROUGE ? "R" : "N") ;

    // Affichage du sous-arbre gauche
    print_tree(root->left, space) ;
}

int get_height(Node * n) {
    // Si le nœud est vide, retourne -1
    if (n == NULL) {
        return -1 ;
    }

    // Retourne la hauteur du nœud
    return n->height ;
}

void update_height(Node * n) {
    // Si le nœud est vide, arrête la procédure
    if (n == NULL) {
        return ;
    }

    // Récupère les hauteurs gauche et droite
    int hl = get_height(n->left) ;
    int hr = get_height(n->right) ;

    // La hauteur du nœud est égale à la hauteur de son plus haut sous-arbre incrémentée de 1
    if (hl > hr) {
        n->height = 1 + hl ;
    }
    else {
        n->height = 1 + hr ;
    }
}

void update_heights(Node * root) {
    // Si la racine est vide, arrête la procédure
    if (root == NULL) {
        return ;
    }
    
    // Met à jour les hauteurs du sous-arbre gauche, du sous-arbre droit et de la racine
    update_heights(root->left) ;
    update_heights(root->right) ;
    update_height(root) ;
}
