#include <stdio.h>

int main(void)
{

    struct account{
    int id;
    char gender;
    int age;
    char name[30];
    char surname[30];
    float balance;
    };struct account v[1000],s,t,u;


    s.id=140;
    s.age=24;
    s.gender='M';
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
    s.balance=140.9;

    printf("ID:%d\n",s.id);
    printf("NAME:%s\n",s.name);
    printf("SURNAME:%s\n",s.surname);
    printf("Age:%d\n",s.age);
    printf("Balance:%f\n",s.balance);

    return 0;

}
