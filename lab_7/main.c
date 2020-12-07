#include <stdio.h>
#include <stdlib.h>

#define PART 0

#if PART == 0

int main()
{
    char str[81], result[81];

    printf("Введите строку (не более 80 символов): ");
    fgets(str, sizeof str, stdin);

    puts(str);

    return 0;
}

#elif PART == 1

#endif