
#include"hash table.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>



ht_t *create_ht(void)
{
    ht_t *ht = malloc(sizeof(ht_t) * 1);

    ht->ht_entries = malloc(sizeof(ht_entry_t) * TABLE_SIZE);

    int i;
    for(i = 0; i < TABLE_SIZE; i++)
    {
        ht->ht_entries[i] = NULL;
    }

    return ht;
}

int unsigned hash_function(const char *key)  // to be improved ?
{
    int unsigned long hash_value = 0;
    int i;

    for(i = 0; i < strlen(key); i++)
    {
        hash_value = hash_value * 37 + key[i];   // adding values of ASCI
    }

    hash_value = hash_value % TABLE_SIZE;

return hash_value;
}

ht_entry_t *create_ht_entry(const char *key, const char *content)
{
    //allocate new entry
    ht_entry_t *entry = malloc(sizeof(ht_entry_t) * 1);
    entry->key = malloc(strlen(key) + 1);
    entry->content = malloc(strlen(content) + 1);

    //set values
    strcpy(entry->key, key);
    strcpy(entry->content, content);
    entry->next_entry = NULL;

    return entry;
}

void set_ht_entry(ht_t *ht, const char *key, const char *content)
{
    unsigned int slot = hash_function(key);
    ht_entry_t *entry = ht->ht_entries[slot];      // initial address is the first element in this slot

    if(entry == NULL)    // slot empty, create new entry
    {
        ht->ht_entries[slot] = create_ht_entry(key, content);
        return;     // new entry created, exit function
    }

    ht_entry_t *previous;

    while(entry != NULL)
    {
        if(strcmp(entry->key, key) == 0)    // key match
        {
            free(entry->content);
            entry->content = malloc(strlen(content) + 1);
            strcpy(entry->content, content);
            return;     // existing entry updated
        }

        previous = entry;
        entry = entry->next_entry;  // go to next
    }

    previous->next_entry = create_ht_entry(key, content); // new entry created (new element of linked list)
}

char *get_ht_entry(ht_t *ht, const char *key)
{
    unsigned int slot = hash_function(key);
    ht_entry_t *entry = ht->ht_entries[slot];

    if(entry == NULL)
    {
        return NULL;
    }

    while(entry != NULL)
    {
    if(strcmp(entry->key, key) == 0)
        {
            return entry->content;
        }

        entry = entry->next_entry;
    }

    return NULL;
}

void remove_ht_key(ht_t *ht, const char *key)
{
    unsigned int slot = hash_function(key);
    ht_entry_t *entry = ht->ht_entries[slot];

    if(entry == NULL)  return;

    if(strcmp(entry->key, key) == 0)        // key matched at position 0 of the slot
    {
        if(entry->next_entry == NULL)       // only one key
        {
            free(entry->key);
            free(entry->content);
            free(entry);
            ht->ht_entries[slot] = NULL;    // empty slot
            return;
        }

        else
        {
            free(entry->key);
            free(entry->content);
            ht->ht_entries[slot] = entry->next_entry;   // re-attach following entry
            free(entry);
            return;
        }
    }

    if(entry->next_entry != NULL) // unnecessary ???
    {
        ht_entry_t *previous = entry;

        entry = entry->next_entry;

        while(entry != NULL)
        {
            if(strcmp(entry->key, key) == 0)
            {
                free(entry->key);
                free(entry->content);

                if(entry->next_entry == NULL)
                    previous->next_entry = NULL;
                else
                    previous->next_entry = entry->next_entry;

                return;
            }

            entry = entry->next_entry;
        }
    }
}

// to print all elements of hash table
void preview_ht(ht_t *ht)
{
    int i;

    for(i = 0; i < TABLE_SIZE; i++)
    {
        ht_entry_t *entry = ht->ht_entries[i];

        if(ht->ht_entries[i] != NULL)       // check first entry in this slot
        {
            printf("ht_entries[%d] \n", i);
            printf(" key = %s  content = %s\n", entry->key, entry->content);

            int entry_number = 0;

            while(entry->next_entry != NULL)   // go through all elements of linked list
            {
                entry_number++;
                int i;

                for(i = 0; i < entry_number ; i++)  putchar(' ');  // just to improve readability
                entry = entry->next_entry;
                printf(" key = %s  content = %s\n", entry->key, entry->content);
            }

            printf("\n");
        }
    }
}
