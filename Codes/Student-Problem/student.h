#include <assert.h>
#include <stdlib.h>
#include <string.h>


//data Structures
typedef struct _student_ Student;
struct _student_{
    char name[20];
    char program[20];
    char grade;
    int marks;
    Student *next;
};

typedef struct _slist_ Slist;
struct _slist_
{
    Student *head;
    Student *tail;
    int count;
};


//functions
Slist create_list();
Slist* add_student(Slist *list ,char name[20],int marks,char program[20],char grade);
int search_student_max(Slist *slist);
