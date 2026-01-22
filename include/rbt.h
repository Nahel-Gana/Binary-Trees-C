#ifndef RBT_H
#define RBT_H

#include "node.h"

/**
 * @brief Vérifie si un arbre binaire est un arbre Rouge-Noir valide.
 *
 * Cette fonction parcourt l'arbre en O(n) et vérifie simultanément :
 * - La propriété d'ABR (ordre des clés).
 * - L'absence de double rouge (un nœud rouge ne peut avoir un enfant rouge).
 * - L'égalité des hauteurs noires de tous les chemins.
 *
 * @param root Pointeur vers la racine de l'arbre.
 * @return int Retourne 1 si l'arbre est un RBT valide, 0 sinon.
 */
int is_red_black(Node * root) ;

#endif
