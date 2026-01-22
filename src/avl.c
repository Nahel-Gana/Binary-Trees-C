#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "avl.h"
#include "bst.h"

int get_balance(Node * n) {
    // Si le nœud est nul, retourne 0
    if (n == NULL) {
        return 0 ;
    }

    // Retourne la différence entre la hauteur du fils gauche et la hauteur du fils droit
    return get_height(n->left) - get_height(n->right) ;
}

Node * rotate_right(Node * x) {
    // Si x ou son fils gauche est nul, retourne x
    if (x == NULL || x->left == NULL) {
        return x ;
    }

    // Rotation de l'arbre (la racine du sous-arbre gauche devient la racine et la racine devient la racine du sous-arbre droit)
    Node * y = x->left ;
    Node * tmp = y->right ;
    y->right = x ;
    x->left = tmp ;

    // Mise à jour des hauteurs
    update_height(x) ;
    update_height(y) ;

    // Retourne le nouvel arbre pivoté
    return y ;
}

Node * rotate_left(Node * x) {
    // Si x ou son fils droit est nul, retourne x
    if (x == NULL || x->right == NULL) {
        return x ;
    }

    // Rotation de l'arbre (la racine du sous-arbre droit devient la racine et la racine devient la racine du sous-arbre gauche)
    Node * y = x->right ;
    Node * tmp = y->left ;
    y->left = x ;
    x->right = tmp ;

    // Mise à jour des hauteurs
    update_height(x) ;
    update_height(y) ;

    // Retourne le nouvel arbre pivoté
    return y ;
}

Node * insert_avl(Node * root, int key) {
    // Si la racine est vide, crée un nouveau nœud contenant la clé passée en paramète
    if (root == NULL) {
        return create_node(key) ;
    }

    // Si la clé est inférieure à la clé de la racine, insérer le nœud dans le sous-arbre gauche
    if (key < root->key) {
        root->left = insert_avl(root->left, key) ;
    }
    else {
        // Si la clé est supérieure à la clé de la racine, insérer le nœud dans le sous-arbre droit
        if (key > root->key) {
            root->right = insert_avl(root->right, key) ;
        }
        // Si la clé est déjà présente, ne rien faire
        else {
            return root ;
        }
    }

    // Mise à jour de la hauteur de la racine
    update_height(root) ;

    // Récupération du facteur d'équilibre
    int balance = get_balance(root) ;

    // Si le facteur d'équilbre est inapproprié et que la clé est inférieure à la clé de la racine du sous-arbre gauche, pivoter à droite
    if (balance > 1 && key < root->left->key) {
        return rotate_right(root) ;
    }

    // Si le facteur d'équilbre est inapproprié et que la clé est supérieure à la clé de la racine du sous-arbre droit, pivoter à gauche
    if (balance < -1 && key > root->right->key) {
        return rotate_left(root) ;
    }

    // Si le facteur d'équilbre est inapproprié et que la clé est supérieure à la clé de la racine du sous-arbre gauche, pivoter à gauche le sous-arbre gauche puis pivoter à droite
    if (balance > 1 && key > root->left->key) {
        root->left = rotate_left(root->left) ;
        return rotate_right(root) ;
    }

    // Si le facteur d'équilbre est inapproprié et que la clé est inférieure à la clé de la racine du sous-arbre droit, pivoter à droite le sous-arbre droit puis pivoter à gauche
    if (balance < -1 && key < root->right->key) {
        root->right = rotate_right(root->right) ;
        return rotate_left(root) ;
    }

    // Retourne la racine
    return root ;
}

/**
 * @brief Fonction interne pour vérifier qu'un arbre est AVL.
 *
 * Vérifie :
 * - propriété d'ABR (clé de gauche < clé < clé de droite),
 * - facteur d'équilibre ≤ 1.
 * Retourne la hauteur si AVL valide, -1 sinon.
 *
 * @param root Racine du sous-arbre.
 * @param min Valeur minimale autorisée pour les clés.
 * @param max Valeur maximale autorisée pour les clés.
 * @return Hauteur du sous-arbre si AVL valide, -1 sinon.
 */
static int is_avl_util(Node * root, int min, int max) {
    // Si la racine est vide, retourne 0 (Hauteur d'un arbre vide = 0)
    if (root == NULL) {
        return 0 ;
    }

    // Si l'arbre n'est pas un ABR, retourne -1
    if (!is_bst(root)) {
        return -1 ;
    }

    // Initialisation de la hauteur gauche
    int hl = is_avl_util(root->left, min, root->key);
    // Si le sous-arbre gauche n'est pas un AVL, retourne -1
    if (hl == -1) {
        return -1 ;
    }

    // Initialisation de la hauteur droite
    int hr = is_avl_util(root->right, root->key, max);
    // Si le sous-arbre droit n'est pas un AVL, retourne -1
    if (hr == -1) {
        return -1 ;
    }

    // Si la différence de hauteur est supérieure à 1 (en valeur absolue), retourne -1
    if (hl - hr > 1 || hl - hr < -1) {
        return -1 ;
    }

    // Si la hauteur gauche est plus grande que la hauteur droite, la hauteur est égale à la hauteur gauche incrémentée de 1
    if (hl > hr) {
        return 1 + hl ;
    }
    // Si la hauteur droite est plus grande que la hauteur gauche, la hauteur est égale à la hauteur droite incrémentée de 1
    else {
        return 1 + hr ;
    }
}

int is_avl(Node * root) {
    // Retourne 1 si l'arbre est un AVL et que la clé de la racine est un int valide, et 0 sinon (en s'aidant de la fonction is_avl_util)
    return is_avl_util(root, INT_MIN, INT_MAX) != -1;
}
