#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 81


int open(FILE **file, char path[], char rights[]);
void close(FILE **file);
int func(char filename[]);


int main() {
    char filename[N];

    printf("Введите имя файла: ");
    gets(filename);

    return func(filename);
}


int open(FILE **file, char path[], char rights[]) 
{
    if ((*file = fopen(path, rights))==NULL) 
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}


void close(FILE **file) 
{
    if (*file != NULL) 
    {
        fclose(*file);
    }
}


int func(char filename[])
{
    FILE *f, *temp;
    char c;

    if (open(&temp, "_temp", "w") && open(&f, filename, "r")) {
        c = fgetc(f);
        while (!feof(f))
        {
            if (c != 'e' && c != 'y' && c != 'u' && c != 'i' && c != 'o' && c != 'a' && c != 'u' && c != 'E' && c != 'Y' && c != 'U' && c != 'I' && c != 'O' && c != 'A' && c != 'U')
                fputc(c, temp);
            
            c = fgetc(f);
        }

        close(&f);
        close(&temp);
        remove(f);
        rename("_temp", filename);
        printf("Гласные удалены и файл закрыт!\n");
        return 0;
    }
    else {
        printf("Не удалось открыть файл!\n");
        getchar();
        close(&temp);
        return 1;
    }
}