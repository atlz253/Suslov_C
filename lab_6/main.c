#include <stdio.h>
#include <stdlib.h>

#define PART 0

#if PART == 0

int main()
{
    unsigned short int n;
    printf("Введите кол-во элементов массива: ");
    while (scanf("%hu", &n)!=1) {
        while (getchar()!='\n');
        printf("Неверные данные! Введите кол-во элементов массива: ");
    }
}

#elif PART == 1

#elif PART == 2

#endif // PART