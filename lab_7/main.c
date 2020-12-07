#include <stdio.h>
#include <stdlib.h>

#define PART 0

#if PART == 0

int main()
{
    short int a, i;
    char str[81], result[81];

    printf("Введите строку (не более 80 символов): ");
    fgets(str, sizeof str, stdin);

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

#endif