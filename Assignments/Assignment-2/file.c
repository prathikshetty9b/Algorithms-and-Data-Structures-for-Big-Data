/*********
Author: Prathik B Shetty
Date: 29 Oct 2021
**********/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "file.h"

/*1. Create Structure to store details of Employees. Data need to be stored are Name, EmpID, Phone number,Designation, Salary.
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
