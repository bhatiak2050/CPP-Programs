#include<iostream>
#include<stdio.h>
using namespace std;

class Complex
{
	double real, imag;
	friend Complex operator+(Complex &, Complex &);

public:
	Complex(double real, double imag)
	{
		this->real=real;
		this->imag=imag;
	}

	inline double getreal() { return real; }
	inline double getimag() { return imag; }
};

Complex operator+(Complex &c1, Complex &c2)
{
	double real = c1.real + c2.real;
	double imag = c1.imag + c2.imag;
	Complex c3 = Complex(real, imag);
	return c3;
}

int main()
{
	double real, imag;
	char op;

	cout<<"Enter the first Complex number\n";
	scanf("%lf%ci%lf", &real, &op, &imag);
	if(op=='-') imag = -imag;
	Complex c1(real, imag);

	cout<<"Enter the second Complex number\n";
	scanf("%lf%ci%lf", &real, &op, &imag);
	if(op=='-') imag = -imag;
	Complex c2(real, imag);	

	Complex c3 = c1+c2;

	cout<<"The sum is: "<<c3.getreal();
	if(c3.getimag()<0) cout<<"-i"<<-1*c3.getimag();
	else cout<<"+i"<<c3.getimag()<<endl;

	return 0;
}