# **Algorithms and Data Structers for Big Data**
## **Assignment 1 | Due Date : 03 Nov 2021**
## Write assert based programs.

1. Text file contains ‘n’ numbers. Compute the sum of ‘n’ numbers present in file.

2. Write function to generate square of a number. Numbers comes from text file. Squared number should be written to another file.

3. Text file contains ‘n’ numbers, one number per line. Write function to store the numbers in other file in reversed order. (Let as assume that source.txt contains 10, 25, 30, 35, 50. Then dest.txt should contain 50, 35, 30, 25, 10).

4. Text file contains some text data (some sentences). Write function to compute number of times a pattern present in the given text data. Pattern is passed as argument to function.

5. Text file contain one sentence per line. Write function to find the length of each lines and write it to another file. Function should return length of longest sentence.

---

## Header file [`file.h`](https://github.com/prathikshetty9b/Algorithms-and-Data-Structures-for-Big-Data/blob/main/Assignments/Assignment-1/file.h)

```c
/*********
Author: Prathik B Shetty
Date: 28 Oct 2021
**********/

#define INVALID -1
#define SIZE 15

int sum_of_n_mumbers_in_file(int n,char file[SIZE]);
int find_square_and_write_to_file(char source[SIZE], char destination[SIZE]);
int store_n_numbers_in_reversed_order(int n,char source[SIZE], char destination[SIZE]);
int count_text_pattern(const char *my_string,char file_name[SIZE]);
int length_of_each_line_in_file(char source_file[SIZE], char destination_file[SIZE]);
```

---

## Functions [`file.c`](https://github.com/prathikshetty9b/Algorithms-and-Data-Structures-for-Big-Data/blob/main/Assignments/Assignment-1/file.c)

**1. Text file contains ‘n’ numbers. Compute the sum of ‘n’ numbers present in file.**

```c
//1.Text file contains ‘n’ numbers. Compute the sum of ‘n’ numbers present in file.
int sum_of_n_mumbers_in_file(int n, char file_name[SIZE])
{
    FILE *file;

    //Open File in read mode
    file = fopen(file_name,"r");
    int number[SIZE];
    int sum = 0;

    //Make sure file is proper and n is greater than 0
    assert( (file != NULL) || (n <= 0) );

    //Iterate through every number in the file
    for(int i=0; i<n ;i++)
    {
        //Read number
        fscanf(file,"%d",&number[i]);

        //add number to sum variable
        sum=sum + number[i];

    }

    fclose(file);
    return sum;
}
```

**2. Write function to generate square of a number. Numbers comes from text file. Squared number should be written to another file.**

```c
//2.Write function to generate square of a number. Numbers comes from text file. Squared number should be written to another file.
int find_square_and_write_to_file(char source[SIZE], char destination[SIZE])
{
    FILE *file_1, *file_2;

    //Open File 1 in read mode
    file_1 = fopen(source, "r");

    //Clear contents of File 2
    fclose(fopen(destination,"w"));
    int number,square;

    //Check if the file is empty or not
    assert(file_1 != NULL);

    //Run loop until it reaches end of file
    while(!feof(file_1))
    {
        fscanf(file_1,"%d",&number);
        if(!feof(file_1))
        {
            //Find Square
            square = number * number;

            //Open File 2 in append mode
            file_2 = fopen(destination, "a");
            //Write Squared numbers to the file
            fprintf(file_2,"%d",square);
            fprintf(file_2,"\n");
            //close file 2
            fclose(file_2);
        }

    }
    fclose(file_1);
    return 1;
}
```

**3. Text file contains ‘n’ numbers, one number per line. Write function to store the numbers in other file in reversed order. (Let as assume that source.txt contains 10, 25, 30, 35, 50. Then dest.txt should contain 50, 35, 30, 25, 10).**

```c
//3.Text file contains ‘n’ numbers, one number per line. Write function to store the numbers in other file in reversed order.
// (Let as assume that source.txt contains 10, 25, 30, 35, 50. Then dest.txt should contain 50, 35, 30, 25, 10).
int store_n_numbers_in_reversed_order(int n,char source[SIZE], char destination[SIZE])
{
    FILE *file_1, *file_2;
    int number[SIZE];

    //Open File 1 in read mode
    file_1 = fopen(source, "r");

    //Check if the file is empty or not
    assert(file_1 != NULL);

    //Clear contents of File 2
    fclose(fopen(destination,"w"));

    //Check if file is empty or not
    if(file_1 == NULL || n <= 0)
    {
        fclose(file_1);
        return -1;
    }

    for(int i = 0; i < n; i++)
    {
        //Read from the file
        fscanf(file_1,"%d",&number[i]);

        //Return -1 if there are not enough numbers in the file
        if(feof(file_1))
            return -1;
    }
    file_2 = fopen(destination, "a");
    for(int i = n ; i > 0; i--)
    {
        fprintf(file_2,"%d",number[i-1]);
        fprintf(file_2,"\n");
    }
    fclose(file_1);
    return 1;
}
```

**4. Text file contains some text data (some sentences). Write function to compute number of times a pattern present in the given text data. Pattern is passed as argument to function.**

```c
//4.Text file contains some text data (some sentences). Write function to compute number of times a pattern present in the given text data.
//  Pattern is passed as argument to function.
int count_text_pattern(const char *my_string,char file_name[SIZE])
{
    int len = strlen(my_string);
    FILE *file;
    char ch;
    int i,count = 0;

    //Open File 1 in read mode
    file = fopen(file_name, "r");

   //Check if the file is empty or not
    assert(file != NULL);

    while(!feof(file))
    {
        //Check every character with given string
        for( i=0; i < len; i++ )
        {
            //read single character from file
            ch = fgetc(file);
            if (ch != my_string[i])
                break;

        }
        //Raise count when all the characters in the string are found.
        if(my_string[i] == '\0')
            count++;
    }
    fclose(file);
    return count;
}
```

**5. Text file contain one sentence per line. Write function to find the length of each lines and write it to another file. Function should return length of longest sentence.**

```c
//5.Text file contain one sentence per line. Write function to find the length of each lines and write it to another file.
//  Function should return length of longest sentence.
int length_of_each_line_in_file(char source_file[SIZE], char destination_file[SIZE])
{
    FILE *file_1, *file_2;
    char ch;
    int line = 1, max_length = 0, len = 0;

    //Open File 1 in read mode
    file_1 = fopen(source_file, "r");
    assert(file_1 != NULL );

    //Clear contents of File 2
    fclose(fopen(destination_file,"w"));

    //open file 2 in append mode
    file_2 = fopen(destination_file,"a");
    assert(file_2 != NULL );

    while(1)
    {
        //Break when pointer reaches end of file
        if(feof(file_1))
            break;

         //Read single character from file
         ch = getc(file_1);
         len++;
         if(ch == '\n')
         {
            fprintf(file_2,"Line %d length is %d\n",line++,len);
            if(len > max_length)
                max_length = len;
            len = 0;

         }

    }
    fclose(file_2);
    fclose(file_1);
    return max_length;
}
```

---

## Main Function [`main.c`](https://github.com/prathikshetty9b/Algorithms-and-Data-Structures-for-Big-Data/blob/main/Assignments/Assignment-1/main.c)

```c
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
```
