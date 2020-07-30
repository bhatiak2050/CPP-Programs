/*
	Prototype:
	sort(startaddress, endaddress)

	startaddress: the address of the first element of the array
	endaddress: the address of the next contiguous location of the last element of the array.
	So actually sort() sorts in the range of [startaddress,endaddress)
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

	sort(a, a+10);

	cout<<"The sorted array is\n";
	for (int i = 0; i < 10; ++i)
		cout<<a[i]<<" ";
	
	return 0;
}