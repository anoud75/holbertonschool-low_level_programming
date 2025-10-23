# 0x1A. C - Hash tables

This project implements hash tables in C using chaining for collision resolution.

## Description
A hash table is a data structure that provides fast lookup, insertion, and deletion of key-value pairs using a hash function to compute an index into an array of buckets.

## Files
- `hash_tables.h` - Header file with structures and function prototypes
- `0-hash_table_create.c` - Creates a hash table
- `1-djb2.c` - Hash function (djb2 algorithm)
- `2-key_index.c` - Returns the index of a key
- `3-hash_table_set.c` - Adds or updates an element in the hash table
- `4-hash_table_get.c` - Retrieves a value associated with a key
- `5-hash_table_print.c` - Prints a hash table
- `6-hash_table_delete.c` - Deletes a hash table

## Compilation
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hash_tables
```

## Hash Function
Uses the djb2 algorithm, a simple and effective hash function.

## Collision Handling
Uses chaining - each bucket contains a linked list of nodes.

## Author
Alanoud
