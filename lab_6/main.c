#include <stdio.h>
#include <stdlib.h>

#define PART 0

#if PART == 0

int main()
{
    unsigned short int n, i;
    printf("Введите кол-во элементов массива: ");
    while (scanf("%hu", &n)!=1) {
        while (getchar()!='\n');
        printf("Неверные данные! Введите кол-во элементов массива: ");
    }

    short int arr[n];
    for (i=0;i<n;i++) {
        printf("Введите значение %hd: ", i);
        while (scanf("%hd", &arr[i])!=1) {
            while (getchar()!='\n');
            printf("Неверные данные! Введите значение %hd: ", i);
        }
        while (getchar()!='\n');
    }
}

#elif PART == 1

#elif PART == 2

#endif // PART