#include <stdio.h>
#define STUDENT 3
#define EXAMS 4

int minimum(const int grades[][EXAMS],int pupils,int tests);
int maximum(const int grades[][EXAMS],int pupils,int tests);
double average(const int setOfGrades[],int tests);
void printArray(const int grades[][EXAMS],int pupils,int tests);

int main()
{
	int student;
	const int studentGrades[STUDENT][EXAMS]={{77,68,86,73},{96,87,89,78},{70,90,86,81}};
	
	printf("The array is:\n");
	
	printArray(studentGrades,STUDENT,EXAMS);
	
	printf("\n\nLowest grade:%d\n Highest grade:%d\n",minimum(studentGrades,STUDENT,EXAMS),maximum(studentGrades,STUDENT,EXAMS));
	
	for(student=0;student<STUDENT;student++)
	{
		printf("The average grade for student %d is %.2f\n",student,average(studentGrades[student],EXAMS));
	}
	return 0;
}

int minimum(const int grades[][EXAMS],int pupils,int tests)
{
	int i;
	int j;
	int lowGrade=10;
	
	for(i=0;i<pupils;i++)
	{
		for(j=0;j<tests;j++)
		{
			if(grades[i][j]<lowGrade)
			{
				lowGrade=grades[i][j];
			}
		}
	}
	return lowGrade;
}

int maximum(const int grades[][EXAMS],int pupils,int tests)
{
	int i;
	int j;
	int highGrade=0;
	
	for(i=0;i<pupils;i++)
	{
		for(j=0;j<tests;j++)
		{
			if(grades[i][j]>highGrade)
			{
				highGrade=grades[i][j];
			}
		}
	}
	return highGrade;
}

double average(const int setOfGrades[],int tests)
{
	int i;
	int total=0;
	
	for(i=0;i<tests;i++)
	{
		total+=setOfGrades[i];
	}
	
	return (double) total/tests;
}

void printArray(const int grades[][EXAMS],int pupils,int tests)
{
	int i;
	int j;
	
	printf("[0],[1],[2],[3]");
	for(i=0;i<pupils;i++)
	{
		printf("\nstudentGrades[%d]",i);
		
		for(j=0;j<tests;j++)
		{
			printf("%d",grades[i][j]);
		}
	}
	
	
}

