/*
		 size() – Returns the number of elements in the vector.
	 max_size() – Returns the maximum number of elements that the vector can hold.
	 capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
	  resize(n) – Resizes the container so that it contains ‘n’ elements.
		empty() – Returns whether the container is empty.
shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
	  reserve() – Requests that the vector capacity be at least enough to contain n elements.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> v;

	for (int i = 0; i < 5; ++i)
		v.push_back(i);

	cout<<"\nSize of the vector: "<<v.size();
	cout<<"\nMaximum size of the vector: "<<v.max_size();
	cout<<"\nStorage space currently allocated: "<<v.capacity();

	v.resize(10);
	cout<<"\nNew Size of the vector: "<<v.size();
	cout<<"\nMaximum size of the vector: "<<v.max_size();
	cout<<"\nIs vector empty?: "<<v.empty();

	v.shrink_to_fit();
	cout<<"\nNew Size of the vector: "<<v.size();
	cout<<"\nMaximum size of the vector: "<<v.max_size();

	v.reserve(10);
	cout<<"\nNew Size of the vector: "<<v.size();
	cout<<"\nMaximum size of the vector: "<<v.max_size();

	return 0;
}