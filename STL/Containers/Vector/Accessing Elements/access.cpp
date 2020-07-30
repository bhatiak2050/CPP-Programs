/*
reference operator [g] – Returns a reference to the element at position ‘g’ in the vector
	at(g) – Returns a reference to the element at position ‘g’ in the vector
  front() – Returns a reference to the first element in the vector
   back() – Returns a reference to the last element in the vector
   data() – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> v;

	for (int i = 0; i < 10; ++i)
		v.push_back(i+1);

	cout<<"\nReference operator v[1]: "<<v[1];
	cout<<"\nat: v.at(1): "<<v.at(1);
	cout<<"\nfront: v.front(): "<<v.front();
	cout<<"\nback: v.back(): "<<v.back();

	int *ptr = v.data();
	cout<<"\nAccessing the elements using a direct pointer: ";
	for (int i = 0; i < 10; ++i)
	{
		cout<<*(ptr+i)<<" ";
	}

	return 0;
}