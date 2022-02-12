/************
* Author: Prathik B Shetty
* Date: 02 Feb 2022
*************/


#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

void test_hashtable(){
    HashTable ht = hashtable_new(11);
    HashTable *htb = &ht;
    assert(htb->table_size == 11);
    hashtable_add_element(htb, "MSIS");
    hashtable_add_element(htb, "MIT");
    hashtable_add_element(htb, "Manipal");

    assert(hashtable_lookup(htb,"MSIS") == 1);

    hashtable_add_element(htb, "Mangalore");
    assert(hashtable_lookup(htb, "Mangalore") == 1);
    hashtable_del_element(htb, "Mangalore");
    assert(hashtable_lookup(htb, "Mangalore") == 0);

}



int main()
{
    test_hashtable();
    return 0;
}
