#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 15

int Number = 4;

struct studlist
{
    char surname[BUF]; //Фамилия
    char name[BUF]; //Имя
    char group[BUF]; //Группа
    int exam1; //Первый экзамен
    int exam2; //Второй экзамен
    int exam3; //Третий экзамен
    double gpa; //grade point average(Средний балл)
}*list;

void gpa(struct studlist *list)
{
    for (int i = 0; i < Number; i++)
        list[i].gpa = (list[i].exam1 + list[i].exam2 + list[i].exam3) / 3.0;
}

void getgpa(struct studlist *list)
{
    for (int i = 0; i < Number; i++)
        if (list[i].gpa >= 4.5)
        {
            printf("%d)", i + 1);
            printf("%-*s\t", BUF, list[i].surname);
            printf("%-*s\t", BUF, list[i].name);
            printf("%-*s\t", BUF, list[i].group);
            printf("%4d ", list[i].exam1);
            printf("%4d ", list[i].exam2);
            printf("%4d    ", list[i].exam3);
            printf("%4lf\n", list[i].gpa);
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
    
    char *data_input = (char *)malloc(sizeof(char));
    int data_exam;
    
    gets(data_input);
    
    printf("Enter surname -> ");
    gets(data_input);
    strncpy(list[Number - 1].surname, data_input, BUF);
    
    printf("Enter name -> ");
    gets(data_input);
    strncpy(list[Number - 1].name, data_input, BUF);
    
    printf("Enter group -> ");
    gets(data_input);
    strncpy(list[Number - 1].group, data_input, BUF);
    
    printf("Enter exam1 -> ");
    scanf("%d", &data_exam);
    list[Number - 1].exam1 = data_exam;
    
    printf("Enter exam2 -> ");
    scanf("%d", &data_exam);
    list[Number - 1].exam2 = data_exam;
    
    printf("Enter exam3 -> ");
    scanf("%d", &data_exam);
    list[Number - 1].exam3 = data_exam;
    
    printf("---------------\n");
    print3(list);
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
    
    printf("---------------\n");
    print3(list);
}

void print3(struct studlist *list)
{
    gpa(list);
    for (int i = 0; i < Number; i++)
    {
        printf("%d) ", i + 1);
        printf("%-*s\t", BUF, list[i].surname);
        printf("%-*s\t", BUF, list[i].name);
        printf("%-*s\t", BUF, list[i].group);
        printf("%4d ", list[i].exam1);
        printf("%4d ", list[i].exam2);
        printf("%4d    ", list[i].exam3);
        printf("%4f\n", list[i].gpa);
    }
}

void load4(FILE *fp, struct studlist *list)
{
    fp = fopen("text.txt", "r");
    if (fp == NULL)
    {
        printf("ERROR: ошибка открытия файла\n");
        exit(1);
    }

    if (!fscanf(fp, "%d", &Number))
    {
        printf("ERROR: не задан параметр Number\n");
        exit(2);
    }

    for (int i = 0; i < Number; i++)
    {
        fscanf(fp, " %s", (list + i)->surname);
        fscanf(fp, " %s", (list + i)->name);
        fscanf(fp, " %s", (list + i)->group);
        fscanf(fp, "%d", &(list + i)->exam1);
        fscanf(fp, "%d", &(list + i)->exam2);
        fscanf(fp, "%d", &(list + i)->exam3);
    }
    fclose(fp);
    print3(list);
}

void save3(FILE *fp, struct studlist *list)
{
    fp = fopen("text.txt", "w");
    if (fp == NULL)
    {
        printf("ERROR: ошибка создания файла\n");
        exit(4);
    }

    fprintf(fp, "%d\n", Number);

    for (int i = 0; i < Number; i++)
    {
        fscanf(fp, " %s", (list + i)->surname);
        fscanf(fp, " %s", (list + i)->name);
        fscanf(fp, " %s", (list + i)->group);
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
    
    strncpy(list[0].surname, "Rechuk", BUF);
    strncpy(list[0].name, "Dmitrii", BUF);
    strncpy(list[0].group, "606-11", BUF);
    list[0].exam1 = 5;
    list[0].exam2 = 4;
    list[0].exam3 = 5;

    strncpy(list[1].surname, "Koplova", BUF);
    strncpy(list[1].name, "Anna", BUF);
    strncpy(list[1].group, "111-11", BUF);
    list[1].exam1 = 5;
    list[1].exam2 = 5;
    list[1].exam3 = 5;

    strncpy(list[2].surname, "Shelkov", BUF);
    strncpy(list[2].name, "Egor", BUF);
    strncpy(list[2].group, "222-11", BUF);
    list[2].exam1 = 4;
    list[2].exam2 = 4;
    list[2].exam3 = 5;

    strncpy(list[3].surname, "Komarov", BUF);
    strncpy(list[3].name, "Maxim", BUF);
    strncpy(list[3].group, "333-11", BUF);
    list[3].exam1 = 4;
    list[3].exam2 = 4;
    list[3].exam3 = 4;
    
    for (;;)
    {
        printf("---------------\n");
        printf("Enter comand\n 1-insert\n 2-delete\n 3-save\n 4-loading\n 5-exit\n 6-gpa\n 7-print \n");
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
                save3(fp, list);
                break;
            case 4:
                load4(fp, list);
                break;
            case 5:
                return 0;
            case 6:
                getgpa(list);
                break;
            case 7:
                print3(list);
                break;
            default:
                printf("You entered an incorrect value");
        }
    }
    
    free(list);
    
    return 0;
}