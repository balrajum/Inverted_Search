#include "inverted.h"

void file_validation(File_list **f_head, char *argv[])
{
    int i = 1, flag;
    while (argv[i] != NULL)
    {
        if (flag == FILE_EMPTY)
        {
            printf("FILE: %s is not having any content\n", argv[i]);
            i++;
            continue;
        }
        else
        {
            int res = create_file_list(f_head, argv[i]);
            if (res == SUCCESS)
            {
                printf("Inserted the file into list");
            }
        }
    }
}