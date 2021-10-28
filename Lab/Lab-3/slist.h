/************
* Author: Prathik B Shetty
* Date: 27 October, 2021
* Purpose:
*************/

#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED
#include <stdint.h>

/* Data Structures */

typedef struct _node_ Node; /*Node of a linked list*/
struct _node_
{
    int32_t data; //Computer architecture independent
    Node *next;
};

typedef struct _slist_ Slist;
struct _slist_
{
    Node *head;//Linked List starting address
    Node *tail;//Address of last node
    uint32_t count;//Number of nodes
};

/* Public Interface */
Slist slist_new();
uint32_t slist_count(const Slist *list);
Slist* slist_add_at_head(Slist *list,int32_t element);
Slist* slist_add_at_tail(Slist *list,int32_t element);
uint8_t slist_lookup(const Slist *list,int32_t key);

#endif // SLIST_H_INCLUDED
