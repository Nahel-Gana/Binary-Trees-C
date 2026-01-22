#ifndef TEST_AVL_H
#define TEST_AVL_H

/**
 * @brief Teste les rotations d'un arbre AVL.
 *
 * Cette fonction crée manuellement des arbres pour vérifier
 * les rotations Droite (Right) et Gauche (Left).
 * Elle affiche les arbres avant et après rotation pour vérification visuelle.
 */
void test_avl_rotations(void) ;

/**
 * @brief Teste l'insertion dans un arbre AVL.
 *
 * Cette fonction insère des nœuds dans un AVL en utilisant insert_avl,
 * puis affiche l'arbre après chaque insertion pour vérifier
 * que les rotations et les hauteurs sont correctement mises à jour.
 */
void test_avl_insertion(void) ;

/**
 * @brief Teste la vérification de la propriété AVL.
 *
 * Cette fonction utilise is_avl pour vérifier si différents arbres
 * (équilibrés et déséquilibrés) respectent les propriétés AVL
 * en termes de facteur d'équilibre et d'ordre des clés.
 */
void test_avl_verification(void) ;

#endif
