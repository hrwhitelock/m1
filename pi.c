//#ifndef PI
//#define PI
#include<stdio.h>
#include<math.h>
#include"pi.h"

double piLeibniz(int n){
	double sum = 0;
	int sign = 1; 
	double denom = 1.;
	for (int i = 0; i<n; i++){
		sum += sign/denom; 
		sign *= -1;
		denom += 2.;  
	}
	return 4*sum;
}
double piBBP(int n){
	double sum = 0; 
	double a=1., b=1., c=4., d=5., e=6.;
	for (int j = 0; j<n; j++){
		sum += ((4/b)-(2/c)-(1/d)-(1/e))/a; 
		a *= 16; 
		b += 8;
		c += 8; 
		d += 8; 
		e += 8; 

	}
	return sum; 
}
//#endif //PI



