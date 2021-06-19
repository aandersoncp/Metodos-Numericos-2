#include<stdio.h>
#include<math.h>

long double funcao(long double x){
	long double valor = pow(x, 1.5) + 2;
	//printf("f(%.5Lf) = %Lf\n", x, valor);
	return valor;
}

long double integral_numerica_fechada(long double x, long double h){
	long double valor, a = 45;
	valor = (2/a)*h*(7*funcao(x) + 32*funcao(x + h) + 12*funcao(x + 2*h) + 32*funcao(x + 3*h) + 7*funcao(x + 4*h));
	return valor;
}

long double integral_numerica_aberta(long double x, long double h){
	long double valor, a = 10;
	valor = (3/a)*h*(11*funcao(x) - 14*funcao(x + h) + 26*funcao(x + 2*h) - 14*funcao(x + 3*h) + 11*funcao(x + 4*h));
	return valor;
}

int main(){
	long double valor_a, valor_b, valor_anterior, delta, limite_inferior, limite_superior, h_b, h_a, h, epsilon, xi, xf, I_a, I_b, N;
	printf("Digite o valor do limite inferior: \n");
	scanf("%Lf", &limite_inferior);
	printf("Digite o valor do limite superior: \n");
	scanf("%Lf", &limite_superior);
	printf("Digite o valor da tolerância: \n");
	scanf("%Lf", &epsilon);
	N = 1;
	valor_a = 0;
	valor_anterior = 0;
	I_a = 0;
	I_b = 0;
	h = h_a/4;
	
	do{
		N = 2*N;
		delta = (limite_superior - limite_inferior)/N;
		valor_anterior = valor_a;
		for(int i = 0; i < 5; i++){
			xi = limite_inferior + i*h_a;
			xf = xi + h_a;
			valor_a = integral_numerica_fechada(xi, h);
			I_a = I_a + valor_a;
		}
	} while((valor_a - valor_anterior)/valor_a > epsilon);
	
	valor_b = 0;
	valor_anterior = 0;
	h = h_b/6;
	do{
		valor_anterior = ;
		for(int i = 1; i < 6; i++){
			xi = limite_inferior + i*h_b;
			xf = xi + h_b;
			valor_b = integral_numerica_aberta(xi, h);
			I_b = I_b + valor_b;
		}
	} while((valor_b - valor_anterior)/valor_b > epsilon);
	
	printf("\nFECHADA: %.4Lf\n", I_a);
	printf("ABERTA: %.4Lf\n", I_b);
	return 0;
}