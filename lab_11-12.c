#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 10

int Number = 4;

struct studlist
{
    char surname[BUF]; //Фамилия
    char name[BUF]; //Имя
    char group[BUF]; //Группа
    int exam1; //Первый экзамен
    int exam2; //Второй экзамен
    int exam3; //Третий экзамен
    float gpa; //grade point average(Средний балл)
}* list;

void change(char addr[])
{
    char str[BUF];

    fflush(stdin);

    scanf("%[^\n]s", str);

    strncpy(addr, str, BUF);
}

void gpa(struct studlist *list)
{
    for (int i = 0; i < Number; i++)
    {
        list[i].gpa = (list[i].exam1 + list[i].exam2 + list[i].exam3) / 3;
    }
    for (int i = 0; i < Number; i++)
    {
        if (list[i].gpa >= 4.5)
        {
            printf("%d)", i + 1);
            printf("%-*s\t", BUF, list[i].surname);
            printf("%-*s\t", BUF, list[i].name);
            printf("%-*s\t", BUF, list[i].group);
            printf("%4d ", list[i].exam1);
            printf("%4d ", list[i].exam2);
            printf("%4d    ", list[i].exam3);
            printf("%4f\n", list[i].gpa);
        }
    }
}

void insert1(struct studlist *list)
{
    Number++;
    list = realloc(list, Number * sizeof(struct studlist));
    if (NULL == list)
    {
        printf("Error");
        exit(1);
    }

    printf("Enter surname ->\n");
    scanf("%c", &list[Number - 1].surname);
    change(list[Number - 1].surname);
    
    printf("Enter name ->\n");
    scanf("%c", &list[Number - 1].name);
    change(list[Number - 1].name);
    
    printf("Enter group ->\n");
    scanf("%c", &list[Number - 1].group);
    change(list[Number - 1].group);

    printf("Enter  exam1 ->\n");
    scanf("%d", &list[Number - 1].exam1);
    change(list[Number - 1].exam1);
    
    printf("Enter  exam2 ->\n");
    scanf("%d", &list[Number - 1].exam2);
    change(list[Number - 1].exam2);
    
    printf("Enter  exam3 ->\n");
    scanf("%d", &list[Number - 1].exam3);
    change(list[Number - 1].exam3);
    fflush(stdin);
}

void delete2(struct studlist *list)
{
    int n;
    printf("Enter string number -> ");
    scanf("%d", &n);
    fflush(stdin);

    for (int i = n - 1; i < Number; i++)
        list[i] = list[i + 1];
    Number--;
    list = realloc(list, Number * sizeof(struct studlist));
    if (NULL == list)
    {
        printf("Error");
        exit(1);
    }
}

void print3(struct studlist *list)
{
    for (int i = 0; i < Number; i++)
    {
        printf("%d)", i + 1);
        printf("%-*s\t", BUF, list[i].surname);
        printf("%-*s\t", BUF, list[i].name);
        printf("%-*s\t", BUF, list[i].group);
        printf("%4d ", list[i].exam1);
        printf("%4d ", list[i].exam2);
        printf("%4d    ", list[i].exam3);
        printf("%4f\n", list[i].gpa);
    }
}

void load5(FILE *fp)
{
    fp = fopen("text.txt", "r");
    if (fp == NULL)
    {
        printf("ERROR OPENNING FILE\n");
        exit(1);
    }

    if (!fscanf(fp, "%d", &Number))
    {
        printf("FILE POVREGDEN: NE ZADAN PARAMETR NUMBER\n");
        exit(2);
    }

    list = realloc(list, Number * sizeof(struct studlist));
    if (NULL == list)
    {
        printf("Error DINAMIC MEMORY\n");
        exit(3);
    }

    for (int i = 0; i < Number; i++)
    {
        fscanf(fp, " %[^\t]s", (list + i)->surname);
        fscanf(fp, " %[^\t]s", (list + i)->name);
        fscanf(fp, " %[^\t]s", (list + i)->group);
        fscanf(fp, "%d", &(list + i)->exam1);
        fscanf(fp, "%d", &(list + i)->exam2);
        fscanf(fp, "%d", &(list + i)->exam3);
    }
    fclose(fp);
}

void save4(FILE *fp)
{
    fp = fopen("text.txt", "w");
    if (fp == NULL)
    {
        printf("ERROR: NE UDAYOTSY SOZDAT' FILE\n");
        exit(4);
    }

    fprintf(fp, "%d\n", Number);

    for (int i = 0; i < Number; i++)
    {
        fscanf(fp, " %[^\t]s", (list + i)->surname);
        fscanf(fp, " %[^\t]s", (list + i)->name);
        fscanf(fp, " %[^\t]s", (list + i)->group);
        fscanf(fp, "%d", &(list + i)->exam1);
        fscanf(fp, "%d", &(list + i)->exam2);
        fscanf(fp, "%d", &(list + i)->exam3);
    }

    fclose(fp);
}

int main()
{
    int l;
    FILE *fp = NULL;
    
    struct studlist *list = (struct studlist *)malloc(Number * sizeof(struct studlist));
    if (NULL == list)
    {
        printf("Error");
        exit(1);
    }
    
    gpa(list);
    
    strncpy(list[0].surname, "Rechuk", BUF);
    strncpy(list[0].name, "Dmitrii", BUF);
    strncpy(list[0].group, "606-11", BUF);
    list[0].exam1 = 5;
    list[0].exam2 = 4;
    list[0].exam3 = 5;

    strncpy(list[1].surname, "Koplova", BUF);
    strncpy(list[1].name, "Anna", BUF);
    strncpy(list[1].group, "606-11", BUF);
    list[1].exam1 = 5;
    list[1].exam2 = 5;
    list[1].exam3 = 5;

    strncpy(list[2].surname, "Shelkov", BUF);
    strncpy(list[2].name, "Egor", BUF);
    strncpy(list[2].group, "606-11", BUF);
    list[2].exam1 = 4;
    list[2].exam2 = 4;
    list[2].exam3 = 5;

    strncpy(list[3].surname, "Komarov", BUF);
    strncpy(list[3].name, "Maxim", BUF);
    strncpy(list[3].group, "606-11", BUF);
    list[3].exam1 = 4;
    list[3].exam2 = 4;
    list[3].exam3 = 4;
    
    for (;;)
    {
        printf("---------------\n");
        printf("Enter comand\n 1-insert\n 2-delete\n 3-print\n 4-save\n 5-loading\n 6-exit\n 7-gpa\n");
        printf("---------------\n");
        scanf("%d", &l);
        printf("---------------\n");
        fflush(stdin);

        switch (l)
        {
            case 1:
                insert1(list);
                break;
            case 2:
                delete2(list);
                break;
            case 3:
                print3(list);
                break;
            case 4:
                save4(fp);
                break;
            case 5:
                load5(fp);
                break;
            case 6:
                return 0;
            case 7:
                gpa(list);
                break;
            default:
                printf("You entered an incorrect value");
        }
    }
    
    free(list);
    
    return 0;
}