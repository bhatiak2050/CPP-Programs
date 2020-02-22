#include<iostream>
using namespace std;

template <class T>
void swap(const T &a, const T &b){
	T t = a;
	a=b;
	b=t;
}

int main(){
	int a, b;
	cout<<"Enter a & b: ";
	cin>>a>>b;
	swap(a, b);
	cout<<a<<" "<<b<<endl;

	double c, d;
	cout<<"Enter c & d: ";
	cin>>c>>d;
	swap(c, d);
	cout<<c<<" "<<d<<endl;
	return 0;
}