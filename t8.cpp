#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TEST
{
public:
	TEST(){	cout<<"HAHA"<<endl;	}
	TEST(int i)
	{
		cout<<"Default"<<i<<endl;
		this->i = i;
	}
	TEST(const synTEST&t)
	{
		cout<<"Copy Constructor"<<endl;
	}
	int get_i(){return i;}
private:
	int i = 0;
};

TEST tfun()
{
	TEST a(5);
	return a;
}

struct AA{
	int a,b;
	AA()
	{
		cout<<"Default 0"<<endl;
	}
	AA(int d)
	{
		cout<<"Default "<<d<<endl;
		a=d;b=d;
	}
	AA(const AA& A)
	{
		a = A.a;
		b = A.b;
	}
};


AA afun()
{
	AA b(3);
	return b;
}
int main()
{
	//TEST a;
	//TEST b=a;
	//TEST c(a);

	//TEST d=tfun();
	cout<<tfun().get_i()<<endl;

	AA m = afun();

	// vector<AA> a(10);
	
	// AA & thisone = a[5];
	// thisone.a = 10;
	// thisone.b = 15;

	// AA* thatone = &a[5];
	// cout<<thatone->a<<" "<<thatone->b<<endl;

#ifdef _MSC_VER
	system("pause");
#endif // _MSC_VER

	

	return 0;
}

