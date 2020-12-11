#include <stdio.h>
#include <stdlib.h>

FILE *f;
char buffer[100];

int open(FILE **file, char path[]) {
    if ((*file = fopen(path, "r+"))==NULL) {
        printf("Не удалось открыть файл!\n");
        getchar();
        return 0;
    }
    else {
        return 1;
    }
}


void close() {
    if (f != NULL) {
        printf("Файл закрыт!\n");
        fclose(f);
    }
}


int main()
{
    if (open(&f, "test.txt")) {
        fgets(buffer, 127, f);
        printf("%s", buffer);
        close();
    }
    else {
        printf("Не удалось открыть файл!\n");
        getchar();
        return 0;
    }

    return 0;
}
