#include <stdio.h>
#include <math.h>

#define PI 3.1415926

float f(float x){
	return pow(x, 2);
}

void funcao_2(){
	long double  aux[2], x[2], resultado, w1, w2, w3, w4, total;
	x[0] = -1/sqrt(2);
	x[1] = 1/sqrt(2);

	w1 = (PI)/2;
	w2 = (PI)/2;

	total = f(x[0])*w1 + f(x[1])*w2;
	printf("Valor GC2 = %Lf\n", total); 
}

void funcao_3(){
	long double  aux[3], x[3], resultado, w1, w2, w3, w4, total;
	x[0] = -sqrt(3)/2;
	x[1] = 0;
	x[2] = sqrt(3)/2;;

	w1 = (PI)/3;
	w2 = (PI)/3;
	w3 = (PI)/3;

	total = f(x[0])*w1 + f(x[1])*w2 + f(x[2])*w3;
	printf("Valor GC3 = %Lf\n", total); 
}


void funcao_4(){
	long double  aux[4], x[4], resultado, w1, w2, w3, w4, total;
	x[0] = 0.923880;
	x[1] = 0.382683;
	x[2] = -0.382683;
	x[3] = -0.923880;

	w1 = (PI)/4;
	w2 = (PI)/4;
	w3 = (PI)/4;
	w4 = (PI)/4;

	total = f(x[0])*w1 + f(x[1])*w2 + f(x[2])*w3 + f(x[3])*w4;
	printf("Valor GC4 = %Lf\n", total); 
}

int main(int argc, char const *argv[]){

	funcao_2();
	funcao_3();
	funcao_4();

	return 0;
}

