#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using std::cout;
using std::endl;

typedef const int conint;
typedef const double condb;
typedef std::vector<double> dvec;
typedef std::vector<dvec> dmat;


class VOLSPACE {
public:
	VOLSPACE(int n1, int n2, int NX):N1(n1),N2(n2),data(n1*n2)
	{
		for(int i= 0; i<n1;i++)
			for(int j =0; j<n2; j++)
				data[j*n1+i].resize(NX);
	}
	dvec& operator()(conint& i, conint& j)
	{
		return data[j*N1+i];
	}
private:
	int N1, N2;
	dmat data;

};



class VOL {
public:
	VOL(int sx,int sy, int sz):sX(sx),sY(sy),sZ(sz),vals(sx*sy*sz){}
	double operator()(conint& i, conint& j, conint& k ) const
	{
		assert(i<sX);
		assert(j<sY);
		assert(k<sZ);
		return vals[(k*sY+j)*sX +i];
	}
	int getDim(conint& dim)
	{
		assert(dim>0 && dim <=3);
		switch (dim) {
			case 1:
			return sX;
			case 2:
			return sY;
			case 3:
			return sZ;
		}
	}
	int getSize()
	{
		//return sX*sY*sZ;
		return vals.size();
	}
private:
	int sX, sY, sZ;
	dvec vals;
};

int main()
{
	int n = 10;

	VOL sols(n,n-4,n+5);

	std::cout<<sols(2,5,1)<<std::endl;

	cout<<sols.getSize()<<endl;
	cout<<sols.getDim(2)<<endl;

	//cout<<max(2.0,3.0)<<endl;
	cout<<fmax(2.0,3.0)<<endl;

	double x = 0.0000000000001;
	cout.setf(std::ios::fixed);
	cout.precision(30);
	cout<<exp(x)-1<<"  "<<expm1(x)<<endl;



	return 0;
}
