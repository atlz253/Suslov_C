#include <stdio.h>
#include <stdlib.h>

#define PART 1

#if PART == 0

int main()
{
    unsigned short int n, i;
    printf("Введите кол-во элементов массива: ");
    while (scanf("%hu", &n)!=1) {
        while (getchar()!='\n');
        printf("Неверные данные! Введите кол-во элементов массива: ");
    }

    short int arr[n], min=0;
    for (i=0;i<n;i++) {
        printf("Введите значение %hd: ", i);
        while (scanf("%hd", &arr[i])!=1) {
            while (getchar()!='\n');
            printf("Неверные данные! Введите значение %hd: ", i);
        }

        if (arr[min]<0&&arr[i]<0&&arr[i]>arr[min]||arr[min]>=0) {
            min=i;
        }
    }

    if (arr[min]<0) {
        printf("Исходный массив: ");
        for (i=0;i<n;printf("%d ", arr[i++]));

        printf("\nРезультат: ");
        for (i=0;i<n;i++) {
            if (i==min||arr[min]==arr[i]) continue;
            printf("%d ", arr[i]);
        }
    }
    else {
        printf("В массиве нет отрицательных чисел!\n");
    }

    return 0;
}

#elif PART == 1

int main()
{
    unsigned long int n, i;
    printf("Введите кол-во элементов массива: ");
    while (scanf("%lu", &n)!=1) {
        while (getchar()!='\n');
        printf("Неверные данные! Введите кол-во элементов массива: ");
    }

    int arr[n];
    for (i=0;i<n;arr[i++]=random()%9999);
    
    printf("Исходный массив: ");
    for (i=0;i<n;printf("%d ", arr[i++]));
    return 0;
}

#elif PART == 2

#endif // PART