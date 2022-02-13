#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

void test_char_queue() {
    Queue q1 = queue_new(40);
    Queue *q = &q1;
    QueueResult res;

    q = queue_add(q, 'A', &res);
    q = queue_add(q, 'B', &res);
    q = queue_add(q, 'C', &res);

    q = queue_delete(q, &res);
    assert(res.data == 'A');
    printf ("Deleted element: %c\n", res.data);
    printf("Queue size %d\n", q->size);

}

void test_double_queue() {
    Queue q1 = queue_new(50);
    Queue *q = &q1;
    QueueResult res;

    q = queue_add(q, 25.45, &res);
    q = queue_add(q, 12345.987, &res);
    q = queue_add(q, 3536.34, &res);

    q = queue_delete(q, &res);
    assert(res.data == 25.45);
    printf ("Deleted element: %lf\n", res.data);
    printf("Queue size %d\n", q->size);

}

int main(){

    //test_char_queue();
    //test_double_queue();
    return 0;
}

/*
*   command to compile
*   gcc -Wall -D QUEUE_CONTENT_TYPE="double" -D MAX_DEPTH=50 queue.c main.c -o AQ
*/
