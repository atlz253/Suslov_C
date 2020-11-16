#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PART 0

#if PART == 0

int main()
{
    short int n, i;
    float result, a;

    do {
        printf("Введите натуральное число: ");
        while (scanf("%hd", &n)!=1) {
            while (getchar()!='\n');
            printf("Введены некорректные данные!\nВведите натуральное число: ");
        }
        if (n<0) printf("Введены некорректные данные! Число не является натуральным.\n");
    } while(n<0);

    for (i=1;i<=n;) {
        result += (float) i/++i;
    }

    printf("Результат: %.2f\n", result);

    return 0;
}

#elif PART == 1

int main() {
    unsigned short int i;
    unsigned long int n;

    printf("Введите натуральное число: ");
    scanf("%lu", &n);

    while (n!=0) {
        if (n%2==0) {
            i++;
        }
        n/=10;
    }
    
    printf("Четных цифр в записи числа: %hu\n", i);
    return 0;
}

#elif PART == 2

#define a 1.8
#define b 4.2

int main() {
    short int x_min, x_max, i;
    float x, y, c;

    do {
        printf("Введите x_min и x_max: ");
        while(scanf("%hd %hd", &x_min, &x_max)!=2) {
            while (getchar()!='\n');
            printf("Введены некорректные данные!\nВведите x_min и x_max: ");
        }
        if(x_min>x_max) printf("x_min>x_max\n");
    } while (x_min>x_max);

    for (i=x_min;i<=x_max;i++) {
        x = i;
        if (x==-1) {
            y=exp(fabsf(x));
        }
        else if (x<-1) {
            c = b*cos(x);
            if (c!=-1) {
                y=sin(a*x)/(1+c);
            }
            else {
                printf("b*cos(x)!=-1\n");
                return 0;
            }
        }
        else {
            if (fabsf(x-b)>1e-3) {
                y=(a+cbrt(x*x))/(b-x);
            }
            else {
                printf("x==b\n");
                return 0;
            }
        }

        

        if (i==x_min) {
            printf("\n╔═════╦═══════╗");
            printf("\n║  x  ║   f   ║");
            printf("\n╠═════╬═══════╣");
            printf("\n║ %3.0f ║ %5.2f ║", x, y);
            printf("\n╠═════╬═══════╣");
        }
        else if (i==x_max) {
            printf("\n║ %3.0f ║ %5.2f ║", x, y);
            printf("\n╚═════╩═══════╝\n");
        }
        else {
            printf("\n║ %3.0f ║ %5.2f ║", x, y);
            printf("\n╠═════╬═══════╣");
        }
    }

    return 0;
}

#endif // PART