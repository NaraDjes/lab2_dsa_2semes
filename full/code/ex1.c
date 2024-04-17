#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include "hashtab.h"
#include "bstree.h"
// #include <time.h>
#define MAX_WORDS 200000

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int main()
{
    /*
    char words[MAX_WORDS][10];
    FILE *file;
    int word_count = 0;
    file = fopen("data_ shuffle.txt", "r");
    while (fscanf(file, "%s", words[word_count]) == 1)
    {
        word_count++;
    }
    fclose(file);

    file = fopen("data_ex1.txt", "w");
    char str[100];

    struct bstree *tree = bstree_create(words[0], 0);

    struct listnode *node;
    struct listnode *hashtab[HASHTAB_SIZE];
    hashtab_init(hashtab);

    for (int i = 2; i <= MAX_WORDS; i++)
    {
        bstree_add(tree, words[i - 1], i - 1);
        hashtab_add(hashtab, words[i - 1], i - 1);
        if (i % 10000 == 0)
        {
            char w[10];
            strcpy(w, words[getrand(0, i - 1)]);

            double t1 = wtime();
            // clock_t start = clock();
            struct bstree *bs_node = bstree_lookup(tree, w);
            // clock_t end = clock();
            t1 = wtime() - t1;
            printf("Bstree n=%d; time = %lf\n", i, t1);

            double t2 = wtime();
            struct listnode *ht_node = hashtab_lookup(hashtab, w);
            t2 = wtime() - t2;
            // printf("%lf %lf\n", t2, t1);
            printf("Hashtab n=%d; time = %lf\n", i, t2);
            // printf("%s %s %d\n\n", w, ht_node->key, ht_node->value);

            snprintf(str, 100, "%d %lf %lf\n", i, t1, t2);
            fputs(str, file);
        }
    }*/
    // working
    char words[MAX_WORDS][10];
    FILE *file;
    int word_count = 0;
    file = fopen("dataA-Z.txt", "r");
    while (fscanf(file, "%s", words[word_count]) == 1)
    {
        word_count++;
    }
    fclose(file);

    file = fopen("data_ex1.txt", "w");
    char str[100];

    struct bstree *tree = bstree_create(words[0], 0);

    struct listnode *node;
    struct listnode *hashtab[HASHTAB_SIZE];
    hashtab_init(hashtab);

    for (int i = 2; i <= MAX_WORDS; i++)
    {
        bstree_add(tree, words[i - 1], i - 1);
        hashtab_add(hashtab, words[i - 1], i - 1);
        if (i % 10000 == 0)
        {
            char w[10];
            strcpy(w, words[getrand(0, i - 1)]);
            int k = 1;
            double t1 = wtime() * k;
            struct bstree *bs_node = bstree_lookup(tree, w);
            t1 = wtime() * k - t1;
            printf("Bstree n=%d; time = %.9lf\n", i, t1);

            double t2 = wtime() * k;
            struct listnode *ht_node = hashtab_lookup(hashtab, w);
            t2 = wtime() * k - t2;
            // printf("Node : %s, %d, hash=%d\n", ht_node->key, ht_node->value, hashtab_hash(w));
            printf("Hashtab n=%d; time = %.9lf\n\n", i, t2);

            snprintf(str, 100, "%d %.9lf %.9lf\n", i, t1, t2);
            fputs(str, file);
        }
    }
}