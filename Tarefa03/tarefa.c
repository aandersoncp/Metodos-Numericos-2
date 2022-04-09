// NOME: ANTÔNIO ANDERSON COSTA PEREIRA 
// MATRÍCULA: 422029

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
	long double valor_anterior, delta, limite_inferior, limite_superior, epsilon = 0.000001, xi, xf, I_a, I_b, N, E, contador;
	printf("Digite o valor do limite inferior: \n");
	scanf("%Lf", &limite_inferior);
	printf("Digite o valor do limite superior: \n");
	scanf("%Lf", &limite_superior);
	
	N = 1;
	valor_anterior = 0;
	contador = 0;

	do{
		contador++;
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

	printf("\nFECHADA:\nValor: %.6Lf\nNúmero de iterações: %.0Lf\nNúmero de segmentos: %.0Lf\n", I_a, contador, N);
	
	N = 1;
	valor_anterior = 0;
	contador = 0;
	do{
		contador++;
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
	
	printf("\nABERTA: \nValor: %.6Lf\nNúmero de iterações: %.0Lf\nNúmero de segmentos: %.0Lf\n", I_b, contador, N);
	return 0;
}