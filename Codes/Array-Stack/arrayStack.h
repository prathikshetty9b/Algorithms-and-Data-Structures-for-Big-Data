
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "constants.h"
#include <stdint.h>

//Data Structures
typedef struct _stack_ Stack;
typedef struct _stack_result_ StackResult;

struct _stack_{
    uint32_t size;
    int32_t top;
    int data[MAX_DEPTH];

};

struct _stack_result_{
    int data;
    uint8_t status;
};

//User defined Functions
Stack stack_new(uint32_t size);
uint8_t stack_empty(Stack *stk);
uint8_t stack_full(Stack *stk);
Stack* stack_push(Stack *stk, int element, StackResult *res);
Stack* stack_pop(Stack *stk,StackResult *res);
int stack_peek(Stack *stk,StackResult *res);

#endif // STACK_H_INCLUDED
