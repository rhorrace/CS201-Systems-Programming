#include <stdio.h>
#include <stdlib.h>

//Horrace, Robert CS201
/*
   This program is for the final exam.
   This program will have a checksum function
   This is too difficult to do with our current knowledge of C.
 */

unsigned char checksum(unsigned char *ptr, size_t sz);//checksum function
void displayall(char name[12][50]);//display all function
int main()
{
	int i = 0;
	char name[12][50];
	FILE *ptr = fopen("header.txt.","r");
	if(ptr)
	{
		while(!feof(ptr))
		{
			fgets(name[i],50,ptr);
			++i;
		}
		fclose(ptr);
	}
	for(i = 0;i < 12; ++i)
		printf("%s\n", name[i]);
	return 0;
}

unsigned char checksum(unsigned char * ptr, size_t sz)//checksum implementation
{
	unsigned char chk = 0;
	while( sz-- != 0)
		chk -= *ptr++;
	return chk;
}

void displayall(char name[12][50])//display all function
{
	int i = 0;
	while(i < 12)
	{
		printf("%s\n",name[i]);
		++i;
	}
}
