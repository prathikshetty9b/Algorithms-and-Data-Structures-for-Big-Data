/************
* Author: Prathik B Shetty
* Date: 27 October, 2021
* Purpose:
*************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.h"

void test_empty_list()
{
   Slist l1 = slist_new();
   Slist *list = &l1;
   assert(slist_count(list) == 0);
}

void test_add_node_at_head()
{
    Slist l1 = slist_new();
    Slist *list = &l1;
    //Add one element
    list = slist_add_at_head(list,10);
    assert(slist_count(list) == 1);
    //Add 4 more elements
    list = slist_add_at_head(list,20);
    list = slist_add_at_head(list,30);
    list = slist_add_at_head(list,40);
    list = slist_add_at_head(list,50);
    assert(slist_count(list) == 5);


    //Search for elements
    assert(slist_lookup(list,20) == 1);
    assert(slist_lookup(list,50) == 1);
    assert(slist_lookup(list,60) == 0);
    assert(slist_lookup(list,10) == 1);

}

void test_add_node_at_tail()
{
    Slist l1 = slist_new();
    Slist *list = &l1;
    //Add one element
    list = slist_add_at_tail(list,10);
    assert(slist_count(list) == 1);
    //Add 3 more elements
    list = slist_add_at_tail(list,20);
    list = slist_add_at_tail(list,30);
    list = slist_add_at_tail(list,40);
    assert(slist_count(list) == 4);

    //Search for elements
    assert(slist_lookup(list,20) == 1);
    assert(slist_lookup(list,50) == 0);
    assert(slist_lookup(list,60) == 0);
    assert(slist_lookup(list,10) == 1);

    //Check data in tail
    assert(list->tail->data == 40);
    list = slist_add_at_tail(list,70);
    assert(list->head->data == 10);

}

int main()
{
    test_empty_list();
    test_add_node_at_head();
    test_add_node_at_tail();
    return 0;
}
