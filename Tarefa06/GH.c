#include <stdio.h>
#include <math.h>

#define PI 3.1415926

long double f(long double x){
	return pow(x, 2);
}

void funcao_2(){
	long double x[2], w1, w2,w3, w4, total;

	x[0] = -1/sqrt(2);
	x[1] = 1/sqrt(2);

	w1 = (sqrt(PI))/(2);
	w2 = (sqrt(PI))/(2);

	total = f(x[0])*w1 + f(x[1])*w2;
	printf("Valor GH2 = %Lf\n", total); 
}

void funcao_3(){
	long double x[3], w1, w2, w3, total;

	x[0] = -sqrt(1.5);
	x[1] = 0;
	x[2] = sqrt(1.5);

	w1 = sqrt(PI)/6;
	w2 = (2*sqrt(PI))/3;
	w3 = sqrt(PI)/6;

	total = f(x[0])*w1 + f(x[1])*w2 + f(x[2])*w3;
	printf("Valor GH3 = %Lf\n", total); 
}

void funcao_4(){
	long double aux[4], x[4], resultado, w1, w2,w3, w4,total;

	x[0] = sqrt((3 + sqrt(6))/2);
	x[1] = -sqrt((3 + sqrt(6))/2);
	x[2] = sqrt((3 - sqrt(6))/2);
	x[3] = -sqrt((3 - sqrt(6))/2);
	for(int i = 0; i < 4; i++){
		resultado = (8*pow(x[i], 3) - 12.0*x[i]);
		aux[i] = pow(resultado, 2);
	}

	w1 = (12*sqrt(PI))/(aux[0]);
	w2 = (12*sqrt(PI))/(aux[1]);
	w3 = (12*sqrt(PI))/(aux[2]);
	w4 = (12*sqrt(PI))/(aux[3]);

	total = f(x[0])*w1 + f(x[1])*w2 + f(x[2])*w3 + f(x[3])*w4;
	printf("Valor GH4 = %Lf\n", total); 
}

int main(int argc, char const *argv[]){
	
	funcao_2();
	funcao_3();
	funcao_4();

	return 0;
}

