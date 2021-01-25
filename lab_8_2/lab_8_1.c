#include <stdio.h>
#include <stdlib.h>

#define N 6

int main()
{
    float *arr, *p, *pp, tmp;
    arr = (float*) calloc(N, sizeof(float));
    if (arr == NULL)
    {
        puts("Memory error!");
        return 1;
    }

    for (p = arr; p != arr + N; p++)
    {
        printf("Введите элемент: ");
        while (scanf("%f", p) != 1)
        {
            while (getchar() != '\n');
            printf("Ошибка ввода!\nВведите элемент: ");
        }
    }

    puts("Исходный массив");
    for (p = arr; p != arr + N; p++)
    {
        printf("%8.2f", *p);
    }

    for (p = arr; p != arr + N / 2 - 1; p++)
    {
        for (pp = arr + N / 2 - 1; pp != p; pp--)
        {
            if (*(pp - 1) > *pp)
            {
                tmp = *(pp - 1);
                *(pp - 1) = *pp;
                *pp = tmp;
            }
        }
    }

    for (p = arr + N / 2; p != arr + N - 1; p++)
    {
        for (pp = arr + N - 1; pp != p; pp--)
        {
            if (*(pp - 1) < *pp)
            {
                tmp = *(pp - 1);
                *(pp - 1) = *pp;
                *pp = tmp;
            }
        }
    }

    puts("\n\nРезультат");
    for (p = arr; p != arr + N; p++)
    {
        printf("%8.2f", *p);
    }

    free(arr);
    return 0;
}
