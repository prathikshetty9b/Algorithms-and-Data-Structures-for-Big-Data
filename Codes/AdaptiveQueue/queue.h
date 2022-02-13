#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "appconst.h"


#ifndef QUEUE_CONTENT_TYPE
#define QUEUE_CONTENT_TYPE uint32_t
#endif
#include <stdint.h>

typedef struct _queue_ Queue;
typedef struct _queue_result_ QueueResult;

struct _queue_ {
	uint32_t 	size;
	uint32_t	count;
	uint32_t	front;
	uint32_t	rear;
	QUEUE_CONTENT_TYPE		data[MAX_DEPTH];
};

struct _queue_result_ {
	QUEUE_CONTENT_TYPE		data;
	QueueStatus	status;
};


Queue  		queue_new(uint32_t size);
uint32_t	queue_full(Queue *q);
uint32_t	queue_empty(Queue *q);
Queue*		queue_add(Queue* q, QUEUE_CONTENT_TYPE element, QueueResult *res);
Queue*		queue_delete(Queue *q, QueueResult *res);


#endif // QUEUE_H_INCLUDED
