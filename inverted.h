#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1
#define FILE_EMPTY -2

typedef struct file_node
{
    char filename[20];
    struct file_node *link;
} File_list;
typedef struct main_node
{
    int word_count;
    char file_name[20];
    struct main_node *link;
} Ltable;

typedef struct subnode
{
    int file_count;
    char word[15];
    Ltable *Tlink;
    struct subnode *link;
} Wlist;

int create_file_list(File_list **f_head, char *name);

void create_database(File_list *f_head, Wlist *head[]);

Wlist *read_datafile(File_list *file, Wlist *head[], char *filename);

int insert_at_last(Wlist **head, char *data, char *filename);

int update_linktable(Wlist **head, char *filename);

int update_wordcount(Wlist **head, char *file_name);

int print_wordcount(Wlist *head);

int search_database(Wlist *head, char *word);

void display_database(Wlist *head[]);

void save_database(Wlist *head[]);

void write_database_file(Wlist *head, FILE *databasefile, int index);

int update_database(Wlist *head[], File_list **f_head);

int isFileEmpty(char *filename);

void file_validation(File_list **f_head, char *argv[]);
