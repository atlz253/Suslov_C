#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PART 1

#if PART == 0

int main()
{
    short int a, i;
    char str[81], result[81];

    do {
        for (i=0;i<81;str[i++]='\0');
        printf("Введите строку (не более 80 символов): ");
        gets(str);
        if (strlen(str)>=80&&str[81]!='\0') printf("Введено больше 80 символов!\n");
    } while (strlen(str)>=80&&str[81]!='\0');

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

    printf("Результат: ");
    puts(result);

    return 0;
}

#elif PART == 1

#define STANDARTFUNC 0

int main()
{
    short int n, i, j, s, maxl=0;

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
        #if STANDARTFUNC == 0
            do {
                for (j=0;j<81;str[i][j++]='\0');
                printf("Введите строку %hd (не более 80 символов): ", i);
                gets(str[i]);
                if (strlen(str[i])>=80&&str[i][81]!='\0') printf("Введено больше 80 символов!\n");
            } while (strlen(str[i])>=80&&str[i][81]!='\0');
        #elif STANDARTFUNC == 1
            printf("Введите строку %hd: ", i);
            scanf("%80s", str[i]);
            while (getchar()!='\n');
        #endif
        if (maxl<strlen(str[i])) maxl=strlen(str[i]);
    }

    printf("\nИзначальные строки\n");
    for (i=0;i<n;i++) {
        #if STANDARTFUNC == 0
            puts(str[i]);
        #elif STANDARTFUNC == 1
            printf("%s\n", str[i]);
        #endif
    }

    printf("\nСтроки \"по центру\"\n");
    for (i=0;i<n;i++) {
        s = (maxl-strlen(str[i]))/2;

        for (j=0;j<strlen(str[i])+s+1;j++) {
            if (j<s) {
                result[i][j] = ' ';
            }
            else {
                result[i][j] = str[i][j-s];
            }
        }

        #if STANDARTFUNC == 0
            puts(result[i]);
        #elif STANDARTFUNC == 1
            printf("%s\n", result[i]);
        #endif
    }

    return 0;
}

#endif