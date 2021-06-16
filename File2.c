#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	unsigned long w;
	char q;
	char e[100];
	double r;
	void *data;
}MYDATA;

int main()
{
	MYDATA u,v;
	u.w=912361286UL;
	u.q=-12;
	u.e[0]='4';
	u.e[1]='w';
	u.e[2]=-99;
	u.r=7836121.1276172;
	u.data=NULL;
	
	FILE *fp;
	
	fp=fopen("comp.txt","wb");
	fwrite(&u,sizeof(MYDATA),1,fp);
	fclose(fp);
	
	fp=fopen("comp.txt","rb");
	fread(&v,sizeof(MYDATA),1,fp);
	fclose(fp);
	
	return 0;
	
	
	
	
}
