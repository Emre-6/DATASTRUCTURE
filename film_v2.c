#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000                                        //Do not edit this macro.

typedef struct{
	int film_id;
	char title[255];
	char description[1023];
	unsigned int release_year;
	char rental_duration;
	float rental_rate;
	unsigned char length;
	float replacement_cost;
	char rating[10];
	char last_update[30];
} RECORD_t, *RECORD;                                    //Do not edit this struct.

/* DECLARE YOUR FUNCTION PROTOTYPES HERE */
/* DECLARE YOUR FUNCTION PROTOTYPES HERE */
/* DECLARE YOUR FUNCTION PROTOTYPES HERE */

/* DECLARE YOUR FUNCTION PROTOTYPES HERE */
void find_by_year(int release_year, RECORD *film_array, int size, int start, int end, int *found_num, RECORD **found_films);
/* DECLARE YOUR FUNCTION PROTOTYPES HERE */
RECORD find_by_title(char *title, RECORD *film_array, int size, int start, int end);
/* DECLARE YOUR FUNCTION PROTOTYPES HERE */
RECORD delete(int film_id, RECORD *film_array, int size);
int insert(RECORD film, RECORD *film_array, int size);
void sort(RECORD film_array, int size, char *rating, char *title);

int size = 1000;

int main(){
	/* --- DO NOT EDIT THIS PART. --- */
	int num_records = MAX;
	int i;
	RECORD tmp;
	RECORD *rec = (RECORD *)malloc(sizeof(RECORD)*num_records);
	FILE *file = fopen("data.txt", "rb");
	if (file == NULL) {
		printf("Cannot open the file.\n");
		exit(0);
	}
	for(i=0; i<num_records; i++) {
		tmp = (RECORD)malloc(sizeof(RECORD_t));
		fread(tmp, sizeof(RECORD_t), 1, file);
		rec[i] = tmp;
	}
	fclose(file);
	/* --- --- */

	/**************************/
	/* Your code starts here. */
	/**************************/

	//The following is a hint to access the rec array in memory.
	printf("ID: %d\n", rec[189]->film_id);
	printf("TITLE: %s\n", rec[189]->title);
	printf("DESCRIPTION: %s\n", rec[189]->description);
	printf("RELEASE YEAR: %d\n", rec[189]->release_year);
	printf("RENTAL DURATION: %d\n", rec[189]->rental_duration);
	printf("RENTAL RATE: %f\n", rec[189]->rental_rate);
	printf("REPLACEMENT COST: %f\n", rec[189]->replacement_cost);
	printf("RATING: %s\n", rec[189]->rating);
	printf("LAST UPDATE: %s\n", rec[189]->last_update);

	//..
	int *numOfMovies;
	RECORD **foundMovies;

	find_by_year(538976288, rec, 1000, 10, 100, numOfMovies, *foundMovies);



	/**************************/
	/* Your code ends here.   */
	/**************************/

	/* --- DO NOT EDIT THIS PART. --- */
	file = fopen("data_out.txt", "wb");
	for(i=0; i<num_records; i++) {
		tmp = rec[i];
		fwrite(tmp, sizeof(RECORD_t), 1, file);
		free(tmp);
	}
	fclose(file);
	free(rec);
	return 1;
	/* --- DO NOT EDIT THIS PART. --- */
}

/* IMPLEMENT YOUR FUNCTIONS HERE */
void find_by_year(int release_year, RECORD *film_array, int size, int start, int end, int *found_num, RECORD **found_films)
{
	found_num = 0;
	int i;
	for(i = start;i<end;i++)
	{
		if (film_array[i]->release_year == release_year)
		{
			found_num++;
		}
	}

	*found_films = (RECORD *)malloc(sizeof(RECORD)*(*found_num));

	int counter = 0;
	for (i=start;i<end;i++)
	{
		if(film_array[i]->release_year == release_year)
		{
			*found_films[counter] = film_array[i];
			counter++;
		}
	}

}
/* IMPLEMENT YOUR FUNCTIONS HERE */
RECORD find_by_title(char *title, RECORD *film_array, int size, int start, int end)
{
	int isFound = 0;
	int i;
	for (i=start;i<end;i++)
	{
		if (film_array[i]->title == title)
		{
			isFound = 1;
			return film_array[i];
		}
	}


if (isFound == 0)
{
	return NULL;
}

}
/* IMPLEMENT YOUR FUNCTIONS HERE */
RECORD delete(int film_id, RECORD *film_array, int size)
{
	RECORD r = NULL;
	int i;
for (i=0;i<MAX;i++)
{
	if (film_array[i]->film_id == film_id)
	{
		r = film_array[i];
		film_array[i] = NULL;
	}
}

	return r;
}

int insert(RECORD film, RECORD *film_array, int size)
{
	int isInserted = 0;
	int i;

	for (i = 0; i < 1000; i++)
	{
		if (film_array[i]->film_id == film->film_id)
		{
			return -1;
		}
	}

	for (i = 0; i < 1000; i++)
	{
		if (film_array[i] == NULL)
		{
			isInserted = 1;
			film_array[i] = film;
			return i;
		}
	}


	if (isInserted == 0)
	{
		int i;
		size++;
		RECORD tmp;
		RECORD *rec = (RECORD *)malloc(sizeof(RECORD)*size);
		FILE *file = fopen("data.txt", "rb");
	if(file == NULL) 
	{
		printf("Cannot open the file.\n");
		return -1;
	}
	for (i = 0; i < size; i++) 
	{
		tmp = (RECORD)malloc(sizeof(RECORD_t));
		fread(tmp, sizeof(RECORD_t), 1, file);
		rec[i] = tmp;
	}
	fclose(file);


	for (i = 0;i<size;i++)
	{	
		if (film_array[i] == NULL)
		{
			film_array[i] = film;
			return i;
		}
	}
  }
}

void sort(RECORD film_array, int size, char *rating, char *title)
{
	int i;
	for(i=0;i<MAX-1;i++)
	{
		if (strcmp(film_array[i].rating, film_array[i + 1].rating))
		{

		RECORD_t *temp;

		*temp = film_array[i];
		film_array[i] = film_array[i + 1];
		film_array[i + 1] = *temp;
		}
	}
}



