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

	//...

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
/* IMPLEMENT YOUR FUNCTIONS HERE */
/* IMPLEMENT YOUR FUNCTIONS HERE */



