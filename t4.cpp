#include <cstdio>
#include <vector>

using std::vector;

void Thomas_Solver(const double *a, const double *b, const double *c, vector<double> &Sol_FDM, double *dummy, const int n)
{
	int j, StartPnt;
	double bet = 1.0;
	// Boundary Condition is embeded in Thomas_Solver function(Prefixed)
	// a[0]=0, b[0]=1, c[0]=0;
	// a[n-1]=1, b[n-1]=-1, c[n-1]=0;

	// Preset : dummy[0] = Force[0] = DailyBwdDiscFactor[t],
	//          dummy[n+1] = Force[n-1] = 0 
	StartPnt = (int)dummy[n]; // (= BarrierPnt+1)

	if (StartPnt == 0)
		Sol_FDM[0] = dummy[0];
	else
		dummy[n] = 0.0; // Boundary Condition for S = maxS.

	Sol_FDM[n - 1] = dummy[n];
	for (j = StartPnt + 1; j<n; j++) {
		dummy[j] = c[j - 1] / bet;		// c'[j-1]
		bet = b[j] - a[j] * dummy[j];	// b'[j]
		Sol_FDM[j] = (Sol_FDM[j] - a[j] * Sol_FDM[j - 1]) / bet;
	}

	for (j = (n - 2); j >= StartPnt; j--)
		Sol_FDM[j] -= dummy[j + 1] * Sol_FDM[j + 1];

}

void ThomasSolver(double *a, double *b, double *c, double*d, int n, double *sol, int start = 1)
{
	d[start] -= a[start]*sol[start-1];
	d[n-2] -= c[n-2]*sol[n-1];

	for(int i = start+1; i <=n-2; i++)
		b[i] -= a[i]/b[i-1]*c[i-1];

	sol[n-2] = d[n-2] / b[n-2];
	for(int i = n-3; i>=start; i--)
		sol[i] = (d[i] - c[i]*sol[i+1]) / b[i];
}

int main()
{
	double a[]={0,0.5,1.7, 1};
	double b[]={1, 1.2,2.3,-1};
	double c[]={0,0.8,2.5,0};

	vector<double> Sol_FDM = {0,1.2,1.5,1.8};
	for(int i = 0; i<4;i++) printf("%f ",Sol_FDM[i]); 	printf("\n");
	

	double *dummy=new double[5];
	dummy[4]=0.;
	dummy[0] = 0.;
	Thomas_Solver(a,b,c,Sol_FDM,dummy,4);
	for(int i = 0; i<4;i++) printf("%f ",Sol_FDM[i]); 	printf("\n");

	vector<double> sol_new(4);
	sol_new[0] = 0;
	//sol_new[3] = -0.054545;
	Sol_FDM = {0,1.2,1.5,1.8};
	for(int i = 0; i<4;i++) printf("%f ",sol_new[i]); 	printf("\n");
	ThomasSolver(a,b,c,Sol_FDM.data(), 4, sol_new.data());
	for(int i = 0; i<4;i++) printf("%f ",Sol_FDM[i]); 	printf("\n");
	for(int i = 0; i<4;i++) printf("%f ",sol_new[i]); 	printf("\n");


#ifdef _MSC_VER
	system("pause");
#endif

	return 0;



}