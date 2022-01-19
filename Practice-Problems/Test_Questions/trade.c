//
#include "trade.h"

static Node* _get_newnode_(char name[20],char date[10],float price, int quantity)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    strcpy(newnode->name,name);
    strcpy(newnode->date,date);
    newnode->price = price;
    newnode->quantity = quantity;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

Queue queue_new()
{
    Queue q = {NULL,NULL,0,QEMPTY};
    return q;
}

Queue* buy_stock(Queue *q,Transac *res,char name[20],char date[10],float price, int quantity)
{
    assert(q != NULL && res != NULL);
    if(q->count < 5)
    {
        if(!stock_lookup(q,name))
        {

            Node* newnode = _get_newnode_(name,date,price,quantity);

            if(q->count == 0)
            {
                q->front = q->rear = newnode;
            }
            else
            {
                newnode->prev = q->rear;
                q->rear->next = newnode;
                q->rear =newnode;
            }
            q->count++;
            q->status = QOK;
        }
        else
        {
            stock_topup(q,name,quantity,price,res);
        }



    }
    else
    {
        if(!stock_lookup(q,name))
        {
            sell_stock(q,res);
            buy_stock(q,res,name,date,price,quantity);
        }
        else
        {
            stock_topup(q,name,quantity,price,res);
        }
    }
    return q;

}

Queue* sell_stock(Queue *q, Transac *res)
{
    assert(q != NULL && res != NULL);

    Node *del = q->front;
    if(q->count > 0)
    {
        //Only one share in queue
        if(q->count == 1)
            q->rear = NULL;

        q->front = q->front->next;
        //q->front->prev = NULL;
        --q->count;
        q->status = QOK;

    }
    else
    {
        q->status = QEMPTY;
    }
    free(del);
    return q;

}

Queue* sell_stock_partial(Queue *q,Transac *res, char name[20],int quantity)
{
    assert(q != NULL && res!=NULL);
    Node* cur;
    for(cur = q->front;cur != NULL;cur=cur->next)
    {
        if(!strcmp(cur->name,name))
        {
            if(cur->quantity >= quantity)
            {
                cur->quantity -= quantity;
                break;
            }
        }
    }
    return q;
}

int stock_lookup(Queue *q, char name[20])
{
    assert(q != NULL);
    Node* cur;
    for(cur = q->front;cur != NULL;cur=cur->next)
    {
        if(!strcmp(cur->name,name))
            return 1;

    }
    return 0;
}

Queue* stock_topup(Queue *q,char name[20],int quantity, float price, Transac *res)
{
    assert(q != NULL && res!=NULL);
    assert(q != NULL);
    Node* cur;
    for(cur = q->front;cur != NULL;cur=cur->next)
    {
        if(!strcmp(cur->name,name))
        {
            cur->quantity += quantity;
            break;
        }
    }
    return q;
}
