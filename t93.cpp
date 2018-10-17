#include <iostream>
#include <ctime>
#include <thread>
using namespace std;

int main()
{

	int arr[2][2];
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[1][0] = 3;
	arr[1][1] = 4;

	for(int i = 0; i<4;i++)
			cout<<*(arr+i)<<",";
	cout<<endl;

	for(int i =0; i<2;i++)
	{
		for(int j = 0; j<2; j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}


	int num = 40000;
	int *buf = new int[num];
	for(int i = 0;i<num; i++)
		buf[i] = i;
	int * bi = &buf[100];
	cout<<bi[500]<<endl;



	return 0;

}
