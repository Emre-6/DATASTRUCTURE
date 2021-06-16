#include"arraylist.h"

//generic insert implementation
int insertArrayListGeneric(ArrayList l, int (*find)(ArrayList, void *))
{
	//...
	return 0;
}



#define NAME_SIZE 30

typedef struct Student_s {
	int id;
	char name[NAME_SIZE];
} STUDENT_t, *STUDENT;

int findInsertionIndex_STUDENT_ascending(ArrayList l, void *e)
{
	//...
	return 0;
}

int findInsertionIndex_STUDENT_descending(ArrayList l, void *e)
{
	//...
	return 0;
}

void fprintf_STUDENT(FILE *fp, void *e)
{
	//...
}

int compare_STUDENT_name_descending(void *e1, void *e2)
{
	//..
	return 0;
}



#define N 10

int main()
{
	//create array list
	
	//create and insert students into array list while preserving ascending order w.r.t. their names
	
	//print array list
	
	//sort array list in descending order w.r.t. student names
	
	//print array list
	
	//create and insert students into array list preserving descending order w.r.t. their names
	
	//print array list
	
	//delete and destroy students
	
	//destroy array list
	
	return 0;
}


