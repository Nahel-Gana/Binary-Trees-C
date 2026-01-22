#ifndef BST_H
#define BST_H

#include "node.h"

/**
 * @brief Crée un nouveau nœud pour un ABR.
 *
 * Le nœud est initialisé avec la clé donnée, les enfants NULL, 
 * hauteur = 0 et couleur NOIR.
 *
 * @param key La valeur du nœud.
 * @return Node* Pointeur vers le nouveau nœud.
 */
Node * create_node(int key) ;

/**
 * @brief Insère une clé dans un arbre binaire de recherche (ABR).
 *
 * Si la racine est NULL, crée un nouveau nœud. Sinon, insère
 * récursivement dans le sous-arbre gauche ou droit selon la clé.
 *
 * @param root Racine de l’arbre.
 * @param key Clé à insérer.
 * @return Node* Nouvelle racine après insertion.
 */
Node * insert_bst(Node * root, int key) ;

/**
 * @brief Effectue un parcours infixe (gauche → racine → droite) et affiche les clés.
 *
 * @param root Racine de l’arbre.
 */
void inorder_print(Node * root) ;

/**
 * @brief Vérifie si un arbre est un ABR valide.
 *
 * L’arbre est considéré valide si, pour chaque nœud, toutes les clés
 * du sous-arbre gauche sont < clé du nœud et toutes les clés du sous-arbre
 * droit sont > clé du nœud.
 *
 * @param root Racine de l’arbre.
 * @return int 1 si l’arbre est un ABR valide, 0 sinon.
 */
int is_bst(Node * root) ;

/**
 * @brief Affiche l’arbre sous forme “visuelle” avec indentation.
 *
 * La racine est affichée au milieu, le sous-arbre gauche en bas,
 * le sous-arbre droit en haut. Les espaces augmentent avec la profondeur.
 *
 * @param root Racine de l’arbre.
 * @param space Nombre d’espaces pour l’indentation (mettre 0 à l’appel initial).
 */
void print_tree(Node * root, int space) ;

/**
 * @brief Retourne la hauteur d’un nœud.
 *
 * @param n Nœud à mesurer.
 * @return int Hauteur du nœud, -1 si NULL.
 */
int get_height(Node * n) ;

/**
 * @brief Met à jour la hauteur d’un nœud en fonction de ses enfants.
 *
 * @param n Nœud à mettre à jour.
 */
void update_height(Node * n) ;

/**
 * @brief Met à jour la hauteur de tous les nœuds de l’arbre.
 *
 * Appelle récursivement update_height sur tous les nœuds.
 *
 * @param root Racine de l’arbre.
 */
void update_heights(Node * root) ;

#endif
