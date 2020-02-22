#include<iostream>
using namespace std;

class Test 
{
	static int count;
public:
	Test()
	{
		count++;
		d=5;
	}

	int getcount()
	{
		return count;
	}
};

int Test::count=0;

int main()
{
	Test q,w,e,r,t,y,u,i,o;
	cout<<t.getcount()<<endl;
	return 0;
}