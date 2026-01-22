#include <stdio.h>
#include "tests/test_bst.h"
#include "tests/test_avl.h"
#include "tests/test_rbt.h"
#include "tests/test_compare.h"

/**
 * @file main.c
 * @brief Point d'entrée pour exécuter tous les tests sur les arbres ABR, AVL, RBT et comparaisons.
 *
 * Ce programme exécute successivement :
 * 1. Les tests de l'ABR (insertion et vérification).
 * 2. Les tests AVL (rotations, insertions et vérification).
 * 3. Les tests des Arbres Rouge-Noir (ARN / RBT).
 * 4. Les comparaisons expérimentales entre ABR et AVL.
 *
 * Les résultats sont affichés dans la console.
 */

/**
 * @brief Fonction principale du programme de tests.
 *
 * @return int Code de retour : 0 si tout s'est bien passé.
 */
int main(void) {
    printf("===== LANCEMENT DES TESTS =====\n\n") ;

    // Tests ABR
    printf("Début tests bst :\n") ;
    test_bst_insertion() ;    // Vérification de l'insertion
    test_bst_verification() ; // Vérification de la propriété d'ABR
    printf("Fin tests bst.\n\n") ;
    
    // Tests AVL
    printf("Début tests avl :\n") ;
    test_avl_rotations() ;    // Vérification des rotations
    test_avl_insertion() ;    // Vérification des insertions
    test_avl_verification() ; // Vérification de la propriété AVL
    printf("Fin tests avl.\n\n") ;

    // Tests ARN
    printf("Début tests rbt :\n") ;
    test_rbt_verification() ; // Vérification des propriétés RBT
    printf("Fin tests rbt.\n\n") ;

    // Comparaison expérimentale
    printf("Début tests comparaisons :\n") ;
    test_comparison() ;       // Mesure des hauteurs et vérification AVL
    printf("Fin tests comparaisons.\n\n") ;
    
    printf("===== FIN DES TESTS =====\n") ;
    
    // Retourne 0
    return 0 ;
}
