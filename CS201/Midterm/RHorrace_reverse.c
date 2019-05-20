#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ** reverse = calloc(100,sizeof(char *));
	FILE * ftext;
	char array1[100];
	char array2[100];
	int size = 100;
	int i = 0;
	int j = 0;
	int k = size - 1;

	for(i = 0; i < size; ++i)
	{
		reverse[i] = NULL;
	}
	ftext = fopen("raddr.txt","rt");
	if(ftext)
	{
		while(fgets(array1,100,ftext)!= NULL)
		{
			for(j = strnlen(array1) - 1;j >= 0; j--)
			{
				array2[i] = array1[j];
				i++;
			}
			printf("%s",array2);
		}
	}
	else printf("File doesn't exist.\n");
	for(i = 0; i < size; ++i)
	{
		if(reverse[i]) free(reverse[i]);
	}
	free(reverse);
	free(ftext);
	return 0;
}
