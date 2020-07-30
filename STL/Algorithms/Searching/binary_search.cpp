/*
	binary_search(startaddress, endaddress, valuetofind)

	startaddress: the address of the first element of the array.
	endaddress: the address of the last element of the array.
	valuetofind: the target value which we have to search for.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int a[10];
	cout<<"Enter 10 elements\n";
	for (int i = 0; i < 10; ++i)
		cin>>a[i];

	int x;
	cout<<"Enter the number to search: ";
	cin>>x;
	
	if(binary_search(a, a+10, x))
		cout<<"Element found\n";
	else
		cout<<"Element not found";

	return 0;
}