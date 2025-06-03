#include "inverted.h"
#include <string.h>
void create_database(File_list *f_head, Wlist *head[])
{
    while (f_head)
    {
        read_datafile(f_head, head, f_head->filename);
        f_head = f_head->link;
    }
}

Wlist *read_datafile(File_list *file, Wlist *head[], char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        perror("Error openning file");
        return NULL;
    }

    char word[10];

    while (fscanf(fptr, "%s", word) != EOF)
    {
        int index = tolower(word[0]) % 97;

        if (!(index >= 0 && index <= 25))
        {
            index = 26;
        }
        int flag = 1;
        if (head[index] != NULL)
        {
            Wlist *temp = head[index];

            while (temp)
            {
                if (!strcmp(temp->word, word))
                {
                    update_wordcount(&temp, filename);
                    flag = 0;
                    break;
                }
                temp = temp->link;
            }
        }
        if (flag)
        {
            insert_at_last(&head[index], word, filename);
        }
    }
    fclose(fptr);
    return NULL;
}

int update_wordcount(Wlist **head, char *file_name)
{
    if (!strcmp(file_name, (*head)->Tlink->file_name))
    {
        (*head)->Tlink->word_count += 1;
    }
    else
    {
        (*head)->file_count += 1;

        Ltable *new = malloc(sizeof(Ltable));
        if (new = NULL)
        {
            return FAILURE;
        }
        strcpy(new->file_name, file_name);
        new->word_count = 1;
        new->link = NULL;

        Ltable *current = (*head)->Tlink;

        while (current->link != NULL)
        {
            current = current->link;
        }
        current->link = new;
    }
    return SUCCESS;
}