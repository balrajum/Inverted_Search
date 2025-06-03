#include "inverted.h"

void display_database(Wlist *head[])
{
    printf("\n Index     Word    file_count   file/s   File_name     word_count\n");

    for (int i = 0; i < 28; i++)
    {
        if (head[i] != NULL)
        {
            print_wordcount(head[i]);
        }
    }
}

int print_wordcount(Wlist *head)
{
    while (head != NULL)
    {
        int index = tolower(head->word[0]) % 97;

        if (!(index >= 0 && index <= 25))
        {
            index = 26;
        }
        printf("%d     \t%s    \t%d     file/s:", index, head->word, head->file_count);

        Ltable *Thead = head->Tlink;

        while (Thead)
        {
            printf("\tFile : %s \t %d", Thead->file_name, Thead->word_count);
            Thead = Thead->link;
        }
        printf("\n");
        head = head->link;
    }
    return 0;
}