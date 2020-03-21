//Parallel
#include <omp.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	int t_id, num_t;
	#pragma omp parallel num_threads(5)
	{
		num_t = omp_get_num_threads();
		t_id = omp_get_thread_num();
		printf("Hello world from thread ID %d/%d\n",t_id,num_t);
	}
} 

