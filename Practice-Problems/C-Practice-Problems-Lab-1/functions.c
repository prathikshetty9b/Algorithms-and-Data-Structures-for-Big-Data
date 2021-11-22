#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "header.h"



//1.Text file contains ‘n’ numbers. Compute the sum of ‘n’ numbers present in file.
int sum_of_n_mumbers_in_file(int n)
{
    FILE *file;

    //Open File in read mode
    file = fopen("numbers.txt","r");
    int number[SIZE];
    int sum = 0;

    //Check if the file is empty or not
    if(file == NULL || n <= 0)
    {
        fclose(file);
        return -1;
    }

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

//2.Write function to generate square of a number. Numbers comes from text file. Squared number should be written to another file.
int find_square_and_write_to_file()
{
    FILE *file_1, *file_2;

    //Open File 1 in read mode
    file_1 = fopen("numbers.txt", "r");

    //Clear contents of File 2
    fclose(fopen("squares.txt","w"));
    int number,square;

    //Check if the file is empty or not
    if(file_1 == NULL)
    {
        fclose(file_1);
        return -1;
    }
    //Run loop until it reaches end of file
    while(!feof(file_1))
    {
        fscanf(file_1,"%d",&number);
        if(!feof(file_1))
        {
            //Find Square
            square = number * number;

            //Open File 2 in append mode
            file_2 = fopen("squares.txt", "a");
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

//3.Text file contains ‘n’ numbers, one number per line. Write function to store the numbers in other file in reversed order.
// (Let as assume that source.txt contains 10, 25, 30, 35, 50. Then dest.txt should contain 50, 35, 30, 25, 10).
int store_n_numbers_in_reversed_order(int n)
{
    FILE *file_1, *file_2;
    int number[SIZE];

    //Open File 1 in read mode
    file_1 = fopen("source.txt", "r");

    //Clear contents of File 2
    fclose(fopen("dest.txt","w"));

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
    file_2 = fopen("dest.txt", "a");
    for(int i = n ; i > 0; i--)
    {
        fprintf(file_2,"%d",number[i-1]);
        fprintf(file_2,"\n");
    }
    fclose(file_1);
    return 1;
}

//4.Text file contains some text data (some sentences). Write function to compute number of times a pattern present in the given text data.
//  Pattern is passed as argument to function.
int count_text_pattern(const char *my_string)
{
    int len = strlen(my_string);
    FILE *file;
    char ch;
    int i,count = 0;

    //Open File 1 in read mode
    file = fopen("count.txt", "r");
    if(file == NULL)
    {
        fclose(file);
        return -1;
    }

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

//5.Text file contain one sentence per line. Write function to find the length of each lines and write it to another file.
//  Function should return length of longest sentence.
int length_of_each_line_in_file()
{
    FILE *file_1, *file_2;
    char ch;
    int line = 1, max_length = 0, len = 0;

    //Open File 1 in read mode
    file_1 = fopen("sentences.txt", "r");

    //Clear contents of File 2
    fclose(fopen("length.txt","w"));

    if(file_1 == NULL)
    {
        fclose(file_1);
        return -1;
    }


    //open file 2 in append mode
    file_2 = fopen("length.txt","a");

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

/*Write a C program to create 50 files with names filei.txt (ie. file1.txt to file50.txt) which contains numbers from 0 to i (file1.txt contains 0 and 1 , file2.txt contains 0, 1 and 2 etc). Each number is separated by white single space.

Contents of filei.txt should be copied to file(i-1).txt and file1.txt should be copied to file50.txt

Initial file contents

file1.txt:	0 1
file2.txt:	0 1 2
file3.txt: 	0 1 2 3
.
.
file50.txt	0 1 2 3 4 ………49 50
	After rewriting

file1.txt:	0 1 2
file2.txt:	0 1 2 3
file3.txt:	0 1 2 3 4
.
.
file50.txt: 0 1

*/
int pass_file(int n)
{
    FILE *file;
    char name[20];

    for(int i=0; i<n; i++)
    {


        sprintf(name,"file%d.txt",i+1);
        file = fopen(name,"w");

        for (int j = 0; j<= i+1; j++)
        {
            fprintf(file,"%d",j);
        }

        fclose(file);
    }
    return 0;
}

int rewrite_file(int n)
{
    FILE *file1,*file2,*temp;
    file1 = fopen("file1.txt","r");
    temp = fopen("temp.txt","w");
    char dest[20],src[20];

    assert(file1 != NULL || temp != NULL);
    char ch;
    while(!feof(file1))
    {
        ch = getc(file1);
        putc(ch,temp);

    }
    fclose(file1);
    fclose(temp);

    for(int i = 1; i < n ; i++)
    {
        sprintf(src,"file%d.txt",i+1);
        file1 = fopen(src,"r");
        sprintf(dest,"file%d.txt",i);
        file2 = fopen(dest,"w");
        assert(file1 != NULL || file2 != NULL);
        while(!feof(file1))
        {
            ch = getc(file1);
            putc(ch,file2);
        }
        fclose(file1);
        fclose(file2);

    }

    temp = fopen("temp.txt","r");
    file1 = fopen("file10.txt","w");
    while(!feof(temp))
    {
        ch = getc(temp);
        putc(ch,file1);
    }
    fclose(temp);
    fclose(file1);
    return 1;
}



