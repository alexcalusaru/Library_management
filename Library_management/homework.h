#ifndef HOMEWORK_H_INCLUDED
#define HOMEWORK_H_INCLUDED

struct BOOK
{
    char author[100];
    char title[100];
    struct BOOK *next;
};

void search_by_title(struct BOOK *head, char title_searched[]);
void search_by_author(struct BOOK *head, char author_searched[]);
void insert_book(struct BOOK *head, char new_book_title[], char new_book_author[]);
char *randstring(size_t length);

#endif // HOMEWORK_H_INCLUDED
