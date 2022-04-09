#include <stdio.h>
#include <math.h>

long double f(long double x){
	return pow(x, 2);
}

void funcao_2(){
	long double  aux[2], x[2], resultado, w1, w2, w3, w4, total;
	x[0] = 2 - sqrt(2);
	x[1] = 2 + sqrt(2);

	w1 = (2 + sqrt(2))/4;
	w2 = (2 - sqrt(2))/4;

	total = f(x[0])*w1 + f(x[1])*w2;
	printf("Valor GL2 = %Lf\n", total); 
}

void funcao_3(){
	long double  aux[3], x[3], resultado, w1, w2, w3, w4, total;
	x[0] = 0.415775;
	x[1] = 2.294280;
	x[2] = 6.289945;

	w1 = 0.711093;
	w2 = 0.278518;
	w3 = 0.010389;

	total = f(x[0])*w1 + f(x[1])*w2 + f(x[2])*w3;
	printf("Valor GL3 = %Lf\n", total); 
}

void funcao_4(){
	long double  aux[4], x[4], resultado, w1, w2, w3, w4, total;
	x[0] = 0.322548;
	x[1] = 1.745761;
	x[2] = 4.536620;
	x[3] = 9.395071;

	for(int i = 0; i < 4; i++){
		resultado = -(pow(x[i], 5) - 25*pow(x[i], 4) + 200*pow(x[i], 3) - 600*pow(x[i], 2) + 600*x[i] - 120)/120; 
		aux[i] = pow(resultado, 2);
	}

	w1 = (x[0])/(25*aux[0]);
	w2 = (x[1])/(25*aux[1]);
	w3 = (x[2])/(25*aux[2]);
	w4 = (x[3])/(25*aux[3]);

	total = f(x[0])*w1 + f(x[1])*w2 + f(x[2])*w3 + f(x[3])*w4;
	printf("Valor GL4 = %Lf\n", total); 
}

int main(int argc, char const *argv[]){
	
	funcao_2();
	funcao_3();
	funcao_4();

	return 0;
}
