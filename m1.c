#include<stdio.h>
#include<math.h>
#include"pi.c"	
#include"timer.c" 
#include"adjust.c"

static double tol = 10e-06; 
void loopLeibniz( void);
void loopLeibniz( void){
	//loops through leibniz until the error is
	//below the tolerance
	int i = 1;
	double pi; 
	double abserr; 
	do{
		pi = piLeibniz (i);
		abserr = fabs (pi - M_PI);
	//	printf ("%8d %20.15f %20.15f\n", i, pi, abserr);
		i *= 2;
	}
	while (abserr > tol);
}


void loopBBP( void);
void loopBBP( void){
	//loops through BBP until error
	//is below tolerance
        int i = 1;
        double pi;
        double abserr;
        do{
                pi = piBBP (i);
                abserr = fabs (pi - M_PI);
//                printf ("%8d %20.15f %20.15f\n", i, pi, abserr);
                i *= 2;
        }
        while (abserr > tol);
}
void timeLiebniz(void);
void timeLiebniz(void){
	//timing for Liebniz
	int count = 1000;
	double time; 
	double time1;
	double tmin = 1.;
	double tmax = 2.; 
	
	do
	{
		timer_start ();
		for (int i = 0; i <count; i++){
			loopLeibniz();
		}
		time = timer_stop ();
		time1 = time / count;
		printf (" %10.2f usec %10.6f sec %10d\n",
		time1 * 1.e6, time, count);
		count = adjust_rep_count (count, time, tmin, tmax);
	}
	while ((time > tmax) || (time < tmin));
}
void timeBBP(void);
void timeBBP(void){
	//implementatin of a timing function for BBP
        int count1 = 1000;
        double time;
        double time1;
        double tmin = 1.;
        double tmax = 2.;

        do
        {
                timer_start ();
                for (int i = 0; i <count1; i++){
                        loopBBP();
                }
                time = timer_stop ();
                time1 = time / count1;
                printf (" %10.2f usec %10.6f sec %10d\n",
                time1 * 1.e6, time, count1);
                count1 = adjust_rep_count (count1, time, tmin, tmax);
        }
        while ((time > tmax) || (time < tmin));
}

int main(void){
	timeLiebniz();
	timeBBP();
}
