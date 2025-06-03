"Inverted Search"

Inverted Search is a file-based indexing system that allows fast searching of words across multiple text files. It works like a mini search engine by building an index of all words found in the given files and mapping them to the files in which they appear.

This project is typically implemented in C using data structures like hash tables, linked lists, and file handling techniques.

Features
Indexes all unique words from multiple text files

Maps each word to the files in which it appears

Shows frequency of words per file

Supports search for a specific word

Uses hash table for efficient indexing

 How It Works:
Takes multiple .txt files as input (only .txt files)

Reads each word from the files

Stores each word into a hash table (using the first character as the hash index)

For each word, maintains a list of files and frequencies where it appears

Allows searching of words across all indexed files

Data Structures Used
Hash Table: For indexing words

Linked List: For storing word metadata and file occurrence list

Structures: To represent words, file data, and node connections
