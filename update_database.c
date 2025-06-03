#include "inverted.h"
#include <string.h>

int update_database(Wlist *head[], File_list **f_head)
{
    char file_name[15];
    printf("Enter the new file\n");
    scanf("%s", file_name);

    int empty = isFileEmpty(file_name);

    if (empty == FAILURE)
    {
        printf("File is not available");
        return 0;
    }
    else if (empty == FILE_EMPTY)
    {
        printf("No content in the file\n");
        return 0;
    }
    else
    {
        int ret = create_file_list(f_head, file_name);
        if (ret == SUCCESS)
        {
            printf("Successfully inserted\n");
            *f_head = (*f_head)->link;
        }
        else if (ret == FAILURE)
        {
            printf("file already existed\n");
            return 0;
        }
        else
            return FAILURE;
    }
    while (*f_head)
    {
        if (!strcmp((*f_head)->filename, file_name))
        {
            create_database(*f_head, head);
        }
        *f_head = (*f_head)->link;
    }
}