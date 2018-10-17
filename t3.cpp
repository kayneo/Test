#include <cstdio>
#include <vector>
#include <omp.h>

int main()
{
	char c = 's';
	while( c != 'e') {
		printf("%d\n",omp_get_dynamic());
		#pragma omp parallel
		printf("%d @%d\n", omp_get_thread_num(), omp_get_num_threads());
		scanf("%c",&c);
	}

	return 0;
}