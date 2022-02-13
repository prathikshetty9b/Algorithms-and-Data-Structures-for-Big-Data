#include <stdio.h>
#include <assert.h>
#include "header.h"
//---------------------------------------------LAB 1 -------------------------------------------------------------

//1.Text file contains ‘n’ numbers. Compute the sum of ‘n’ numbers present in file.
void test_sum_of_n_mumbers_in_file()
{
    assert(sum_of_n_mumbers_in_file(2) == 3);
    assert(sum_of_n_mumbers_in_file(5) == 15);
    assert(sum_of_n_mumbers_in_file(10) == 56);
    assert(sum_of_n_mumbers_in_file(-10) == INVALID);
}

//2.Write function to generate square of a number. Numbers comes from text file. Squared number should be written to another file.
void test_find_square_and_write_to_file()
{
    assert(find_square_and_write_to_file() == 1);
}

//3.Text file contains ‘n’ numbers, one number per line. Write function to store the numbers in other file in reversed order.
// (Let as assume that source.txt contains 10, 25, 30, 35, 50. Then dest.txt should contain 50, 35, 30, 25, 10).

void test_store_n_numbers_in_reversed_order()
{
    assert(store_n_numbers_in_reversed_order(5) == 1);
}

//4.Text file contains some text data (some sentences). Write function to compute number of times a pattern present in the given text data.
//  Pattern is passed as argument to function.
void test_count_text_pattern()
{
    assert(count_text_pattern("Hello how do you do?") == 4);
}

//5.Text file contain one sentence per line. Write function to find the length of each lines and write it to another file.
//  Function should return length of longest sentence.
void test_length_of_each_line_in_file()
{
    assert(length_of_each_line_in_file() == 86);
}

//--------------------------------------------------------------Lab 2 -------------------------------------------------------


int main()
{

    test_sum_of_n_mumbers_in_file();
    test_find_square_and_write_to_file();
    test_store_n_numbers_in_reversed_order();
    test_count_text_pattern();
    test_length_of_each_line_in_file();
    pass_file(10);
    rewrite_file(10);

    return 0;
}



