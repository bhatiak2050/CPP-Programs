#include<iostream>
#include<stdio.h>
using namespace std;

struct student{
	char USN[11];
	char name[25];
};

void getdata(student *s){
	cin>>s->USN;
	cin>>s->name;
}

void display(student *s){
	cout<<"USN: "<<s->USN<<endl;
	cout<<"Name: "<<s->name<<endl;
}

int main(){
	student s;
	cout<<"Enter student USN and name\n";
	getdata(&s);
	cout<<"\nStudent Details: \n";
	display(&s);
	return 0;
}