#include<iostream>
using namespace std;

class A{
	int a;
	friend class B;
public:
	A(){
		a=5;
	}
};

class B{
	int b;
public:
	B(){
		b=6;
	}
	void displayab(A &a1){
		cout<<a1.a<<" "<<b<<endl;
	}
};

int main(){
	A a1;
	B b1;
	b1.displayab(a1);
	return 0;
}