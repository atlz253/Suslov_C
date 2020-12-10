#include <stdio.h>
#include <stdlib.h>

#define PART 1

#if PART == 0

#define Arrinput 1

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

#define N 5
#define M 6

int main()
{
    short int arr[N][M], (*ps)[M], *p;

    for (ps=arr;ps<arr+N;ps++) {
        for (p=*ps;p<*ps+M;p++) {
            printf("Введите элемент: ");
            while (scanf("%hd", p)!=1) {
                printf("Введены неверные данные!\nВведите элемент: ");
            }
            getchar();
        }
    }

    for (ps=arr;ps<arr+N;ps++) {
        for (p=*ps;p<*ps+M;p++) {
            printf("%hd ", *p);
        }
        putchar('\n');
    }
    return 0;
}

#elif PART == 2

int main()
{
    printf("Hello world!\n");
    return 0;
}

#endif