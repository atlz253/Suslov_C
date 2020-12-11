#include <stdio.h>
#include <stdlib.h>

int open(FILE *file, char path[]) {
    if ((file = fopen(path, "r+"))==NULL) {
        return 0;
    }
    else {
        return 1;
    }
}

int main()
{
    FILE *file;

    if (open(file, "test.txt")) {

    }
    else {
        printf("Не удалось открыть файл!\n");
        getchar();
        return 0;
    }

    return 0;
}
