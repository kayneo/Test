#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void test(double* v, int n)
{
    for(int i = 0; i<n;i++)
	cout<<v[i]<<" ";
    cout <<endl;
}

class A {
    public:
	static void show();
};

void A::show()
{
    cout<<"hi"<<endl;
}


int main()
{
    std::vector<double> v;
    int n = 10;
    for(int i = 0; i<n;i++)
	v.push_back(i*0.4);

    int k = 0;

    test(v.data()+k, n-k);

    A::show();

    return 0;

}
