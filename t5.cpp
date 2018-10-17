#include <iostream>
#include <fstream>
using namespace std;

int returnplace(double t, int indaynum)
{
	double timeInDay = t - int(t);
	double node[]={9.5/24, 11.5/24, 13.0/24, 15.0/24};
	double tStep = 4./24 / indaynum;

	if( timeInDay > node[1] && timeInDay <node[2])
		timeInDay = node[2];
	int place;
	if( timeInDay < node[0] + tStep)
		place = 0;
	else if( timeInDay < node[1])
		place = int((timeInDay - node[0]) / tStep);
	else if(timeInDay < node[3])
		place = int( (timeInDay -node[0]-(node[2]-node[1]))/ tStep);
	else
		place = indaynum;

	return place;
}

int main()
{
	int len = 3000;
	int indaynum = 7;
	ofstream fout("D:\\Desktop\\tmp.txt");

	for(int i = 0; i<len; i++)
	{
		double t = i/double(len);
		fout<<t<<","<<returnplace(t,indaynum)<<endl;
		cout<<t<<","<<returnplace(t,indaynum)<<endl;
	}
	fout.close();
	return 0;
}
