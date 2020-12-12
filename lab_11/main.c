#include <stdio.h>
#include <stdlib.h>

FILE *f;

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


void close() { // TODO: передавать указатель на файл, который нужно закрыть
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

    for (p=arr;p<arr+lines;p++) {
        printf("%hd ", *p);
    }
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
