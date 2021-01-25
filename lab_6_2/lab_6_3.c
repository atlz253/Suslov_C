#include <stdio.h>
#include <stdlib.h>

#define N 3

int main()
{
    int arr[N][N], i, j, min_i, min_j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("Введите элемент arr[%d][%d]: ", i, j);
            while (scanf("%d", &arr[i][j]) != 1)
            {
                while (getchar() != '\n');
                printf("Ошибка ввода!\nВведите элемент arr[%d][%d]: ", i, j);
            }
        }
    }
    
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == 0 && j == 0 || arr[i][j] > 0 && arr[i][j] < arr[min_i][min_j])
            {
                min_i = i;
                min_j = j;
            }
        }
    }

    if (arr[min_i][min_j] > 0 && min_i == min_j)
        printf("Минимальный положительный элемент %d лежит на главной диагонали\n", arr[min_i][min_j]);
    else
        printf("Минимальный положительный элемент %d не лежит на главной диагонали\n", arr[min_i][min_j]);

    return 0;
}
