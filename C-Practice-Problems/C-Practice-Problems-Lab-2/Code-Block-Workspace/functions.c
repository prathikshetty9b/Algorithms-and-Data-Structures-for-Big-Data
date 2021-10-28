#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "header.h"


//1. Create Structure to store details of Employees. Data need to be stored are Name, EmpID, Phone number,Designation, Salary.
//   *Store this information in "Employee.txt" file. Read the data from the file and perform the following actions.
//   ->Count Total number of employees.
//   ->Count number of employees with same designation
//   ->Total Salary of all employees.
//   ->Place the employees in separate file based on their designation.

/*static Employee get_employee()
{
    Employee e1 = {"Prathik", 1200, 7022, "Developer", 20000};
    return e1;
}*/

void add_employee_to_file( )
{


    FILE *file;

    file = fopen("Employee.txt","w");
    assert( file != NULL);

    //Employee emp = get_employee();
    Employee e1 = {"Prathik", 1200, 7022, "Developer", 20000};
    Employee e2 = {"Rohan", 1200, 7022, "Trainee", 15000};
    Employee e3 = {"Cane", 1200, 7022, "Developer", 20000};

    fwrite(&e1, sizeof(Employee), 1, file);
    fwrite(&e2, sizeof(Employee), 1, file);
    fwrite(&e3, sizeof(Employee), 1, file);

    //fprintf(file,"%s,%d,%d,%s,%d\n",emp.name,emp.id,emp.phone,emp.designation,emp.salary);


    fclose(file);


}

void display_employee()
{
    Employee e;
    FILE *file;
    file = fopen("Employee.txt","r");
    assert (file != NULL);

    //Read until fread returns 0
    while(fread(&e, sizeof(Employee), 1, file))
        printf("\t%s,%d,%d,%s,%d\n",e.name,e.id,e.phone,e.designation,e.salary);


}

//Count Total number of employees.
int count_employees()
{
    Employee e;
    int count=0;

    FILE *file;
    file = fopen("Employee.txt","r");
    assert (file != NULL);

    //Read until fread returns 0
    while(fread(&e, sizeof(Employee), 1, file))
        count++;

    printf("\tNumber of Records : %d",count);
    return count;
}

//Count number of employees with same designation
int number_of_employees_with_same_designation(char* desi)
{
    int count=0,count1=0;
    FILE *file;
    file = fopen("Employee.txt","r");
    assert (file != NULL);

    Employee e;
    while(fread(&e, sizeof(Employee), 1, file))
    {
        if(!strcmp(e.designation,desi))
        {
            count++;
        }
    }
    printf("Count = %d",count);
    return count;
}
//Total Salary of all employees
int total_salary()
{
    int sum=0;
    FILE *file;
    file = fopen("Employee.txt","r");
    assert (file != NULL);

    Employee e;
    while(fread(&e, sizeof(Employee), 1, file))
    {
        sum+=e.salary;
    }
    printf("Total Salary = %d",sum);
    return sum;
}

//Place the employees in separate file based on their designation
int employees_separate_designation()
{
    int sum=0;
    FILE *file,*desi1,*desi2;
    file = fopen("Employee.txt","r");
    assert (file != NULL);

    Employee e;
    while(fread(&e, sizeof(Employee), 1, file))
    {
        if(!strcmp(e.designation,"Developer"))
        {
           desi1 =  fopen("Desi1.txt","a");
           fwrite(&e, sizeof(Employee), 1, desi1);
           fclose(desi1);
        }
        else if(!strcmp(e.designation,"Trainee"))
        {
           desi2 =  fopen("Desi2.txt","a");
           fwrite(&e, sizeof(Employee), 1, desi2);
           fclose(desi2);
        }
    }
    //printf("Total Salary = %d",sum);
    return sum;
}
