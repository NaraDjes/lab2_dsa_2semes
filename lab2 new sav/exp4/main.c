#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"
#include <time.h>
#define MAX_WORDS 200000

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
    srand(time(NULL));
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int main()
{
    char words1[MAX_WORDS][10];
    FILE *file;
    int word1_count = 0;

    file = fopen("data_shuffle_2.txt", "r");
    while (fscanf(file, "%s", words1[word1_count]) == 1)
    {
        word1_count++;
    }
    fclose(file);


    char words2[MAX_WORDS][10];
    int word2_count = 0;
    file = fopen("dataZ-A.txt", "r");
    while (fscanf(file, "%s", words2[word2_count]) == 1)
    {
        word2_count++;
    }
    fclose(file);

    file = fopen("data_ex4.txt", "w");
    char str[100];

    struct bstree *tree1 = bstree_create(words1[0], 0);
    struct bstree *tree2 = bstree_create(words2[0], 0);

    for (int i = 2; i <= MAX_WORDS; i++)
    {
        bstree_add(tree1, words1[i - 1], i - 1);
        bstree_add(tree2, words2[i - 1], i - 1);
        if (i % 10000 == 0)
        {
            double t1 = wtime();
            struct bstree *bs_node1 = bstree_min(tree1);
            t1 = wtime() - t1;
            printf("Bstree1 n=%d; time = %.11lf\n", i, t1);
            printf("min =%s\n", bs_node1->key);

            double t2 = wtime();
            struct bstree *bs_node2 = bstree_min(tree2);
            t2 = wtime() - t2;
            printf("Bstree2 n=%d; time = %.11lf\n", i, t2);
            printf("min =%s\n\n", bs_node2->key);

            snprintf(str, 100, "%d %.11lf %.11lf\n", i, t1, t2);
            fputs(str, file);
        }
    }
}