/*
  begin() – Returns an iterator pointing to the first element in the vector
    end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
 rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
   rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
 cbegin() – Returns a constant iterator pointing to the first element in the vector.
   cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
  crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
*/

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> v;
	cout<<"Enter 5 elements to the vector\n";
	int x;
	for (int i = 0; i < 5; ++i)
	{
		cin>>x;
		v.push_back(x);
	}

	cout<<"Vector elements in normal order: ";
	for(auto i = v.begin(); i != v.end(); i++)
		cout<<*i<<" ";

	cout<<"\nVector elements in reverse order: ";
	for(auto i = v.rbegin(); i != v.rend(); i++)
		cout<<*i<<" ";

	return 0;
}