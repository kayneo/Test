#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> a(10,0);
	cout<<a.size()<<endl;
	for(int i = 0; i<5; ++i)
		a[i]= i+1;

	int sz = distance(a.begin(),find(a.begin(), a.end(),0))-1;

	cout<<sz<<" "<<a[sz]<<endl;

	return 0;
}