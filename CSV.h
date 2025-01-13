#ifndef CSV_H_INCLUDED
#define CSV_H_INCLUDED


   typedef struct {
    int id;
    char title[100];
    char author[100];
    char description[255];
    char username[100];
    float price;
    char category[50];
    int available;
} Book;

  void add_book();

  void modify_book();

  void remove_book();

  void sort_books_by_title();

  void sort_books_by_category();

  void display_books();

  void search_book();

  void rent_book();

#endif // CSV_H_INCLUDED
