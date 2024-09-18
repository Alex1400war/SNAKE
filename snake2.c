#include <unistd.h>
#include <stdlib.h>  // Pour malloc
#include <stdio.h>   // Pour printf

typedef struct snake {
    char head;
    char body;
    int size;
    char obj;
} snake;

// Fonction pour créer et initialiser le plateau de jeu
char **Mboard() {
    struct snake s;
    int x, y;
    
    // Créer un tableau dynamique pour le plateau de jeu
    char **map = malloc(6 * sizeof(char *));
    for (int i = 0; i < 6; i++) {
        map[i] = malloc(6 * sizeof(char));
    }

    // Initialiser la structure snake
    s.head = 's';
    s.body = 'x';
    s.size = 1;
    s.obj = 'O';
    
    // Remplir le plateau de jeu avec des '.' et placer la tête du serpent
    for (y = 0; y < 6; y++) {
        for (x = 0; x < 6; x++) {
            if (y == 3 && x == 3) {
                map[y][x] = s.head;  // Placer la tête du serpent
            } else {
                map[y][x] = '.';  // Remplir le reste avec des '.'
            }
        }
    }

    return map;
}

// Fonction pour imprimer le plateau de jeu
void print_board(char **board) {
    int x, y;

    for (y = 0; y < 6; y++) {
        for (x = 0; x < 6; x++) {
            write(1, &board[y][x], 1);  // Imprimer chaque caractère
        }
        write(1, "\n", 1);  // Ajouter un retour à la ligne après chaque rangée
    }
}

// Fonction principale
int main() {
    char **board;

    board = Mboard();  // Créer le plateau de jeu
    print_board(board);  // Imprimer le plateau de jeu

    // Libérer la mémoire allouée dynamiquement
    for (int i = 0; i < 6; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}
