#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>
/**
 * hash_table_set - sets a key to a value in the hash table
 * @ht: hash table to add element to
 * @key: key for the data
 * @value: data to store
 *
 * Return: 1 if successful, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *hash_node = NULL, *tmp = NULL;
	char *new_value;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(tmp->value);
			tmp->value = new_value;
			return (1);
		}
		tmp = tmp->next;
	}
	hash_node = malloc(sizeof(hash_node_t));
	if (hash_node == NULL)
		return (0);

	hash_node->key = strdup(key);
	hash_node->value = strdup(value);
	if (hash_node->key == NULL || hash_node->value == NULL)
	{
		free(hash_node->key);
		free(hash_node->value);
		free(hash_node);
		return (0);
	}

	hash_node->next = ht->array[index];
	ht->array[index] = hash_node;

	return (1);
}
