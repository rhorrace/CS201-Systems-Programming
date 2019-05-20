#include "rhorrace_hw1.h"

/*Horrace, Robert CS 201*/
/*
   This program is for the prototypes.
   The prototypes will be implemented completely.
   All functions will be used.
 */

char ** readfile(int * length, int * width,int start[],int finish[])/*function that reads from a file*/
{
	FILE * fmaze;
	char response;
	char reader;/*used for lines*/
	srand(time(NULL));
	int mz = rand()%3+1;
	int i = 0;
	do{
		printf("Would you like to do a maze?(Y/N): ");
		scanf("%c", &response);
		response = toupper(response);
	}while(response != 'N' && response != 'Y');
	if(response == 'N') return 0;
	do{
		switch(mz)
		{
			case 1:/*if 1 was chosen*/
				fmaze = fopen("maze1.txt","rt");
				break;
			case 2:/*if 2 was chosen*/
				fmaze = fopen("maze2.txt","rt");
				break;
			case 3:/*if 3 was chosen*/
				fmaze = fopen("maze3.txt","rt");
				break;
			default:
				mz = rand()%3+1;
		}
	}while(mz != 1 && mz != 2 && mz != 3);/*repeats if 1,2,or3 wasn't chosen*/
	if(!fmaze) return 0;
	while(i < 3)
	{
		if(i == 0) fscanf(fmaze, "%d,%d", *&length, *&width);/*reads in length and width*/
		if(i == 1) fscanf(fmaze, "%d,%d", &start[0],&start[1]);/*reads in start coordinates*/
		if(i == 2) fscanf(fmaze, "%d,%d", &finish[0],&finish[1]);/*reads in finish coordinates*/
		++i;
	}
	i = 0;
	int j = 0;
	char a_maze[*length][*width];/*maze temp*/
	/*reads and puts each char in each index*/
	char ** b_maze = calloc(*length,sizeof(char*));/*temp char** */
	/*char ** gets allocated*/
	for(i = 0; i < *length;++i)
	{
		b_maze[i] = calloc(*width,sizeof(char));
	}
	/*each index becomes the other maze's index*/
	for(i = 0; i< *width;++i)
	{
		for(j = 0; j < *length; ++j)
		{
			reader = fgetc(fmaze);
			b_maze[j][i] = reader;
		}
		fgetc(fmaze);
	}
	fclose(fmaze);
	if(fmaze)i
	{ 
		free(fmaze);
		fmaze = NULL;
	}
	return b_maze;/*returns b_maze*/
}

int display_maze(char ** maze, int length, int width)/*display maze function*/
{
	if(!maze) return 0;/*if no maze*/
	int i = 0;
	int j = 0;
	/*displays each index*/
	for(i = 0; i < width;++i)
	{
		for(j = 0;j<length;++j)
		{
			printf("%c",maze[j][i]);
			if(j == length -1) printf("\n");
		}
	}
}

int check_wall(char ** maze, int coord[],int length,int width)/*function that checks for walls*/
{
	char wall = 'X';
	if(!maze) return 0;/*if no maze*/
	printf("%d,%d\n",coord[0],coord[1]);
	if(coord[0] > 0 && coord[1] > 0 && coord[0] < length - 1 && coord [1] < width -1 )/*if somewhere in the middle of maze*/
	{
		if(maze[coord[0]-1][coord[1]] == wall) printf("On the right: Wall\n");
		else printf("On the right: No wall\n");
		if(maze[coord[0]+1][coord[1]] == wall) printf("On the left: Wall\n");
		else printf("On the left: No wall\n");
		if(maze[coord[0]][coord[1]-1] == wall) printf("Behind: Wall\n");
		else printf("Behind: No wall\n");
		if(maze[coord[0]][coord[1]+1] == wall) printf("In front: Wall\n");
		else printf("In front: No wall\n");
	}
	else if(coord[0] == 0 && coord[1] > 0 && coord[1] < width - 1)/*if x-coordinate is 0*/
	{
		if(maze[coord[0]+1][coord[1]] == wall) printf("On the left: Wall\n");
		else printf("On the left: No wall\n");
		if(maze[coord[0]][coord[1]-1] == wall) printf("Behind: Wall\n");
		else printf("Behind: No wall\n");
		if(maze[coord[0]][coord[1]+1] == wall) printf("In front: Wall\n");
		else printf("In front: No wall\n");
	}
	else if(coord[0] == length - 1 && coord[1] > 0 && coord[1] < width - 1)/*if at the farthest x-coordinate*/
	{
		if(maze[coord[0]-1][coord[1]] == wall) printf("On the right: Wall\n");
		else printf("On the right: No wall\n");
		if(maze[coord[0]][coord[1]-1] == wall) printf("Behind: Wall\n");
		else printf("Behind: No wall\n");
		if(maze[coord[0]][coord[1]+1] == wall) printf("In front: Wall\n");
		else printf("In front: No wall\n");
	}
	else if(coord[0] > 0 && coord[0] < length - 1 && coord[1] == 0)/*if y-coordinate is 0*/
	{	
		if(maze[coord[0]-1][coord[1]] == wall) printf("On the right: Wall\n");
		else printf("On the right: No wall\n");
		if(maze[coord[0]+1][coord[1]] == wall) printf("On the left: Wall\n");
		else printf("On the left: No wall\n");
		if(maze[coord[0]][coord[1]+1] == wall) printf("In front: Wall\n");
		else printf("In front: No wall\n");
	}
	else if(coord[0] > 0 && coord[0] < length - 1 && coord[1] == width - 1)/*if at the farthest y-coordinate*/
	{
		if(maze[coord[0]-1][coord[1]] == wall) printf("On the right: Wall\n");
		else printf("On the right: No wall\n");
		if(maze[coord[0]+1][coord[1]] == wall) printf("On the left: Wall\n");
		else printf("On the left: No wall\n");
		if(maze[coord[0]][coord[1]-1] == wall) printf("Behind: Wall\n");
		else printf("Behind: No wall\n");
	}
	return 1;
}
