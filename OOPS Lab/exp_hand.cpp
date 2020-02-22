#include<iostream>
using namespace std;

int main(){
	try{
		cout<<"Inside try block\n";
		throw 100;
	}
	catch(int e){
		cout<<"Caught exception "<<e<<endl;
	}
	return 0;
}