#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DataInput 0 // макрос, чтобы не вводить a, b, eps

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

float f(float x) {
    return 3*sin(sqrt(x))+b*x-a;
}

void root(float *arr, float x_min, float x_max) {
    float (*fp)(float x), x_middle, y, n=0;
    fp = f;

    do {
        x_middle = (x_min+x_max)/2;
        if (fp(x_min)*fp(x_middle)<0) {
            x_max = x_middle;
        }
        else {
            x_min = x_middle;
        }
        n++;
    } while(fabs(f(x_middle))>eps);

    *arr = x_middle;
    *(arr+1) = n;
}

int main() {
    float result[2];

    #if DataInput == 1
        a = input(a, "Введите a: "); //TODO: убрать передачу переменной в функцию
        b = input(b, "Введите b: ");
        eps = input(eps, "Введите точность: ");
    #else
        a = 3.8;
        b = 0.35;
        eps = 10e-6;
    #endif

    root(result, 1, 3);

    print(result[0]);
    print(result[1]);

    return 0;
}
