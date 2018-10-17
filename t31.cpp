#include <algorithm>
#include <iostream>
using namespace std;



int main()
{
	int arr[5]={1,3,5,4,8};
	cout<<distance(arr, find(arr, arr+5,9))<<endl;
	cout<<arr+5<<" "<<find(arr, arr+5,9)<<endl;

	double *dptr = new double[20];

	int n = 5;
	typedef double(*ARRPTR)[n];
	ARRPTR aptr = (ARRPTR) dptr;


	aptr[2][4] = 11.;
	cout<<dptr[14]<<endl;

	return 0;
}