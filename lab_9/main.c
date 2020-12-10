#include <stdio.h>
#include <stdlib.h>

#define PART 2


#if PART == 0
#define Arrinput 1 // макрос, чтобы не вводить массив вручную

#define N 10

void NumDel(short int *arr, short int num) {
    short int *p, i=0;

    for (p=arr;p<arr+N;p++) {
        if (*p==num) {
            i+=1;
            *p=*(p+1);
        }
        else {
            *(p-i)=*p;
        }
    }

    for (p=arr+N;p>arr+N-i-1;p--) {
        *p=0;
    }
}

int main()
{
    #if Arrinput == 1
        short int arr[N], *p, num;

        for (p=arr;p<arr+N;p++) {
            printf("Введите элемент: ");
            while (scanf("%hd", p)!=1) {
                while (getchar()!='\n');
                printf("Введены неверные данные!\nВведите элемент: ");
            }
        }
        getchar();
    #else
        short int *p, num, arr[10]={1, 2, 3, 2, 4, 5, 6, 7, 2, 9};
    #endif

    printf("Введите число: ");
    while (scanf("%hd", &num)!=1) {
        while (getchar()!='\n');
        printf("Введены неверные данные!\nВведите число: ");
    }

    printf("Исходный массив: ");
    for (p=arr;p<arr+N;p++) {
        printf("%hd ", *p);
    }

    NumDel(arr, num);

    printf("\nРезультат: ");
    for (p=arr;p<arr+N;p++) {
        printf("%hd ", *p);
    }
    putchar('\n');

    return 0;
}

#undef N
#undef Arrinput


#elif PART == 1
#define Arrinput 0 // макрос, чтобы не вводить матрицу вручную

#define N 5
#define M 6

void LastNegativeToZero(short int (*arr)[M]) {
    short int (*ps)[M], *p;

    for (ps=arr;ps<arr+N;ps++) { 
        for (p=*ps+M-1;p>*ps;p--) { 
            if (*p<0) {
                *p = 0;
                break;
            }
        }
    }
}

int main()
{
    #if Arrinput == 1
        short int arr[N][M], (*ps)[M], *p;

        for (ps=arr;ps<arr+N;ps++) {
            for (p=*ps;p<*ps+M;p++) {
                printf("Введите элемент: ");
                while (scanf("%hd", p)!=1) {
                    while (getchar()!='\n');
                    printf("Введены неверные данные!\nВведите элемент: ");
                }
                getchar();
            }
        }
    #else
        short int (*ps)[M], *p, arr[5][6] = {
            {1, 2, 3, 4, 5, 6},
            {-1, -2, -3, -4, -5, -6},
            {1, -3, 5, 6, 7, -10},
            {-3, 10, 5, -8, 7, 20},
            {1, -3, 5, 6, 7, 10}
        };
    #endif

    printf("\nИсходная матрица\n");
    for (ps=arr;ps<arr+N;ps++) {
        for (p=*ps;p<*ps+M;p++) {
            printf("%5hd", *p);
        }
        putchar('\n');
    }

    LastNegativeToZero(arr);

    printf("\nРезультат\n");
    for (ps=arr;ps<arr+N;ps++) {
        for (p=*ps;p<*ps+M;p++) {
            printf("%5hd", *p);
        }
        putchar('\n');
    }
    return 0;
}

#undef Arrinput
#undef N
#undef M


#elif PART == 2
#define Arrinput 0 // макрос, чтобы не вводить матрицу вручную

#define N 5
#define M 6

void LastNegativeToZero(short int arr[N][M]) {
    short int i, j;

    for (i=0;i<N;i++) {
        for (j=M-1;j>0;j--) { 
            if (arr[i][j]<0) {
                arr[i][j] = 0;
                break;
            }
        }
    }
}

int main()
{
    #if Arrinput == 1
        short int arr[N][M], i, j;

        for (i=0;i<N-1;i++) {
            for (j=0;j<M-1;j++) {
                printf("Введите элемент: ");
                while (scanf("%hd", &arr[i][j])!=1) {
                    while (getchar()!='\n');
                    printf("Введены неверные данные!\nВведите элемент: ");
                }
                getchar();
            }
        }
    #else
        short int i, j, arr[5][6] = {
            {1, 2, 3, 4, 5, 6},
            {-1, -2, -3, -4, -5, -6},
            {1, -3, 5, 6, 7, -10},
            {-3, 10, 5, -8, 7, 20},
            {1, -3, 5, 6, 7, 10}
        };
    #endif

    printf("\nИсходная матрица\n");
    for (i=0;i<N;i++) {
        for (j=0;j<M;j++) {
            printf("%5hd", arr[i][j]);
        }
        putchar('\n');
    }

    LastNegativeToZero(arr);

    printf("\nРезультат\n");
    for (i=0;i<N;i++) {
        for (j=0;j<M;j++) {
            printf("%5hd", arr[i][j]);
        }
        putchar('\n');
    }
    return 0;
}

#endif