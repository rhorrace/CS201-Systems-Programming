#include <stdio.h>
#include <stdlib.h>

/*Horrace, Robert CS201*/
/*
   This program is the header file of the whole program.
   This will hold all the functions being used and possibly
   any constant variables.
   All functions will be used and implemented.
 */

char ** readfile(int * length, int * width, int start[],int finish[]);/*function that reads from a file*/
int display_maze(char ** maze,int length,int width);/*display function for displaying the whole maze*/
int check_wall(char ** maze,int coord[],int length, int width);/*check wall function*/
