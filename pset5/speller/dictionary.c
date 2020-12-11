// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1024 * 10;

// Hash table
node *table[N];

int total_size = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int h = hash(word);
    node *head = table[h];
    while (head) {
        if (!strcasecmp(head->word, word)) {
            return true;
        }
        head = head->next;
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    for(; *word; word++) {
        sum += tolower(*word);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    char buffer[LENGTH + 1];
    while (fscanf(file, "%s", buffer) != EOF) { // fscanf遇到空格和换行时结束，注意空格时也结束。这与fgets有区别，fgets遇到空格不结束 
    // while (!feof(file)) {
    //     if (fgets(buffer,LENGTH + 1,file) != NULL)
    	{
    	    node *n = calloc(1, sizeof(node));
    	    strcpy(n->word, buffer);
    	    total_size++;
    	    int h = hash(buffer);
    	    n->next = table[h];
    	    table[h] = n;
    	}
    }
   
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return total_size;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++) {
        node *head = table[i];
        if (head != NULL) {
            node *next = NULL;
            do {
                next = head->next;
                free(head);
                head = next;
            } while (head != NULL);
        }
    }
    return true;
}
