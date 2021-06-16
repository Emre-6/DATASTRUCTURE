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


void find_by_year(int release_year, RECORD *film_array, int size, int start, int end, int *found_num, RECORD **found_films);
RECORD find_by_title(char *title, RECORD *film_array, int size, int start, int end);
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
	free(tmp);
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


	RECORD **found_films = NULL;

	find_by_year(1954,NULL,1000,0,1000,NULL,NULL);

		for (i = 0; i < size; i++)
		{
			if(found_films[i]->release_year==release_year)
			{
				printf("%d\n",found_films[i]);
			}
		}
		return **found_films;

	RECORD r = find_by_title(NULL,NULL,1000,0,1000);
	for(i=0;i<size;i++)
	{
		r[i]->title;
	}
	return r;
	// r yi EKRANA BAS

	RECORD d = delete(0,NULL,1000);
	for(i=0;i<size;i++)
	{
		d[i]->length;
	}
	return d;
	// d yi EKRANA BAS


	
	RECORD f = (RECORD *)malloc(sizeof(RECORD));
	for(i=0;i<size;i++)
	{
		f->description=description;
	}
	


	int index = insert(NULL,NULL,1000);
	printf("%d\n",index);
	


	
	file = fopen("data_out.txt", "wb");
	for(i=0; i<num_records; i++) {
		tmp = rec[i];
		fwrite(tmp, sizeof(RECORD_t), 1, file);
		free(tmp);
	}
	fclose(file);
	free(rec);
	return 1;
}

void find_by_year(int release_year, RECORD *film_array, int size, int start, int end, int *found_num, RECORD **found_films)
{
	found_num = 0;
	int index_2 = 0;
	int i;
	
	for (i = start; i < end; i++)
	{
		
		if (film_array[i]->release_year == release_year)
		{
			found_num++;
		}
	}
	
	
	*found_films = (RECORD *)malloc(sizeof(RECORD)*(*found_num));

	
	
	for (i = start; i < end; i++)
	{

		if (film_array[i]->release_year == release_year)
		{
			*found_films[index_2++] = film_array[i];

		}
	}

}

RECORD find_by_title(char *title, RECORD *film_array, int size, int start, int end)
{
	RECORD *film = NULL;
	// loop from start to end indexes in film array
	int i;
	for (i = start; i < end; i++)
	{
		// compare tile with input paramater
		if (strcmp(film_array[i]->title, title) == 0)
		{
			film = film_array[i];
			return film_array[i];
		}
	}

	return film;
}

RECORD delete(int film_id, RECORD *film_array, int size)
{
	RECORD r = NULL;
	int i;
	for (i = 0; i < MAX; i++)
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
	int insertedIndex = -1;
	int i;
	
	for (i = 0; i < size; i++)
	{
		if (film_array[i]->film_id == film->film_id)
		{
			return -1;
		}
	}

	
	for (i = 0; i < size; i++)
	{
		if (film_array[i] == NULL)
		{
			
			film_array[i] = film;
			insertedIndex = i;
			return insertedIndex;
		}
	}

	
	if (insertedIndex == -1)
	{
		size++;
		RECORD tmp;
		RECORD *rec = (RECORD *)malloc(sizeof(RECORD)*size);
		FILE *file = fopen("data.txt", "rb");
		int i;
		if (file == NULL) {
			printf("Cannot open the file.\n");
			return -1;
		}
		for (i = 0; i < size-1; i++) {
			tmp = (RECORD)malloc(sizeof(RECORD_t));
			fread(tmp, sizeof(RECORD_t), 1, file);
			rec[i] = tmp;
		}
		fclose(file);

		rec[size - 1] = film;
		insertedIndex = size - 1;
		return insertedIndex;
	}

	return insertedIndex;
}

void sort(RECORD film_array, int size, char *rating, char *title) 
{
	int i;
	for (i = 0; i < MAX-1; i++)
	{
		if (strcmp(film_array[i].rating, film_array[i + 1].rating))
		{
			// swap
			RECORD_t *temp;

			*temp = film_array[i];
			film_array[i] = film_array[i + 1];
			film_array[i + 1] = *temp;
		}
	}
	
}
