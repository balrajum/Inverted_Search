#include "inverted.h"
#include <string.h>

int insert_at_last(Wlist **head, char *data, char *filename)
{
    Wlist *new = malloc(sizeof(Wlist));

    if (new == NULL)
        return FAILURE;

    new->file_count = 1;
    strcpy(new->word, data);
    new->Tlink = NULL;
    new->link = NULL;

    update_linktable(&new, filename);

    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    Wlist *temp = *head;
    while (temp->link)
    {
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}

int update_linktable(Wlist **head, char *filename)
{
    Ltable *new = malloc(sizeof(Ltable));

    if (new == NULL)
    {
        return FAILURE;
    }

    new->word_count = 1;
    strcpy(new->file_name, filename);
    new->link = NULL;
}