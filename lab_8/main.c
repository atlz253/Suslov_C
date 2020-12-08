#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PART 1

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
        if (*p<48&&*p!=0||*p>=48&&p==str&&*p<=57||*p>57&&*p<65||*p>90&&*p!='_'&&*p<97||*p>122) {
            printf("Строку нельзя использовать в качестве идентификатора переменной из-за символа %c.\n", *p);
            return 0;
        }
    }

    printf("Строку можно использовать в качестве идентификатора переменной\n");

    return 0;
}

#elif PART == 1

int main()
{
    char c, str[5][81] = {
        "sit eveniet excepturi sed deleniti sequi sed officiis excepturi.",
        "soluptatem consequuntur aut rerum dolor ducimus eum ea sed.",
        "suasi aut doloribus laboriosam tempore numquam aut accusantium.",
        "suo similique fugiat magnam fugiat voluptate voluptatem occaecati quae.",
        "senetur harum et sit distinctio sunt sint aspernatur."
    };

    printf("Введите символ, который для поиска: ");
    while (scanf("%c", &c)!=1) {
        while (getchar()!='\n');
        printf("Введены неверные данные!\nВведите символ, который для поиска: ");
    }

    return 0;
}

#endif