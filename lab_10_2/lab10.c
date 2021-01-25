#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void input(char flag[], void *var, char message[]);
void print(float **arr, int M, int N);
void alg(float **arr, float (*func) (float x, float a, float b), int M, int N, float a, float b);
float f(float x, float a, float b);


int main(int argc, char *argv[])
{
    int M, N;
    float a, b;

    input("%d", &M, "Введите M: ");
    input("%d", &N, "Введите N: ");
    input("%f", &a, "Введите a: ");
    input("%f", &b, "Введите b: ");
    
    if (M <= 7)
    {
        float **arr, **ps, *p;
        arr = (float**) calloc(M, sizeof(float*));
        if (arr == NULL)
        {
            puts("Memory error!");
            return 1;
        }

        for (ps = arr; ps < arr + M; ps++)
        {
            *ps = (float*) calloc(N, sizeof(float));
            for (p = *ps; p < *ps + N; p++)
            {
                input("%f", p, "Введите элемент матрицы: ");
            }
        }

        puts("Исходная матрица");
        print(arr, M, N);

        alg(arr, f, M, N, a, b);

        puts("\nРезультат");
        print(arr, M, N);
    }
    else
    {
        puts("M <= 7");
    }

    return 0;
}


void input(char flag[], void *var, char message[])
{
    printf(message);
    var;
    while (scanf(flag, var) != 1)
    {
        while (getchar() != '\n');
        puts("Ошибка ввода!");
        printf(message);
    }
}


void print(float **arr, int M, int N)
{
    float **ps, *p;

    for (ps = arr; ps < arr + M; ps++)
    {
        for (p = *ps; p < *ps + N; p++)
        {
            printf("  %8.2f", *p);
        }
        putchar('\n');
    }
}


void alg(float **arr, float (*func) (float x, float a, float b), int M, int N, float a, float b)
{
    float **ps, *p, min, **mins;

    for (ps = arr; ps < arr + M; ps++)
    {
        for (p = *ps; p < *ps + N; p++)
        {
            *p = func(*p, a, b);
            if (*p < min || ps == arr && p == *ps)
            {
                min = *p;
                mins = ps;
            }
        }
    }

    p = *mins;
    *mins = *arr;
    *arr = p;
}


float f(float x, float a, float b)
{
    return sqrt(a + b * sin(x) * sin(x));
}
