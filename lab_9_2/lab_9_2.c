#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5
#define M 81


int f (char **arr, int num);


int main()
{
    char **arr, **ps;
    arr = (char**) calloc(N, sizeof(char*));
    if (arr == NULL)
    {
        puts("Memory error!");
        return 1;
    }

    for (ps = arr; ps != arr + N; ps++)
    {
        *ps = (char*) calloc(M, sizeof(char));
        printf("Введите строку: ");
        gets(*ps);
    }

    puts("Исходная строка");
    for (ps = arr; ps != arr + N; ps++)
    {
        puts(*ps);
    }

    printf("Количество слов: %d\n", f(arr, N));

    return 0;
}


int f (char **arr, int num)
{
    int words = 0;
    char **ps, *p;

    for (ps = arr; ps != arr + num; ps++)
    {
        p = strtok(*ps, " ,.-");
        
        while (p != NULL)
        {
            words++;
            p = strtok(NULL, " ,.-");
        }
    }

    return words;
}