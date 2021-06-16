#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	void **list;
	unsigned long student_id;
	char name[20];
	char surname[20];
	int midterm;
	int final;
	int homework;
	int lab_notes;
} STUDENT_t, *STUDENT;

STUDENT createSTUDENT(int midterm,int final,int homework,int lab_notes)
{
	
	STUDENT l;
	l=(STUDENT)malloc(sizeof(STUDENT_t));
	if(l!=NULL)
	{
		l->list=(void**)malloc(struct*sizeof(void**));
		
		if(l->list!=NULL)
		{
			l->struct=struct;
		}
		else
		{
			free(l);
			l=NULL;
		}
		
	}
	return 1;
}

void insert()
{
	
}
void delete()
{
	
}

int main()
{
	return createSTUDENT;
}
