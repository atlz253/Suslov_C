#include <stdio.h>
#include <stdlib.h>

#define PART 2

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
    unsigned long int n, i, j, tmp;
    printf("Введите кол-во элементов массива: ");
    while (scanf("%lu", &n)!=1) {
        while (getchar()!='\n');
        printf("Неверные данные! Введите кол-во элементов массива: ");
    }

    int arr[n];
    for (i=0;i<n;arr[i++]=random()%9999);

    printf("Исходный массив: ");
    for (i=0;i<n;printf("%d ", arr[i++]));

    for (i=n-1;i>0;i--) {
        for (j=0;j<i;j++) {
            if (arr[j]>arr[j+1]) {
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    printf("\nРезультат: ");
    for (i=0;i<n;printf("%d ", arr[i++]));

    return 0;
}

#elif PART == 2

#define DEBUG 0

int main()
{
    unsigned short int m, n;
    #if DEBUG == 0
        m = 8;
        n = 10;
    #elif DEBUG == 1
        printf("Введите M N: ");
        while (scanf("%hu %hu", &m, &n)!=2) {
            while (getchar()!='\n');
            printf("Неверные данные! Введите M N: ");
        }
    #endif // DEBUG
    unsigned short int i, j, a[m][n];

    for (i=0;i<m;i++) {
        for (j=0;j<n;j++) {
            #if DEBUG == 0
                a[i][j] = random()%120;
            #elif DEBUG == 1
                printf("Введите значение A[%hd][%hd]: ", i, j);
                while (scanf("%hd", &a[i][j])!=1) {
                    while (getchar()!='\n');
                    printf("Неверные данные! Введите значение A[%hd][%hd]: ", i, j);
                }
            #endif // DEBUG
        }
    }

    for (i=0;i<m;i++) { 
        printf("[");
        for (j=0;j<n;j++) {
            printf("%3.hd", a[i][j]);
            if (j!=n-1) printf(" ");
        }
        printf("]\n");
    }

    return 0;
}

#undef DEBUG
#endif // PART