#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define value1 20
#define value2 10


void swap(char *a,char *b)
{
	char t[30];
	strcmp(t,a);
	strcmp(a,b);
	strcmp(b,t);
}


void compare(char a[][MAX],char b)
{
	char temp[30];
	int i,j;
	
	for(j=0;j<MAX-1;j++)
	{
		for(i=j+1;i<MAX;i++)
		{
			if(strcmp(a[0][i],a[0][j]))
			{
				strcmp(temp,a[0][i]);
				strcmp(a[0][i],a[0][j]);
				strcmp(a[0][j],temp);
			}
		}
	}
}


void bubble_sort(char a[][100],int n)
{
	while(n!=0)
	{
		int i,j;
		for(i=0;i<n-2;i++)
		{
			for(j=0;j<MAX;j++)
			{
				if(a[i][j]>a[i][j+1])
				{
					int value=a[i][j];
					a[i][j]=a[i][j+1];
					a[i][j+1]=value;
				}
			}
		}
	}
}



void printArray(char array[][MAX],int word1,int word2)
{
	int i,j;
	
	for(i=0;i<word1;i++)
	{
		for(j=0;j<word2;j++)
		{
			printf("%s",array[i][j]);
		}
	}
}



int main()
{
	char a[][100]={"GeeksforGeeks","Quiz","Practice","Gblogs","Coding"};
	int n=sizeof(a)/sizeof(a[0]);
	
	bubble_sort(a,n);
	
	void printArray(char array[][MAX],int word1,int word2);
	
	return 0;
}
