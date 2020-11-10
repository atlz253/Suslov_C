#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PART 2

#if PART == 0

#define a 9
#define b 5

int main() {
    float x, y, c;

    printf("x input: ");
    scanf("%f", &x);

    if (x!=-1) {
        c = cos(b*x);
        if (c!=-1) {
            y = (a/(1+x) + cbrt(x)/2)/(1+c)*exp(x);
            printf("x=%.2f f=%.2f\n", x, y);
            getchar();
        }
        else {
            printf("cos(b*x) can't be equal -1\n");
            getchar();
        }
    }
    else {
        printf("x can't be equal -1\n");
        getchar();
    }

    return 0;
}

#elif PART == 1

int main() {
    float x, y;

    printf("x: ");
    scanf("%f", &x);

    x<0?(y=0):(x>=1?(y=x):(y=sqrt(x)));

    printf("x=%.2f f=%.2f\n", x, y);
    getchar();

    return 0;
}

#elif PART == 2

#define r 10
#define a 2

int main() {
    float x, y, c, p;

    printf("Enter x and y: ");
    scanf("%f %f", &x, &y);

    if (y==0 && x==0) {
        printf("Точка находится на оси x и y\n");
    }
    else if (y==0) {
        printf("Точка находится на оси x\n");
    }
    else if (x==0) {
        printf("Точка находится на оси y\n");
    }
    else if (x < 0 || y < 0) {
        printf("Точка находится вне области определения\n");
    }
    else {
        p = a*x*x;
        c = sqrt(x*x+y*y);
        if (c<r && p<y) {
            printf("Точка (%.2f,%.2f) находится в 1 области\n", x, y);
        }
        else if (c<r && p>y) {
            printf("Точка (%.2f,%.2f) находится во 2 области\n", x, y);
        }
        else if (c>r && p<y) {
            printf("Точка (%.2f,%.2f) находится в 3 области\n", x, y);
        }
        else if (c>r && p>y) {
            printf("Точка (%.2f,%.2f) находится в 4 области\n", x, y);
        }
        else {
            printf("Ошибка определения области\n");
        }
    }

    return 0;
}

#endif // PART



