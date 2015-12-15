#include<stdio.h>
#include<math.h>
#include"pi.h"

static double tol = 10e-06; 
void loopLeibniz( void);
void loopLeibniz( void){
	int i = 1;
	double pi; 
	double abserr; 
	do{
		pi = piLeibniz (i);
		abserr = fabs (pi - M_PI);
		printf ("%8d %20.15f %20.15f\n", i, pi, abserr);
		i *= 2;
	}
	while (abserr > tol);
}


void loopBBP( void);
void loopBBP( void){
        int i = 1;
        double pi;
        double abserr;
        do{
                pi = piBBP (i);
                abserr = fabs (pi - M_PI);
                printf ("%8d %20.15f %20.15f\n", i, pi, abserr);
                i *= 2;
        }
        while (abserr > tol);
}
void timeBBP(void);
void timeBBP(void){
	int count = 1000;
	double time; 
	double time1; 
	
	do
	{
		timer_start ();
			loopLiebniz();
		time = timer_stop ();
		time1 = time / count;
		printf (" %10.2f usec %10.6f sec %10d\n",
		time1 * 1.e6, time, count);
		count = adjust_rep_count (count, time, tmin, tmax);
	}
	while ((time > tmax) || (time < tmin));
}

int main(void){
	loopLeibniz(); 
	loopBBP();
}
