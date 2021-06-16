#include <stdio.h>

int main()
{
	
	struct account{
	int id;
	int age;
	char name[30];
	char surname[30];
	float balance;
	char gender;
	};struct account v[1000],s,t,u;

	
	s.id=30982;
	s.gender='M';
	s.age=24;
	
	s.name[0]='E';
	s.name[1]='M';
	s.name[2]='R';
	s.name[3]='E';
	s.name[4]='\0';
	s.surname[0]='O';
	s.surname[1]='M';
	s.surname[2]='U';
	s.surname[3]='R';
	s.surname[4]='T';
	s.surname[5]='A';
	s.surname[6]='K';
	s.surname[7]='\0';
	s.balance=1996.6;
	
	printf("ID=%d\n",s.id);
	printf("Name=%s\n",s.name);
	printf("Surname=%s\n",s.surname);
	printf("Gender=%c\n",s.gender);
	printf("Age=%d\n",s.age);
	printf("Balance=%f\n",s.balance);
	
	return 1;
	
	
	
}
