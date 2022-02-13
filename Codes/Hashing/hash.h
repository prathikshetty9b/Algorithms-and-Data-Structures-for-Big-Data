/************
* Author: Prathik B Shetty
* Date: 02 Feb 2022
*************/


#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#define MAXLEN 50

//Headers
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

//Data Structures

typedef struct _node_ Node;
struct _node_{
    char data[MAXLEN];
    Node *next;
};

typedef struct _hashtable_ HashTable;
struct _hashtable_{
    uint16_t table_size;
    Node **table_address;
};

// User Defined Functions
/*
static int32_t _generate_hashcode_(char *data);
static uint16_t _generate_index_(int32_t hashcode, uint16_t t_size);
static uint16_t _hash_(char *data, uint16_t t_size);*/

HashTable   hashtable_new(uint16_t size);
uint8_t     hashtable_lookup(HashTable *htb, char *key);
HashTable*   hashtable_add_element(HashTable *htb, char *data);
HashTable*   hashtable_del_element(HashTable *htb, char *data);


#endif // HASH_H_INCLUDED
