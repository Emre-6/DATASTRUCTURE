#include<stdlib.h>
#include"arraylist.h"

//generic insert implementation
int insertArrayListGeneric(ArrayList l, void *e, int (*find)(ArrayList, void *))
{
	
	return 0;
}



#define NAME_SIZE 30

typedef struct Student_s {
	int id;
	char name[NAME_SIZE];
} STUDENT_t, *STUDENT;

int findInsertionIndex_STUDENT_ascending(ArrayList l, void *e)
{
	STUDENT s = (STUDENT)e;

	for (int i = 0; i < l->size; i++)
	{
		if (strcmp(l->list[i], s->name) == 0)
			return i;
	}
	return -1;
}

int findInsertionIndex_STUDENT_descending(ArrayList l, void *e)
{
	STUDENT s = (STUDENT)e;

	for (int i = l->size-1; i >= 0; i--)
	{
		if (strcmp(l->list[i], s->name) == 0)
			return i;
	}
	return -1;
}

void fprintf_STUDENT(FILE *fp, void *e)
{
	//this function is implemented.
	STUDENT s = (STUDENT)e;
	fprintf(fp, "%d, %s\n", s->id, s->name);
}

int compare_STUDENT_name_descending(void *e1, void *e2)
{
	STUDENT s1 = (STUDENT)e1;
	STUDENT s2 = (STUDENT)e2;

	if (strcmp(s1->name, s2->name) > 0)
	{
		return 1;
	}
	else if (strcmp(s1->name, s2->name) < 0)
	{
		return -1;
	}
	else { return 0; }

}



#define INIT_CAP 3
#define NUM_STUDENT 10

int main()
{
	ArrayList arr;
	STUDENT s;
	int i;
	
	//create array list
	arr = createArrayList(INIT_CAP);
	
	//create and insert students into array list while preserving ascending order w.r.t. their names
	//the below implementation is exemplary. you can set id and name values differently.
	for(i=0; i<NUM_STUDENT; i++) {
		s = malloc(sizeof(STUDENT_t));
		
		s->id = i; //each student's id is set to i. you can change this.
		itoa(i, s->name, 2); //each student's name is set to i in base 2. you can change this.
		
		//insertArrayListGeneric(arr, (void *)s, findInsertionIndex_STUDENT_ascending); //this line will work after insertArrayListGeneric and findInsertionIndex_STUDENT_ascending are implemented.
		insertArrayList(arr, (void *)s, i); //this line should be disabled when the above line works.
	}
	
	//print array list
	fprintfArrayList(stdout, arr, fprintf_STUDENT);
	
	//sort array list in descending order w.r.t. student names
	bubbleSortArrayList(arr, compare_STUDENT_name_descending); //this line will work after compare_STUDENT_name_descending is implemented.
	
	//print array list
	fprintfArrayList(stdout, arr, fprintf_STUDENT);
	
	//create and insert students into array list while preserving descending order w.r.t. their names
	//the below implementation is exemplary. you can set id and name values differently.
	for(i=NUM_STUDENT; i<2*NUM_STUDENT; i++) {
		s = malloc(sizeof(STUDENT_t));
		
		s->id = -i; //each student's id is set to -i.
		itoa(-i, s->name, 2); //each student's name is set to -i in base 2.
		
		//insertArrayListGeneric(arr, (void *)s, findInsertionIndex_STUDENT_descending); //this line will work after insertArrayListGeneric and findInsertionIndex_STUDENT_descending are implemented.
		insertArrayList(arr, (void *)s, i); //this line should be disabled when the above line works.
	}
	
	//print array list
	fprintfArrayList(stdout, arr, fprintf_STUDENT);
	
	//delete and destroy students
	while(!isArrayListEmpty(arr)) {
		s = deleteArrayList(arr, arr->size-1);
		free(s);
	}
	
	//print array list
	fprintfArrayList(stdout, arr, fprintf_STUDENT);
	
	//destroy array list
	destroyArrayList(arr);
	
	return 0;
}

