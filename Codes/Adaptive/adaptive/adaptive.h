#define MAX_DEPTH 32
#define QUEUE_OK 4
#define QUEUE_EMPTY 0
#define QUEUE_FULL 1

#ifndef DATATYPE
#define DATATYPE int
#endif

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include<stdint.h>
#include<assert.h>

//Data Structures
typedef struct _queue_ Queue;
typedef struct _queue_result_ QueueResult;

struct _queue_{
    uint32_t size;
    uint32_t front;
    uint32_t rear;
    uint32_t count;
    DATATYPE data[MAX_DEPTH];
};

struct _queue_result_{
    DATATYPE data;
    uint8_t status;
};

//user defined functions
Queue queue_new(uint32_t size);
uint8_t queue_empty(Queue *q);
uint8_t queue_full(Queue *q);
Queue* queue_add(Queue *q, DATATYPE element, QueueResult *res);
Queue* queue_delete(Queue *q,QueueResult *res);

#endif // QUEUE_H_INCLUDED

