#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "header.h"


void test_add_employee_to_file()
{



    add_employee_to_file();

    //add_employee_to_file("Rohan",102,7022410025,"Senior Developer",80000);


}

int main()
{
    //test_add_employee_to_file();
    //display_employee();
    count_employees();
    char *desi = "Developer";
    number_of_employees_with_same_designation("Developer");
    //char desi1 = "Developer";
    //number_of_employees_with_same_designation(desi1);
    total_salary();
    employees_separate_designation();
    return 0;
}
