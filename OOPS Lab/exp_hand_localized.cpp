#include<iostream>
using namespace std;

void test(int i){
	try{
		if(i) throw i;
	}
	catch(int e){
		cout<<"Caught exception "<<e<<endl;
	}
}

int main(){
	test(0);
	test(100);
	test(500);
	return 0;
}