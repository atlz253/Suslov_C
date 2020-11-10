#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PART 2

#if PART == 0

int main()
{
    unsigned short int n, i;
    float result, a;

    printf("Введите натуральное число: ");
    scanf("%hu", &n);

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

    printf("Введите x_min и x_max: ");
    scanf("%hu %hu", &x_min, &x_max);

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
            printf("\n╔════╦═══════╗");
            printf("\n║   x   ║   f   ║");
            printf("\n╠════╬═══════╣");
            printf("\n║ %2.0f ║ %5.2f ║", x, y);
            printf("\n╠════╬═══════╣");
        }
        else if (i==x_max) {
            printf("\n║ %2.0f ║ %5.2f ║", x, y);
            printf("\n╚════╩═══════╝\n");
        }
        else {
            printf("\n║ %2.0f ║ %5.2f ║", x, y);
            printf("\n╠════╬═══════╣");
        }
    }

    return 0;
}

#endif // PART