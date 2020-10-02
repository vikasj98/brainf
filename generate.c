#include<stdio.h>
#include<math.h>
#include<string.h>

#define LIMIT 1000

int main()
{
	unsigned char text[LIMIT];
	int s,r,difference,length;
	unsigned char lastchar,currentchar,c;
	int count=0;
	printf("Text : \n");
	int i=0;
	while((c = getchar()) != '\n')
	{
		text[i++] = c;
	}
	text[i] = '\0';
	length = strlen(text);
	printf("length : %d\n",length);
	printf("\nCode : \n");
	currentchar = text[0];
	s = sqrt(currentchar);
	r = currentchar - s*s;
	for( int i=1; i<=s; i++)
		putchar('+');
	printf("[>");
	for( int i=1; i<=s; i++)
		putchar('+');
	printf("<-]>");
	for( int i=1; i<=r; i++)
		putchar('+');
	putchar('.');
	i=1;
	do
	{
		currentchar = text[i];
		lastchar = text[i-1];
		if(currentchar >= lastchar)
		{
			difference = currentchar - lastchar;
			s = sqrt(difference);
			r = difference - s*s;
			putchar('<');
			for(int j=1; j<=s; j++)
				putchar('+');
			printf("[>");
			for(int j=1; j<=s; j++)
				putchar('+');
			printf("<-]>");
			for(int j=1; j<=r; j++)
				putchar('+');
		}
		else
		{
			difference = lastchar - currentchar;
			s = sqrt(difference);
			r = difference - s*s;
			putchar('<');
			for(int j=1; j<=s; j++)
				putchar('+');
			printf("[>");
			for(int j=1; j<=s;j++)
				putchar('-');
			printf("<-]>");
			for(int j=1; j<=r; j++)
				putchar('-');
		}
		putchar('.');
		count++;
	}while(++i<length);
	printf("\n%d characters printed\n",count);
	return 0;
}
	
