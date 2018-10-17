#include <random>
#include <cmath>
#include <ctime>
#include <omp.h>
using namespace std;

default_random_engine eng(time(NULL));
normal_distribution<double> norm(0,1);

double payoff(double &s, double &k)
{
    return fmax(s-k,0.);
}

double pnode(double &s0, double& u, double& q, double& vol, double& t)
{
    return s0*exp((u-q-0.5*vol*vol)*t + sqrt(t)*vol*norm(eng));
}

double mc(int& npath, const int& msteps)
{
    double u = 0;
    double q = 0;
    double vol = 0.2;
    double r = 0.035;
    double s0 = 1.;
    double t = 1.;
    double k = 1.;

    double val = 0.;
#pragma omp parallel for reduction(+:val)
    for(int i = 0; i<npath; ++i)
    {
        double dt = t / msteps;
        double st = s0;
        for(int j = 0; j<msteps; ++j)
            st=pnode(st,u,q,vol,dt);
        double v=payoff(st,k)*exp(-r * t); 
        val +=v;
    }

    printf("%d steps to terminal with %d paths : v=%f\n", msteps, npath, val/npath);

}

int main()
{
    clock_t t1 = clock();
    double ompt1 = omp_get_wtime();
    int n= 100000;
    int m = 100;
    mc(n, 1);
    mc(n,m);
    double ompt2 = omp_get_wtime();
    printf("Time cost %f\n", ompt2-ompt1);
    return 0;

}