#include "student.h"

void test_student()
{
    Slist l = create_list();
    Slist *list = &l;

    assert(list->head == NULL && list->tail ==  NULL && list->count == 0);

    list = add_student(list,"Avani",100,"BDA",'A');
    //list = add_student(list,name,100);
    assert(strcmp(list->head->name,"Avani") == 0);
    assert(list->head->marks == 100);

    assert(search_student_max(list) == 100);

    list = add_student(list,"Nithesh",200,"CLO",'A');

    assert(search_student_max(list) == 200);
    assert(list->tail->marks == 100);
}

int main()
{
    test_student();
    return 0;
}
