#ifndef APPCONST_H_INCLUDED
#define APPCONST_H_INCLUDED

#if MAX_DEPTH < 32
#undef MAX_DEPTH
#define MAX_DEPTH	32
#endif

typedef enum {
    QUEUE_OK = 1,
    QUEUE_FULL,
    QUEUE_EMPTY
}QueueStatus;

#endif // APPCONST_H_INCLUDED
