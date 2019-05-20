#include "cls.h"

//Horrace, Robert CS201
/*
	This is the main.
	This will call all the functions implemented.
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
