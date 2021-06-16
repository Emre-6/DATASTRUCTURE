#include <stdio.h>

int main()
{
	int id;
	char age;
	char gender;
	char name[30];
	char surname[30];
	float balance;
	
	id=140;
	age=24;
	name[0]='O';
	name[1]='Z';
	name[2]='G';
	name[3]='U';
	name[4]='N';
	name[5]='\0';
	name[6]='E';
	name[7]='M';
	name[8]='R';
	name[9]='E';
	name[10]='\0';
	surname[0]='O';
	surname[1]='M';
	surname[2]='U';
	surname[3]='R';
	surname[4]='T';
	surname[5]='A';
	surname[6]='K';
	surname[7]='\0';
	
	printf("ID=%d\n",id);
	printf("Name=%s\n",name);
	printf("Surname=%s\n",surname);
	printf("Age=%d\n",age);
	printf("Balance=%f\n",balance);
	printf("Gender:%c\n",gender);
	
	return 1;
}
