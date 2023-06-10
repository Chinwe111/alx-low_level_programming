#include "hash_tables.h"
/**
 * shash_table_create - creates a hash table
 * @size: size of the array
 *
 * Return: pointer to the newly created hash table
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *shash_table = NULL;
	unsigned long int i;

	shash_table = malloc(sizeof(shash_table_t));
	if (shash_table == NULL)
		return (NULL);
	shash_table->size = size;
	shash_table->array = malloc(size * sizeof(shash_node_t *));
	if (shash_table->array == NULL)
	{
		free(shash_table);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		shash_table->array[i] = NULL;
	return (shash_table);
}

/**
 * shash_table_set - sets a key to a value in the hash table
 * @ht: hash table to add element to
 * @key: key for the data
 * @value: data to store
 *
 * Return: 1 if successful, 0 otherwise
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *shash_node = NULL, *tmp = NULL;
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
	shash_node = malloc(sizeof(shash_node_t));
	if (shash_node == NULL)
		return (0);

	shash_node->key = strdup(key);
	shash_node->value = strdup(value);
	if (shash_node->key == NULL || shash_node->value == NULL)
	{
		free(shash_node->key);
		free(shash_node->value);
		free(shash_node);
		return (0);
	}

	shash_node->next = ht->array[index];
	ht->array[index] = shash_node;

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: table to retrieve value from
 * @key: key to find value
 *
 * Return: value associated with key, or NULL if key cannot be found
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints hash table
 * @ht: hash table to print
 *
 * Return: void
 */

void shash_table_print(const shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *tmp;
	char flag = 0;

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->shead;
		while (tmp != NULL)
		{
			if (flag == 1)
				printf(", ");
			printf("'%s': '%s'", tmp->key, tmp->value);
			flag = 1;
			tmp = tmp->snext;
		}
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: hash table to print
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char flag = 0;

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	tmp = ht->stail;
	while (tmp != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		flag = 1;
		tmp = tmp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table to delete
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *tmp;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (i = 0; i < ht->size; i++)
	{
		while (ht->array[i] != NULL)
		{
			tmp = ht->array[i]->next;
			free(ht->array[i]->key);
			free(ht->array[i]->value);
			free(ht->array[i]);
			ht->array[i] = tmp;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
