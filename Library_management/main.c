#include <stdio.h>
#include <stdlib.h>
#include "homework.h"
#include <string.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // different seed every compilation

    struct BOOK *head = malloc(sizeof(struct BOOK));
    head->next = NULL;

    FILE *file_out = fopen("data_out","w");

    int i;
    for(i=0; i<20;i++){ //20 books
    char new_author[100],new_title[100];
    strcpy(new_author,randstring(6));//6 letters word
    strcpy(new_title,randstring(7));// 7 letters word
    fprintf(file_out,"Author:%s ", new_author);
    fprintf(file_out,"Title:%s \n", new_title);
    fprintf(file_out,"\n");
    insert_book(head,new_title,new_author);
    }

    //first author and title
    printf("Title:");
    search_by_author(head, head->next->author);
    printf("\nAuthor:");
    search_by_title(head, head->next->title);



    free(head);

    fclose(file_out);
    return 0;
}
