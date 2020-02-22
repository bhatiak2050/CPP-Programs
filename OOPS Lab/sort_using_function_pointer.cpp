#include<iostream>
using namespace std;

void (*fptr_asc)(int , int []);
void (*fptr_desc)(int , int []);

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort_asc(int n, int array[])
{
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			if(array[i] > array[j])
				swap(array[i], array[j]);
}

void sort_desc(int n, int array[])
{
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			if(array[i] < array[j])
				swap(array[i], array[j]);
}

int main(int argc, char const *argv[]) 
{
	int n, choice;
	fptr_asc  = &sort_asc;
	fptr_desc = &sort_desc;
	
	cout<<"Enter the number of elements: ";
	cin>>n;

	int *array = new int[10];

	cout<<"Enter the elements\n";
	for (int i = 0; i < n; ++i)
		cin>>array[i];

	cout<<"Sort in\n1) Ascending order\n2) Descending order\nEnter your choice: ";
	cin>>choice;

	switch(choice){
		case 1: (*fptr_asc)(n, array);
				cout<<"In Ascending order: ";
				for (int i=0; i<n; ++i)
					cout<<array[i]<<" ";
				break;
		case 2: (*fptr_desc)(n, array);
				cout<<"In Descending order: ";
				for (int i=0; i<n; ++i)
					cout<<array[i]<<" ";
				break;
	}
}