#ifndef TRADE_HEADER_INCLUDED
#define TRADE_HEADER_INCLUDED

//Headers
#include<assert.h>
#include<stdlib.h>
#include<string.h>

//Constants
#define QOK 1
#define QEMPTY 0
#define QFULL 2

//Data Structures
typedef struct _node_ Node;
struct _node_{
    char name[20];
    char date[10];
    float price;
    int quantity;
    Node *next;
    Node *prev;
};

typedef struct _queue_ Queue;
struct _queue_{
    Node *front;
    Node *rear;
    int count;
    int status;
};
//Transaction part Incomplete
typedef struct _transaction_ Transac;
struct _transaction_{
    char date[10];
    char name[20];
    int quantity;
    float price;
    int buysell;
    Transac *next;
};



//Functions
Queue queue_new();
Queue* buy_stock(Queue *q, Transac *res,char name[20], char date[10], float price, int quantity);
Queue* sell_stock(Queue *q,Transac *res);
Queue* sell_stock_partial(Queue *q,Transac *res, char name[20],int quantity);
int stock_lookup(Queue *q,char name[20]);
Queue* stock_topup(Queue *q,char name[20],int quantity, float price, Transac *res);

//When person buy share (enqueue), details like share name, date, price and quantity are stored in
//“Trading Q”. Date can be taken as string like “22-12-2020”.


#endif
