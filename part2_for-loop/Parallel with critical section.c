//Parallel with critical section
#include <omp.h>
#include <stdio.h>
#include <math.h>
#define NUMBER 500000
int main(int argc, char *argv[])
{
	int i, data[NUMBER];
	double result=0.0;
	for (i=0; i<NUMBER; i++)
	{
		data[i]=i*i;
	}
	//#pragma omp parallel num_threads(5)
	#pragma omp parallel for
	for (i=0; i<NUMBER; i++)
	{
	#pragma omp critical
		result+=(sin(data[i])-cos(data[i]))/(sin(data[i])+cos(data[i]));
	}
	printf("Result = %f\n",result);
}

