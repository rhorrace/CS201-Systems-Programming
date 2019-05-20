#include "rhorrace_hw1.h"

/*/Horrace, Robert CS201*/
/*
   This program is designed to help solve a maze.
   The algorithm being used is the Right Wall Follower
   algorithm, which uses the right-hand policy.
 */
int main()
{
	int coord[2] = {0,0};/*coordinate variable*/
	int length = 0;/*length variable*/
	int width = 0;/*width variable*/
	int start[2] = {0,0};/*start array*/
	int finish[2] = {0,0};/*finish array*/
	char ** maze = NULL;/*maze variable*/
	maze = readfile(&length,&width,start,finish);/*call readfile function*/
	coord[0] = start[0];
	coord[1] = start[1];
	printf("%d,%d\n",start[0],start[1]);
	display_maze(maze,length,width);/*call display maze function*/
/*	check_wall(maze,coord,length,width);/*call check wall function*/
	int i = 0;
	for(i = 0; i < length;++i)
	{
		free(maze[i]);
		maze[i] = NULL;
	}
	free(maze);
	maze = NULL;
	return 0;
}

