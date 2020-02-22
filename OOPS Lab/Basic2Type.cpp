//Conversion from Basic type to class data type
#include <iostream>
using namespace std;

class Celcius{
	int temp;
public:
	Celcius(){
		temp=0;
	}
	Celcius(float ftemp){
		temp = (ftemp-32)*5/9;
	}
	void show(){
		cout<<"Temperature = "<<temp<<"°C"<<endl;
	}
};

int main(){
	Celcius c;
	float f;

	cout<<"Enter the Temperature in Farenheit: ";
	cin>>f;

	c=f;
	c.show();
}