#include "cls.h"

/*Horrace, Robert CS201*/
/*
	This program is the .c file of
	the program.
	This will hold the implementations
	of the prototypes and main.
	All functions will be used.
*/

int main()
{
	int choice = 0;

	printf("1. cls\n");
	printf("2. cls-a\n");
	printf("3. cls-l\n");
	printf("4. cls-R\n");
	do{
	printf("enter your choice(enter #):");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			ls();
			break;
		case 2:
			lsa();
			break;
		case 3:
			lsl();
			break;
		case 4:
			lsR();
			break;
		default:
			printf("Error: not an option.\n");
	}
	}while(choice != 1 && choice != 2 && choice != 3 && choice != 4);
	return 0;
}

void ls()
{
	FILE *ptr;
	char line [150];
	
	ptr = popen("ls","r");
	while(fgets(line,sizeof(line),fptr))
		printf("%s",line);
	pclose(ptr);
}

void lsa()
{
	FILE *ptr;
	char line [150];
	
	ptr = popen("ls -a","r");
	while(fgets(line,sizeof(line),fptr))
		printf("%s",line);
	pclose(ptr);
}

void lsl()
{
	FILE *ptr;
	char line [150];
	
	ptr = popen("ls -l","r");
	while(fgets(line,sizeof(line),fptr))
		printf("%s",line);
	pclose(ptr);
}

void lsR()
{
	FILE *ptr;
	char line [150];
	
	ptr = popen("ls -R","r");
	while(fgets(line,sizeof(line),fptr))
		printf("%s",line);
	pclose(ptr);
}
