#include<iostream>
using namespace std;

class Test {
	int a;

public:
	Test(){
		a=5;
		cout<<"\nObject constructed with data "<<a;
	}

	~Test(){
		cout<<"\nObject Destroyed\n";
	}

	int geta(){ return a; }
};

int main(int argc, char const *argv[]) {
	Test a;
	cout<<"From main(): "<<a.geta();
	return 0;
}