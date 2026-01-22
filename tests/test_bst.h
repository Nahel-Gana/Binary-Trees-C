#ifndef TEST_BST_H
#define TEST_BST_H

/**
 * @brief Teste l'insertion dans un arbre binaire de recherche (BST).
 *
 * Cette fonction vérifie que les nœuds sont correctement insérés
 * et que le parcours infixe retourne les clés dans l'ordre croissant.
 */
void test_bst_insertion(void) ;

/**
 * @brief Teste la vérification de la propriété BST.
 *
 * Cette fonction crée des arbres valides et invalides et
 * vérifie que la fonction `is_bst` détecte correctement
 * si un arbre respecte la propriété d'ordre d'un BST.
 */
void test_bst_verification(void) ;

#endif
