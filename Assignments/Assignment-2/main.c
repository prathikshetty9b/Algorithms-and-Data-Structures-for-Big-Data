/*********
Author: Prathik B Shetty
Date: 28 Oct 2021
**********/

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
    assert(count_employees() == 3);
}

void test_number_of_employees_with_same_designation()
{
    assert(number_of_employees_with_same_designation("Developer")== 1 );
    assert(number_of_employees_with_same_designation("Senior Developer")== 2 );

}

void test_total_salary()
{
    assert(total_salary() == 220000);
}

void test_employee_seperate_designation()
{

}

/********---------Main Function-----------********/
int main()
{
        test_add_employee_to_file();
        test_count_employees();
        test_number_of_employees_with_same_designation();
        test_total_salary();
        return 0;

}
