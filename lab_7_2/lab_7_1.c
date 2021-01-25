#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 81

int main()
{
    char str[N];
    int i, count = 0, len;

    do {
        printf("Введите строку (не более 80 символов): ");
        gets(str);
        if (strlen(str) >= 81 && str[80] != '\0') 
            printf("Введено больше 80 символов!\n");
    } while (strlen(str) >= 81 && str[80] != '\0');

    for (i = 0; i < N; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            count++;
        else if (str[i] == '\0')
            break;
    }

    if (count % 2 == 0)
    {
        printf("В строке четное количество цифр: %d\n", count);
    }
    else
    {
        len = strlen(str);

        if (len % 2 == 0)
            len = len / 2;
        else
            len = len / 2 + 1;
        
        for (i = len; i < N; i++)
        {
            str[i - 1] = str[i];
            if (str[i] == '\0')
                break;
        }

        printf("В строке нечетное количество цифр: %d\nИзмененная строка: %s\n", count, str);
    }
        

    return 0;
}
