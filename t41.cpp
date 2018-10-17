#include <iostream>
#include <ctime>
#include <string>
using namespace std;
void test_time();
int main()
{
	std::hash<string> str_hash;
	string id = "BVAA_941";
	size_t hashid = str_hash(id);
	cout<<str_hash(id)<<" "<< hashid<<endl;
	cout<<sizeof(hashid)<<" "<<sizeof(double)<<" "<<sizeof(time_t)<<endl;
	test_time();
	return 0;
}

void test_time()
{
	time_t timestamp = time(NULL);
	tm ts = *localtime(&timestamp);
	cout<<ts.tm_year+1900<<"-"
	<<	ts.tm_mon+1<<"-"
	<<	ts.tm_mday<<endl;

	int n = 10;	
	ts.tm_year = 70;
	ts.tm_mon = 0;
	ts.tm_mday = 1;

	ts.tm_hour = 8;
	ts.tm_min = 0;
	ts.tm_sec = 0;
	timestamp = mktime(&ts);
	do 	{
		
		cout<<ts.tm_year+1900<<"-"
		<<	ts.tm_mon+1<<"-"
		<<	ts.tm_mday<<"\t";
		cout<<mktime(&ts) <<" "<<mktime(&ts) - timestamp<<endl;
	} while(n-- && ts.tm_mday ++);
	cout<<"hi"<<endl;

	time_t time = 0;
	tm ts2 =* localtime(&time);
	cout<<ts2.tm_year+1900<<"-"
		<<	ts2.tm_mon+1<<"-"
		<<	ts2.tm_mday<<" "
		<<ts2.tm_hour<<":"<<ts2.tm_min<<":"<<ts2.tm_sec<<endl;

}