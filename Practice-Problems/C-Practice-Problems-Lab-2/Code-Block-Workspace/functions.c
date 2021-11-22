#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "header.h"


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
    Employee e1 = {"Prathik",101, 7022410278, "Developer",50000};
    Employee e2 = {"Rohan", 102, 9876542541, "Senior Developer", 80000};
    Employee e3 = {"Sohan", 103, 8546547892, "Senior Developer", 90000};

    //Write employees to file in binary write mode
    fwrite(&e1, sizeof(Employee), 1, file);
    fwrite(&e2, sizeof(Employee), 1, file);
    fwrite(&e3, sizeof(Employee), 1, file);

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
//3.Total Salary of all employees
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
