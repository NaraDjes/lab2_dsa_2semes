#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include "hashtab.h"
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
    char words[MAX_WORDS][10];
    FILE *file;
    int word_count = 0;

    file = fopen("dataA-Z.txt", "r");
    while (fscanf(file, "%s", words[word_count]) == 1)
    {
        word_count++;
    }
    fclose(file);

    file = fopen("data_ex6_add.txt", "w");
    char str[100];

    struct listnode *hashtab[HASHTAB_SIZE];
    hashtab_init(hashtab);
    int colission_count = 0;
    for (int i = 2; i <= MAX_WORDS; i++)
    {
        colission_count += hashtab_add(hashtab, words[i - 1], i - 1);
        if (i % 10000 == 0)
        {
            char w[10];
            strcpy(w, words[getrand(0, i - 1)]);

            double t1 = wtime();
            hashtab_lookup(hashtab, w);
            t1 = wtime() - t1;
            printf("Hashtab n=%d; time = %.20lf, colission_count = %d\n\n", i, t1, colission_count);

            snprintf(str, 100, "%d %.9lf %d\n", i, t1, colission_count);
            fputs(str, file);
        }
    }
}