//Parallel 
#include <omp.h>
#include <stdio.h>
#define NUMBER 100

double alpha()
{
	int i;	double a=0.0;
	for (i=0; i<NUMBER; i++)
		 a+=(i-1)/(i+1);
	return a;
}

double beta()
{
	int i;	double b=0.0;
	for (i=NUMBER; i>0; i--)
		 b+=i*(i-1);
	return b;
}

double delta()
{
	int i,j;	double c=0.0;
	for (i=NUMBER,j=0; i>0,j<NUMBER; i--,j++)
		c+=(i-j)/NUMBER;
	return c;
}

double gamma(double d, double e)
{
	return (d-e);
}

double epsilon(double f, double g)
{
	return (f+g);
}

int main(int argc, char *argv[])
{
	double w, v, x, y;
	//#pragma omp parallel num_threads(5)	
	#pragma omp parallel
	{
		#pragma omp sections
   		{
			#pragma omp section  
      			w = alpha();
			#pragma omp section
      			v = beta();
			#pragma omp section
      			y = delta();
		}
   	}
   	x = gamma(v, w);
  	printf ("%12.4f\n", x);   	printf ("%12.4f\n", epsilon(x,y));
}

