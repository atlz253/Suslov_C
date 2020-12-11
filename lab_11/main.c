#include <stdio.h>
#include <stdlib.h>

FILE *f;

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
    if (open(f, "test.txt")) {

    }
    else {
        printf("Не удалось открыть файл!\n");
        getchar();
        return 0;
    }

    return 0;
}
