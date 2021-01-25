#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>


#define CLEAR if(CLEAR_CONSOLE) system("cls")
#define CLEAR_CONSOLE 1

#define N 41
#define PAGE 10


struct zoo
{
    char name[N];
    char zone[N];
    float cost;
};


int Menu();
int Open(FILE **file, char path[], char rights[]);
void Close(FILE **file);
void Create();
void Input(char flag[], void *a, char message[]);
void AddData();
void FileView();
void Delete();
void Edit();
void Search();
void CostMonth();


char filename[N];


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    CLEAR;
    if (argc == 2) {
        strcpy(filename, argv[1]);
    }
    else if (argc == 1) {
        int i = 0;

        printf("Введите имя файла: ");
        fgets(filename, N, stdin);
        while (filename[i] != '\0')
        {
            if (filename[i] == '\n')
                filename[i] = '\0';
            
            i++;
        }
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
        puts("4. Поиск количества животных определенной природной зоны");
        puts("5. Определить, сколько денег тратится на содержание определенного животного в месяц");
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
            Create();
            break;
        case 2:
            AddData();
            break;
        case 3:
            FileView();
            break;
        case 4:
            Search();
            break;
        case 5:
            CostMonth();
            break;
        case 6:
            Delete();
            break;
        case 7:
            Edit();
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


int Open(FILE **file, char path[], char rights[]) 
{
    if ((*file = fopen(path, rights)) == NULL) 
    {
        CLEAR;
        printf("Ошибка открытия файла!\n");
        getchar();
        return 0;
    }
    else 
    {
        return 1;
    }
}


void Close(FILE **file) 
{
    if (*file != NULL) 
    {
        fclose(*file);
    }
}


void Create() 
{
    FILE *f;
    if(Open(&f, filename, "w")) 
    {
        printf("Файл создан!\n");
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


void AddData() {
    CLEAR;
    FILE *f;
    if(Open(&f, filename, "ab")) 
    {
        int i = 0;
        struct zoo new;
        getchar();

        printf("Введите название животного: ");
        fgets(new.name, N, stdin);
        while (new.name[i] != '\0')
        {
            if (new.name[i] == '\n')
                new.name[i] = '\0';
            
            i++;
        }

        printf("Введите зону обитания: ");
        fgets(new.zone, N, stdin);
        while (new.zone[i] != '\0')
        {
            if (new.zone[i] == '\n')
                new.zone[i] = '\0';
            
            i++;
        }

        do
        {
            Input("%f", &new.cost, "Введите затраты на корм за один день: ");
            if (new.cost < 0)
                printf("Нельзя ввести отрицательную стоимость! Пожалуйста повторите попытку.\n");
        } while (new.cost < 0);
        

        fwrite(&new, sizeof(struct zoo), 1, f);
        printf("Запись завершена!\n");
        Close(&f);
    }
}


void FileView() 
{
    CLEAR;
    FILE *f;
    if(Open(&f, filename, "rb")) 
    {
        int count, pages_num, i, j;
        struct zoo current;
        char choice;

        fseek(f, 0, SEEK_END);
        count = ftell(f)/sizeof(struct zoo);
        pages_num = count/PAGE + 1;
        while(count >= PAGE)
            count = count - PAGE;
        fseek(f, 0, SEEK_SET);

        for (i=0;i<pages_num;i++) 
        {
            CLEAR;
            puts("|            название животного            |              природная зона              | затраты на корм за один день |");

            for (j=0;j<PAGE;j++) 
            {
                fread(&current, sizeof(struct zoo), 1, f);
                if(feof(f))
                    break;

                printf("| %-41s| %-41s| %-29.2f|\n", current.name, current.zone, current.cost);
            }
            printf("<--j   q-выход   l-->\n");

            do 
            {
                printf("Ввод: ");
                while(getchar() != '\n');
                while (!scanf("%c", &choice)) 
                {
                    printf("Ошибка ввода!\nВвод: ");
                    while(getchar() != '\n');
                }

                if(choice != 'j' && choice != 'q' && choice != 'l') printf("Неизвестная команда!\n");
            } while(choice != 'j' && choice != 'q' && choice != 'l');

            if(choice == 'j') 
            {
                if(i == 0)
                    break;
                else if(i+1 == pages_num)
                    fseek(f, -sizeof(struct zoo)*(count+PAGE), SEEK_CUR);
                else
                    fseek(f, -sizeof(struct zoo)*PAGE*2, SEEK_CUR);

                i -= 2;
            }
            else if (choice == 'q') 
            {
                break;
            }
        }

        Close(&f);
    }
}


void Delete() 
{
    CLEAR;
    int i = 0, flag = 1;
    FILE *f, *t;
    char del[N], choice;
    struct zoo current;

    printf("Введите строку: ");
    while(getchar() != '\n');    
    fgets(del, N, stdin);
    while (del[i] != '\0')
    {
        if (del[i] == '\n')
            del[i] = '\0';
        
        i++;
    }

    if(Open(&f, filename, "rb")) 
    {
        if(Open(&t, "_temp", "wb")) 
        {
            fread(&current, sizeof(struct zoo), 1, f);
            while(!feof(f)) 
            {
                if(!strcmp(current.name, del))
                {
                    flag = 0;
                    puts("|            название животного            |              природная зона              | затраты на корм за один день |");
                    printf("| %-41s| %-41s| %-29.2f|\n", current.name, current.zone, current.cost);

                    do
                    {
                        printf("\nВы хотите удалить данное животное?\ny - да n - нет\n");
                        while(scanf("%c", &choice) != 1) 
                        {
                            while(getchar() != '\n');
                            printf("Ошибка ввода!\nВы хотите удалить данное животное?\ny - да n - нет\n");
                        }
                        if(choice != 'y' && choice != 'n')
                            printf("Ошибка ввода!\n");
                    } while (choice != 'y' && choice != 'n');
                    getchar();

                    if(choice == 'n')
                        fwrite(&current, sizeof(struct zoo), 1, t);
                }
                else 
                {
                    fwrite(&current, sizeof(struct zoo), 1, t);
                }

                fread(&current, sizeof(struct zoo), 1, f);
                if (feof(f) && flag)
                {
                    printf("Животное не найдено!\n");
                    getchar();
                }  
            }

            Close(&f);
            remove(filename);
            Close(&t);
            rename("_temp", filename);
        }
    }
}


void Edit() 
{
    CLEAR;
    FILE *f;
    int i = 0, flag = 1;
    int int_choice;
    char edit[N], choice;
    struct zoo current;

    printf("Введите строку: ");
    while(getchar() != '\n');
    fgets(edit, N, stdin);
    while (edit[i] != '\0')
    {
        if (edit[i] == '\n')
            edit[i] = '\0';
        
        i++;
    }

    if(Open(&f, filename, "rb+")) 
    {
        fread(&current, sizeof(struct zoo), 1, f);
        while(!feof(f)) {
            if(!strcmp(current.name, edit))
            {
                flag = 0;
                puts("|            название животного            |              природная зона              | затраты на корм за один день |");
                printf("| %-41s| %-41s| %-29.2f|\n", current.name, current.zone, current.cost);

                do
                {
                    printf("\nВы хотите изменить данное животное?\ny - да n - нет\n");
                    while(scanf("%c", &choice) != 1) {
                        while(getchar() != '\n');
                        printf("Ошибка ввода!\nВы хотите изменить данное животное?\ny - да n - нет ");
                    }
                    if(choice != 'y' && choice != 'n')
                        printf("Ошибка ввода!\n");
                } while (choice != 'y' && choice != 'n');
                getchar();

                if(choice == 'y') {
                    do {
                        puts("1. Изменить название");
                        puts("2. Изменить зону обитания");
                        puts("3. Изменить затраты на корм за один день");
                        puts("0. Завершить редактирование");
                        Input("%d", &int_choice, "Введите пункт: ");
                        CLEAR;

                        switch(int_choice) {
                            case 1:
                                printf("Введите название животного: ");
                                fgets(current.name, N, stdin);
                                i = 0;
                                while (current.name[i] != '\0')
                                {
                                    if (current.name[i] == '\n')
                                        current.name[i] = '\0';
                                    
                                    i++;
                                }
                                break;
                            case 2:
                                printf("Введите зону обитания: ");
                                fgets(current.zone, N, stdin);
                                i = 0;
                                while (current.zone[i] != '\0')
                                {
                                    if (current.zone[i] == '\n')
                                        current.zone[i] = '\0';
                                    
                                    i++;
                                }
                                break;
                            case 3:
                                do
                                {
                                    Input("%f", &current.cost, "Введите затраты на корм за один день: ");
                                    if (current.cost < 0)
                                        printf("Нельзя ввести отрицательную стоимость! Пожалуйста повторите попытку.\n");
                                } while (current.cost < 0);
                                break;
                            case 0:
                                break;
                            default:
                                puts("Введен неверный пункт меню!");
                        }
                    } while(int_choice < 0 || int_choice > 3 || int_choice);

                    fseek(f, -sizeof(struct zoo), SEEK_CUR);
                    fwrite(&current, sizeof(struct zoo), 1, f);

                    fseek(f, 0, SEEK_END);
                }
            }

            fread(&current, sizeof(struct zoo), 1, f);
            if (feof(f) && flag)
            {
                printf("Животное не найдено!\n");
                getchar();
            }
        }

        Close(&f);
    }
}


void Search() 
{
    CLEAR;
    int i = 0;
    char zone[N];
    int count = 0;
    struct zoo current;

    getchar();
    printf("Введите зону: ");
    fgets(zone, N, stdin);
    while (zone[i] != '\0')
    {
        if (zone[i] == '\n')
            zone[i] = '\0';
        
        i++;
    }

    FILE *f;
    if(Open(&f, filename, "rb")) 
    {
        fread(&current, sizeof(struct zoo), 1, f);
        while(!feof(f)) 
        {
            if(!strcmp(current.zone, zone)) 
                count++;

            fread(&current, sizeof(struct zoo), 1, f);
        }
    }

    printf("Количество животных проживающих в %s: %d\nДля продолжения нажмите любую клавишу...", zone, count);
    getchar();
}


void CostMonth()
{
    CLEAR;
    int i = 0, flag = 1;
    char name[N], choice;
    struct zoo current;
    FILE *f;

    getchar();
    printf("Введите имя животного: ");
    fgets(name, N, stdin);
    while (name[i] != '\0')
    {
        if (name[i] == '\n')
            name[i] = '\0';
        
        i++;
    }

    if(Open(&f, filename, "rb")) {
        fread(&current, sizeof(struct zoo), 1, f);
        while(!feof(f)) {
            if (!strcmp(current.name, name))
            {
                flag = 0;
                CLEAR;
                puts("|            название животного            |              природная зона              | затраты на корм за один день |");
                printf("| %-41s| %-41s| %-29.2f|\n", current.name, current.zone, current.cost);

                do
                {
                    printf("\nВы хотите подсчет содержание этого животного?\ny - да n - нет\n");
                    while(scanf("%c", &choice) != 1) {
                        while(getchar() != '\n');
                        printf("Ошибка ввода!\nВы хотите подсчет содержание этого животного?\ny - да n - нет ");
                    }
                    if(choice != 'y' && choice != 'n')
                        printf("Ошибка ввода!\n");
                } while (choice != 'y' && choice != 'n');
                getchar();

                if (choice == 'y')
                {
                    printf("На содержание %s в месяц тратится: %.2f\n", current.name, current.cost*30);
                    fseek(f, 0, SEEK_END);
                }
            }

            fread(&current, sizeof(struct zoo), 1, f);            
            if (feof(f) && flag)
                printf("Животное не найдено!\n");
        }
    }

    printf("Для продолжения нажмите любую клавишу...");
    getchar();
}