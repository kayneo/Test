#include <iostream>
#include <vector>
using namespace std;

struct A
{
	int a,b;
};

struct B{
	int ba, bb;
};

struct C: A, B{
	int cc;
};

int main()
{
	C cs;
	A as;
	B bs;

	as.a = 10;as.b=11;
	bs.ba=11;bs.bb=100;

	//cs = as;
	vector<int> a(5);
	for (int i = 0 ; i < a.size(); i++)
		a[i] = i;

	for (int i = 0 ; i < a.size(); i++)
		cout<<a[i]<<" ";
	cout<<endl;


	typedef vector<vector<double>> DBMtx;

	DBMtx vanillahedge;

	vector<int> m(5,3);

	int xx= 5 | m[2];
	cout<<xx<<endl;

	vector<bool> inuse(2,false); 

	cout<<sizeof(inuse)<<endl;


}