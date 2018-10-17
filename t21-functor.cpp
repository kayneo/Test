#include <iostream>

using namespace std;

void test(bool flag, int a)
{
	if (flag)
	{
		cout<<a<<endl;
	}
	else
	{
		cout<<"null"<<endl;
	}
}

class EPayOff
{
public:
	EPayOff(double K, char callput):K(K),callput(callput){}
	double operator()(double S)
	{
		if ( callput == 'c' )
			return max(S-K,0.);
		else
			return max(K-S,0.);
	}
private:
	double K;
	char callput;
};
int main()
{
	int a = 3;
	test(true,a);
	//test(false,NULL);

	EPayOff c_payoff(2.3,'c'), p_payoff(2.3, 'p');

	for(int i = 0; i<10;i++)
	{
		double s = i*0.2 + 1.0;
		cout.width(3);
		cout<< s<<"\t"<<c_payoff(s)<<"\t"<<p_payoff(s)<<endl;
	}
	
	return 0;

}