#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fptr;
    char path[100];
    int i, j, len, index, Unique;
    char words[30][50];
    char word[50], str[50];
    int count[30];
    fptr = fopen("file1.txt", "r");
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        exit(1);
    }
    for (i = 0; i < 30; i++)
    {
        count[i] = 0;
    }
    index = 0;
    while (fscanf(fptr, "%s", word) != EOF)
    {
        strlwr(word);
        Unique = 1;
        for (i = 0; i < index && Unique; i++)
        {
            if (strcmp(words[i], word) == 0)
                Unique = 0;
        }
        if (Unique)
        {
            strcpy(words[index], word);
            count[index]++;
            index++;
        }
        else
        {
            count[i - 1]++;
        }
    }
    fclose(fptr);
    printf("\nOccurrences of all distinct words in file: \n");
    for (i = 30; i > 0; i--)
    {
        for (j = 0; j < index; j++)
        {
            if (count[j] == i)
                printf("\n%s => %d\n", words[j], count[j]);
        }
    }
    return 0;
}
