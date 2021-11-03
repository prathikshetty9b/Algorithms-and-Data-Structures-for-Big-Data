/*********
Author: Prathik B Shetty
Date: 28 Oct 2021
**********/

#include <stdio.h>
#include <assert.h>
#include "file.h"

/*---------------------------------------------Assignment 1 -------------------------------------------------------------*/

//1.Text file contains ‘n’ numbers. Compute the sum of ‘n’ numbers present in file.
void test_sum_of_n_mumbers_in_file()
{
    assert(sum_of_n_mumbers_in_file(2,"numbers.txt") == 3);
}

//2.Write function to generate square of a number. Numbers comes from text file. Squared number should be written to another file.
void test_find_square_and_write_to_file()
{
    assert(find_square_and_write_to_file("numbers.txt","squares.txt") == 1);
}

//3.Text file contains ‘n’ numbers, one number per line. Write function to store the numbers in other file in reversed order.
// (Let as assume that source.txt contains 10, 25, 30, 35, 50. Then dest.txt should contain 50, 35, 30, 25, 10).

void test_store_n_numbers_in_reversed_order()
{
    assert(store_n_numbers_in_reversed_order(5,"source.txt","dest.txt") == 1);
}

//4.Text file contains some text data (some sentences). Write function to compute number of times a pattern present in the given text data.
//  Pattern is passed as argument to function.
void test_count_text_pattern()
{
    assert(count_text_pattern("Hello how do you do?","count.txt") == 4);
}

//5.Text file contain one sentence per line. Write function to find the length of each lines and write it to another file.
//  Function should return length of longest sentence.
void test_length_of_each_line_in_file()
{
    assert(length_of_each_line_in_file("sentences.txt","length.txt") == 86);
}



int main()
{
    //test functions
    test_sum_of_n_mumbers_in_file();
    test_find_square_and_write_to_file();
    test_store_n_numbers_in_reversed_order();
    test_count_text_pattern();
    test_length_of_each_line_in_file();
    return 0;
}

