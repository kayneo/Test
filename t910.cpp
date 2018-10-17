#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class A {
    public:
	virtual void test()
	{
	    cout<<"In A"<<endl;
	}
};

class B: public A
{
    public:
	virtual void test()
	{
	    //cout<<"In B"<<endl;
	    A::test();
	    xxx();
	}
	void xxx()
	{
	    cout<<"Another XXX"<<endl;
	}
};

void test()
{
    map<string,int> a;
    a["first"]=1;
    a["second"]=2;
    a["Teacher"]=3;

    //for_each(a.begin(),a.end(),[](int &s){cout<<s<<endl;});
    cout<<a["Teacher"]<<endl;
}

int main()
{
    A a;
    B obj;
    obj.test();
    a.test();

    test();
    return 0;
}
