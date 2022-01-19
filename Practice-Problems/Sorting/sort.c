/***************************
* Author : Prathik B Shetty
* Date : 09 Jan 2022
****************************/

#include "sort.h"


//Swap Function
static void _swap_(int32_t *num1, int32_t *num2)
{
    int32_t temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

//Bubble Sort
void bubble_sort(int32_t list[], uint16_t size)
{
    for(int16_t pass = 0; pass < size - 1; pass++)
    {
        for(int16_t index = size - 1; index > pass ; index--)
        {
            //Swap if previous element is greater than current element
            if(list[index] < list[index - 1])
                _swap_(&list[index],&list[index - 1]);
        }
    }
}

//Selection Sort
void selection_sort(int32_t list[], uint16_t size)
{
    int16_t min_pos;
    for(int16_t pass = 0; pass < size - 1; pass++)
    {
        min_pos = pass;
        for(int16_t index = size -1; index > pass; index--)
        {
            if(list[index] < list[min_pos])
                min_pos = index;
        }
        _swap_(&list[pass],&list[min_pos]);
    }
}

//Insertion Sort
void insertion_sort(int32_t list[], uint16_t size)
{
    int32_t key;
    int16_t pass, index;

    for(pass = 1; pass < size; pass++)
    {
        key = list[pass];
        index = pass - 1;
        while(index >= 0 && list[index] > key)
        {
            //Right shift
            list[index + 1] = list[index];
            index--;
        }
        //Insert element to correct position
        list[index+1] = key;
    }
}

//Quick Sort
static uint16_t _partition_(int32_t list[],uint16_t start, uint16_t end)
{
    uint16_t up,down;
    up = start;
    down = end;

    int32_t pivot = list[start];

    do
    {
        while(list[up] <= pivot && up <= down)
            ++up;
        while(list[down] > pivot && up <= down)
            --down;
        if(up < down)
            _swap_(&list[up],&list[down]);
    }while(up <= down);

    _swap_(&list[down],&list[start]);

    return down;
}

void quick_sort(int32_t list[], uint16_t start, uint16_t end)
{
    uint16_t mid;
    //More than 1 element
    if(start < end)
    {
        mid = _partition_(list,start,end);
        quick_sort(list,start,mid);
        quick_sort(list,mid+1,end);
    }
}

//Merge Sort
static void _merge_(int32_t list[], uint16_t low, uint16_t mid, uint16_t high)
{
    //pointers for two list and temporary array
    int32_t temp_array[ARRAY_SIZE];
    //pointers for two lists and temporary array
    int16_t f_index = low;
    int16_t s_index = mid+1;
    int16_t t_index = low;

    //Compare elements in two lists and copy the smallest to temp array. Repeat until one
    //of list is exhausted
    while(f_index <= mid && s_index <= high)
    {
        if(list[f_index] < list[s_index])
            temp_array[t_index++] = list[f_index++];
        else
            temp_array[t_index++] = list[s_index++];
    }

    //Copy remaining elements if one of the two lists is exhausted
    if(f_index > mid)
    {
        while(s_index <= high)
            temp_array[t_index++] = list[s_index++];
    }
    else
    {
        while(f_index <= mid)
            temp_array[t_index++] = list[f_index++];
    }

    //Copy sorted list to original list
    for(int16_t index = low; index <= high; index++)
        list[index] = temp_array[index];


}

void merge_sort(int32_t list[], uint16_t low, uint16_t high)
{
    int16_t mid;
    if(low < high)
    {
        mid = (low + high)/2;
        merge_sort(list,low,mid);
        merge_sort(list,mid+1,high);
        _merge_(list,low,mid,high);
    }
}
