# TP1 – Structures d’arbres équilibrés (ABR, AVL, ARN)

## Présentation générale

Ce TP a pour objectif d’implémenter, tester et comparer différentes structures d’arbres de recherche en C :

- **ABR (Arbre Binaire de Recherche)**
- **AVL (Arbre AVL, auto‑équilibré)**
- **ARN / RBT (Arbre Rouge‑Noir)**

Le travail inclut :

- l’implémentation des structures et algorithmes associés,
- la vérification des propriétés théoriques,
- une campagne de tests unitaires,
- une comparaison expérimentale des hauteurs,
- une documentation générée avec **Doxygen**.

---

## Organisation du projet

```bash
TP1-Algo/
├── include/        # Fichiers d’en-tête (.h)
│   ├── node.h
│   ├── bst.h
│   ├── avl.h
│   └── rbt.h
├── src/            # Implémentations (.c)
│   ├── bst.c
│   ├── avl.c
│   └── rbt.c
├── tests/          # Tests unitaires et expérimentaux
│   ├── test_bst.c / .h
│   ├── test_avl.c / .h
│   ├── test_rbt.c / .h
│   └── test_compare.c / .h
├── main.c          # Programme principal lançant tous les tests
├── Makefile        # Compilation du projet
├── Doxyfile        # Configuration Doxygen
├── test.sh         # Compilation et Exécution
└── README.md
```

---

## ABR – Arbre Binaire de Recherche

### Fonctionnalités implémentées

- Création de nœuds
- Insertion dans un ABR
- Parcours infixe
- Calcul et mise à jour des hauteurs
- Vérification de la propriété ABR
- Affichage structuré de l’arbre

### Tests

- Insertion simple
- Vérification d’arbres valides et invalides

---

## AVL – Arbre AVL

### AVL : Fonctionnalités implémentées

- Calcul du facteur d’équilibrage
- Rotations simples (gauche / droite)
- Rotations doubles
- Insertion avec équilibrage automatique
- Vérification complète de la propriété AVL

### AVL : Tests

- Tests unitaires des rotations
- Insertion de suites de valeurs
- Vérification de l’équilibrage final

---

## ARN – Arbre Rouge‑Noir

### ARN : Fonctionnalités implémentées

- Gestion de la coloration des nœuds (ROUGE / NOIR)
- Vérification des propriétés d’un ARN :
  - racine noire
  - absence de double rouge
  - hauteur noire constante
  - respect de la propriété ABR

> L’ARN est ici **vérifié**, mais pas construit automatiquement.

### ARN : Tests

- Arbre rouge‑noir valide
- Cas avec double rouge
- Cas avec hauteur noire incorrecte
- Cas violant la propriété ABR

---

## Comparaison expérimentale ABR vs AVL

Un test expérimental compare la hauteur d’un ABR simple et d’un AVL après insertion de **N = 10 000** valeurs aléatoires.

Les mesures incluent :

- hauteur finale de l’ABR
- hauteur finale de l’AVL
- vérification AVL
- calcul du ratio :

```math
hauteur(AVL) / log_2(N)
```

Ce test illustre expérimentalement l’efficacité de l’équilibrage AVL.

---

## Programme principal

Le fichier `main.c` orchestre l’ensemble des tests :

1. Tests ABR
2. Tests AVL
3. Tests ARN
4. Test de comparaison ABR / AVL

Chaque partie affiche clairement les résultats (**PASS / FAIL**) dans le terminal.

---

## Compilation et exécution

```bash
bash test.sh
```
---

## Documentation Doxygen

Une documentation complète a été générée avec **Doxygen** :

- commentaires normalisés (`/** ... */`, `@param`, `@return`)
- documentation des fichiers, fonctions et structures
- génération HTML

Commande utilisée :

```bash
doxygen Doxyfile
```

La documentation générée se trouve dans le dossier `html/`.

---

## Conclusion

Ce TP met en œuvre :

- des structures de données fondamentales,
- des algorithmes d’équilibrage non triviaux,
- une validation systématique par tests,
- une comparaison expérimentale conforme à la théorie,
- une documentation propre et exploitable.

Il constitue une base solide pour la compréhension et l’utilisation des arbres équilibrés en algorithmique.

---

**Auteur :** Nahel GANA
