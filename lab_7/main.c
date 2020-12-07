#include <stdio.h>
#include <stdlib.h>

#define PART 1

#if PART == 0

int main()
{
    short int a, i;
    char str[81], result[81];

    printf("Введите строку (не более 80 символов): ");
    fgets(str, 81, stdin);

    for (i=0;i<81; i++) {
        if (str[i]==' '&&str[i-1]==' ') {
            a++;
            continue;
        }
        else {
            result[i-a] = str[i];
        }
    }

    printf("Исходная строка: ");
    puts(str);

    printf("Резултат: ");
    puts(result);

    return 0;
}

#elif PART == 1

int main()
{
    short int n, i;

    do {
        printf("Введите количество строк: ");
        while (scanf("%hd", &n)!=1) {
            while (getchar()!='\n');
            printf("Введены неверные данные!\nВведите количество строк: ");
        }
        if (n>6) printf("Максимальное количество строк - 6.\nВведите количество строк: ");
        if (n<1) printf("Минимальное количество строк - 1.\nВведите количество строк: ");
    } while(n>6||n<1);
    getchar();

    char str[n][81], result[n][81];

    for (i=0;i<n;i++) {
        printf("Введите строку %hd (не более 80 символов): ", i);
        //scanf("%80s", str[i]);
        fgets(str[i], 81, stdin);
    }

    for (i=0;i<n;i++) {
        puts(str[i]);
    }

    return 0;
}

#endif