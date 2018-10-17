#include <cmath>
#include <iostream>

//测试3维插值

typedef const double condb;
double linearInterpolation3D(condb& x1, condb& x2, condb& y1, condb& y2, condb& z1, condb& z2,
		condb& v111, condb& v211, condb& v121, condb& v221, condb& v112, condb& v212,
		condb& v122, condb& v222, condb& x, condb& y, condb& z)
{
	double xf1 = (x-x2)/(x1-x2); double xf2 = 1.-xf1;
	double yf1 = (y-y2)/(y1-y2); double yf2 = 1.-yf1;
	double zf1 = (z-z2)/(z1-z2); double zf2 = 1.-zf1;

	return v111*xf1*yf1*zf1 + v211*xf2*yf1*zf1+v121*xf1*yf2*zf1+v221*xf2*yf2*zf1
	+v112*xf1*yf1*zf2+v212*xf2*yf1*zf2+v122*xf1*yf2*zf2+v222*xf2*yf2*zf2;

}



double f(double x,double y, double z)
{
	return sin(x)*exp(y) + z*z;

}
int main()
{
	double x[]= {1,1.0001};
	double y[]= {2,2.0001};
	double z[]= {1,1.0001};
	double *val = new double[8];

	for(int k = 0; k<sizeof(x)/sizeof(double); k++)
		for(int j  = 0; j<sizeof(x)/sizeof(double); j++)
			for(int i = 0; i<sizeof(x)/sizeof(double); i++)
			{
				double tmp =f(x[i],y[j],z[k]);
				val[k*4+j*2+i] = tmp;
				printf("%7.3f ",tmp);
			}
	printf("\n");



	double xo = (x[0]+x[1])/2;
	double yo = (y[0]+y[1])/2;
	double zo = (z[0]+z[1])/2;

	printf("The value is %7.3f\n", linearInterpolation3D(x[0],x[1], y[0],y[1],z[0],z[1],
		val[0], val[1],val[2],val[3],val[4],val[5],val[6],val[7],xo,yo,zo));

	delete val;
	return 0;
}
