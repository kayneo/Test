#include <iostream>
using namespace std;

enum type{
	first = 1,
	second,
	third
};

void test(int a)
{
	cout<<a<<endl;
}
int main()
{
	type a=second;
	test(a);
	return 0;
}