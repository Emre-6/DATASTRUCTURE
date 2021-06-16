#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void shuffle(RECORD rec);
/* DECLARE YOUR FUNCTION PROTOTYPES HERE */
/* DECLARE YOUR FUNCTION PROTOTYPES HERE */

void main(){
	RECORD rec = (RECORD)malloc(sizeof(RECORD_t)*MAX);  //Do not edit this line.
	FILE *file = fopen("data.txt", "rb");               //Do not edit this line.
	if (file == NULL) {                                 //Do not edit this line.
		printf("Cannot open the file.\n");              //Do not edit this line.
		exit(0);                                        //Do not edit this line.
	}                                                   //Do not edit this line.
	fread(rec, sizeof(RECORD_t)*MAX, 1, file);          //Do not edit this line.
	fclose(file);                                       //Do not edit this line.



	/**************************/
	/* Your code starts here. */
	/**************************/

	//The following is a hint to access the rec array in memory.
	printf("ID: %d\n", rec[189].film_id);
	printf("TITLE: %s\n", rec[189].title);
	printf("DESCRIPTION: %s\n", rec[189].description);
	printf("RELEASE YEAR: %d\n", rec[189].release_year);
	printf("RENTAL DURATION: %d\n", rec[189].rental_duration);
	printf("RENTAL RATE: %f\n", rec[189].rental_rate);
	printf("REPLACEMENT COST: %f\n", rec[189].replacement_cost);
	printf("RATING: %s\n", rec[189].rating);
	printf("LAST UPDATE: %s\n", rec[189].last_update);

	//...
		srand(time(NULL));
	shuffle(rec);
	/**************************/
	/* Your code ends here.   */
	/**************************/
/*
	file = fopen("data.txt", "wb");                     //Do not edit this line.
	fwrite(rec, sizeof(RECORD_t)*MAX, 1, file);         //Do not edit this line.
	fclose(file);                                       //Do not edit this line.
	free(rec);   
	*/                                       //Do not edit this line.
	return 1;                                           //Do not edit this line.
}


void shuffle(RECORD rec){
	
RECORD_t temp;
int r;
int i;

for(i=0;i<1000;i++){
	
	r = rand() % 1000;
	temp = rec[i];
	rec[i] = rec[r];
	rec[r] = temp;
	
	
	
}



	
	
	
}






