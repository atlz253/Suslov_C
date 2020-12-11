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


void NegativeToTop(FILE **file) {
    unsigned short int lines=0;
    while (!feof(*file)) {
        if (fgetc(*file) == '\n') lines++;
    }
    fseek(*file, 0, SEEK_SET);

    fgets(buffer, 127, *file);
    printf("%s", buffer);
}


int main() {
    if (open(&f, "test.txt")) {
        NegativeToTop(&f);
        close();
    }
    else {
        printf("Не удалось открыть файл!\n");
        getchar();
        close();
        return 0;
    }

    return 0;
}
