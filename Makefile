# ===== Compilateur et options =====
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

# ===== Dossiers =====
SRC_DIR = src
TEST_DIR = tests
OBJ_DIR = obj
BIN_DIR = bin

# ===== Fichiers sources =====
SRC_FILES = $(SRC_DIR)/bst.c $(SRC_DIR)/avl.c $(SRC_DIR)/rbt.c
TEST_FILES = $(TEST_DIR)/test_bst.c $(TEST_DIR)/test_avl.c $(TEST_DIR)/test_rbt.c $(TEST_DIR)/test_compare.c
MAIN_FILE = main.c

# ===== Fichiers objets =====
OBJ_FILES = $(OBJ_DIR)/bst.o \
            $(OBJ_DIR)/avl.o \
            $(OBJ_DIR)/rbt.o \
            $(OBJ_DIR)/test_bst.o \
            $(OBJ_DIR)/test_avl.o \
            $(OBJ_DIR)/test_rbt.o \
            $(OBJ_DIR)/test_compare.o \
            $(OBJ_DIR)/main.o

# ===== Exécutable =====
EXEC = $(BIN_DIR)/test_arbre

# ===== Règles =====

all: $(EXEC)

# Création de l'exécutable
$(EXEC): $(OBJ_FILES)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -lm

# Compilation des fichiers sources
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation des fichiers de tests
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation du main
$(OBJ_DIR)/main.o: $(MAIN_FILE)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Nettoyage complet
mrproper: clean
