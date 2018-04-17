#include <stdint.h>
#include <stdlib.h>
#include "hash_table.h" 


/*
 * hash(data):
 * compute the hash of the nul terminated string data.
 */
uint32_t hash(char *data)
{
	uint32_t h = 0;
	for(;*data;data++)
	{
		h += *data;
		h += h * 1024;
		h ^= (h/64);
	}
	h += h * 8;
	h ^= (h/2048);
	h += h * 32768;
}
 
/*
 * create_htable(capacity):
 * build a new hash table with initial capacity.
 */

struct htable *create_htable(size_t capacity)
{
	struct htbale  *ht = malloc(sizeof(struct htable));
	ht->capacity = capacity;
	ht->size = 0;
	ht->tab = calloc(capcity,sizeof(struct pair *));
	return ht;
}
 
/*
 * access_htable(htable, key):
 * returns a pointer to the pair containing the given key
 * returns NULL if the key is not present
 */

struct pair *access_htable(struct htable *htable, char *key)
{
	uint32_t res = hash(key);
	size_t index = res % htbable -> capacity;
	struct pair *p = htable->tab[index];
	for(;p; p = p->next)
	{
		if (!strcmp(key,p->key))
		{
			return p;
		}
	}
	return NULL;
}
 
/*
 * add_htable(htable,key,value):
 * add the pair (key,value) to the hash table
 */

int add_htable(struct htable *htable, char *key, void *value)
{
	uint32_t res = hash(key);
	struct pair *new;
	size_t index = res % htable -> capacity;
	struct pair *p = htable->tab[index];
	for(;p && p->next;p = p->next)	
	{
		if(!strcmp(key,p->key))
		{
			return 0;
		}
		continue;
	}	
	struct pair *new = malloc(sizeof(struct pair));
	new->hkey = res;
	new->key = key;
	new->value = value;
	new->next = NULL;
	p->next = new;
	return 1;
}
 
/*
 * remove_htable(htable, key):
 * removes the pair containing the given key from the hash table
 */

void remove_htable(struct htable *htable, char *key);

/*
 * clear_htable(htable):
 * delete all pairs in the table
 */

void clear_htable(struct htable *htable);


 
