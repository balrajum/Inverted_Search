#include "inverted.h"
#include <string.h>

int search_database(Wlist *head, char *word)
{
    if (head == NULL)
    {
        printf("List Empty\n");
        return FAILURE;
    }

    while (head)
    {
        if (!strcmp(head->word, word))
        {
            printf("Word is in %d file/s\n", word, head->file_count);

            Ltable *Thead = head->Tlink;
            while (Thead)
            {
                printf("In file: %s\t%d times\n", Thead->file_name, Thead->word_count);
                Thead = Thead->link;
            }
            printf("\n");
            return 0;
        }
        head = head->link;
    }
    printf("Search word is not in the lsit\n");
}