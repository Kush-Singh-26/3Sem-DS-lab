#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define size 50

struct Student
{
    int roll_no;
    char name[size];
    char branch_id[10];
    float cgpa;
    struct Student *next;
} *Student_head = NULL, *fail_student_head = NULL;

struct University
{
    char univ_id[10];
    char univ_name[size];
    char univ_location[size];
    int start_year;
    struct University *next;
} *University_head = NULL;

struct Branch
{
    char branch_id[5];
    char univ_id[10];
    char branch_name[size];
    struct Branch *next;
} *Branch_head = NULL;

void create_student();
void create_University();
void create_Branch();
void capitalize(char *str);
int validate_Unique_rollno(int rollno);
int validate_Unique_univid(char *univid);
int validate_Unique_branchid(char *branchid);
int validate_existing_uni_id(char *univid);
int validate_existing_branchid(char *branchid);
void display_student();
void display_university();
void display_branch();
void delete_fail();
void display_kiit();
void display_kiit_cse();
void display_branches_in_university(char *university_name);
void sort_universities_by_start_year();
void search_substring_in_names(char *substring, int choice);

int main()
{
    int choice;
    char substring[size], university_name[size];

    printf("\nMenu:\n");
    printf("1. Add a Student\n");
    printf("2. Add a University\n");
    printf("3. Add a Branch\n");
    printf("4. Display All Students\n");
    printf("5. Display All Universities\n");
    printf("6. Display All Branches\n");
    printf("7. Delete Students with CGPA < 6.0\n");
    printf("8. Display Students Attending KIIT University\n");
    printf("9. Display Students Attending KIIT in Branch CSE\n");
    printf("10. Display Branches in a Given University\n");
    printf("11. Display Universities in Ascending Order by Start Year\n");
    printf("12. Search Substring in Student or University Names\n");
    printf("0. Exit\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_student();
            break;

        case 2:
            create_University();
            break;
        case 3:
            create_Branch();
            break;

        case 4:
            printf("Student List:\n");
            display_student();
            break;

        case 5:
            printf("University List:\n");
            display_university();
            break;

        case 6:
            printf("Branch List:\n");
            display_branch();
            break;

        case 7:
            delete_fail();
            printf("Students with CGPA < 6.0 moved to the fail list.\n");
            break;

        case 8:
            printf("Students Attending KIIT University:\n");
            display_kiit();
            break;

        case 9:
            printf("Students Attending KIIT in Branch CSE:\n");
            display_kiit_cse();
            break;

        case 10:
            printf("Enter the University Name: ");
            scanf(" %[^\n]%*c", university_name);
            capitalize(university_name);
            display_branches_in_university(university_name);
            break;

        case 11:
            sort_universities_by_start_year();
            printf("Universities Sorted by Start Year:\n");
            display_university();
            break;

        case 12:
            printf("Enter the substring to search: ");
            scanf(" %[^\n]%*c", substring);
            printf("Search in:\n1. Student Names\n2. University Names\n");
            int search_choice;
            scanf("%d", &search_choice);
            search_substring_in_names(substring, search_choice);
            break;

        case 0:
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void create_student()
{
    struct Student *ptr = (struct Student *)malloc(sizeof(struct Student));
    ptr->next = NULL;

    printf("Enter the roll number : ");
    scanf("%d", &ptr->roll_no);
    if (!(validate_Unique_rollno(ptr->roll_no)))
    {
        printf("This Roll number already exists. Student not added. \n");
        free(ptr);
        return;
    }

    printf("Enter Name of the student : ");
    scanf(" %[^\n]%*c", ptr->name);
    capitalize(ptr->name);

    printf("Enter Branch ID : ");
    scanf(" %[^\n]%*c", ptr->branch_id);
    if (!validate_existing_branchid(ptr->branch_id))
    {
        printf("This Branch ID does not exist. Student not added.\n");
        free(ptr);
        return;
    }

    printf("Enter CGPA : ");
    scanf("%f", &(ptr->cgpa));

    if (Student_head == NULL)
        Student_head = ptr;

    else
    {
        struct Student *temp = Student_head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
}

void create_University()
{
    struct University *ptr = (struct University *)malloc(sizeof(struct University));
    ptr->next = NULL;

    printf("Enter University ID : ");
    scanf(" %[^\n]%*c", ptr->univ_id);
    if (!validate_Unique_univid(ptr->univ_id))
    {
        printf("This University ID already exist. University not added.\n");
        free(ptr);
        return;
    }

    printf("Enter Name of the University : ");
    scanf(" %[^\n]%*c", ptr->univ_name);
    capitalize(ptr->univ_name);

    printf("Enter Location of the University : ");
    scanf(" %[^\n]%*c", ptr->univ_location);

    printf("Enter the Year of Start : ");
    scanf("%d", &ptr->start_year);

    if (University_head == NULL)
        University_head = ptr;

    else
    {
        struct University *temp = University_head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
}

void create_Branch()
{
    struct Branch *ptr = (struct Branch *)malloc(sizeof(struct Branch));
    ptr->next = NULL;

    printf("Enter Branch ID : ");
    scanf(" %[^\n]%*c", ptr->branch_id);
    if (!validate_Unique_branchid(ptr->branch_id))
    {
        printf("This Branch ID already exists. Branch not added.\n");
        free(ptr);
        return;
    }

    printf("Enter University ID : ");
    scanf(" %[^\n]%*c", ptr->univ_id);
    if (!validate_existing_uni_id(ptr->univ_id))
    {
        printf("This University ID does not exist. Branch not added.\n");
        free(ptr);
        return;
    }

    printf("Enter Name of the Branch : ");
    scanf(" %[^\n]%*c", ptr->branch_name);
    capitalize(ptr->branch_name);

    if (Branch_head == NULL)
        Branch_head = ptr;

    else
    {
        struct Branch *temp = Branch_head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
}

void capitalize(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = toupper(str[i]);
    }
}

int validate_Unique_rollno(int rollno)
{
    struct Student *temp = Student_head;
    while (temp != NULL)
    {
        if (temp->roll_no == rollno)
            return 0;
        temp = temp->next;
    }
    return 1;
}

int validate_Unique_univid(char *univid)
{
    struct University *temp = University_head;
    while (temp != NULL)
    {
        if (strcmp(temp->univ_id, univid) == 0)
            return 0;
        temp = temp->next;
    }
    return 1;
}

int validate_Unique_branchid(char *branchid)
{
    struct Branch *temp = Branch_head;
    while (temp != NULL)
    {
        if (strcmp(temp->branch_id, branchid) == 0)
            return 0;
        temp = temp->next;
    }
    return 1;
}

int validate_existing_uni_id(char *univid)
{
    struct University *temp = University_head;
    while (temp != NULL)
    {
        if (strcmp(temp->univ_id, univid) == 0)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int validate_existing_branchid(char *branchid)
{
    struct Branch *temp = Branch_head;
    while (temp != NULL)
    {
        if (strcmp(temp->branch_id, branchid) == 0)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void display_student()
{
    struct Student *temp = Student_head;
    while (temp != NULL)
    {
        printf("Roll number :  %d, Name : %s, Branch ID : %s, CGPA : %.2f\n", temp->roll_no, temp->name, temp->branch_id, temp->cgpa);
        temp = temp->next;
    }
}

void display_university()
{
    struct University *temp = University_head;
    while (temp != NULL)
    {
        printf("University ID : %s, University Name : %s, University Location : %s, Year of Start : %d\n", temp->univ_id, temp->univ_name, temp->univ_location, temp->start_year);
        temp = temp->next;
    }
}

void display_branch()
{
    struct Branch *temp = Branch_head;
    while (temp != NULL)
    {
        printf("Branch ID : %s, Unviersity ID : %s, Branch Name : %s\n", temp->branch_id, temp->univ_id, temp->branch_name);
        temp = temp->next;
    }
}

void delete_fail()
{
    struct Student *temp1 = Student_head;
    struct Student *prev = NULL;

    while (temp1 != NULL)
    {
        if (temp1->cgpa < 6.0)
        {
            if (fail_student_head == NULL)
            {
                fail_student_head = temp1;
                temp1 = temp1->next;
                fail_student_head->next = NULL;
            }
            else
            {
                struct Student *temp2 = fail_student_head;
                while (temp2->next != NULL)
                    temp2 = temp2->next;
                temp2->next = temp1;
                temp1 = temp1->next;
                temp2->next->next = NULL;
            }

            if (prev == NULL)
            {
                Student_head = temp1;
            }
            else
            {
                prev->next = temp1;
            }
        }
        else
        {
            prev = temp1;
            temp1 = temp1->next;
        }
    }
}

void display_kiit()
{
    struct Student *student_temp = Student_head;

    while (student_temp != NULL)
    {
        struct Branch *branch_temp = Branch_head;
        struct University *temp_uni = NULL;
        while (branch_temp != NULL)
        {
            if (strcmp(student_temp->branch_id, branch_temp->branch_id) == 0)
            {
                temp_uni = University_head;
                while (temp_uni != NULL)
                {
                    if (strcmp(temp_uni->univ_id, branch_temp->univ_id) == 0 && strcmp(temp_uni->univ_id, "KIIT") == 0)
                    {
                        printf("Roll number :  %d, Name : %s, Branch ID : %s, CGPA : %.2f\n", student_temp->roll_no, student_temp->name, student_temp->branch_id, student_temp->cgpa);
                        break;
                    }
                    temp_uni = temp_uni->next;
                }
            }
            branch_temp = branch_temp->next;
        }
        student_temp = student_temp->next;
    }

    struct Student *student_fail_temp = fail_student_head;

    while (student_fail_temp != NULL)
    {
        struct Branch *branch_temp = Branch_head;
        struct University *temp_uni = NULL;
        while (branch_temp != NULL)
        {
            if (strcmp(student_fail_temp->branch_id, branch_temp->branch_id) == 0)
            {
                temp_uni = University_head;
                while (temp_uni != NULL)
                {
                    if (strcmp(temp_uni->univ_id, branch_temp->univ_id) == 0 && strcmp(temp_uni->univ_id, "KIIT") == 0)
                    {
                        printf("Roll number :  %d, Name : %s, Branch ID : %s, CGPA : %.2f\n", student_fail_temp->roll_no, student_fail_temp->name, student_fail_temp->branch_id, student_fail_temp->cgpa);
                        break;
                    }
                    temp_uni = temp_uni->next;
                }
            }
            branch_temp = branch_temp->next;
        }
        student_fail_temp = student_fail_temp->next;
    }
}

void display_kiit_cse()
{
    struct Student *student_temp = Student_head;

    printf("Students Attending KIIT in Branch CSE:\n");
    while (student_temp != NULL)
    {
        struct Branch *branch_temp = Branch_head;
        while (branch_temp != NULL)
        {
            if (strcmp(student_temp->branch_id, branch_temp->branch_id) == 0 &&
                strcmp(branch_temp->branch_id, "CSE") == 0) // Compare branch ID
            {
                struct University *temp_uni = University_head;
                while (temp_uni != NULL)
                {
                    if (strcmp(temp_uni->univ_id, branch_temp->univ_id) == 0 &&
                        strcmp(temp_uni->univ_id, "KIIT") == 0) // Compare university ID
                    {
                        printf("Roll number :  %d, Name : %s, Branch ID : %s, CGPA : %.2f\n",
                               student_temp->roll_no, student_temp->name,
                               student_temp->branch_id, student_temp->cgpa);
                        break; // Exit university loop once a match is found
                    }
                    temp_uni = temp_uni->next;
                }
            }
            branch_temp = branch_temp->next;
        }
        student_temp = student_temp->next;
    }
}

void display_branches_in_university(char *university_name)
{
    struct University *uni_temp = University_head;
    struct Branch *branch_temp = Branch_head;

    char university_id[10];
    int found = 0;

    while (uni_temp != NULL)
    {
        if (strcmp(uni_temp->univ_name, university_name) == 0)
        {
            strcpy(university_id, uni_temp->univ_id);
            found = 1;
            break;
        }
        uni_temp = uni_temp->next;
    }

    if (!found)
    {
        printf("University not found.\n");
        return;
    }

    printf("Branches available in %s:\n", university_name);
    while (branch_temp != NULL)
    {
        if (strcmp(branch_temp->univ_id, university_id) == 0)
        {
            printf("Branch ID: %s, Branch Name: %s\n", branch_temp->branch_id, branch_temp->branch_name);
        }
        branch_temp = branch_temp->next;
    }
}

void sort_universities_by_start_year()
{
    struct University *i, *j;
    int temp_year;
    char temp_id[10], temp_name[size], temp_location[size];

    for (i = University_head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->start_year > j->start_year)
            {
                temp_year = i->start_year;
                i->start_year = j->start_year;
                j->start_year = temp_year;

                strcpy(temp_id, i->univ_id);
                strcpy(i->univ_id, j->univ_id);
                strcpy(j->univ_id, temp_id);

                strcpy(temp_name, i->univ_name);
                strcpy(i->univ_name, j->univ_name);
                strcpy(j->univ_name, temp_name);

                strcpy(temp_location, i->univ_location);
                strcpy(i->univ_location, j->univ_location);
                strcpy(j->univ_location, temp_location);
            }
        }
    }
}

void search_substring_in_names(char *substring, int choice)
{
    if (choice == 1)
    {
        struct Student *temp = Student_head;
        printf("Students with '%s' in their names:\n", substring);
        while (temp != NULL)
        {
            if (strstr(temp->name, substring) != NULL)
                printf("Roll number : %d, Name : %s, Branch ID : %s, CGPA : %.2f\n", temp->roll_no, temp->name, temp->branch_id, temp->cgpa);
            temp = temp->next;
        }
    }
    else if (choice == 2)
    {
        struct University *temp = University_head;
        printf("Universities with '%s' in their names:\n", substring);
        while (temp != NULL)
        {
            if (strstr(temp->univ_name, substring) != NULL)
                printf("University ID : %s, Name : %s, Location : %s, Start Year : %d\n", temp->univ_id, temp->univ_name, temp->univ_location, temp->start_year);
            temp = temp->next;
        }
    }
    else
    {
        printf("Invalid choice.\n");
    }
}
