#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define red "\033[1;31m"
#define magenta "\033[1;35m"
#define cyan "\033[1;36m"
#define gray "\033[38;5;245m"
#define reset "\033[0m"

struct Add_Student
{
    char Roll[10];
    char Name[100];
    char grade[5];
    char phone[20];
};

void Add_Student();
void Search_Student();
void Update_Details();
void Remove_Student();
void View_Records();

void Add_Student()
{
    FILE *file = fopen("student.txt", "a+");
    if (file == NULL)
    {
        printf(red "\nError opening file!\n" reset);
        return;
    }

    struct Add_Student student;
    char tempRoll[10];

    getchar();
    printf("\nEnter Student's Roll Number: ");
    fgets(tempRoll, sizeof tempRoll, stdin);
    tempRoll[strcspn(tempRoll, "\n")] = '\0';

    char line[256];
    while (fgets(line, sizeof line, file))
    {
        char roll[10];
        sscanf(line, "%[^,]", roll);
        if (strcmp(roll, tempRoll) == 0)
        {
            printf(red "\nError: Roll number already exists!\n" reset);
            fclose(file);
            return;
        }
    }

    strcpy(student.Roll, tempRoll);

    printf("Enter Student's Name: ");
    fgets(student.Name, sizeof student.Name, stdin);
    student.Name[strcspn(student.Name, "\n")] = '\0';

    printf("Enter Student's Grade: ");
    fgets(student.grade, sizeof student.grade, stdin);
    student.grade[strcspn(student.grade, "\n")] = '\0';

    printf("Enter Student's Phone: ");
    fgets(student.phone, sizeof student.phone, stdin);
    student.phone[strcspn(student.phone, "\n")] = '\0';

    fprintf(file, "%s,%s,%s,%s\n", student.Roll, student.Name, student.grade, student.phone);
    fclose(file);

    printf(cyan "\nStudent Added Successfully!\n" reset);
}

void Search_Student()
{
    FILE *file = fopen("student.txt", "r");
    if (file == NULL)
    {
        printf(red "\nError opening file or no records found!\n" reset);
        return;
    }

    char search[100];
    int found = 0;

    getchar();
    printf("\nEnter Roll Number or Name to Search: ");
    fgets(search, sizeof search, stdin);
    search[strcspn(search, "\n")] = '\0';

    char line[256];
    while (fgets(line, sizeof line, file))
    {
        char roll[10], name[100], grade[5], phone[20];
        sscanf(line, "%[^,],%[^,],%[^,],%s", roll, name, grade, phone);

        if (strcmp(roll, search) == 0 || strcmp(name, search) == 0)
        {
            printf(cyan "\nRecord Found:\n" reset);
            printf("%-10s %-20s %-10s %-15s\n", "Roll", "Name", "Grade", "Phone");
            printf("%-10s %-20s %-10s %-15s\n", roll, name, grade, phone);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf(red "\nNo matching record found!\n" reset);
    }

    fclose(file);
}

void Update_Details()
{
    FILE *file = fopen("student.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (file == NULL || temp == NULL)
    {
        printf(red "\nError opening file!\n" reset);
        return;
    }

    char search[100];
    int found = 0;

    getchar();
    printf("\nEnter Roll Number to Update: ");
    fgets(search, sizeof search, stdin);
    search[strcspn(search, "\n")] = '\0';

    char line[256];
    while (fgets(line, sizeof line, file))
    {
        struct Add_Student student;
        sscanf(line, "%[^,],%[^,],%[^,],%s", student.Roll, student.Name, student.grade, student.phone);

        if (strcmp(student.Roll, search) == 0)
        {
            found = 1;
            printf("\nEnter New Name: ");
            fgets(student.Name, sizeof student.Name, stdin);
            student.Name[strcspn(student.Name, "\n")] = '\0';

            printf("Enter New Grade: ");
            fgets(student.grade, sizeof student.grade, stdin);
            student.grade[strcspn(student.grade, "\n")] = '\0';

            printf("Enter New Phone: ");
            fgets(student.phone, sizeof student.phone, stdin);
            student.phone[strcspn(student.phone, "\n")] = '\0';
        }

        fprintf(temp, "%s,%s,%s,%s\n", student.Roll, student.Name, student.grade, student.phone);
    }

    fclose(file);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
        printf(cyan "\nRecord Updated Successfully!\n" reset);
    else
        printf(red "\nNo matching record found!\n" reset);
}

void Remove_Student()
{
    FILE *file = fopen("student.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (file == NULL || temp == NULL)
    {
        printf(red "\nError opening file!\n" reset);
        return;
    }

    char removeRoll[10];
    int found = 0;

    getchar();
    printf("\nEnter Roll Number to Remove: ");
    fgets(removeRoll, sizeof removeRoll, stdin);
    removeRoll[strcspn(removeRoll, "\n")] = '\0';

    char line[256];
    while (fgets(line, sizeof line, file))
    {
        struct Add_Student student;
        sscanf(line, "%[^,],%[^,],%[^,],%s", student.Roll, student.Name, student.grade, student.phone);

        if (strcmp(student.Roll, removeRoll) == 0)
        {
            found = 1;
            continue;
        }

        fprintf(temp, "%s,%s,%s,%s\n", student.Roll, student.Name, student.grade, student.phone);
    }

    fclose(file);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
        printf(cyan "\nRecord Removed Successfully!\n" reset);
    else
        printf(red "\nNo matching record found!\n" reset);
}

void View_Records()
{
    FILE *file = fopen("student.txt", "r");
    if (file == NULL)
    {
        printf(red "\nNo records found!\n" reset);
        return;
    }

    printf("\n%-10s %-20s %-10s %-15s\n", "Roll", "Name", "Grade", "Phone");
    printf("------------------------------------------------------\n");

    char line[256];
    while (fgets(line, sizeof line, file))
    {
        char roll[10], name[100], grade[5], phone[20];
        sscanf(line, "%[^,],%[^,],%[^,],%s", roll, name, grade, phone);

        printf("%-10s %-20s %-10s %-15s\n", roll, name, grade, phone);
    }

    fclose(file);
}

int main()
{
    printf("\n=================Student Record Management System=================\n");

    do
    {
        char choice;

        printf("\n                    1. Add a New Student\n");
        printf("                    2. Search for a Student\n");
        printf("                    3. Update Student Details\n");
        printf("                    4. Remove a Student Record\n");
        printf("                    5. View All Records\n");
        printf("                    0. Exit\n");
        printf("                    Choose Between (0-5): ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            Add_Student();
            break;
        case '2':
            Search_Student();
            break;
        case '3':
            Update_Details();
            break;
        case '4':
            Remove_Student();
            break;
        case '5':
            View_Records();
            break;
        case '0':
            exit(0);
            break;
        default:
            printf(red "\nInvalid Input! Please Choose a valid option Between (0-5)\n" reset);
        }

    } while (1);

    return 0;
}