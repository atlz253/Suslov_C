#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float a, b, eps;

float input(float num, char str[]) {
    printf("%s", str);
    while (scanf("%f", &num)!=1) {
        while(getchar()!='\n');
        printf("Неверные данные!\n%s", str);
    }

    return num;
}

void print(float num) {
    printf("%f\n", num);
}

int main()
{
    a = input(a, "Введите a: ");
    b = input(b, "Введите b: ");
    eps = input(eps, "Введите точность: ");

    return 0;
}
