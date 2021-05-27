#ifndef MYFILE_H
#define MYFILE_H

#include<iostream>
#include<stdio.h>
#include<vector>

#include "Grid.h"
using namespace std;

/**
 * Function that parses a line and returns all the space separated numbers as vectors
 * @param line character array line to be parsed
 * @param len length of the line to be parsed
 * @return integer vector storing all the numbers in the line.
*/
vector<int> parse_line(char *line,int len);

/**
 * Function that parses a file line by line and initializes a grid object
 * @param filename stores the filename to be openend
 * @return Grid object containing all the data regarding the grid
*/
Grid * parse_file(char * filename);


#endif