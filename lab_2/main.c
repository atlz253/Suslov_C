#include <stdio.h>
#include <stdlib.h>

#define MODE 2

int main()
{
    #if MODE == 0 // Ввод/вывод целых чисел
        int default_int;
        short int short_int;
        long int long_int;
        unsigned int unsigned_int;
        unsigned short int us_short_int;
        unsigned long int us_long_int;

        printf("int: ");
        scanf("%i", &default_int);
        printf("\tdefault int: %i", default_int);

        printf("\nshort int: ");
        scanf("%hd", &short_int);
        printf("\tshort int: %hd", short_int);

        printf("\nlong int: ");
        scanf("%ld", &long_int);
        printf("\tlong int: %ld", long_int);

        printf("\nunsigned int: ");
        scanf("%lu", &unsigned_int);
        printf("\tunsigned int: %lu", unsigned_int);

        printf("\nunsigned short int: ");
        scanf("%hu", &us_short_int);
        printf("\tunsigned short int: %hu", us_short_int);

        printf("\nunsigned long int: ");
        scanf("%lu", &us_long_int);
        printf("\tunsigned long int: %lu", us_long_int);

        getchar();
    #elif MODE == 1 // Ввод/вывод вещественных чисел
        float default_float;
        double default_double;

        printf("\nfloat: ");
        scanf("%f", &default_float);
        printf("\tfloat: %f", default_float);

        printf("\ndouble: ");
        scanf("%lf", &default_double);
        printf("\tdouble: %lf", default_double);

        printf("\ne: ");
        scanf("%le", &default_double);
        printf("\te: %le", default_double);

        getchar();
    #elif MODE == 2 // Ввод/вывод символов
        char default_char;
        int integer;

        printf("\nEnter char: ");
        scanf("%c%*c", &default_char);
        printf("\tchar: %c", default_char);

        printf("\nEnter ASCII code (140 for KOI8-R): ");
        scanf("%i", &integer);
        printf("\tASCII: %c", integer);
    #elif MODE == 3 // 2 часть задания
        float i;
        short int j, k;

        printf("String (1.e23-459): ");
        scanf("%4f%*c%2hd%*c%1hd", &i, &j, &k);
        printf("\n╔═══╦══════════╗");
        printf("\n║ i ║ %.2e ║", i);
        printf("\n╠═══╬══════════╣");
        printf("\n║ j ║    %hd    ║", j);
        printf("\n╠═══╬══════════╣");
        printf("\n║ k ║    %#o   ║", k);
        printf("\n╚═══╩══════════╝\n");
        getchar();
    #endif // MODE
}
