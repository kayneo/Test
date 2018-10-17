#include <iostream>

void testsize()
{
	printf("%s:%d\n%s:%d\n%s:%d\n%s:%d\n%s:%d\n%s:%d\n",
		"short", sizeof(short),
		"int", sizeof(int),
		"long", sizeof(long),
		"long long", sizeof(long long),
		"double", sizeof(double),
		"long double", sizeof(long double));
}
int main()
{
	
	testsize();



	return 0;
}