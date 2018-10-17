#include <amp_math.h>
#include <cstdio>
using  concurrency::precise_math::erfinv;

int main() 
{
	double a = 0.55;
	printf("%f\n", erfinv(0.5));  //0.5*erfc(-0.5/sqrt(2.))

}

