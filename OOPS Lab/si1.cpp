#include<iostream>
using namespace std;

class SI {
	int p, t, r;

public:
	SI (int p, int t, int r=5){
		this->p=p;
		this->t=t;
		this->r=r;
	}

	inline double getSI(){
		return (p*t*r/100);
	}
};

int main(int argc, char const *argv[]){
	int p, t, r;
	cout<<"Enter the principle, time and rate of interest:\n";
	cin>>p>>t>>r;

	SI si = SI(p,t,r);

	cout<<"The SI is: "<<si.getSI();
	return 0;
}