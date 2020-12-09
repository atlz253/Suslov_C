#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PART 0

#if PART == 0

int main()
{
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
    char c, *p, (*ps)[81], str[5][81] = {
        "ann likes apples a fox lives in the forest ben and ann are the best friends bear",
        "cows give milk cabbage salad is my favorite dish dogs hate cats ducks are walkin",
        "elephants are big and kind eight is my favorite number five mice live in the hou",
        "four books are in the bag girls are beautiful green crocodiles live in africa",
        "horses are strong ham is useful kate likes reading keys are on the table"
    };

    do {
        printf("Введите английскую букву в нижнем регистре: ");
        while (scanf("%c", &c)!=1) {
            while (getchar()!='\n');
            printf("Введены неверные данные!\nВведите английскую букву в нижнем регистре: ");
        }
        if(c<97||c>122) printf("Введенная буква не является английской в нижнем регистре!\n");
        while (getchar()!='\n');
    } while (c<97||c>122);

    printf("\nИсходный массив\n");
    for (ps=str;ps<str+5;ps++) {
        puts(*ps);
    }

    printf("\nРезультат\n");
    for (ps=str;ps<str+5;ps++) {
        for(p=*ps;p<*ps+81;p++) {
            if (*p==c&&*(p-1)==' '||p==*ps&&*p==c) {
                do {
                    printf("%c", *p);
                    p++;
                } while (*p!=' '&&*p!='\0');
                putchar(' ');
            }
        }
        putchar('\n');
    }

    return 0;
}

#endif