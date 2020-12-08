#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PART 0

#if PART == 0

int main()
{
    short int i;
    char str[81], *p;

    do {
        for (p=str;p<str+80;*p++='\0');
        printf("Введите строку (не более 80 символов): ");
        gets(str);
        if (strlen(str)>=81&&str[80]!='\0') printf("Введено больше 80 символов!\n");
    } while (strlen(str)>=81&&str[80]!='\0');
    
    for (p=str;p<str+80;p++) {
        if (*p<65&&*p!=0||*p>90&&*p!='_'&&*p<97||*p>122) {
            printf("Строку нельзя использовать в качестве идентификатора переменной из-за символа %c %d.\n", *p, *p);
            return 0;
        }
    }

    printf("Строку можно использовать в качестве идентификатора переменной\n");

    return 0;
}

#elif PART == 1

int main()
{
    printf("Hello world!\n");
    return 0;
}

#endif