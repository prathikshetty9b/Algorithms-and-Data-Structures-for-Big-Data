/***************************
* Author : Prathik B Shetty
* Date : 09 Jan 2022
****************************/

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void assert_sorting(int32_t list[], int16_t size)
{
    for(int32_t pass = 0; pass < size - 1; pass++)
        assert(list[pass] <= list[pass + 1]);
}

void test_bubble_sort()
{
    int32_t list[5] = {5,4,6,2,1};
    bubble_sort(list,5);
    assert_sorting(list,5);
}

void test_selection_sort()
{
    int32_t list[5] = {5,4,6,2,1};
    selection_sort(list,5);
    assert_sorting(list,5);
}

void test_insertion_sort()
{
    int32_t list[5] = {10,5,7,2,9};
    insertion_sort(list,5);
    assert_sorting(list,5);
}

void test_quick_sort()
{
    int32_t list[5] = {5,4,6,2,1};
    quick_sort(list,0,4);
    assert_sorting(list,5);
}

void test_merge_sort()
{
    int32_t list[5] = {10,5,7,2,9};
    merge_sort(list,0,4);
    assert_sorting(list,5);
}

int main()
{
    test_bubble_sort();
    test_selection_sort();
    test_insertion_sort();
    test_quick_sort();
    test_merge_sort();
    return 0;
}
