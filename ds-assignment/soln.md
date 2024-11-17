# Activity-V Data Structures

**Ishan Chowdhury 2305132**<br>
**Krish Kumar 2305135**<br>
**Ankit Kumar 23051409** <br>
**Kush Singh 23052247**  

## A-1: Create three database using header linked list
**Student** (Roll No, Name, Branch ID, CGPA)  
**University** (University ID, University Name, University Location, Year of start)  
**Branch** (Branch ID, University ID, Branch Name)

**Implement the following modules/ sub-modules using menu driven approach:**
- Keep the Roll No, University ID and Branch ID Unique (Duplicated entry should not be allowed and accordingly user will be prompted)
- Student can take a University ID/ Branch ID only if it is available in the University/ Branch database.
- Student Name, University Name and Branch Name should all be in Capital Letters. (If user has not entered accordingly, then the program must convert it into Capital Letters and store.)
- Display the entire student list/ University list/ Branch List
- Delete all students whose CGPA < 6.0 and store them in another list. They will come back to the original student list if their CGPA >= 6.0 (Update function)
- Display the list of students reading in KIIT University
- ADD/ MODIFY/ DELETE/ UPDATE using key value in any of the database as per requirement.
- Display the student details who are reading at KIIT University with branch CSE.
- Display the list of Branches available in any given University
- Display the University details in ascending order of their year of starting
- Display the all Student name/ all University name for a given name substring entered by the user.

***Solution:***
``` c
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
```
---
## A-2: Create one database using header linked list to store the details of a shopping card given by the Shopping Mall.
**Shopping Card** (Card_ID, Customer_Name, Points, Date_of_Birth, Last_date_of_transaction, Address)  
**Item** (Item_ID, Item_Name, Price, Quantity)

**Implement the following modules/ sub-modules using menu driven approach:**
- Keep the Card_ID and Item_ID Unique (Duplicated entry should not be allowed and prompted)
- Update function to update the address only (if required). Other fields can’t be updated by the customer.
- A customer can buy different products listed and accordingly points will be assigned as follows:

| Type of Item  | Points for every Rs. 100 purchase |
|---------------|-----------------------------------|
| Grocery       | 1                                 |
| Garments      | 5                                 |
| Electronics   | 10                                |

- When the manager of the shopping mall decides (decides a date), a discount of 10% can be given to 10 customers who have first accumulated 1000 points. The customer may immediately redeem the points and get 10% discount and its points will be reset to zero, else keep it for later use. The next 10 customers will get the discount in the next month on the same date. This process continues.
- When the manager of the shopping mall decides (decides a date), a discount of 15% can be given to 5 customers who have first accumulated 1000 points and are senior citizens (age > 60). The customer may immediately redeem the points and get 10% discount and its points will be reset to zero, else keep it for later use. This process is repeated every month.
- Display the customer details and item details as per requirements.
- Add new customers as well as new items.
- Delete existing customers if the last transaction date is before one year.
- The system should show the items out of stock during the purchase.

***Solution***

``` c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item
{
  int item_id;
  char item_name[30];
  float price;
  int quantity;
  struct item *next;
} item;

typedef struct shopping_card
{
  int card_id;
  char customer_name[50];
  int points;
  char dob[15];
  char last_transaction_date[15];
  char address[100];
  struct shopping_card *next;
} shopping_card;

typedef struct header
{
  int count;
  struct item *item_head;
  struct shopping_card *card_head;
} header;

header *initialize_header()
{
  header *new_header = (header *)malloc(sizeof(header));
  new_header->count = 0;
  new_header->item_head = NULL;
  new_header->card_head = NULL;
  return new_header;
}

shopping_card *create_customer(int card_id, char customer_name[], char dob[], char last_transaction_date[], char address[])
{
  shopping_card *new_customer = (shopping_card *)malloc(sizeof(shopping_card));
  new_customer->card_id = card_id;
  strcpy(new_customer->customer_name, customer_name);
  new_customer->points = 0;
  strcpy(new_customer->dob, dob);
  strcpy(new_customer->last_transaction_date, last_transaction_date);
  strcpy(new_customer->address, address);
  new_customer->next = NULL;
  return new_customer;
}

item *create_item(int item_id, char item_name[], float price, int quantity)
{
  item *new_item = (item *)malloc(sizeof(item));
  new_item->item_id = item_id;
  strcpy(new_item->item_name, item_name);
  new_item->price = price;
  new_item->quantity = quantity;
  new_item->next = NULL;
  return new_item;
}

void add_customer(header *card_header, int card_id, char customer_name[], char dob[], char last_transaction_date[], char address[])
{
  shopping_card *temp = card_header->card_head;
  while (temp != NULL)
  {
    if (temp->card_id == card_id)
    {
      printf("Customer with Card ID %d already exists.\n", card_id);
      return;
    }
    temp = temp->next;
  }
  shopping_card *new_customer = create_customer(card_id, customer_name, dob, last_transaction_date, address);
  new_customer->next = card_header->card_head;
  card_header->card_head = new_customer;
  card_header->count++;
  printf("Customer added successfully!\n");
}

void add_item(header *item_header, int item_id, char item_name[], float price, int quantity)
{
  item *temp = item_header->item_head;
  while (temp != NULL)
  {
    if (temp->item_id == item_id)
    {
      printf("Item with Item ID %d already exists.\n", item_id);
      return;
    }
    temp = temp->next;
  }
  item *new_item = create_item(item_id, item_name, price, quantity);
  new_item->next = item_header->item_head;
  item_header->item_head = new_item;
  item_header->count++;
  printf("Item added successfully!\n");
}

void update_address(header *card_header, int card_id, char new_address[])
{
  shopping_card *temp = card_header->card_head;
  while (temp != NULL)
  {
    if (temp->card_id == card_id)
    {
      strcpy(temp->address, new_address);
      printf("Address updated successfully!\n");
      return;
    }
    temp = temp->next;
  }
  printf("Customer with Card ID %d not found.\n", card_id);
}

void assign_points(header *card_header, header *item_header, int card_id, int item_id, int amount_spent)
{
  shopping_card *temp_card = card_header->card_head;
  while (temp_card != NULL)
  {
    if (temp_card->card_id == card_id)
    {
      item *temp_item = item_header->item_head;
      while (temp_item != NULL)
      {
        if (temp_item->item_id == item_id)
        {
          int points = 0;
          if (strcmp(temp_item->item_name, "Grocery") == 0)
          {
            points = (amount_spent / 100) * 1;
          }
          else if (strcmp(temp_item->item_name, "Garments") == 0)
          {
            points = (amount_spent / 100) * 5;
          }
          else if (strcmp(temp_item->item_name, "Electronics") == 0)
          {
            points = (amount_spent / 100) * 10;
          }
          temp_card->points += points;
          printf("Points assigned based on the purchase.\n");
          return;
        }
        temp_item = temp_item->next;
      }
      printf("Item with ID %d not found.\n", item_id);
      return;
    }
    temp_card = temp_card->next;
  }
  printf("Customer with Card ID %d not found.\n", card_id);
}

float calculate_discount(shopping_card *customer)
{
  float discount = 0.0;
  int age = 2024 - atoi(customer->dob + 6); 

  if (age >= 60)
  {
    discount = 0.1; 
  }
  else if (age <= 12)
  {
    discount = 0.05; 
  }
  else if (strcmp(customer->last_transaction_date, "14/11/2024") == 0)
  {
    discount = 0.15; 
  }

  return discount;
}

void display_customers(header *card_header)
{
  shopping_card *temp = card_header->card_head;
  if (temp == NULL)
  {
    printf("No customers to display.\n");
    return;
  }
  while (temp != NULL)
  {
    printf("Card ID: %d, Name: %s, Points: %d, DOB: %s, Last Transaction Date: %s, Address: %s\n",
           temp->card_id, temp->customer_name, temp->points, temp->dob, temp->last_transaction_date, temp->address);
    temp = temp->next;
  }
}

void display_items(header *item_header)
{
  item *temp = item_header->item_head;
  if (temp == NULL)
  {
    printf("No items to display.\n");
    return;
  }
  while (temp != NULL)
  {
    printf("Item ID: %d, Name: %s, Price: %.2f, Quantity: %d\n",
           temp->item_id, temp->item_name, temp->price, temp->quantity);
    temp = temp->next;
  }
}

int main()
{
  header *item_header = initialize_header();
  header *card_header = initialize_header();
  int choice, card_id, item_id, amount_spent, quantity;
  char customer_name[50], dob[15], last_transaction_date[15], address[100], item_name[30], new_address[100];
  float price;

  do
  {
    printf("\nMenu:\n");
    printf("1. Add Customer\n2. Add Item\n3. Update Address\n4. Assign Points\n5. Display Customers\n6. Display Items\n7. Calculate Discount\n8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter Card ID, Name, DOB (dd/mm/yyyy), Last Transaction Date, Address:\n");
      scanf("%d %s %s %s %s", &card_id, customer_name, dob, last_transaction_date, address);
      add_customer(card_header, card_id, customer_name, dob, last_transaction_date, address);
      break;

    case 2:
      printf("Enter Item ID, Name, Price, Quantity:\n");
      scanf("%d %s %f %d", &item_id, item_name, &price, &quantity);
      add_item(item_header, item_id, item_name, price, quantity);
      break;

    case 3:
      printf("Enter Card ID and New Address:\n");
      scanf("%d %s", &card_id, new_address);
      update_address(card_header, card_id, new_address);
      break;

    case 4:
      printf("Enter Card ID, Item ID, and Amount Spent:\n");
      scanf("%d %d %d", &card_id, &item_id, &amount_spent);
      assign_points(card_header, item_header, card_id, item_id, amount_spent);
      break;

    case 5:
      display_customers(card_header);
      break;

    case 6:
      display_items(item_header);
      break;

    case 7:
      printf("Enter Card ID to calculate discount:\n");
      scanf("%d", &card_id);
      shopping_card *temp = card_header->card_head;
      while (temp != NULL)
      {
        if (temp->card_id == card_id)
        {
          float discount = calculate_discount(temp);
          printf("Discount for Card ID %d: %.2f%%\n", card_id, discount * 100);
          break;
        }
        temp = temp->next;
      }
      if (temp == NULL)
      {
        printf("Customer with Card ID %d not found.\n", card_id);
      }
      break;

    case 8:
      printf("Exiting.\n");
      break;

    default:
      printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 8);

  return 0;
}
```
---
## A-3: In a vaccination centre people make queue. But due to unavailability of space in the same queue, people make a parallel queue (second queue following the first one), then people make another parallel queue (third queue following the second one) and further no queues can be made due to unavailability of space. The case has been shown diagrammatically below. The arrow shows the direction in which people can be added. The box shows the space available for waiting. The size of the three boxes is equal, where the size will be decided by the user.

### Vaccination Centre

- Implement the queues (Insertion and deletion) operations. Whenever the first person gets into the centre, all people will move one step forward.
- Write functions to handle when no one is present to get the vaccine and when no further people can be added to the queue due to unavailability of space.

***Solution***

``` c
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUES 3 

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int count;   
} Queue;

void initializeQueue(Queue *q, int size) {
    q->arr = (int *)malloc(size * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = size;
    q->count = 0;
}

int isEmpty(Queue *q) {
    return q->count == 0;
}

int isFull(Queue *q) {
    return q->count == q->size;
}

int enqueue(Queue queues[], int person, int queueSize) {
    for (int i = 0; i < MAX_QUEUES; i++) {
        if (!isFull(&queues[i])) {
            queues[i].rear = (queues[i].rear + 1) % queueSize;
            queues[i].arr[queues[i].rear] = person;
            queues[i].count++;
            printf("Person %d added to Queue %d.\n", person, i + 1);
            return 1;
        }
    }
    printf("No space available to add more people.\n");
    return 0;
}

int dequeue(Queue queues[], int queueSize) {
    for (int i = 0; i < MAX_QUEUES; i++) {
        if (!isEmpty(&queues[i])) {
            int person = queues[i].arr[queues[i].front];
            queues[i].front = (queues[i].front + 1) % queueSize;
            queues[i].count--;
            printf("Person %d has been vaccinated and removed from Queue %d.\n", person, i + 1);
            return person;
        }
    }
    printf("No one is present to get the vaccine.\n");
    return -1;
}

void moveForward(Queue queues[], int queueSize) {
    for (int i = 0; i < MAX_QUEUES - 1; i++) {
        if (!isEmpty(&queues[i + 1]) && !isFull(&queues[i])) {
            queues[i].rear = (queues[i].rear + 1) % queueSize;
            queues[i].arr[queues[i].rear] = queues[i + 1].arr[queues[i + 1].front];
            queues[i].count++;
            queues[i + 1].front = (queues[i + 1].front + 1) % queueSize;
            queues[i + 1].count--;
            printf("Person moved from Queue %d to Queue %d.\n", i + 2, i + 1);
        }
    }
}

int main() {
    int queueSize, choice, person = 1;
    printf("Enter the size of each queue: ");
    scanf("%d", &queueSize);

    Queue queues[MAX_QUEUES];
    for (int i = 0; i < MAX_QUEUES; i++) {
        initializeQueue(&queues[i], queueSize);
    }

    while (1) {
        printf("\n1. Add Person to Queue\n");
        printf("2. Vaccinate and Remove Person\n");
        printf("3. Move All Forward\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(queues, person++, queueSize);
                break;
            case 2:
                dequeue(queues, queueSize);
                break;
            case 3:
                moveForward(queues, queueSize);
                break;
            case 4:
                printf("Exiting program.\n");
                for (int i = 0; i < MAX_QUEUES; i++) {
                    free(queues[i].arr);
                }
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
```

## A-4: Write a program to implement four numbers of D-queues in an array.

***Solution***

``` c
#include<stdio.h>
#include<stdlib.h>

#define size 20
#define no_dq 4
#define dq_size size/no_dq

struct queue
{
    int q[size];
    int front[no_dq];
    int rear[no_dq];
};

void initialize(struct queue* dq)
{
    for(int i =0;i<no_dq;i++)
    {
        dq->front[i] = -1;
        dq->rear[i] = -1;
    }
}

int isEmpty(struct queue* dq, int q_no)
{
    if(dq->front[q_no] == -1)   return 1;
    return 0;
}

int isFull(struct queue* dq, int q_no)
{
    int start = q_no * dq_size;
    int end = start + dq_size -1;
    return ((dq->rear[q_no] )+ 1 == dq->front[q_no]) || (dq->rear[q_no] == end && dq->front[q_no] == start);
}

void enqueue_front(struct queue* dq, int q_no, int data)
{
    int start = q_no * dq_size;
    int end = start + dq_size -1;

    if(isFull(dq,q_no))
    {
        printf("D-queue %d is full \n",q_no);
        return;
    }

    if(isEmpty(dq,q_no))
        dq->front[q_no] = dq->rear[q_no] = start;
    else
    {
        dq->front[q_no]--;
        if(dq->front[q_no] < start)
            dq->front[q_no] = end;
    }

    dq->q[dq->front[q_no]] = data;
}

void enqueue_rear(struct queue* dq, int q_no, int data)
{
    int start = q_no * dq_size;
    int end = start + dq_size -1;

    if(isFull(dq,q_no))
    {
        printf("D-queue %d is full \n",q_no);
        return;
    }

    if(isEmpty(dq,q_no))
        dq->front[q_no] = dq->rear[q_no] = start;
    else
    {
        dq->rear[q_no]++;
        if(dq->rear[q_no] > end)
            dq->rear[q_no] = start;
    }

    dq->q[dq->rear[q_no]] = data;
}

int dequeue_front(struct queue* dq, int q_no)
{
    if(isEmpty(dq,q_no))
    {
        printf("D-queue %d is empty \n",q_no);
        return -1;
    }

    int data = dq->q[dq->front[q_no]];
    if(dq->front[q_no] == dq->rear[q_no])   
        dq->front[q_no] = dq->rear[q_no] = -1;
    else
    {
        int start = q_no * dq_size;
        int end = start + dq_size -1;

        dq->front[q_no]++;
        if(dq->front[q_no] > end)
            dq->front[q_no] = start;
    }

    return data;
}

int dequeue_rear(struct queue* dq, int q_no)
{
    if(isEmpty(dq,q_no))
    {
        printf("D-queue %d is empty \n",q_no);
        return -1;
    }

    int data = dq->q[dq->rear[q_no]];
    if(dq->front[q_no] == dq->rear[q_no])   
        dq->front[q_no] = dq->rear[q_no] = -1;
    else
    {
        int start = q_no * dq_size;
        int end = start + dq_size -1;

        dq->rear[q_no]--;
        if(dq->rear[q_no] < start)
            dq->rear[q_no] = end;
    }
    return data;
}

void display(struct queue* dq, int q_no)
{
    if(isEmpty(dq,q_no))
    {
        printf("D-queue %d is empty \n",q_no);
        return;
    }
    int start = q_no * dq_size;
    int end = start + dq_size -1;
    int i = dq->front[q_no];

    printf("D-Queue %d : ",q_no);

    while(1)
    {
        printf("%d ",dq->q[i]);
        if(i == dq->rear[q_no])
            break;
        i++;
        if(i > end) i = start;
    }
    printf("\n");    
}

int main()
{
    struct queue* dq = (struct queue*) malloc(sizeof(struct queue));
    initialize(dq);

    int q_no, choice, data;
    char pos;

    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display all queue\n");
    do
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1 :
                printf("Enter queue number (0-3) : ");
                scanf("%d",&q_no);
                printf("Enter value to be entered : ");
                scanf("%d",&data);
                printf("Enqueue from front (f) or rear (r) : ");
                scanf(" %c",&pos);
                if(pos == 'f')
                    enqueue_front(dq,q_no,data);
                else if(pos == 'r')
                    enqueue_rear(dq,q_no,data);
                else
                    printf("Enter choice correctly \n");
                break;
            
            case 2:
                 printf("Enter queue number (0-3) : ");
                scanf("%d", &q_no);
                printf("Dequeue from front or rear : ");
                scanf(" %c",&pos);
                if(pos == 'f')
                    printf("%d\n",dequeue_front(dq,q_no));
                else if(pos == 'r')
                    printf("%d\n",dequeue_rear(dq,q_no));
                else
                    printf("Enter choice correctly \n");
                break;
        
            case 3:
                for(int i =0;i<4;i++)
                {
                    display(dq,i);
                    printf("\n");
                }
                break;

            case 0:
                break;
            
            default:
                printf("Incorrect choice\n");
            break;
        }

    }while(choice != 0);

    return 0;

}
```
---
## A-5: Write a program to implement round robin scheduling concept using a linked list. 
Each node represents a process with attributes as `<PID, CPU_time>`. A quantum time `T` will be input by the user. A process will be executed (when the user wants) for quantum time `T`, and the CPU_time will be updated with `CPU_time - T`, and the current process node is deleted from the beginning and added to the end of the list. If the updated `CPU_time` is <= 0, then the process is deleted from the list. After a process is executed for `T` time, the next process in the queue is executed upon user choice. The entire process gets completed when all process nodes are deleted.

***Solution***
``` c
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int PID;
    int CPU_time;
    struct node* next;
};

struct node* create_node(int PID, int CPU_time);
void create_list(struct node** head, int PID, int CPU_time);
void round_robin(struct node** head, int quatum);

int main()
{
    struct node* head = NULL;
 
    int choice, pid, cputime, quantum;

    printf("1. Add a new process\n");
    printf("2. Start Round Robin Scheduling\n");
    printf("0. EXIT\n");

    do
    {
        printf("Enter choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter PID and CPU_TIME : ");
                scanf("%d%d",&pid,&cputime);
                create_list(&head,pid,cputime);
                break;
            
            case 2:
                printf("Enter time quantum T : ");
                scanf("%d",&quantum);
                round_robin(&head,quantum);
                break;

            case 0:
                break;
            
            default:
                printf("Incorrect choice\n");
        }
    }while(choice != 0);

    return 0;
}

struct node* create_node(int PID, int CPU_time)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->CPU_time = CPU_time;
    ptr->PID = PID;
    ptr->next = NULL;
    return ptr;
}

void create_list(struct node** head, int PID, int CPU_time)
{
    struct node* new_process = create_node(PID,CPU_time);
    if(*head == NULL)
    {
        *head = new_process;
        new_process->next = new_process;
    }
        
    else
    {
        struct node* temp = *head;
        while(temp->next != *head)
            temp = temp->next;
        temp->next = new_process;
        new_process->next = *head;
    }
}

void round_robin(struct node** head, int quantum)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node* temp = *head;

    while(*head != NULL)
    {
        printf("Process %d executed for %d units of time\n",temp->PID,(temp->CPU_time > quantum) ? quantum : temp->CPU_time);
        temp->CPU_time -= quantum;

        if(temp->CPU_time <= 0)
        {
            if(temp->next == temp)
            {
                free(temp);
                *head = NULL;
                temp = NULL;
            }

            else
            {
                struct node* prev = *head;
                while(prev->next != temp)
                    prev = prev->next;
                prev->next = temp->next;

                if(*head == temp)
                    *head = temp->next;
                struct node* temp1 = temp;
                temp = temp->next;
                free(temp1);
            }
        }

        else
        {
            *head = temp->next;
            temp = temp->next;
        }
    }

    printf("\nALL proceses are completed \n");
}
```
---
## A-6: Write a program to construct a binary search tree from a given sequence of preorder and inorder traversal of the tree.

***Solution***
``` c
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* lptr;
    struct node* rptr;
};

struct node* buildTree(int* preorder, int* inorder, int start, int end, int* preIndex);

void preorderT(struct node* root);
void inorderT(struct node* root);
void postorderT(struct node* root);

int main()
{
    int n;
    printf("Enter the number of elemnts in the BST : ");
    scanf("%d",&n);

    int preorder[n];
    int inorder[n];

    printf("Enter the preorder traversal : \n");
    for(int i = 0;i<n;i++)
        scanf("%d",&preorder[i]);

    printf("Enter the inorder traversal : \n");
    for(int i = 0;i<n;i++)
        scanf("%d",&inorder[i]);

    int preIndex = 0;
    struct node* root = buildTree(preorder, inorder, 0, n-1, &preIndex);

    printf("Preorder traversal of the constructed BST: ");
    preorderT(root);
    printf("\n");

    printf("Inorder traversal of the constructed BST: ");
    inorderT(root);
    printf("\n");

    printf("Postorder traversal of the constructed BST: ");
    postorderT(root);
    printf("\n");
    return 0;
}

struct node* buildTree(int* preorder, int* inorder, int start, int end, int* preorderIndex)
{
    if(start > end) return NULL;

    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->data = preorder[*preorderIndex];
    new->lptr = new->rptr = NULL;
    (*preorderIndex)++;

    if(start == end)
        return new;
    
    int inorderIndex;
    for(inorderIndex = start;inorderIndex<=end;inorderIndex++)
        if(inorder[inorderIndex] == new->data) break;
    
    new->lptr = buildTree(preorder, inorder, start, inorderIndex-1,preorderIndex);
    new->rptr = buildTree(preorder, inorder, inorderIndex+1, end,preorderIndex);
    
    return new;
}

void preorderT(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorderT(root->lptr);
        preorderT(root->rptr);
    }
}

void inorderT(struct node* root)
{
    if(root != NULL)
    {
        inorderT(root->lptr);
        printf("%d ",root->data);
        inorderT(root->rptr);
    }
}

void postorderT(struct node* root)
{
    if(root != NULL)
    {
        postorderT(root->lptr);
        postorderT(root->rptr);
        printf("%d ",root->data);
    }
}
```
---

## A-7: Write a program to check that the left sub-tree of a binary search tree is a mirror image of its right sub-tree.

***Solution***
``` c
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* rptr;
    struct node* lptr;
} *root = NULL;


void create(int n);
void preorder(struct node* root);
void inorder(struct node* root);
void postorder(struct node* root);

int is_symmetric(struct node* root);
int is_mirror(struct node* left, struct node* right);

int main()
{
    printf("1. To enter a value\n");
    printf("2. Preorder Traversal\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("0. EXIT\n");

    int choice,data;
    do
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d",&data);
            create(data);
            break;
        
        case 2:
            preorder(root);
            printf("\n");
            break;

        case 3:
            inorder(root);
            printf("\n");
            break;

        case 4:
            postorder(root);
            printf("\n");
            break;

        case 5:
            if(is_symmetric(root))
                printf("The left subtree is \033[1mmirror image\033[0m of its right subtree.\n");
            else
                printf("THe left subtree is \033[1mnot mirror\033[0m image if its right subtree\n");
            break;
            
        case 0:
            break;
        default:
            printf("Incorrect Choice\n");
            break;
        }
    } while (choice != 0);
    
    return 0;
}

void create(int n)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = n;
    new->lptr = NULL;
    new->rptr = NULL;
    struct node* ptr = root;
    struct node* par = NULL;

    if(root == NULL)
        root = new;
    else
    {
        while(ptr != NULL)
        {
            par = ptr;
            if(n<ptr->data)
                ptr = ptr->lptr;
            else
                ptr = ptr->rptr;
        }
        if(n < par->data)
            par->lptr = new;
        else
            par->rptr = new;
    }

}

void preorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->lptr);
        preorder(root->rptr);
    }
}

void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->lptr);
        printf("%d ",root->data);
        inorder(root->rptr);
    }
}

void postorder(struct node* root)
{
    if(root != NULL)
    {
        postorder(root->lptr);
        postorder(root->rptr);
        printf("%d ",root->data);
    }
}

int is_symmetric(struct node* root)
{
    if(root == NULL)
        return 1;
    return is_mirror(root->lptr, root->rptr);
}

int is_mirror(struct node* left, struct node* right)
{
    if(left == NULL && right == NULL)
        return 1;
    
    if(left == NULL || right == NULL)
        return 0;
    
    return is_mirror(left->lptr, right->rptr) && is_mirror(left->rptr, right->lptr);
}
```
---

## A-8: Write a program to implement a graph ADT (using linked list) and traverse the graph in breadth-first search (BFS) and depth-first search (DFS) from a given node.

***Solution***
``` c
#include <stdio.h>
#include <stdlib.h>

struct edge_node;

struct vertex_node {
    int data;
    struct vertex_node* vertex_next;
    struct edge_node* edge_next;
};

struct edge_node {
    struct edge_node* edge_next;
    struct vertex_node* vertex_next;
};

struct vertex_node* create_vertex(int data);
struct edge_node* create_edge(struct vertex_node* dest);
void add_vertex(struct vertex_node** head, int data);
void add_edge(struct vertex_node* head, int src, int dest);
struct vertex_node* find_vertex(struct vertex_node* head, int data);
void bfs(struct vertex_node* head, int start);
void dfs(struct vertex_node* head, int start);
void dfs_util(struct vertex_node* vertex, int* visited);
void input_graph(struct vertex_node** graph);

int main() {
    struct vertex_node* graph = NULL;

    input_graph(&graph);

    int start;
    printf("Enter the starting vertex for BFS and DFS: ");
    scanf("%d", &start);

    printf("BFS from node %d:\n", start);
    bfs(graph, start);

    printf("\nDFS from node %d:\n", start);
    dfs(graph, start);
    printf("\n");

    return 0;
}

struct vertex_node* create_vertex(int data) {
    struct vertex_node* new_vertex = (struct vertex_node*)malloc(sizeof(struct vertex_node));
    new_vertex->data = data;
    new_vertex->vertex_next = NULL;
    new_vertex->edge_next = NULL;
    return new_vertex;
}

struct edge_node* create_edge(struct vertex_node* dest) {
    struct edge_node* new_edge = (struct edge_node*)malloc(sizeof(struct edge_node));
    new_edge->vertex_next = dest;
    new_edge->edge_next = NULL;
    return new_edge;
}

void add_vertex(struct vertex_node** head, int data) {
    struct vertex_node* new_vertex = create_vertex(data);
    new_vertex->vertex_next = *head;
    *head = new_vertex;
}

struct vertex_node* find_vertex(struct vertex_node* head, int data) {
    struct vertex_node* temp = head;
    while (temp) {
        if (temp->data == data)
            return temp;
        temp = temp->vertex_next;
    }
    return NULL;
}

void add_edge(struct vertex_node* head, int src, int dest) {
    struct vertex_node* src_vertex = find_vertex(head, src);
    struct vertex_node* dest_vertex = find_vertex(head, dest);

    if (src_vertex == NULL || dest_vertex == NULL) {
        printf("Vertex not found.\n");
        return;
    }

    struct edge_node* new_edge = create_edge(dest_vertex);
    new_edge->edge_next = src_vertex->edge_next;
    src_vertex->edge_next = new_edge;

    new_edge = create_edge(src_vertex);
    new_edge->edge_next = dest_vertex->edge_next;
    dest_vertex->edge_next = new_edge;
}

void bfs(struct vertex_node* head, int start) {
    struct vertex_node* start_vertex = find_vertex(head, start);
    if (start_vertex == NULL) {
        printf("Start vertex not found.\n");
        return;
    }

    int visited[100] = {0};
    struct vertex_node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = start_vertex;
    visited[start_vertex->data] = 1;

    while (front < rear) {
        struct vertex_node* current = queue[front++];
        printf("%d ", current->data);

        struct edge_node* edge = current->edge_next;
        while (edge) {
            if (!visited[edge->vertex_next->data]) {
                visited[edge->vertex_next->data] = 1;
                queue[rear++] = edge->vertex_next;
            }
            edge = edge->edge_next;
        }
    }
}

void dfs(struct vertex_node* head, int start) {
    struct vertex_node* start_vertex = find_vertex(head, start);
    if (start_vertex == NULL) {
        printf("Start vertex not found.\n");
        return;
    }

    int visited[100] = {0};
    dfs_util(start_vertex, visited);
}

void dfs_util(struct vertex_node* vertex, int* visited) {
    visited[vertex->data] = 1;
    printf("%d ", vertex->data);

    struct edge_node* edge = vertex->edge_next;
    while (edge) {
        if (!visited[edge->vertex_next->data]) {
            dfs_util(edge->vertex_next, visited);
        }
        edge = edge->edge_next;
    }
}

void input_graph(struct vertex_node** graph) {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    for (int i = 0; i < vertices; i++) {
        int data;
        printf("Enter vertex %d: ", i + 1);
        scanf("%d", &data);
        add_vertex(graph, data);
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        add_edge(*graph, src, dest);
    }
}
```
---

## A-9: Suppose the locations of ATMs of different banks are represented by nodes in a graph with information: `<ATM ID, BANK ID, CITY ID, LOCATION ID>`. 

***Solution***
``` txt
DEFINE CONSTANTS:
    MAX_NODES ← Maximum number of nodes
    INF ← Large value representing infinity

STRUCTURES:
    ATM: { id, bank_id, city_id, location_id }
    Edge: { node, distance }
    Queue: { front, rear, size, data[MAX_NODES] }

INITIALIZE:
    graph[MAX_NODES][MAX_NODES] ← Adjacency list for edges
    edge_count[MAX_NODES] ← Array to store neighbor count for each node
    atms[MAX_NODES] ← Array to store ATM metadata

FUNCTION initializeQueue(queue):
    queue.front ← 0
    queue.rear ← 0
    queue.size ← 0

FUNCTION isQueueEmpty(queue):
    RETURN queue.size == 0

FUNCTION enqueue(queue, value):
    queue.data[queue.rear] ← value
    queue.rear ← (queue.rear + 1) MOD MAX_NODES
    queue.size ← queue.size + 1

FUNCTION dequeue(queue):
    value ← queue.data[queue.front]
    queue.front ← (queue.front + 1) MOD MAX_NODES
    queue.size ← queue.size - 1
    RETURN value

FUNCTION findNearestATMs(start_location, bank_id, k):
    INITIALIZE queue
    initializeQueue(queue)
    enqueue(queue, start_location)

    visited[MAX_NODES] ← FALSE for all nodes
    result[MAX_NODES] ← EMPTY
    result_count ← 0

    visited[start_location] ← TRUE

    WHILE queue is not empty AND result_count < k:
        current ← dequeue(queue)

        IF atms[current].bank_id == bank_id:
            ADD current to result
            result_count ← result_count + 1

        FOR each neighbor of current:
            neighbor ← graph[current][neighbor_index].node
            IF visited[neighbor] == FALSE:
                visited[neighbor] ← TRUE
                enqueue(queue, neighbor)

    PRINT "Nearest k ATMs of the given bank:"
    FOR each ATM in result:
        PRINT ATM details

FUNCTION main():
    num_nodes ← Number of nodes
    INITIALIZE graph, edge_count, and atms metadata
    ADD edges to graph

    CALL findNearestATMs(start_location, bank_id, k)


Steps:

    Initialize Data Structures:
        Create an empty queue Q to perform BFS traversal.
        Create an array visited of size equal to the number of nodes, initialized to false.
        Create an empty list result to store the nearest ATMs.

    Start BFS Traversal:
        Mark start_location as visited by setting visited[start_location] = true.
        Enqueue start_location into Q.

    Perform BFS Until Q is Empty or k ATMs are Found:
        While Q is not empty and the size of result is less than k:
            Dequeue a node current from Q.
            Check if the ATM at current belongs to the desired bank_id:
                If true, append current to result.
            For each neighbor neighbor of current:
                If neighbor is not visited:
                    Mark neighbor as visited.
                    Enqueue neighbor into Q.

    Output the Result:
        Return the list result, containing up to k nearest ATMs of the specified bank.
```
---
Write a pseudo code/ algorithm to find the nearest ATM of a given Bank from a given location. Then, find the subsequent neighbouring ATMs as per user’s requirement.

## A-10: Write a program to convert a postfix expression to its equivalent prefix expression by constructing an expression tree.

***Solution***
``` c
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node* left;
    struct node* right;
};

struct stac
{
    struct node* data;
    struct stac* next;
};

void preorder(struct node* root);
void push(struct stac **top, struct node *n);
struct node *pop(struct stac **top);
struct node* createnode(char c);
int isOperator(char c);
void post_to_pre(char* str);
void preorder(struct node* root);

int main()
{
    char str[100];
    printf("Enter the postfix expression: ");
    scanf("%s", str);  
    printf("Postorder Traversal: %s\n", str);
    printf("Preorder Traversal: ");
    post_to_pre(str);
    printf("\n");

    return 0;
}

void push(struct stac **top, struct node *n)
{
    struct stac *newNode = (struct stac *)malloc(sizeof(struct stac));
    newNode->data = n;
    newNode->next = *top;
    *top = newNode;
}

struct node *pop(struct stac **top)
{
    if (*top == NULL)
        return NULL;
    struct node *n = (*top)->data;
    *top = (*top)->next;
    return n;
}

struct node* createnode(char c)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = c;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

int isOperator(char c)
{
    return (c == '/' || c == '+' || c == '-' || c == '*' || c == '^');
}

void post_to_pre(char* str)
{
    struct stac* st = NULL;
    int len = strlen(str);

    for(int i = 0; i < len; i++)
    {
        char c = str[i];

        if(isalnum(c))
        {
            struct node* newnode = createnode(c);
            push(&st, newnode);
        }
        else if(isOperator(c))
        {
            struct node* opnode = createnode(c);
            struct node* rightchild = pop(&st);
            struct node* leftchild = pop(&st);
            opnode->left = leftchild;
            opnode->right = rightchild;

            push(&st, opnode); 
        }
    }

    struct node* root = pop(&st);

    preorder(root);
}

void preorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}



```
---