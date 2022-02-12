/************
* Author: Prathik B Shetty
* Date: 02 Feb 2022
*************/

#include "hash.h"


//Private Functions


static int32_t _generate_hashcode_(char *data){
    int32_t sum = 0;

    while(*data != '\0')
        sum = (sum << 5) + *data++;

    return sum;
}

static uint16_t _generate_index_(int32_t hashcode, uint16_t tsize){
    return hashcode % tsize;
}

static uint16_t _hash_(char *data, uint16_t tsize) {
    int32_t hashcode = _generate_hashcode_(data);
    uint16_t index = _generate_index_(hashcode,tsize);
    return index;
}

//User Defined Functions

HashTable hashtable_new(uint16_t size){
    HashTable hashtable;
    hashtable.table_size = size;
    hashtable.table_address = (Node**)malloc(sizeof(Node*) * size); //(Size of Node * Max number of nodes in the table)

    //Initialize table entries to Null
    for(uint16_t i = 0; i < hashtable.table_size; ++i)
        hashtable.table_address[i] = NULL;

    return hashtable;
}

uint8_t hashtable_lookup(HashTable *hashtable, char *key){
    assert(hashtable != NULL);

    int16_t index = _hash_(key,hashtable->table_size);
    Node *cur = hashtable->table_address[index];

    while(cur != NULL)
    {
        if(!strcmp(cur->data,key))
            break;
        else
            cur = cur->next;
    }
    return cur != NULL;

}

HashTable* hashtable_add_element(HashTable *hashtable, char *data) {
    assert(hashtable != NULL);

    if(!hashtable_lookup(hashtable,data)) {
        uint16_t bucket = _hash_(data,hashtable->table_size);
        Node *old = hashtable->table_address[bucket];
        //New node for the data
        hashtable->table_address[bucket] = (Node*)malloc(sizeof(Node));
        strcpy(hashtable->table_address[bucket]->data,data);
        //Link previous node with the new one
        hashtable->table_address[bucket]->next = old;
    }

    return hashtable;

}


HashTable* hashtable_del_element(HashTable *hashtable, char *data){
    assert(hashtable != NULL);
    uint16_t bucket = _hash_(data,hashtable->table_size);

    if(hashtable->table_address[bucket] != NULL) {
        Node *cur = hashtable->table_address[bucket];
        if(!strcmp(cur->data,data)) {
            hashtable->table_address[bucket] = cur->next;
            free(cur);
        }
        else {
            while(cur->next != NULL) {
                if(!strcmp(cur->next->data,data)) {
                    Node *del = cur->next;
                    cur->next = cur->next->next;
                    free(del);
                }
                else {
                    cur = cur->next;
                }
            }
        }
    }
    return hashtable;
}
