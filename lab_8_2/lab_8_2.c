#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 81
#define M 5

int main()
{
    int count = 0, len = 0;
    char **str, **ps, *p, *x, s = 0; 
    str = (char**) malloc(M * sizeof(char *));
    
    for (ps = str; ps != str + M; ps++)
        *ps = (char*) malloc(N * sizeof(char));

    strcpy(*str, "Sit eveniet excepturi sed deleniti sequi sed officiis");
    strcpy(*(str+1), "Voluptatem consequuntur aut rerum dolor ducimus eum ea sed");
    strcpy(*(str+2), "Quasi aut doloribus laboriosam tempore numquam aut accusantium");
    strcpy(*(str+3), "Quo similique fugiat magnam fugiat voluptate voluptatem occaecati quae");
    strcpy(*(str+4), "Tenetur harum et sit distinctio sunt sint aspernatur");

    printf("Введите символ для поиска: ");
    while (scanf("%c", &s) != 1)
    {
        while(getchar() != '\n');
        printf("Ошибка ввода!\nВведите символ для поиска: ");
    }

    for (ps = str; ps != str + M; ps++)
    {
        for (p = *ps; p != *ps + N; p++)
        {
            if (*p != ' ' && *p != '\0')
            {
                len++;

                if (*p == s)
                    count++;
            }
            else
            {
                if (count == 2)
                {
                    for (x = p - len; x != p; x++)
                        putchar(*x);
                    putchar(' ');
                }

                len = 0;
                count = 0;
            }
        }
        putchar('\n');
    }

    free(str);
    return 0;
}
