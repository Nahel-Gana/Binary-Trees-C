#ifndef TEST_RBT_H
#define TEST_RBT_H

/**
 * @brief Teste la vérification des propriétés d'un Arbre Rouge-Noir (ARN/RBT).
 *
 * Cette fonction construit plusieurs arbres RBT manuellement, 
 * valides ou invalides, pour tester la fonction is_red_black :
 * - Vérifie la propriété d'ordre (ABR)
 * - Vérifie l'absence de double rouge
 * - Vérifie l'égalité des hauteurs noires
 *
 * Les résultats sont affichés sous forme PASS/FAIL.
 */
void test_rbt_verification(void) ;

#endif
