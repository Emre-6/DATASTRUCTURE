#include <stdio.h>

int main(void)
{
   struct account
   {
    int id;
    char gender;
    int age;
    char name[20];
    char surname[20];
    float balance;

   };
   struct account v[1000],s,t,u;

    s.id=30109;
    s.gender='M';
    s.age=56;
    s.name[0]='C';
    s.name[1]='a';
    s.name[2]='n';
    s.name[3]='\0';
    s.surname[0]='T';
    s.surname[1]='o';
    s.surname[2]='k';
    s.surname[3]='\0';
    s.balance=30103.5;

    printf("ID:%d\n",s.id);
    printf("Gender:%s\n",s.gender);
    printf("Age:%d\n",s.age);
    printf("Name:%s\n",s.name);
    printf("Surname:%s\n",s.surname);
    printf("Balance:%f\n",s.balance);

    return 1;
}
