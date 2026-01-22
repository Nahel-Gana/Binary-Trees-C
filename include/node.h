#ifndef NODE_H
#define NODE_H

/**
 * @brief Couleur d'un nœud pour les arbres Rouge-Noir.
 */
typedef enum { 
    ROUGE, /**< Nœud rouge */
    NOIR   /**< Nœud noir */
} Couleur ;

/**
 * @brief Structure représentant un nœud d'arbre binaire.
 *
 * Cette structure est utilisée pour :
 * - les ABR simples,
 * - les arbres AVL (avec le champ `height`),
 * - les arbres Rouge-Noir (avec le champ `color`).
 */
typedef struct Node {
    int key ;               /**< Clé ou valeur stockée dans le nœud */
    struct Node * left ;    /**< Pointeur vers le fils gauche */
    struct Node * right ;   /**< Pointeur vers le fils droit */
    int height ;            /**< Hauteur du nœud (utilisée pour AVL) */
    Couleur color ;         /**< Couleur du nœud (utilisée pour Rouge-Noir) */
} Node ;

#endif
