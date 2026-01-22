#include <stdio.h>
#include <limits.h>
#include "rbt.h"
#include "bst.h"

/**
 * @brief Fonction interne pour vérifier qu'un arbre est un Arbre Rouge-Noir (ARN).
 *
 * Cette fonction effectue un parcours récursif et vérifie simultanément :
 * - la propriété d'ABR (clé du nœud entre min et max),
 * - pas de double rouge (un nœud rouge ne peut pas avoir de fils rouge),
 * - la hauteur noire constante (tous les chemins vers les feuilles ont le même nombre de nœuds noirs).
 *
 * @param root Racine du sous-arbre courant.
 * @param min Valeur minimale autorisée pour les clés (pour propriété ABR).
 * @param max Valeur maximale autorisée pour les clés (pour propriété ABR).
 * @param parent_color Couleur du parent du nœud actuel.
 * @return Hauteur noire du sous-arbre si valide, -1 si violation des propriétés.
 */
static int is_red_black_util(Node * root, int min, int max, int parent_color) {
    // Si la racine est vide, retourne 1 (Hauteur noire d'une feuille NULLE = 1)
    if (root == NULL) {
        return 1 ;
    }

    // Si l'arbre n'est pas un ABR, retourne -1
    if (!is_bst(root)) {
        return -1 ;
    }

    // Si la racine et le parent sont rouges, retourne -1
    if (parent_color == ROUGE && root->color == ROUGE) {
        return -1 ;
    }

    // Initialisation de la hauteur noire gauche
    int hl = is_red_black_util(root->left, min, root->key, root->color);
    // Si le sous-arbre gauche n'est pas un ARN, retourne -1
    if (hl == -1) {
        return -1 ;
    }

    // Initialisation de la hauteur noire droite
    int hr = is_red_black_util(root->right, root->key, max, root->color);
    // Si le sous-arbre droit n'est pas un ARN, retourne -1
    if (hr == -1) {
        return -1 ;
    }

    // Si les hauteurs noires sont différentes, retourne -1
    if (hl != hr) {
        return -1 ;
    }

    // Calcul de la hauteur noire
    int hb ;
    // Si la couleur de la racine est noire, la hauteur noire est égale à la hauteur noire gauche incrémentée de 1
    if (root->color == NOIR) {
        hb = hl + 1 ;
    }
    // Si la couleur de la racine est rouge, la hauteur noire est égale à la hauteur noire gauche
    else {
        hb = hl ;
    }

    // Retourne la hauteur noire
    return hb ;
}

int is_red_black(Node * root) {
    // Si la racine est rouge, retourne 0
    if (root->color != NOIR) {
        return 0 ;
    }
    // Retourne 1 si l'arbre est un ARN et que la clé de la racine est un int valide, et 0 sinon (en s'aidant de la fonction is_red_black_util)
    return is_red_black_util(root, INT_MIN, INT_MAX, NOIR) != -1 ;
}
