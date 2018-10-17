#include <iostream>
#include <array>
#include <algorithm>
#include <functional>
#include <limits>
#include <iomanip>
#include <numeric>
#include <cmath>
using namespace std;


void test(int a, int b);

void test(int a, int b=5)
{
	std::cout<<a<<" "<<b<<std::endl;
}

void test2()
{
	array<double,5> a={1,2,3,4,5};
	array<double,5> b={5,6,7,8,9};
	for_each(a.begin(),a.end(),[](double&x){cout<<x<<" ";});
	cout<<endl<<accumulate(a.begin(),a.end(),0,[](double x, double y){return x+y;})<<endl;
	cout<<endl<<accumulate(a.begin(),a.end(),0,plus<double>())<<endl;
	for_each(a.begin(),a.end(),[](double&x){cout<<x<<" ";});
	
	double s=1.13;
	double dS = 0.01;
	int id = int((s - dS) / dS);
	int id2 = int((s + numeric_limits<double>::epsilon()- dS) / dS );
	cout<<id<<" "<<id2<<endl;
	cout<<setw(20)<<setprecision(15)<<numeric_limits<float>::epsilon()*pow(2,23)<<endl;
	cout<<setw(20)<<setprecision(15)<<numeric_limits<double>::epsilon()*pow(2,52)<<endl;


}

int main()
{
	test(1,2);
	test(3);

	test2();

	cout<<sizeof(long double)<<" "<<sizeof(double)<<endl;
	return 0;

}
