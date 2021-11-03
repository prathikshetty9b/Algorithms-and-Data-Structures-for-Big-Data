# **Algorithms and Data Structers for Big Data**
## **Assignment 2 | Due Date : 03 Nov 2021**
## Problem Description

Create structure to store details of Employees. Data need to be stored are Name, EmpID, Phone number, Designation and salary.

Store this information in “Employee.txt” file. Read the data from file and perform the following actions.

1. Count total number of employees.

2. Count number employees with same designation.

3. Total salary of all employees.

4. Place the employees in separate files based on their designation.
---
```
 ⚠️ Note : All the text files are in binary format
 ```
 ---
## Header File [`file.h`](file.h)

```c
#define INVALID -1
#define SIZE 30
#ifndef EMP_H_INCLUDED
#define EMP_H_INCLUDED

/*1Create Structure to store details of Employees. Data need to be stored are Name, EmpID, Phone number,Designation, Salary.*/
typedef struct _employee_
{
    char name[SIZE];
    int id;
    double phone;
    char designation[SIZE];
    int salary;

}Employee;

#endif // EMP_H_INCLUDED

void add_employee_to_file();
int count_employees(char *file_name);
int number_of_employees_with_same_designation(char *file_name,char* designation);
int total_salary(char *file_name);
void employees_separate_designation(char *file_name);
```

### Data Structure to store Employee information

```c
/*1. Create Structure to store details of Employees. Data need to be stored are Name, EmpID, Phone number,Designation, Salary.*/
typedef struct _employee_
{
    char name[SIZE];
    int id;
    double phone;
    char designation[SIZE];
    int salary;

}Employee;
```

---

## Functions [`file.c`](file.c)

**Create structure to store details of Employees. Data need to be stored are Name, EmpID, Phone number, Designation and salary. Store this information in “Employee.txt” file. Read the data from file and perform the following actions.**

```c
/* Create Structure to store details of Employees. Data need to be stored are Name, EmpID, Phone number,Designation, Salary.
  *Store this information in "Employee.txt" file. Read the data from the file and perform the following actions.
*/
void add_employee_to_file()
{
    FILE *file;

    //Create Employee.txt file
    file = fopen("Employee.txt","w");
    assert( file != NULL);

    //Create employees
    Employee e1 = {"Prathik", 101, 7022410278, "Developer",50000};
    Employee e2 = {"Rohan", 102, 9876542541, "Senior Developer", 80000};
    Employee e3 = {"Sohan", 103, 8546547892, "Senior Developer", 90000};

    //Write employees to file in binary write mode
    fwrite(&e1, sizeof(Employee), 1, file);
    fwrite(&e2, sizeof(Employee), 1, file);
    fwrite(&e3, sizeof(Employee), 1, file);

    fclose(file);

}
```

---

**1. Count total number of employees.**

```c
//1.Count Total number of employees.
int count_employees(char *file_name)
{
    Employee e;
    int count=0;

    FILE *file;
    file = fopen(file_name,"r");
    assert (file != NULL);

    //Read until fread returns 0
    while(fread(&e, sizeof(Employee), 1, file))
        count++;

    return count;
}
```

---

**2. Count number employees with same designation.**

```c
//2.Count number of employees with same designation
int number_of_employees_with_same_designation(char * file_name,char* designation)
{
    int count=0;
    FILE *file;
    file = fopen(file_name,"r");
    assert (file != NULL);

    Employee e;
    while(fread(&e, sizeof(Employee), 1, file))
    {
        if(!strcmp(e.designation,designation))
        {
            count++;
        }
    }
    return count;
}
```

---

**3. Total salary of all employees.**

```c
//3.Total Salary of all employees
int total_salary(char *file_name)
{
    int sum=0;
    FILE *file;
    file = fopen(file_name,"r");
    assert (file != NULL);

    Employee e;
    //Read until fread returns 0
    while(fread(&e, sizeof(Employee), 1, file))
    {
        sum+=e.salary;
    }
    return sum;
}
```

---

**4. Place the employees in separate files based on their designation.**

```c
//4. Place the employees in separate file based on their designation
void employees_separate_designation(char *file_name)
{

    Employee e; //Buffer
    FILE *file,*designation1,*designation2;

    //Files to be modified
    file = fopen(file_name,"r");
    designation1 =  fopen("Developer.txt","w");
    designation2 =  fopen("Senior-Developer.txt","w");
    assert(designation1 != NULL);
    assert(designation2 != NULL);
    assert (file != NULL);

    //Add employees to separate files
    while(fread(&e, sizeof(Employee), 1, file))
    {
        if(!strcmp(e.designation,"Developer"))
           fwrite(&e, sizeof(Employee), 1, designation1);

        else if(!strcmp(e.designation,"Senior Developer"))
           fwrite(&e, sizeof(Employee), 1, designation2);
    }

    fclose(file);
    fclose(designation1);
    fclose(designation2);
}
```

---

## Main Function [`main.c`](main.c)

```c

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "file.h"

/******-----------------Test Functions-------------------*******/

void test_add_employee_to_file(){
    Employee e1;
    add_employee_to_file();

    FILE *file;
    file = fopen("Employee.txt","r");
    assert(file != NULL);

    //Test for first employee
    fread(&e1,sizeof(Employee),1,file);
    assert(!strcmp(e1.name,"Prathik"));
    assert(e1.id == 101);
    assert(e1.phone == 7022410278);
    assert(!strcmp(e1.designation,"Developer"));
    assert(e1.salary == 50000);

     //Test for Second employee
    fread(&e1,sizeof(Employee),1,file);
    assert(!strcmp(e1.name,"Rohan"));
    assert(e1.id == 102);
    assert(e1.phone == 9876542541);
    assert(!strcmp(e1.designation,"Senior Developer"));
    assert(e1.salary == 80000);

    fclose(file);

}

void test_count_employees()
{
    assert(count_employees("Employee.txt") == 3);
}

void test_number_of_employees_with_same_designation()
{
    assert(number_of_employees_with_same_designation("Employee.txt","Developer")== 1 );
    assert(number_of_employees_with_same_designation("Employee.txt","Senior Developer")== 2 );

}

void test_total_salary()
{
    assert(total_salary("Employee.txt") == 220000);
}

void test_employee_seperate_designation()
{
    employees_separate_designation("Employee.txt");
    assert(count_employees("Developer.txt") == 1);
    assert(count_employees("Senior-Developer.txt") == 2);
}

/********---------Main Function-----------********/
int main()
{
        test_add_employee_to_file();
        test_count_employees();
        test_number_of_employees_with_same_designation();
        test_total_salary();
        test_employee_seperate_designation();
        return 0;

}
```
