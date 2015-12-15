#ifndef PI
#define PI
#include<stdio.h>
#include<math.h>

double piLeibniz(int n);
double piLeibniz(int n){
	double sum = 0;
	double sign = 1.0; 
	for (int i = 0; i<n; i++){
		sum = sum+ sign*(1.0/(2.0*i +1.0)); 
		sign = sign*-1.0;  
	}
	return 4*sum;
}
double piBBP(int n);
double piBBP(int n){
	double sum = 0; 
	for (int j = 0; j<n; j++){
		sum += 1.0/pow(16.0, j)*(4/(8.*j+1)-2/(8.*j+4)-1/(8.*j +4)-1/(8.*j +6)); 
	}
	return sum; 
}
#endif //PI



