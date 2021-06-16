#include <stdio.h>

int main()
{
	struct account{
		int id;
		char gender;
		char name[30];
		char surname[30];
		float balance;
	}; struct account v[1000],s,t,u;
	
	v[89].id=69;
	v[89].gender='M';
	v[89].name[0]='C';
	v[89].name[1]='A';
	v[89].name[2]='N'
	v[89].name[3]='\0';
	v[89].surname[0]='A';
	v[89].surname[1]='k';
	v[89].surname[2]='\0';
	v[89].balance=31.9;
	
	printf("ID:%d\n",v[89].id);
	printf("Gender:%s\n",v[89].gender);
	printf("Name:%s\n",v[89].name);
	printf("Surname:%s\n",v[89].surname);
	printf("Balance:%f\n",v[89].balance);
	
	return 1;
}
