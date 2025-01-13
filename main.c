#include <stdio.h>
#include <string.h>
#include "CSV.h"

int main() {
    char Nom[20];
    int choice1, choice;
    do {
        printf("Bonjour! Avant de commencer, veuillez saisir votre nom: ");
        scanf("%s", Nom);
    } while (strlen(Nom) == 0);

    int CFA = 1123;
    int t, M;
    do {
        printf("Êtes-vous un client ou faites-vous partie de l'administration ? \nSi client : 1 \nSi administration : 2 ");
        scanf("%d", &t);
        if (t == 2) {
            printf("Donnez le code d'administration : ");
            scanf("%d", &M);
            if (M == CFA) {
                printf("\nGestion de bibliothèque\n");
                printf("1. Ajouter un livre\n");
                printf("2. Modifier un livre\n");
                printf("3. Supprimer un livre\n");
                printf("4. Trier les livres\n");
                printf("5. Quitter\n");
                printf("Choisissez une option : ");
                scanf("%d", &choice1);
                switch (choice1) {
                    case 1:
                        add_book();
                        break;
                    case 2:
                        modify_book();
                        break;
                    case 3:
                        remove_book();
                        break;
                    case 4:
                        sort_books_by_title();
                        break;
                    case 5:
                        printf("Au revoir !\n");
                        exit(0);
                    default:
                        printf("Choix invalide\n");
                }
            }
        } else if (t == 1) {
            printf("\nGestion de bibliothèque pour un client :\n");
            printf("1. Afficher la liste des livres\n");
            printf("2. Rechercher un livre\n");
            printf("3. Louer un livre\n");
            printf("4. Trier les livres par prix\n");
            printf("5. Quitter\n");
            printf("Choisissez une option : ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    display_books();
                    break;
                case 2:
                    search_book();
                    break;
                case 3:
                    rent_book();
                    break;
                case 4:
                    sort_books_by_category();
                    break;
                case 5:
                    printf("Au revoir !\n");
                    exit(1);
                default:
                    printf("Choix invalide\n");
            }
        }
    } while (t != 1 && t != 2);

    return 0;
}
