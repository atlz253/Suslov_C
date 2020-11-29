#include <stdio.h>
#include <stdlib.h>

int main()
{
    short int x;
    float e;

    printf("Введите x и точность: ");
    while (scanf("%hd %e", &x, &e)!=2) {
        while (getchar()!='\n');
        printf("Введены некорректные данные!\nВведите x и точность: ");
    }

    return 0;
}
