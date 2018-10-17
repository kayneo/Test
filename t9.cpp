#include <iostream>
#include <vector>
using namespace std;




int main()
{
	cout << sizeof(long) << ends << sizeof(int) << ends<<endl;

	vector<int> a; vector<char> b;
	cout << sizeof(a) << ends << sizeof(b) << endl;
	cout << sizeof(char*) << endl;



#ifdef _MSC_VER
	system("pause");
#endif // _MSC_VER

	return 0;
}