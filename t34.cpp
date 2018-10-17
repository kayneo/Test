#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	vector<int> vec;
	random_device rd;
	for(int i =0; i<10;i++)
	vec.push_back(rd()%20);
	for_each(vec.begin(),vec.end(),[](int&i){cout<<i<<" ";}); cout<<endl;

	vector<int*> v;
	for (int i=0;i<vec.size(); i++)
		v.push_back(&vec[i]);
	for_each(v.begin(),v.end(),[](int*i){cout<<*i<<" ";}); cout<<endl;

	hash<string> h;
	size_t id;
	clock_t t1=clock();
	for(int i = 0; i<10000;i++)
		id = h("hihiidoefdettfefefdr");
	clock_t t2 = clock();

	cout<<id<<" "<<sizeof(id) <<" time:"<<t2-t1<<"ms."<<endl;

	//======================================

	time_t dt1= time(NULL);
	tm dts1,dts;
	dts = *gmtime(&dt1);
	dts1 = *localtime(&dt1);
	cout<< dts.tm_isdst<<" "<<dts.tm_hour<<endl;
	cout<< dts1.tm_isdst<<" "<<dts1.tm_hour<<endl;
	cout<<dt1<<" "<<mktime (&dts)<<endl;
	cout<<dt1<<" "<< mktime(&dts1)<<endl;

	dts1.tm_sec = 0;
	dts1.tm_min = 0;
	dts1.tm_hour = 0;
	time_t dt2 = mktime(&dts1);
	cout<< dt1<<"  "<<dt2<<endl;
	dts1.tm_mday ++;

	time_t dt3 = mktime(&dts1);

	cout<< dt1<<"  "<<dt3<<"  "<<dt3-dt2<<endl;
	cout<<asctime(&dts)<<endl;
	cout<<ctime(&dt1)<<endl;

	double a=25.234;
	int x;
	double b = frexp(a,&x);
	cout<<a<<"="<<b<<"*2^"<<x<<",  a="<<ldexp(b,x)<<endl;
	cout <<sizeof(time_t)<<" "<<sizeof(size_t)<<endl;
	cout<<pow(2,17)-1<<endl;
	cout<<log(86400)/log(2)<<endl;

	time_t dt4 = ((dt1) & 131071);
	tm dtstct;
	dtstct = *localtime(&dt4);
	cout<<dt4<<"="<<dtstct.tm_mday<<" "<<dtstct.tm_hour<<":"<<dtstct.tm_min<<":"<<dtstct.tm_sec<<endl;
	tm dts2={0,0,0,0,0,0,0,0,0};
	dts2.tm_hour = 15;
	cout<<mktime(&dts2)<<endl;

	struct aa{
		int a;
		int b;
	};

	vector<aa> aav;
	aav.push_back({1,2});
	aav.push_back({4,2});
	aav.push_back({1,5});


	char s[10], s2[8];
	strcpy(s,"hi");
	strcpy(s2,"hi");
	cout<< strcmp(s,s2)<<endl;

	vector<int> va, vb(5,2);
	va = vb;
	vb.clear();
	cout<<va[2]<<endl;

	void test(int*b, int& bn);

	int * ab, bn;
	test(ab, bn);
	for(int i =0;i<bn;i++)
		cout<<*ab<<endl;



	return 0;
}

void test(int* b, int& bn)
{
	static vector<int> a(5,2);	
	cout<<a.size()<<" "<<a[3]<<endl;
	b = a.data();
	bn = a.size();

}