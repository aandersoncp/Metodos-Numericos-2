#include<stdio.h>
#include<math.h>

long double funcao(long double x){
	long double valor = pow(x, 1.5) + 2;
	return valor;
}

long double integral_numerica_fechada(long double xi, long double xf){
	long double valor, a = 45, h;
	h = (xf - xi)/4;
	valor = (2/a)*h*(7*funcao(xi) + 32*funcao(xi + h) + 12*funcao(xi + 2*h) + 32*funcao(xi + 3*h) + 7*funcao(xi + 4*h));
	return valor;
}

long double integral_numerica_aberta(long double xi, long double xf){
	long double valor, a = 10, h;
	h = (xf - xi)/6;
	valor = (3/a)*h*(11*funcao(xi + h) - 14*funcao(xi + 2*h) + 26*funcao(xi + 3*h) - 14*funcao(xi + 4*h) + 11*funcao(xi + 5*h));
	return valor;
}

int main(){
	long double valor_anterior, delta, limite_inferior, limite_superior, epsilon, xi, xf, I_a, I_b, N, E;
	printf("Digite o valor do limite inferior: \n");
	scanf("%Lf", &limite_inferior);
	printf("Digite o valor do limite superior: \n");
	scanf("%Lf", &limite_superior);
	printf("Digite o valor da tolerância: \n");
	scanf("%Lf", &epsilon);
	
	N = 1;
	valor_anterior = 0;

	do{
		N = 2*N;
		delta = (limite_superior - limite_inferior)/N;
		I_a = 0;
		for(int i = 0; i < N; i++){
			xi = limite_inferior + i*delta;
			xf = xi + delta;
			I_a = I_a + integral_numerica_fechada(xi, xf);
		}
		E = (I_a - valor_anterior)/I_a;
		valor_anterior = I_a;
	} while(E > epsilon);
	
	N = 1;
	valor_anterior = 0;
	do{
		N = 2*N;
		delta = (limite_superior - limite_inferior)/N;
		I_b = 0;
		for(int i = 0; i < N; i++){
			xi = limite_inferior + i*delta;
			xf = xi + delta;
			I_b = I_b + integral_numerica_aberta(xi, xf);
		}
		E = (I_b - valor_anterior)/I_b;
		valor_anterior = I_b;
	} while(E > epsilon);
	
	printf("\nFECHADA: %.4Lf\n", I_a);
	printf("ABERTA: %.4Lf\n", I_b);
	return 0;
}