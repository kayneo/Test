#include<iostream>
#include <functional>
#include <string>
using namespace std;

int main()
{
    std::hash<std::string> str_hash;
    cout<<str_hash("nihao")<<endl;
    string s ="nihao";

    switch (str_hash(s))
    {
    	case str_hash("nihao"):
    	cout<<"ok"<<endl;
    	break;
    	default:
    	cout<<"no"<<endl;

    }
    return 0;
}
