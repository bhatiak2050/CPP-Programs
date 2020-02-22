#include<iostream>
using namespace std;

inline long double cube(int a){ return a*a*a; }

int main(){
	int a;
	cout<<"Enter the number: ";
	cin>>a;
	cout<<cube(a);
	return 0;
}