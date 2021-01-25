#include <stdio.h>
#include <stdlib.h>


int f(int *arr, int size, int num, int add);


int N = 5;


int main()
{
    int *arr, *p, num, add;
    arr = (int*) calloc(N, sizeof(int));
    if (arr == NULL)
    {
        puts("Memory error!");
        return 1;
    }

    for (p = arr; p != arr + N; p++)
    {
        printf("Введите элемент массива: ");
        while (scanf("%d", p) != 1)
        {
            while (getchar() != '\n');
            printf("Ошибка ввода!\nВведите элемент массива: ");
        }
    }

    printf("Введите число: ");
    while (scanf("%d", &num) != 1)
    {
        while (getchar() != '\n');
        printf("Ошибка ввода!\nВведите число: ");
    }

    do
    {
        printf("Введите адрес: ");
        while (scanf("%d", &add) != 1)
        {
            while (getchar() != '\n');
            printf("Ошибка ввода!\nВведите адрес: ");
        }
        if (add < 0 || add > N)
            puts("Неверный адрес!");
    } while (add < 0 || add > N);

    puts("Исходный массив");
    for (p = arr; p != arr + N; p++)
    {
        printf("   %d", *p);
    }

    N = f(arr, N, num, add);

    puts("\n\nРезультат");
    for (p = arr; p != arr + N; p++)
    {
        printf("   %d", *p);
    }

    free(arr);
    return 0;
}


int f(int *arr, int size, int num, int add)
{
    int *p;
    size++;
    arr = (int*) realloc(arr, sizeof(int)*size);

    putchar('\n');
    for (p = arr + size - 2; p != arr + add - 1; p--)
    {
        *(p + 1) = *p;
    }
    *(arr + add) = num;

    return size;
}