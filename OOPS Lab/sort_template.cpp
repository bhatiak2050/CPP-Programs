#include<iostream>
using namespace std;

template <class T>
void sort(int n, T arr[]){
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-i-1; j++)
			if(arr[j] > arr[j+1]){
				T t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
}

int main(){
	int i, arr[5] = {5, 2, 3, 1, 4};
	sort(5, arr);
	for(i=0; i<5; i++) cout<<arr[i]<<" ";

	cout<<endl;

	double d_arr[5] = {3.2, 4.1, 5.7, 1.3, 2.6};
	sort(5, d_arr);
	for(i=0; i<5; i++) cout<<d_arr[i]<<" ";	
	return 0;
}