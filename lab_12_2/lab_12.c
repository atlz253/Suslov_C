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

        printf("������� ��� �����: ");
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
        printf("������� ����� ����������!\n");
        return -1;
    }    

    
    return Menu();
}


int Menu() {
    int choice;

    do {
        CLEAR;
        puts("1. �������� �����");
        puts("2. ���������� ������");
        puts("3. �������� ����������� �����");
        puts("4. ����� ���������� �������� ������������ ��������� ����");
        puts("5. ����������, ������� ����� �������� �� ���������� ������������� ��������� � �����");
        puts("6. �������� ������");
        puts("7. �������������� ������");
        puts("0. ��������� ���������\n");

        printf("������� ����� ����: ");
        while (!scanf("%d", &choice)) {
            printf("������� �������� ������!\n������� ����� ����: ");
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
            puts("������ �������� ����� ����!");
        }

    } while (choice < 0 || choice > 7 || choice);

    return 0;
}


int Open(FILE **file, char path[], char rights[]) 
{
    if ((*file = fopen(path, rights)) == NULL) 
    {
        CLEAR;
        printf("������ �������� �����!\n");
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
        printf("���� ������!\n");
        Close(&f);
    }
}


void Input(char flag[], void *a, char message[]) {
    printf(message);
    while (!scanf(flag, a)) {
        puts("�������� ������!");
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

        printf("������� �������� ���������: ");
        fgets(new.name, N, stdin);
        while (new.name[i] != '\0')
        {
            if (new.name[i] == '\n')
                new.name[i] = '\0';
            
            i++;
        }

        printf("������� ���� ��������: ");
        fgets(new.zone, N, stdin);
        while (new.zone[i] != '\0')
        {
            if (new.zone[i] == '\n')
                new.zone[i] = '\0';
            
            i++;
        }

        do
        {
            Input("%f", &new.cost, "������� ������� �� ���� �� ���� ����: ");
            if (new.cost < 0)
                printf("������ ������ ������������� ���������! ���������� ��������� �������.\n");
        } while (new.cost < 0);
        

        fwrite(&new, sizeof(struct zoo), 1, f);
        printf("������ ���������!\n");
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
            puts("|            �������� ���������            |              ��������� ����              | ������� �� ���� �� ���� ���� |");

            for (j=0;j<PAGE;j++) 
            {
                fread(&current, sizeof(struct zoo), 1, f);
                if(feof(f))
                    break;

                printf("| %-41s| %-41s| %-29.2f|\n", current.name, current.zone, current.cost);
            }
            printf("<--j   q-�����   l-->\n");

            do 
            {
                printf("����: ");
                while(getchar() != '\n');
                while (!scanf("%c", &choice)) 
                {
                    printf("������ �����!\n����: ");
                    while(getchar() != '\n');
                }

                if(choice != 'j' && choice != 'q' && choice != 'l') printf("����������� �������!\n");
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

    printf("������� ������: ");
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
                    puts("|            �������� ���������            |              ��������� ����              | ������� �� ���� �� ���� ���� |");
                    printf("| %-41s| %-41s| %-29.2f|\n", current.name, current.zone, current.cost);

                    do
                    {
                        printf("\n�� ������ ������� ������ ��������?\ny - �� n - ���\n");
                        while(scanf("%c", &choice) != 1) 
                        {
                            while(getchar() != '\n');
                            printf("������ �����!\n�� ������ ������� ������ ��������?\ny - �� n - ���\n");
                        }
                        if(choice != 'y' && choice != 'n')
                            printf("������ �����!\n");
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
                    printf("�������� �� �������!\n");
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

    printf("������� ������: ");
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
                puts("|            �������� ���������            |              ��������� ����              | ������� �� ���� �� ���� ���� |");
                printf("| %-41s| %-41s| %-29.2f|\n", current.name, current.zone, current.cost);

                do
                {
                    printf("\n�� ������ �������� ������ ��������?\ny - �� n - ���\n");
                    while(scanf("%c", &choice) != 1) {
                        while(getchar() != '\n');
                        printf("������ �����!\n�� ������ �������� ������ ��������?\ny - �� n - ��� ");
                    }
                    if(choice != 'y' && choice != 'n')
                        printf("������ �����!\n");
                } while (choice != 'y' && choice != 'n');
                getchar();

                if(choice == 'y') {
                    do {
                        puts("1. �������� ��������");
                        puts("2. �������� ���� ��������");
                        puts("3. �������� ������� �� ���� �� ���� ����");
                        puts("0. ��������� ��������������");
                        Input("%d", &int_choice, "������� �����: ");
                        CLEAR;

                        switch(int_choice) {
                            case 1:
                                printf("������� �������� ���������: ");
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
                                printf("������� ���� ��������: ");
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
                                    Input("%f", &current.cost, "������� ������� �� ���� �� ���� ����: ");
                                    if (current.cost < 0)
                                        printf("������ ������ ������������� ���������! ���������� ��������� �������.\n");
                                } while (current.cost < 0);
                                break;
                            case 0:
                                break;
                            default:
                                puts("������ �������� ����� ����!");
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
                printf("�������� �� �������!\n");
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
    printf("������� ����: ");
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

    printf("���������� �������� ����������� � %s: %d\n��� ����������� ������� ����� �������...", zone, count);
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
    printf("������� ��� ���������: ");
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
                puts("|            �������� ���������            |              ��������� ����              | ������� �� ���� �� ���� ���� |");
                printf("| %-41s| %-41s| %-29.2f|\n", current.name, current.zone, current.cost);

                do
                {
                    printf("\n�� ������ ������� ���������� ����� ���������?\ny - �� n - ���\n");
                    while(scanf("%c", &choice) != 1) {
                        while(getchar() != '\n');
                        printf("������ �����!\n�� ������ ������� ���������� ����� ���������?\ny - �� n - ��� ");
                    }
                    if(choice != 'y' && choice != 'n')
                        printf("������ �����!\n");
                } while (choice != 'y' && choice != 'n');
                getchar();

                if (choice == 'y')
                {
                    printf("�� ���������� %s � ����� ��������: %.2f\n", current.name, current.cost*30);
                    fseek(f, 0, SEEK_END);
                }
            }

            fread(&current, sizeof(struct zoo), 1, f);            
            if (feof(f) && flag)
                printf("�������� �� �������!\n");
        }
    }

    printf("��� ����������� ������� ����� �������...");
    getchar();
}