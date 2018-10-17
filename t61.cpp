#include <iostream>
using namespace std;

int main()
{
	
	int arr[2][2];
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[1][0] = 3;
	arr[1][1] = 4;

	int *p =arr[0];
	for(int i = 0; i<4;i++)
			cout<<"("<<p+i<<","<<*(p+i)<<"),";
	cout<<endl;

	for(int i =0; i<2;i++)
	{
		for(int j = 0; j<2; j++)
			cout<<"("<<arr[i][j]<<","<<*(p+i*2+j)<<") ";
		cout<<endl;
	}

	int arrb[100];
	for(int i = 0; i<100; i++)
		arrb[i] = i;
	int* pb=&arrb[50];
	for(int i = 0; i<20; i++)
		cout<<pb[i]<<" ";
	cout<<endl;

	return 0;
}