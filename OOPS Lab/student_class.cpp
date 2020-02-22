#include<iostream>
#include<stdio.h>
using namespace std;

class student{
	char Usn[11];
	char name[25];
public:
	void getdata(){
		cin>>Usn;
		cin>>name;
	}

	void display(	){
		cout<<"USN: "<<Usn<<endl;
		cout<<"Name: "<<name<<endl;
	}
};

int main(){
	student s;
	cout<<"Enter student USN and name\n";
	s.getdata();
	cout<<"\nStudent Details: \n";
	s.display();
	return 0;
}