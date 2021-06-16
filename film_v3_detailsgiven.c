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
void find_by_year(int release_year, RECORD *film_array, int size, int start, int end, int *p_found_num, RECORD **p_found_films);
RECORD find_by_title(char *title, RECORD *film_array, int size, int start, int end);
int insert(RECORD film, RECORD *film_array, int *p_size);
RECORD delete(int film_id, RECORD *film_array, int *p_size);
void sort(RECORD film_array, int size, char *rating, char *title);

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

	/*

		Call the functions that you implemented, 
		You can create a menu to demonstrate your functions.
		
	*/

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
void find_by_year(int release_year, RECORD *film_array, int size, int start, int end, int *p_found_num, RECORD **p_found_films) {	
/*
	num <- find the number of RECORDs with given release_year between start and end in film_array
	films <- NULL
	if num != 0 then
		films <- allocate an array of RECORDs of size num
		put the RECORDs with given release_year between start and end in film_array into films
	endif
	*p_found_num <- num //return the number of RECORDs via pointer parameter
	*p_found_films <- films //return the array of found RECORDS via pointer parameter
*/
}

RECORD find_by_title(char *title, RECORD *film_array, int size, int start, int end) {
/*
	p_found <- NULL
	p_found <- find the RECORD with given title in film_array between start and end (p_found does not change if no such RECORD is found)
	return p_found
*/
}

int insert(RECORD film, RECORD **p_film_array, int *p_size) {
/*
	index <- find the first location which contains NULL in film_array
	if index is valid then
		*p_film_array[index] <- film
	else
		new_films_array <- extends *p_film_array by 1 to insert to the end
		if extension is successful then
			index <- *p_size
			new_films_array[index] <- film
			*p_film_array <- new_films_array //return the new array via pointer parameter
			*p_size <- *p_size + 1 //return the new size via pointer parameter
		else
			index <- -(*p_size)
		endif
	endif
	return index
*/
}

RECORD delete(int film_id, RECORD *film_array, int size) {
/*	
	index <- find the index of the RECORD with given film_id in film_array
	if index is valid then
		rec <- film_array[index]
	else
		rec <- NULL
	endif
	return rec
*/	
}

void sort(RECORD film_array, int start, int end, char *rating, char *title) {
/*
	x <- end + 1
	while x != start do
		high <- start
		for i<-start, i <= x-2, i++ do
			if compare(film_array[i], film_array[i+1]) > 0 then
				swap(&film_array[i], &film_array[i+1])
				high <- i+1
			endif
		endfor
		x <- high;
	endwhile
*/
}

