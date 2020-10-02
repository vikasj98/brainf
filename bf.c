#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define CODE_LIMIT 10000
#define LOOP_LIMIT 1000
#define GRID_SIZE 1000

int main()
{	
	char grid[GRID_SIZE] = "";
	char *ptr = grid;	//The main grid
	char code[CODE_LIMIT];
	int array1[LOOP_LIMIT];	//To hold locations of [
	int array2[LOOP_LIMIT];	//To hold locations of ]
	int jump1[LOOP_LIMIT];
	int jump2[LOOP_LIMIT];
	int length,index1=0,index2=0,temp;
	int count,i,j;
	printf("Code : \n");
	scanf("%s",code);
	length = strlen(code);
	for(i = 0; i<length; i++)	//Storing the locations of [ and ] in the code
	{
		if(code[i] == '[')
		{
			array1[index1] = i;
			count = 0;
			for(j=i+1; j<length; j++)
			{
				if(code[j] == '[')
					count++;
				else if(code[j] == ']' && --count<=0)
				{
					jump1[index1++] = j;
					break;
				}
			}
		}
		else if(code[i] == ']')
			array2[index2++] = i;
	}
	
	for( i=0; i<index2; i++)
	{
		for(j=0; j<index1; j++)
		{
			if(jump1[j] == array2[i])
			{
				jump2[i] = array1[j];
				break;
			}
		}
	}
	printf("Output : \n");
	i = 0;
	do
	{
		switch(code[i])
		{
			case '+':
				//printf("Case +\n");
				(*ptr)++;
				break;
			case '-':
				//printf("Case -\n");
				(*ptr)--;
				break;
			case '>':
				//printf("Case >\n");
				ptr++;
				break;
			case '<':
				//printf("Case <\n");
				ptr--;
				break;
			case '.':
				//printf("Case .\n");
				putchar(*ptr);
				//printf("%d\n",*ptr);
				break;
			case ',':
				//printf("Case ,\n");
				printf("Enter the value : ");
				scanf("%d",&temp);
				*ptr = (unsigned char)temp;
				break;
			case '[':
				//printf("Case [\n");
				if(*ptr == 0)
				{
					for(j=0; i<index1; j++)
					{
						if(array1[j] == i)
						{
							i = jump1[j];
							break;
						}
					}
				}
				break;
			case ']':
				//printf("Case ]\n");
				if(*ptr !=0)
				{
					for(j = 0; j<index2; j++)
					{
						if(array2[j] == i)
						{
							i = jump2[j];
							break;
						}
					}
				}
		}
	}while(i++ < length);
	printf("\n");
	return 0;
}
