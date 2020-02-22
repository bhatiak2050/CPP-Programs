#include<iostream>
using namespace std;

int main(){
	int a, b;
	cout<<"Enter a, b: ";
	cin>>a>>b;

	try{
		if(!b) throw b;
		cout<<"The quotient is "<<a/b<<endl;
	}
	catch(int e){
		cout<<"Caught divide by 0 error\n";
			abort();
	}

	return 0;
}