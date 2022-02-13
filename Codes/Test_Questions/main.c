#include <stdio.h>
#include <stdlib.h>
#include "trade.h"
int main()
{
    Queue queue = queue_new();
    Queue *q = &queue;

    Transac transac = {"","",0,0,0,NULL};
    Transac *t = &transac;

    buy_stock(q,t,"Avani","20102000",202.2,100);

    assert(q->count == 1 && strcmp(q->rear->name,"Avani") == 0 && strcmp(q->front->name,"Avani") == 0 && q->front->quantity == 100);


    buy_stock(q,t,"Avani","20102000",202.2,100);

    assert(q->count == 1 && strcmp(q->rear->name,"Avani") == 0 && strcmp(q->front->name,"Avani") == 0 && q->front->quantity == 200);
    assert(q->front->next == NULL);

    buy_stock(q,t,"Aayush","20102020",1000,200);

    assert(q->count == 2 && strcmp(q->rear->name,"Aayush") == 0 && strcmp(q->front->name,"Avani") == 0 && q->rear->quantity == 200);

    buy_stock(q,t,"Prathik","20102020",100,10);
    buy_stock(q,t,"SK","20102020",100,420);
    buy_stock(q,t,"Niriksha","20102020",100,421);

    assert(q->count == 5 && strcmp(q->rear->name,"Niriksha") == 0 && strcmp(q->front->name,"Avani") == 0 && q->rear->quantity == 421);


    //assert(q->count == 4 && strcmp(q->rear->name,"Niriksha") == 0 && strcmp(q->front->name,"Aayush") == 0 && q->front->quantity == 200);
    sell_stock_partial(q,t,"Avani",80);
    assert(q->count == 5 && strcmp(q->rear->name,"Niriksha") == 0 && strcmp(q->front->name,"Avani") == 0 && q->front->quantity == 120);

    buy_stock(q,t,"Pradyumns","20102020",100,421);

    assert(q->count == 5 && strcmp(q->rear->name,"Pradyumns") == 0 && strcmp(q->front->name,"Aayush") == 0 && q->front->quantity == 200);
    assert(q->count == 5);
    sell_stock(q,t);

    assert(q->count == 4 && strcmp(q->rear->name,"Pradyumns") == 0 && strcmp(q->front->name,"Prathik") == 0 && q->front->quantity == 10);

    /*assert(q->count == 4);
    assert(strcmp(q->rear->name,"Niriksha")==0);
    assert(strcmp(q->front->name,"Aayush")==0);*/


    return 0;

}
