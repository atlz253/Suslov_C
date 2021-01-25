#include <stdio.h>
#include <stdlib.h>

#define N 20

int main()
{
    int arr[N], i, j, imax, x;

    for (i = 0; i < N; i++)
    {
        printf("Введите элемент arr[%d]: ", i);
        while (scanf("%d", &arr[i]) != 1)
        {
            while (getchar() != '\n');
            printf("Ошибка ввода!\nВведите элемент arr[%d]: ", i);
        }
    }

    puts("Исходный массив");
    for (i = 0; i < N; i++)
        printf("   %d", arr[i]);
    putchar('\n');

    for (i = 0; i < N; i++)
    {
        for (j = i + 1, imax = i; j < N; j++)
            if (arr[imax] < arr[j])
                imax = j;

        x = arr[imax];
        arr[imax] = arr[i];
        arr[i] = x;
    }

    puts("Результат");
    for (i = 0; i < N; i++)
        printf("   %d", arr[i]);
    putchar('\n');
    
    return 0;
}
