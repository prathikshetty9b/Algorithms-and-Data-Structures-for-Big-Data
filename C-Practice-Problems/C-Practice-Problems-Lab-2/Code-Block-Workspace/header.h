#define INVALID -1
#define MAX_SIZE 20
#ifndef EMP_H_INCLUDED
#define EMP_H_INCLUDED


typedef struct _employee_
{
    char name[40];
    int id;
    int phone;
    char designation[30];
    int salary;

}Employee;

#endif // EMP_H_INCLUDED

void add_employee_to_file();
void display_employee();
int count_employees();
int number_of_employees_with_same_designation(char*);
int total_salary();
int employees_separate_designation();
