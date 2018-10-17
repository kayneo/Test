#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

class A{
public:
	A(int a_):a(a_){}
	void show()
	{
		cout<<"hi a="<<a<<endl;
	}
private:
	int a;
};


class B{
public:
	B():obj(3){}
	void test()
	{
#pragma omp parallel for firstprivate(obj)
	for(int i = 0; i<5; ++i)
		obj.show();

	}

private:
	A obj;
};


int main()
{
	

	B b;
	b.test();




	return 0;
}