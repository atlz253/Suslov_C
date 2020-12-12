#include <stdio.h>
#include <stdlib.h>

FILE *f;

int open(FILE **file, char path[], char rights[]) {
    if ((*file = fopen(path, rights))==NULL) {
        printf("Не удалось открыть файл!\n");
        getchar();
        return 0;
    }
    else {
        return 1;
    }
}


void close(FILE **file) { // TODO: передавать указатель на файл, который нужно закрыть
    if (*file != NULL) {
        fclose(*file);
    }
}


void NegativeToTop(FILE **file) {
    unsigned short int lines=0;
    while (!feof(*file)) {
        if (fgetc(*file) == '\n') lines++;
    }
    fseek(*file, 0, SEEK_SET);

    short int arr[lines], *pp=arr, *p, tmp;

    for (p=arr;p<arr+lines;p++) {
        fscanf(*file, "%hd", p);
        if (*pp<0&&*p>0) pp = p;

        if (*p<0&&*pp>0) {
            tmp = *pp;
            *pp = *p;
            *p = tmp;
            pp++;
        }
    }
    close(&f);

    if (open(&(*file), "test.txt", "w")) {
        for (p=arr;p<arr+lines;p++) {
            fprintf(*file, "%hd\n", *p);
        }
    }
    else {
        printf("Не удалось открыть файл!\n");
        getchar();
        close(&f);
    }
}


int main() {
    if (open(&f, "test.txt", "r")) {
        NegativeToTop(&f);
        close(&f);
        printf("Файл закрыт!\n");
    }
    else {
        printf("Не удалось открыть файл!\n");
        getchar();
        close(&f);
        return 0;
    }

    return 0;
}
