#ifndef TEST_COMPARE_H
#define TEST_COMPARE_H

/**
 * @brief Effectue une comparaison expérimentale entre un ABR simple et un AVL.
 *
 * Cette fonction génère une liste de 10 000 entiers aléatoires, 
 * les insère dans un ABR simple et dans un AVL, puis mesure :
 * - La hauteur finale de l'ABR simple (pour évaluer si elle est proche de O(log n) ou O(n))
 * - La hauteur finale de l'AVL (pour vérifier que l'arbre reste équilibré)
 * 
 * Elle utilise la fonction de vérification AVL pour certifier la validité de l'AVL.
 * Les résultats et les rapports sont affichés à l'écran.
 */
void test_comparison(void) ;

#endif
