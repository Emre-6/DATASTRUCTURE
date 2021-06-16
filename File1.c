#include <stdio.h>
#include <stdlib.h>

/*

"r": open an existing file for reading
"w": create a new file, or truncate existing one, for writing
"a": open a new file, or append an existing one for writing
"r+": open an existing file for reading and writing
"w+": create a new file, or truncate an existing one for reading and writing
"a+": create a new file, or append an existing one for reading and writing

Add "b" if working in binary mode.

(123)_10=(1111011)_2='{'

*/



int main()
{
	FILE *fp;
	
	char *e="!FANEC!";
	
	fp=fopen("Open Source","w");
	
	fscanf(fp,"%s",e);
	
	printf("%s\n",e);
	
	fclose(fp);
	
	return 0;
}
