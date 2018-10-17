#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct A {
	int a =2;
};

struct B: A{
	int b = 3;
};


vector<double>& operator*(vector<double>& a,double c)
{
	for(int i = 0; i<a.size();i++)
		a[i] *= c;
	return a;
}

int main()
{
	vector<double> arr={1.,2.,3.};
	double c = 3.;

	//arr = ;
	arr*c;
	for_each(arr.begin(),arr.end(),[](double&s){cout<<s<<" ";});cout<<endl;

	B bobj;
	cout<< bobj.a<<bobj.b<<endl;
	string as = "2017-01-01 15:00:01";
	string bs = "2017-01-01 15:00:00";

	if( as > bs)
		cout<<"hi"<<endl;


	return 0;
}
