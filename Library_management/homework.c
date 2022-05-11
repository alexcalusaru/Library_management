#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "homework.h"

void insert_book(struct BOOK *head, char new_book_title[], char new_book_author[])
{
    struct BOOK *new_book = malloc(sizeof(struct BOOK)); // we declare the new book of time BOOK
    strcpy(new_book->author, new_book_author);   // we store the new book author
    strcpy(new_book->title, new_book_title);   // we store the new book title
    new_book->next = head->next;  //we link our book to our list
    head->next = new_book;
}

void search_by_author(struct BOOK *head, char author_searched[])
{
    struct BOOK *iterator = head;   // we start with an iterator of time BOOK from the start of our list
    char author_found[100];
    char title[100];
    int title_found;
    title_found = 0;  // we set title_found to 1 if we find a match
    strcpy(author_found,author_searched);

    while(iterator->next != NULL)   // we are testing the whole list
    {
        if(strcmp(iterator->next->author,author_found)==0)  // we compare the authors
        {
            strcpy(title, iterator->next->title);   // we store the title in order to display it
            title_found = 1;
            printf("%s", title);
        }
        iterator = iterator->next;
    }
    if(title_found != 1)
       printf("not found");
}

void search_by_title(struct BOOK *head, char title_searched[])
{
    struct BOOK *iterator = head;   // we start with an iterator of time BOOK from the start of our list
    char title_found[100];
    char author[100];
    int author_found;
    author_found = 0;   // we set author_found to 1 if we find a match
    strcpy(title_found, title_searched);

    while(iterator->next != NULL)
    {
        if(strcmp(iterator->next->title, title_found)==0)    // we compare the titles
        {
            strcpy(author, iterator->next->author);   // we store the authors in order to display it
            author_found = 1;
            printf("%s", author);
        }
        iterator = iterator->next;
    }
    if(author_found != 1)
        printf("not found");
}

char *randstring(size_t length) {

    int n;
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *randomString = NULL;

    if (length) {
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString) {
            for (n = 0;n < length;n++) {
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[length] = '\0';
        }
    }

    return randomString;
}
