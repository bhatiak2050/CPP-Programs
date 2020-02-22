#include<iostream>
using namespace std;

template <class T, int size>
class stack {
	T arr[size];
	int top;
public:
	stack(){
		top = -1;
	}
	void push(T x){
		if(top == size-1){
			cout<<"Stack full\n";
			return;
		}
		else top++;
		arr[top] = x;
	}

	T pop(){
		if(top == -1){
			cout<<"Stack empty\n";
			return 0;
		}
		else return arr[top--];
	}
};

int main(){
	stack <int, 3> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;

	stack <char, 2> s2;
	s2.push('a');
	s2.push('b');
	s2.push('c');
	cout<<s2.pop()<<endl;
	cout<<s2.pop()<<endl;
	cout<<s2.pop()<<endl;

	return 0;
}