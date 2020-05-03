#ifndef HASH_TABLE_H_INCLUDED
#define HASH_TABLE_H_INCLUDED

#define TABLE_SIZE 3    // set to 3 to test conflict resolution

typedef struct ht_entry_t
{
    char *key;
    char *content;
    struct ht_entry_t *next_entry;

}ht_entry_t;

typedef struct ht_t
{
    ht_entry_t **ht_entries;    // pointer to (first) pointer to ht_entry type
}ht_t;

ht_t *create_ht(void);
int unsigned hash_function(const char *key);
ht_entry_t *create_ht_entry(const char *key, const char *content);
void set_ht_entry(ht_t *ht, const char *key, const char *content);
char *get_ht_entry(ht_t *ht, const char *key);
void remove_ht_key(ht_t *ht, const char *key);
void preview_ht(ht_t *ht);

#endif // HASH_TABLE_H_INCLUDED
