#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_BOOKS 100
static Book lib[MAX_BOOKS];
static int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("La bibliothèque est pleine.\n");
        return;
    }
    Book nb;
    printf("Entrez le titre du livre : ");
    scanf(" %s", nb.title);
    printf("Entrez l'auteur du livre : ");
    scanf(" %s", nb.author);
    printf("Entrez la description du livre : ");
    scanf(" %s", nb.description);
    printf("Entrez le nom d'utilisateur : ");
    scanf(" %s", nb.username);
    printf("Entrez le prix du livre : ");
    scanf("%f", &nb.price);
    printf("Entrez la catégorie du livre : ");
    scanf(" %s", nb.category);
    nb.available = 1;
    nb.id = book_count + 1;
    FILE *file = fopen("biblio.CSV", "a");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }
    fprintf(file, "%d,%s,%s,%s,%s,%.2f,%s,%d\n", nb.id, nb.title, nb.author, nb.description, nb.username, nb.price, nb.category, nb.available);
    fclose(file);

    lib[book_count++] = nb;
    printf("Livre ajouté avec succès.\n");
}

void modify_book() {
    int id;
    printf("Entrez l'ID du livre à modifier : ");
    scanf("%d", &id);
    if (id < 1 || id > book_count ) {
        printf("Livre non trouvé.\n");
        return;
    }
    int i = id - 1;
    printf("Modifier le titre (actuel : %s) : ", lib[i].title);
    scanf(" %s", lib[i].title);
    printf("Modifier l'auteur (actuel : %s) : ", lib[i].author);
    scanf(" %s", lib[i].author);
    printf("Modifier la description (actuel : %s) : ", lib[i].description);
    scanf(" %s", lib[i].description);
    printf("Modifier le nom d'utilisateur (actuel : %s) : ", lib[i].username);
    scanf(" %s", lib[i].username);
    printf("Modifier le prix (actuel : %.2f) : ", lib[i].price);
    scanf("%f", &lib[i].price);
    printf("Modifier la catégorie (actuel : %s) : ", lib[i].category);
    scanf(" %s", lib[i].category);
    printf("Livre modifié avec succès.\n");
}

void remove_book() {
    int id;
    printf("Entrez l'ID du livre à supprimer : ");
    scanf("%d", &id);
    if (id < 1 || id > book_count) {
        printf("Livre non trouvé.\n");
        return;
    }
    for (int i = id - 1; i < book_count - 1; i++) {
        lib[i] = lib[i + 1];
    }
    book_count--;
    printf("Livre supprimé avec succès.\n");
}

void sort_books_by_title() {
    for (int i = 0; i < book_count - 1; i++) {
        for (int j = i + 1; j < book_count; j++) {
            if (strcmp(lib[i].title, lib[j].title) > 0) {
                Book temp = lib[i];
                lib[i] = lib[j];
                lib[j] = temp;
            }
        }
    }
    printf("Livres triés par titre.\n");
}

void sort_books_by_category() {
    for (int i = 0; i < book_count - 1; i++) {
        for (int j = 0; j < book_count - i - 1; j++) {
            if (lib[j].category> lib[j + 1].category) {
                Book temp = lib[j];
                lib[j] = lib[j + 1];
                lib[j + 1] = temp;
            }
        }
    }
    printf("Livres triés par prix avec succès.\n");
}

void display_books() {
    if (book_count == 0) {
        printf("Aucun livre dans la bibliothèque.\n");
        return;
    }
    printf("Liste des livres dans la bibliothèque :\n");
    for (int i = 0; i < book_count; i++) {
        printf("ID: %d\n", lib[i].id);
        printf("Titre: %s\n", lib[i].title);
        printf("Auteur: %s\n", lib[i].author);
        printf("Description: %s\n", lib[i].description);
        printf("Nom d'utilisateur: %s\n", lib[i].username);
        printf("Prix: %.2f\n", lib[i].price);
        printf("Catégorie: %s\n", lib[i].category);
        printf("-----------------------------\n");
    }
}

void search_book() {
    char title[100];
    printf("\nDonnez le nom du livre à rechercher : ");
    scanf(" %99[^\n]", title);
    int found = 0;

    for (int i = 0; i < book_count; i++) {
        if (strcmp(lib[i].title, title) == 0) {
            printf("ID: %d\n", i + 1);
            printf("Titre: %s\n", lib[i].title);
            printf("Auteur: %s\n", lib[i].author);
            printf("Description: %s\n", lib[i].description);
            printf("Nom d'utilisateur: %s\n", lib[i].username);
            printf("Prix: %.2f\n", lib[i].price);
            printf("Catégorie: %s\n", lib[i].category);
            printf("-----------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Aucun livre trouvé avec le titre : %s\n", title);
    }
}

void rent_book() {
    char titre[ 30];
    printf("Entrez le titre du livre à louer : ");
    scanf(" %s", titre);

    for (int i = 0; i < book_count; i++) {
        if (strcmp(lib[i].title, titre) == 0) {
            if (!lib[i].available) {
                printf("Le livre %s est déjà loué.\n", lib[i].title);
            } else {
                printf("Vous avez loué le livre : %s\n", lib[i].title);
                lib[i].available = 0;
            }
            return;
        }
    }
    printf("Aucun livre trouvé avec le titre : %s\n", titre);
}
