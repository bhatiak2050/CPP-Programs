#include<iostream>
using namespace std;

class Rectangle {
	int length, width;

public:
	Rectangle(){
		cout << "Enter the length and width: ";
		cin>>length>>width;
	}

	Rectangle(int length, int width){
		this->length = length;
		this->width = width;
	}

	Rectangle (Rectangle &o){
		this->length = o.length;
		this->width = o.width;
	}

	inline int area (){
		return length * width;
	}

	inline int getlength() { return length; }
	inline int getwidth() { return width; }
};

int main(){
	Rectangle o;
	cout<<"The area is : "<<o.area()<<endl;
	
	cout<<"Enter the Length and width: ";
	int l, b;
	cin>>l>>b;
	Rectangle o1(l,b);
	cout<<"The new area is : "<<o1.area()<<endl;

	Rectangle o2(o1);

	cout<<"The parameters of the third object are: ";
	cout<<o2.getlength()<<" "<<o2.getwidth()<<endl;

	return 0;
}