//Demonstration of function pointer
#include<iostream>
using namespace std;
int sum(int, int);

int (*fptr)(int, int);  		//Declaration of function pointer

int main(){
	int a=5, b=6;
	fptr = &sum;				//Assigning address of function to pointer

	int sum = (*fptr)(a, b);	//Calling the function using function pointer
	cout<<sum<<endl;
}

int sum(int a, int b){
	return a+b;
}	