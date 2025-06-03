#include "inverted.h"

void save_database(Wlist *head[])
{
    int i;
    char file_name[15];

    printf("Enter the file name to save in database:");
    scanf("%s", file_name);

    FILE *fptr = fopen(file_name, "w");

    for (int i = 0; i < 28; i++)
    {
        if (head[i] != NULL)
        {
            write_database_file(head[i], fptr, i);
        }
    }
    printf("Saved\n");
}

void write_database_file(Wlist *head, FILE *databasefile, int index)
{
    while (head)
    {
        fprintf(databasefile, "%d \n word : %s\t filecount : %d", index, head->word, head->file_count);

        Ltable *Thead = head->link;

        while (Thead)
        {
            fprintf(databasefile, "filename: %s\twordcount: %d", Thead->file_name, Thead->word_count);
            Thead = Thead->link;
        }
        fprintf(databasefile, "\n");
        head = head->link;
    }
}