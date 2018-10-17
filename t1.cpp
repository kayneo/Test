#include <iostream>
#include <vector>
using namespace std;

class A{
public:
	A(){cout<<"IN A\n";}
	virtual void show() = 0;
	virtual void funB(){};
	virtual void funC(){};
};

class B:public A{
public:
	B(){cout<<"IN B\n";}
	void show()
	{
		cout<<"Show in B\n";
	}
	void funB()
	{
		cout<<"fun in B\n";
	} 
};

class C:public A{
public:
	C(){cout<<"IN C\n";}
	void show()
	{
		cout<<"Show in C\n";
	}
	void funC()
	{
		cout<<"fun in C\n";
	}
};

void test(A* aptr)
{
	aptr->show();
	aptr->funB();
}

int main()
{
	C c;
	B b;

	test(&c);
	test(&b);

	vector<int> vec ={ 1,2,3,4,5 };
	cout << vec.at(3) << endl;



#ifdef _MSC_VER
	system("pause");
#endif // _MSC_VER




	return 0;
}