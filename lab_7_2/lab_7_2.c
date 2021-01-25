#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 81
#define M 6

int main()
{
    char str[M][N];
    int i, j, count, max;

    for (i = 0; i < M; i++)
    {
        do {
            printf("Введите строку (не более 80 символов): ");
            gets(str[i]);
            if (strlen(str[i]) >= N && str[i][N - 1] != '\0') 
                printf("Введено больше 80 символов!\n");
        } while (strlen(str[i]) >= N && str[i][N - 1] != '\0');
    }
    
    for (i = 0; i < M; i++)
    {
        for (j = 0, count = 0; j < N; j++)
        {
            if (str[i][j] == '\0')
                break;
            else
                count++;
        }

        if (i == 0 || count > max)
            max = count;
    }

    putchar('\n');
    for (i = 0; i < M; i++)
    {
        count = max - strlen(str[i]);
        for (j = strlen(str[i]) + count; j >= 0; j--)
        {
            str[i][j] = str[i][j - count];
            if (j < count)
                str[i][j] = ' ';
        }
        puts(str[i]);
    }

    return 0;
}
