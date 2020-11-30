#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    short int n=0;
    float e, x, a=1, sum=a;

    printf("Введите x и точность: ");
    while (scanf("%f %e", &x, &e)!=2) {
        while (getchar()!='\n');
        printf("Введены некорректные данные!\nВведите x и точность: ");
    }

    while (fabs(a)>e) {
        printf ("n=%d\t a=%lf\t sum=%.5f\n",n,a,sum);
        n++;
        a*=(-(n+1)*x*x)/(2*n*n*(2*n+1));
        sum+=a;
    }
    printf ("n=%d\t a=%lf\t sum=%.5f\n",n,a,sum);
    return 0;
}
