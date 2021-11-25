
#include "student.h"
//static Student* _get_new_student_(int marks)
static Student* _get_new_student_(char name[20],char program[20],char grade,int marks)
{
    Student * new_student = (Student*)malloc(sizeof(Student));
    strcpy(new_student->name,name);
    strcpy(new_student->program,program);
    new_student->grade = grade;
    new_student->marks = marks;
    new_student->next = NULL;
    return new_student;
}

Slist create_list()
{
    Slist list = {NULL,NULL,0};
    return list;
}
//Slist* add_student(Slist *list,int marks)
Slist* add_student(Slist* list,char name[20],int marks,char program[20],char grade)
{
    assert(list != NULL);
   // Student *new_student = _get_new_student_(marks);

    Student *new_student = _get_new_student_(name,program,grade,marks);

    //At head if marks greater than head
    if(list->count > 0 && list->head->marks < marks)
    {
        new_student->next = list->head;
        list->head = new_student;
    }
    else if(list->count > 0 && list->head->marks >= marks)
    {
        list->tail->next = new_student;
        list->tail = new_student;
    }
    else
    {
        list->head = list->tail = new_student;
    }
    list->count++;
    return list;

}

int search_student_max(Slist *list)
{
    assert(list != NULL && list->count >0);
    return list->head->marks;
}
