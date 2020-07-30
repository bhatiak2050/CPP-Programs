/*
	reverse(first_iterator, last_iterator)
*/

#include "iostream"
#include "algorithm"
using namespace std;

int main(int argc, char const *argv[])
{
	int a[10];
	cout<<"Enter 10 integers\n";
	for (int i = 0; i < 10; ++i)
		cin>>a[i];	

	reverse(a, a+10);

	cout<<"The reversed array is\n";
	for (int i = 0; i < 10; ++i)
		cout<<a[i]<<" ";
	
	return 0;
}