#include<iostream>
using namespace std;

int main(){
	try{
		throw '5';
	}
	catch(int e){
		cout<<"Caught integer error\n";
			abort();
	}
	catch(double e){
		cout<<"Caught double error\n";
			abort();
	}
	catch(char e){
		cout<<"Caught character error\n";
			abort();
	}
	return 0;
}