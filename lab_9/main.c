#include <stdio.h>
#include <stdlib.h>

#define PART 0

#if PART == 0

#define N 10

int main()
{
    short int arr[N], *p;

    for (p=arr;p<arr+N;p++) {
        printf("Введите элемент: ");
        while (scanf("%hd", p)!=1) {
            printf("Введены неверные данные!\nВведите элемент: ");
        }
    }

    printf("\nИсходный массив: ");
    for (p=arr;p<arr+N;p++) {
        printf("%hd ", *p);
    }

    printf("\nРезультат: ");
    for (p=arr;p<arr+N;p++) {
        printf("%hd ", *p);
    }
    putchar('\n');

    return 0;
}

#elif PART == 1

int main()
{
    printf("Hello world!\n");
    return 0;
}

#elif PART == 2

int main()
{
    printf("Hello world!\n");
    return 0;
}

#endif