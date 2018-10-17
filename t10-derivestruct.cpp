#include <iostream>
using namespace std;

struct base{
	int a;
	int b;
};

struct derive: base {
	int c;
};

int main()
{
	derive A;
	A.a = 1;
	A.b = 2;
	A.c = 5;

	base B;

	B = A;
	cout<<B.a<<" "<<B.b<<endl;
	return 0;
}