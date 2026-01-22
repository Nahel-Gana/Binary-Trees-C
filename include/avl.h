#ifndef AVL_H
#define AVL_H

#include "node.h"

/**
 * @brief Calcule le facteur d'équilibre d'un nœud AVL.
 *
 * Le facteur d'équilibre est défini comme :
 *     hauteur(fils gauche) - hauteur(fils droit)
 *
 * @param n Pointeur vers le nœud à analyser.
 * @return Facteur d'équilibre (entier positif si gauche plus grand, négatif si droite plus grand).
 */
int get_balance(Node * n) ;

/**
 * @brief Effectue une rotation droite sur un sous-arbre.
 *
 * Utilisée pour rééquilibrer les AVL dans les cas "Gauche-Gauche" ou "Droite-Gauche".
 *
 * @param x Racine du sous-arbre à faire pivoter.
 * @return Nouvelle racine du sous-arbre après rotation.
 */
Node * rotate_right(Node * x) ;

/**
 * @brief Effectue une rotation gauche sur un sous-arbre.
 *
 * Utilisée pour rééquilibrer les AVL dans les cas "Droite-Droite" ou "Gauche-Droite".
 *
 * @param x Racine du sous-arbre à faire pivoter.
 * @return Nouvelle racine du sous-arbre après rotation.
 */
Node * rotate_left(Node * x) ;

/**
 * @brief Insère une clé dans un arbre AVL.
 *
 * Effectue une insertion comme dans un ABR classique, puis met à jour les hauteurs
 * et applique les rotations nécessaires pour maintenir la propriété AVL.
 *
 * @param root Racine de l'arbre (ou sous-arbre) où insérer.
 * @param key Clé à insérer.
 * @return Nouvelle racine de l'arbre (ou sous-arbre) après insertion et rééquilibrage.
 */
Node * insert_avl(Node * root, int key) ;

/**
 * @brief Vérifie si un arbre binaire est un AVL valide.
 *
 * L'algorithme vérifie à la fois :
 * - la propriété d'ABR (ordre des clés),
 * - la propriété d'équilibre (facteur d'équilibre ≤ 1 en valeur absolue).
 *
 * @param root Racine de l'arbre à vérifier.
 * @return 1 si l'arbre est un AVL valide, 0 sinon.
 */
int is_avl(Node * root) ;

#endif
