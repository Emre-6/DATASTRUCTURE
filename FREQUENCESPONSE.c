#include <stdio.h>
#define FREQUENCY_SIZE 11
#define RESPONSE_SIZE 40

int main()
{
	int answer;
	int rating;
	int frequency[FREQUENCY_SIZE]={0};
	int response[RESPONSE_SIZE]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	
	for(answer=0;answer<FREQUENCY_SIZE;answer++)
	{
		++frequency[response[answer]];
	} 
	
	printf("%s%17s\n","Element","Rating");
	
	for(rating=0;rating<RESPONSE_SIZE;rating++)
	{
		printf("%6d%17d\n",rating,frequency[rating]);
	}
	
	return 0;
	
}

