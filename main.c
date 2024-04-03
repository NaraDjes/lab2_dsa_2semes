#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hashtab.h"
#include "bstree.h"


void print_hashtab(listnode **hashtab, size_t size);

int main()
{
    srand(time(NULL));
    int n = 200000;

    int cur_size = 200000;

    listnode *hashtabKR[cur_size];
    listnode *hashtabJenk[cur_size];

    //bstree *bstree;

    FILE *file = fopen("words.txt", "r");
    char words[n][11];

    for(int i = 0; i < 200000; i++)
    {
        fscanf(file ,"%s", words[i]);
    }

    hashtab_init(hashtabKR, cur_size);
    hashtab_add(hashtabKR, words[0], 0, cur_size);
    hashtab_init(hashtabJenk, cur_size);
    hashtab_add(hashtabJenk, words[0], 0, cur_size);

    //bstree = bstree_create(words[0], 0);

    int i = 1;
    for (n = 10000; n <= 200000; n += 10000)
    {
        for (; i < n; i++)
        {
            hashtab_add(hashtabKR, words[i], i, cur_size);
            hashtab_addJenk(hashtabJenk, words[i], i, cur_size);

            //bstree_add(bstree, words[i], i);
        }

        char *find = words[rand()%n];
        struct timespec t1, t2;
        clock_gettime(CLOCK_REALTIME, &t1);

        listnode *KR = hashtab_lookup(hashtabKR, find, cur_size);

        //double begin = clock();
        //struct Bstree *nodebst = bstree_lookup(bstree, find);
        //double end = clock();
        clock_gettime(CLOCK_REALTIME, &t2);
        
        //print_hashtab(hashtabKR, cur_size);
        
        int k = hashtab_collisionKR(hashtabKR, find, cur_size);

        double t = 1000000000*(t2.tv_sec - t1.tv_sec)+(t2.tv_nsec - t1.tv_nsec);
        //double time = (long double)(end - begin) / CLOCKS_PER_SEC;

        printf("hashtabKR lookup #%d : %.9f nsec, k = %d\n", n/10000, t/1000000000, k);

        clock_gettime(CLOCK_REALTIME, &t1);
        // begin = clock();
        listnode *Jenk = hashtab_lookupJenk(hashtabJenk, find, cur_size);
        // end = clock();
        clock_gettime(CLOCK_REALTIME, &t2);
        k = hashtab_collisionJenk(hashtabJenk, find, cur_size);

        t = 1000000000*(t2.tv_sec - t1.tv_sec)+(t2.tv_nsec - t1.tv_nsec);
        printf("hashtabJenk lookup #%d : %.9f nsec, k = %d\n\n", n/10000, t/1000000000, k);

    }

    fclose(file);

    return 0;
}
