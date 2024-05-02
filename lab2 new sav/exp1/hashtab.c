#include "hashtab.h"
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned int hashtab_hash(char *s)
{
    unsigned int h = 0;
    while (*s)
        h += (unsigned int)*s++;
    return h % HASHTAB_SIZE;
}

void hashtab_init(struct listnode **hashtab)
{
    int i;

    for (i = 0; i < HASHTAB_SIZE; i++)
        hashtab[i] = NULL;
}

int hashtab_add(struct listnode **hashtab, char *key, uint32_t value)
{
    struct listnode *node;

    int index = hashtab_hash(key);
    node = malloc(sizeof(*node));
    int f = 0;
    if (node != NULL)
    {
        node->key = key;
        node->value = value;
        node->next = hashtab[index];
        if (hashtab[index] != NULL)
            f = 1;
        hashtab[index] = node;
    }
    return f;
}

struct listnode *hashtab_lookup(struct listnode **hashtab, char *key)
{
    struct listnode *node;

    int index = hashtab_hash(key);
    for (node = hashtab[index]; node != NULL; node = node->next)
    {
        if (0 == strcmp(node->key, key))
            return node;
    }
    return NULL;
}

void hashtab_delete(struct listnode **hashtab, char *key)
{
    struct listnode *node, *prev = NULL;
    int index = hashtab_hash(key);
    for (node = hashtab[index]; node != NULL; node = node->next)
    {
        if (0 == strcmp(node->key, key))
        {
            if (prev == NULL)
                hashtab[index] = node->next;
            else
                prev->next = node->next;
            free(node);
            return;
        }
        prev = node;
    }
}