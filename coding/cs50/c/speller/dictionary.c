// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// 75000 buckets in hash table
enum {M = 75000};

// Hash table
node *table[M] = {NULL};

// Common words array
enum {C = 15};
char comn[C][5] =
{
    "the", "an", "and", "a", "to",
    "in", "is", "you", "that", "it",
    "i", "if", "of", "this", "or"
};

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int place = hash(word);
    node *comp = table[place];
    while (comp != NULL)
    {
        if (strcasecmp(comp->word, word) == 0)
        {
            return true;
        }
        comp = comp->next;
    }
    // Check if word is among the common words included
    for (int i = 0; i < C; i++)
    {
        if (strcasecmp(comn[i], word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // This hash function is an improvised version of the
    // djb2 hash function with 85% of the slots filled
    // with the large dictionary.
    unsigned int num = 173;
    for (int wrds = 0; word[wrds] != '\0'; wrds++)
    {
        num = num * 61 + tolower(word[wrds]);
    }
    num = (num + strlen(word)) % M;
    return num;
}

// Additional global variables
int dict_size = 0;
bool dict_load = false;

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *list = fopen(dictionary, "r");
    if (list == NULL)
    {
        return false;
    }
    char neno[LENGTH + 1];
    // Scan through the list reading each string to memory
    while (fscanf(list, "%s", neno) == 1)
    {
        dict_size++;
        unsigned int place = hash(neno);
        node *input = malloc(sizeof(node));
        if (input == NULL)
        {
            fclose(list);
            return false;
        }
        strcpy(input->word, neno);
        input->next = (table[place] == NULL) ? NULL : table[place];
        table[place] = input;
    }
    fclose(list);
    dict_load = true;
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (dict_load)
    {
        return dict_size;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *test = NULL;
    unsigned int a = 0;
    for (; a < M; a++)
    {
        while (table[a] != NULL)
        {
            test = table[a];
            table[a] = test->next;
            free(test);
        }
    }
    if (a == M)
    {
        return true;
    }
    return false;
}
