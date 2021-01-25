#include <stdio.h>
#include <stdlib.h>

#define N 15

int main()
{
    int arr[N], i, max;
    
    for (i = 0; i < N; i++)
    {
        printf("Введите элемент arr[%d]: ", i);
        while (scanf("%d", &arr[i]) != 1)
        {
            while (getchar() != '\n');
            printf("Ошибка ввода!\nВведите элемент arr[%d]: ", i);
        }
    }

    for (i = 0, max = 0; i < N; i++)
    {
        if (max < arr[i] && arr[i] % 3 == 0)
            max = arr[i];
    }

    if (max != 0)
        printf("Максимальное число, которое делится на 3: %d", max);
    else
        puts("В массиве нет чисел, которые делятся на 3");

    return 0;
}
