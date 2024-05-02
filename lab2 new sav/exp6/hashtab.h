#define HASHTAB_SIZE 200000
#include <inttypes.h>

struct listnode
{
    char *key;
    int value;
    struct listnode *next;
};

unsigned int hashtab_hash(char *key);
void hashtab_init(struct listnode **hashtab);
int hashtab_add(struct listnode **hashtab, char *key, uint32_t value);
struct listnode *hashtab_lookup(struct listnode **hashtab, char *key);
void hashtab_delete(struct listnode **hashtab, char *key);