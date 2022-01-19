/***************************
* Author : Prathik B Shetty
* Date : 09 Jan 2022
****************************/

#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#define ARRAY_SIZE 100

//Headers
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>

//User Defined Functions
void bubble_sort(int32_t list[], uint16_t size);
void selection_sort(int32_t list[], uint16_t size);
void insertion_sort(int32_t list[], uint16_t size);
void quick_sort(int32_t list[], uint16_t start, uint16_t end);
void merge_sort(int32_t list[], uint16_t low, uint16_t high);

#endif // SORT_H_INCLUDED
