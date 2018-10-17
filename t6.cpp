#include <iostream>
#include <iomanip>
using namespace std;

double C(int m, int n)
{
	double v1=1, v2=1;
	//double val = 1.;
	for(int i=0;i<n;i++){
		v1 *= (m-i);
		v2 *= (n-i);
		//val *= (m-i)/double(n-i);
	}
	return v1/v2;
	//return val;

}

int main()
{
	int m = 1000;
	int n = 5;
	cout<<fixed<<C(m,n)<<endl;
	return 0;
}