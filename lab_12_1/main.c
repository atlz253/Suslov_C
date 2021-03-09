/*
Дан файл, содержащий сведения об ассортименте игрушек в магазине. Структура записи: название игрушки, цена, количество,
возрастные границы, например от 2 до 5. Вывести названия игрушек, которые подходят детям определенного возраста и стоят
не больше определенной суммы. Получить сведения о самом дорогом конструкторе.

создание файла ✓
просмотр содержимого файла ✓
добавление ✓
удаление ✓
корректировка данных ✓
выполнение запросов в соответствии с заданием. ✓
Поиск требуемых данных осуществлять по ключевому полю. ✓
Для организации интерфейса должно использоваться меню. ✓
Имена входных файлов должны передаваться программе при ее запуске (через параметры функции main()). ✓
Если параметры пользователем при запуске программы не заданы, имена файлов вводятся с клавиатуры. ✓
Вывод содержимого файла записей осуществлять постранично в табличном виде с графлением визуально подходящими символами, предусмотреть возможность «листания» страниц как в прямом, так и в обратном направлении. ✓
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TABLE_TOP "╔══════════════════════════════════════════╦════════╦════════╦════════════╦════════════╗\n║ Название игрушки                         ║ Цена   ║ Кол-во ║ Возраст от ║ Возраст до ║"
#define TABLE_CONNECT "╠══════════════════════════════════════════╬════════╬════════╬════════════╬════════════╣"
#define TABLE_DATA "║ %s%*s║ %-7g║ %-7d║ %-11d║ %-11d║\n"
#define TABLE_BOTTOM "╚══════════════════════════════════════════╩════════╩════════╩════════════╩════════════╝"
#define CLEAR_CONSOLE 1


#if defined(_WIN64) || defined(_WIN32)
    #include <windows.h>
    #define CLEAR if(CLEAR_CONSOLE) system("cls")
#elif defined(__linux)
    #define CLEAR if(CLEAR_CONSOLE) system("clear")
#endif


#define N 81
#define TOY_PAGE 10


int Menu();
int Open(FILE **file, char path[], char rights[]);
void Close(FILE **file);
int StrPadding(char str[], int space);
void FileView();
void Input(char flag[], void *a, char message[]);
void GetString(char str[N], char message[]);
void AddData();
void CreateFilef();
void ToySearch();
void MaxConstructor();
void ToyDelete();
void ToyEdit();


struct toy {
    char name[N];
    double price;
    int quantity;
    int age_min;
    int age_max;
};


char filename[N];


int main(int argc, char *argv[]) {
    #if defined(_WIN64) || defined(_WIN32)
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
    #endif

    CLEAR;
    if (argc == 2) {
        strcpy(filename, argv[1]);
    }
    else if (argc == 1) {
        GetString(filename, "Введите имя файла: ");
    }
    else
    {
        printf("Слишком много аргументов!\n");
        return -1;
    }

    return Menu();
}


int Menu() {
    int choice;

    do {
        CLEAR;
        puts("1. Создание файла");
        puts("2. Добавление данных");
        puts("3. Просмотр содержимого файла");
        puts("4. Поиск игрушки");
        puts("5. Сведения о самом дорогом конструкторе");
        puts("6. Удаление данных");
        puts("7. Редактирование данных");
        puts("0. Завершить программу\n");

        printf("Введите пункт меню: ");
        while (!scanf("%d", &choice)) {
            printf("Введены неверные данные!\nВведите пункт меню: ");
            while(getchar() != '\n');
        }

        switch (choice) {
        case 1:
            CreateFilef();
            break;
        case 2:
            AddData();
            break;
        case 3:
            FileView();
            break;
        case 4:
            ToySearch();
            break;
        case 5:
            MaxConstructor();
            break;
        case 6:
            ToyDelete();
            break;
        case 7:
            ToyEdit();
            break;
        case 0:
            CLEAR;
            break;
        default:
            puts("Введен неверный пункт меню!");
        }

    } while (choice < 0 || choice > 7 || choice);

    return 0;
}


int Open(FILE **file, char path[], char rights[]) {
    if ((*file = fopen(path, rights)) == NULL) {
        CLEAR;
        printf("Ошибка открытия файла!\n");
        getchar();
        return 0;
    }
    else {
        return 1;
    }
}


void Close(FILE **file) {
    if (*file != NULL) {
        fclose(*file);
    }
}


int StrPadding(char str[], int n) {
    /*
        Русские буквы занимают в строке 2 байта, а ASCII 1 байт
    */
    int i;

    for(i=0; i<N; i++) {
        if(str[i] == '\0')
            break;
        else if(str[i] < 0)
            i++;

        n--;
    }

    return n;
}


void FileView() {
    CLEAR;
    FILE *f;
    if(Open(&f, filename, "rb")) {
        int count, pages_num, i, j;
        struct toy current;
        char choice;

        fseek(f, 0, SEEK_END);
        count = ftell(f)/sizeof(struct toy);
        pages_num = count/TOY_PAGE + 1;
        while(count >= TOY_PAGE)
            count = count - TOY_PAGE;
        fseek(f, 0, SEEK_SET);

        for (i=0;i<pages_num;i++) {
            CLEAR;
            puts(TABLE_TOP);
            
            if(i+1==pages_num&&count==0)
                break;
            
            for (j=0;j<TOY_PAGE;j++) {
                fread(&current, sizeof(struct toy), 1, f);
                if(feof(f))
                    break;

                puts(TABLE_CONNECT);
                printf(TABLE_DATA, current.name, StrPadding(current.name, 41), " ", current.price, current.quantity, current.age_min, current.age_max);
            }
            puts(TABLE_BOTTOM);
            printf("<--j   q-выход   l-->\n");

            do {
                printf("Ввод: ");
                while(getchar() != '\n');
                while (!scanf("%c", &choice)) {
                    printf("Ошибка ввода!\nВвод: ");
                    while(getchar() != '\n');
                }

                if(choice != 'j' && choice != 'q' && choice != 'l') printf("Неизвестная команда!\n");
            } while(choice != 'j' && choice != 'q' && choice != 'l');

            if(choice == 'j') {
                if(i == 0)
                    break;
                else if(i+1 == pages_num)
                    fseek(f, -sizeof(struct toy)*(count+TOY_PAGE), SEEK_CUR);
                else
                    fseek(f, -sizeof(struct toy)*TOY_PAGE*2, SEEK_CUR);

                i -= 2;
            }
            else if (choice == 'q') {
                break;
            }
        }

        Close(&f);
    }
}


void Input(char flag[], void *a, char message[]) {
    printf(message);
    while (!scanf(flag, a)) {
        puts("Неверные данные!");
        puts(message);
        while (getchar()!='\n');
    }
    getchar();
}


void GetString(char str[N], char message[]) {
    int i;

    printf(message);
    fgets(str, N, stdin);
    for (i = 0; i < N; i++)
    {
        if(str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
    }
}


void AddData() {
    CLEAR;
    FILE *f;
    if(Open(&f, filename, "ab")) {
        struct toy new;
        getchar();

        GetString(new.name, "Введите название игрушки: ");        

        Input("%lf", &new.price, "Введите цену: ");
        Input("%d", &new.quantity, "Введите количество: ");
        Input("%d", &new.age_min, "Введите минимальный возраст: ");
        Input("%d", &new.age_max, "Введите максимальный возраст: ");

        fwrite(&new, sizeof(struct toy), 1, f);
        printf("Запись завершена!\n");
        Close(&f);
    }
}


void CreateFilef() {
    FILE *f;
    if(Open(&f, filename, "w")) {
        printf("Файл создан!\n");
        Close(&f);
    }
}


void ToySearch() {
    CLEAR;
    int age;
    double price;
    struct toy current;

    do {
        printf("Введите возраст и цену: ");
        while(scanf("%d%lf", &age, &price) != 2) {
            while(getchar() != '\n');
            printf("Ошибка ввода!\nВведите возраст и цену: ");
        }
        if(age < 0 || price < 0)
            printf("Введено отрицательное значение!\n");
    } while(age < 0 || price < 0);
    while(getchar() != '\n');

    FILE *f;
    if(Open(&f, filename, "rb")) {
        puts(TABLE_TOP);
        while(!feof(f)) {
            fread(&current, sizeof(struct toy), 1, f);
            if(feof(f))
                break;

            if(current.age_min <= age && current.age_max >= age && current.price <= price) {
                puts(TABLE_CONNECT);
                printf(TABLE_DATA, current.name, StrPadding(current.name, 41), " ", current.price, current.quantity, current.age_min, current.age_max);
            }

        }
        puts(TABLE_BOTTOM);
    }

    printf("Для продолжения нажмите любую клавишу...");
    getchar();
}


void MaxConstructor() {
    CLEAR;
    int i;
    FILE *f;
    if(Open(&f, filename, "rb")) {
        double max_price=0;
        struct toy current;

        fread(&current, sizeof(struct toy), 1, f);
        while(!feof(f)) {
            for(i=0; i<N; i++) {
                if(current.name[i] == -48 && current.name[i+1] == -102 && current.name[i+20] == -47 && current.name[i+21] == -128 && max_price < current.price) { // Проверка 2 байт 'К' и 'р'
                    max_price = current.price;
                }
            }

            fread(&current, sizeof(struct toy), 1, f);
        }
        fseek(f, 0, SEEK_SET);

        fread(&current, sizeof(struct toy), 1, f);
        while(!feof(f)) {
            for(i=0; i<N; i++) {
                if(current.name[i] == -48 && current.name[i+1] == -102 && current.name[i+20] == -47 && current.name[i+21] == -128 && max_price == current.price) { // Проверка 2 байт 'К' и 'р'
                    puts(TABLE_TOP);
                    puts(TABLE_CONNECT);
                    printf(TABLE_DATA, current.name, StrPadding(current.name, 41), " ", current.price, current.quantity, current.age_min, current.age_max);
                    puts(TABLE_BOTTOM);

                    while(getchar() != '\n');
                    printf("Для продолжение нажмите любую клавишу...");
                    getchar();
                    fseek(f, 0, SEEK_END);
                }
            }
            fread(&current, sizeof(struct toy), 1, f);
        }

        Close(&f);
    }
}


void ToyDelete() {
    CLEAR;
    FILE *f, *t;
    char del[N], choice;
    struct toy current;

    while(getchar() != '\n');
    GetString(del, "Введите строку: ");

    if(Open(&f, filename, "rb")) {
        if(Open(&t, "_temp", "wb")) {
            fread(&current, sizeof(struct toy), 1, f);
            while(!feof(f)) {
                if(!strcmp(current.name, del)){
                    puts(TABLE_TOP);
                    puts(TABLE_CONNECT);
                    printf(TABLE_DATA, current.name, StrPadding(current.name, 41), " ", current.price, current.quantity, current.age_min, current.age_max);
                    puts(TABLE_BOTTOM);

                    do
                    {
                        printf("\nВы хотите удалить данный товар?\ny - да n - нет\n");
                        while(scanf("%c", &choice) != 1) {
                            while(getchar() != '\n');
                            printf("Ошибка ввода!\nВы хотите удалить данный товар?\ny - да n - нет\n");
                        }
                        if(choice != 'y' && choice != 'n')
                            printf("Ошибка ввода!\n");
                    } while (choice != 'y' && choice != 'n');

                    if(choice == 'n')
                        fwrite(&current, sizeof(struct toy), 1, t);
                }
                else {
                    fwrite(&current, sizeof(struct toy), 1, t);
                }

                fread(&current, sizeof(struct toy), 1, f);
            }

            Close(&f);
            remove(filename);
            Close(&t);
            rename("_temp", filename);
        }
    }
}


void ToyEdit() {
    CLEAR;
    FILE *f;
    int int_choice;
    char edit[N], choice;
    struct toy current;

    while(getchar() != '\n');
    GetString(edit, "Введите строку: ");

    if(Open(&f, filename, "rb+")) {
        fread(&current, sizeof(struct toy), 1, f);
        while(!feof(f)) {
            if(!strcmp(current.name, edit)){
                puts(TABLE_TOP);
                puts(TABLE_CONNECT);
                printf(TABLE_DATA, current.name, StrPadding(current.name, 41), " ", current.price, current.quantity, current.age_min, current.age_max);
                puts(TABLE_BOTTOM);

                do
                {
                    printf("\nВы хотите изменить данный товар?\ny - да n - нет\n");
                    while(scanf("%c", &choice) != 1) {
                        while(getchar() != '\n');
                        printf("Ошибка ввода!\nВы хотите изменить данный товар?\ny - да n - нет ");
                    }
                    if(choice != 'y' && choice != 'n')
                        printf("Ошибка ввода!\n");
                } while (choice != 'y' && choice != 'n');

                if(choice == 'y') {
                    do {
                        puts("1. Изменить название");
                        puts("2. Изменить цену");
                        puts("3. Изменить количество");
                        puts("4. Изменить минимальный возраст");
                        puts("5. Изменить максимальный возраст");
                        puts("0. Завершить редактирование");
                        Input("%d", &int_choice, "Введите пункт: ");
                        CLEAR;

                        switch(int_choice) {
                            case 1:
                                GetString(current.name, "Введите название игрушки: ");
                                break;
                            case 2:
                                Input("%lf", &current.price, "Введите цену: ");
                                break;
                            case 3:
                                Input("%d", &current.quantity, "Введите количество: ");
                                break;
                            case 4:
                                Input("%d", &current.age_min, "Введите минимальный возраст: ");
                                break;
                            case 5:
                                Input("%d", &current.age_max, "Введите максимальный возраст: ");
                                break;
                            case 0:
                                break;
                            default:
                                puts("Введен неверный пункт меню!");
                        }
                    } while(int_choice < 0 || int_choice > 5 || int_choice);

                    fseek(f, -sizeof(struct toy), SEEK_CUR);
                    fwrite(&current, sizeof(struct toy), 1, f);

                    fseek(f, 0, SEEK_END);
                }
            }

            fread(&current, sizeof(struct toy), 1, f);
        }

        Close(&f);
    }
}
