#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> a(5,10),b(300,0);
	vector<int> ai = a;
	vector<int> *bi = &b;

	cout<<sizeof(a)<<" "<<sizeof(ai)<<" "<<sizeof(*bi)<<" " <<sizeof(b)<<endl;


	char s[10] = "123";
	vector<string> strvec;
	strvec.push_back(s);

	cout<<strvec.back()<<endl;

	cout<<"hi"+string("nihao")<<endl;








	cout<<a[2]<<endl;

}