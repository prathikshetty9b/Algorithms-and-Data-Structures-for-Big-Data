/************
* Author: Prathik B Shetty
* Date: 27 October, 2021
* Purpose:
*************/

#include <stdlib.h>
#include <assert.h>
#include "slist.h"

//New list with no nodes
Slist slist_new()
{
    Slist list = {NULL,NULL,0};
    return list;
}

//Returns number of nodes in the linked list
uint32_t slist_count(const Slist *list)
{
    assert(list != NULL);
    return list->count;
}

//Create new node
static Node* _get_new_node_(int32_t ele)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = ele;
    new_node->next = NULL;

    return new_node;
}

//Add new element at head
Slist* slist_add_at_head(Slist *list,int32_t element)
{
    assert(list != NULL);
    Node *new_node = _get_new_node_(element);
    new_node->next = list->head;
    list->head = new_node;

    //Check if the node is first node
    if (list->tail == NULL)
        list->tail = new_node;

    ++list->count;
    assert((list->head == list->tail && list->count == 1) || (list->head != list->tail && list->count !=0));

    return list;
}
//Add new element at tail
Slist* slist_add_at_tail(Slist *list, int32_t element)
{
    assert(list != NULL);
    Node *new_node = _get_new_node_(element);
    new_node->next = NULL;
    if(list->tail != NULL)
    {
       list->tail->next = new_node;
       list->tail = new_node;
    }
    else
    {
        list->tail = list->head = new_node;
    }


    ++list->count;
    assert((list->head == list->tail && list->count == 1) || (list->head != list->tail && list->count !=0));

    return list;

}
//Look for an element in the linked list
uint8_t slist_lookup(const Slist *list, int32_t key)
{
    assert(list != NULL);
    Node *cur;
    for(cur = list->head;  cur != NULL; cur = cur->next)
    {
        if(cur->data == key)
            break;
    }

    return(cur != NULL);
}

