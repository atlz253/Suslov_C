#include <stdio.h>
#include <stdlib.h>

void input(float num, char str[]) {
    printf("%s", str);
    while (scanf("%f", &num)!=1) {
        while(getchar()!='\n');
        printf("Неверные данные!\n%s", str);
    }
}

int main()
{
    float a, b, eps, i, y, x;
    input(a, "Введите a: ");
    input(b, "Введите b: ");
    input(eps, "Введите точность: ");

    for (i=0;i<3;i++) {

    }

    return 0;
}
