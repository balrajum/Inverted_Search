#include "inverted.h"

int main(int argc, char *argv[])
{
  Wlist *head[28]; // = NULL;

  if (argc <= 1)
  {
    printf("Invaid arguments Enter arguments like:-\n");
    printf("./Slist.exe <file1.txt> <file2.txt> <....>\n");
    return 0;
  }

  File_list *f_head = NULL;

  file_validation(&f_head, argv);
  int i = 1;
  while (i)
  {
    printf("Slect your operation:\n");
    printf(" 1. Create database\n 2.Display database \n 3. Update database\n 4. Search database\n 5. Save database\n 6.exit\n ");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
      create_database(f_head, head);
    }
    break;
    case 2:
    {
      display_database(head);
    }
    break;
    case 3:
    {
      update_database(head, f_head);
    }
    break;
    case 4:
    {
      char word[15];
      printf("\nEnter the word to search: ");
      scanf("%[^\n]", word);
      search_database(head[tolower(word[0]) % 97], word);
    }
    break;
    case 5:
      save_database(head);
      break;
    case 6:
      printf("Exit\n");
      i = 0;
      break;
    default:
      printf("Invalid operation. Please select in above options.\n");
      break;
    }
  }
  return 0;
}