#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    FILE *infile = fopen("data_shuffle_2.txt", "r");
    FILE *outfile = fopen("data_sh_c.txt", "w");

    if (infile == NULL || outfile == NULL)
    {
        printf("Error opening filesn");
        return 1;
    }

    // Считываем строки из файла в массив
    char lines[200000][10];
    int num_lines = 0;
    char line[100];
    while (fgets(line, sizeof(line), infile))
    {
        strcpy(lines[num_lines], line);
        num_lines++;
    }

    // Перемешиваем строки

    for (int k = 0; k < 15; k++)
    {
        srand(time(NULL));
        for (int i = num_lines - 1; i > 0; i--)
        {
            int j = rand() % (i + 1);
            char temp[100];
            strcpy(temp, lines[i]);
            strcpy(lines[i], lines[j]);
            strcpy(lines[j], temp);
        }
    }

    // Записываем перемешанные строки в файл
    for (int i = 0; i < num_lines; i++)
    {
        fprintf(outfile, "%s", lines[i]);
    }

    fclose(infile);
    fclose(outfile);

    return 0;
}
