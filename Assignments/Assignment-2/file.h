/*********
Author: Prathik B Shetty
Date: 28 Oct 2021
**********/

#define INVALID -1
#define SIZE 30
#ifndef EMP_H_INCLUDED
#define EMP_H_INCLUDED

/*1. Create Structure to store details of Employees. Data need to be stored are Name, EmpID, Phone number,Designation, Salary.*/
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
int count_employees();
int number_of_employees_with_same_designation(char* designation);
int total_salary();
void employees_separate_designation();
