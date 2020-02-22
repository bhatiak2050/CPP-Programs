#include<iostream>
using namespace std;
int main(){
	int a, flag=0;
	cout<<"Enter the number: ";
	cin>>a;
	
	for(int i=2; i<a; i++)
		if (a%i==0) {
			flag=1;
			break;
		}

	if(flag==1 || a==1 || a==2) cout<<"It is NOT Prime\n";
	else cout<<"It is Prime\n";
}