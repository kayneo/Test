#include <iostream>
#include <string>
using namespace std;

void test(int a, int*b=NULL)
{
	if ( b == NULL){
		cout<<a<<" hiha"<<endl;
		return;
	}

	*b=-1*a;
}




int main()
{
	int a,b;
	a = 5;
	test(a,&b);
	cout<<b<<endl;
	test(a,NULL);
	a=3;
	test(a);

	string s="123456";

	cout<<s.substr(s.size()-3)<<endl;



	return 0;
}