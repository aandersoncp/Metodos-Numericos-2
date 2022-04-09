
// NOME: ANTÔNIO ANDERSON COSTA PEREIRA
// MATRÍCULA: 422029

#include<stdio.h>
#include<math.h>

long double funcao(long double x){
	long double f = pow((sin(2*x) + 4*x*x + 3*x), 2);
	return pow((sin(2*x) + 4*x*x + 3*x), 2);
}

long double GL2(long double limite_inferior, long double limite_superior){
	long double gl;
	long double x1, x2;
	long double w1;
	x1 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(sqrt(1/3));
	x2 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(-sqrt(1/3));
	w1 = 1;
	gl = ((limite_superior - limite_inferior)/2)*(funcao(x1)*w1 + funcao(x2)*w1);
	return gl;
}

long double GL3(long double limite_inferior, long double limite_superior){
	long double gl;
	long double x1, x2, x3;
	long double w1, w2;
	x1 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(-sqrt(3/5));
	x2 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(0);
	x3 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(sqrt(3/5));
	gl = ((limite_superior - limite_inferior)/2)*( ((funcao(x1)*5)/9) + ((funcao(x2)*8)/9) + ((funcao(x3)*5)/9) );

	return gl;
}

long double GL4(long double limite_inferior, long double limite_superior){
	long double gl;
	long double x1, x2, x3, x4;
	long double w1, w3;
	x1 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(sqrt((15 + 2*sqrt(30))/35));
	x2 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(-sqrt((15 + 2*sqrt(30))/35));
	x3 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(sqrt((15 - 2*sqrt(30))/35));
	x4 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(-sqrt((15 - 2*sqrt(30))/35));
	w1 = ((-5 + 3*sqrt(30))/(6*sqrt(30)));
	w3 = ((5 + 3*sqrt(30))/(6*sqrt(30)));
	gl = ((limite_superior - limite_inferior)/2)*(funcao(x1)*w1 + funcao(x2)*w1 + funcao(x3)*w3 +funcao(x4)*w3);
	return gl;
}


int main(){
	long double valor_anterior, delta, limite_inferior, limite_superior, epsilon = 0.000001, xi, xf, I_a, N, E, contador;
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
			I_a = I_a + GL2(xi, xf);
		}
		E = (I_a - valor_anterior)/I_a;
		valor_anterior = I_a;
	} while(E > epsilon);

	printf("\nValor da Integral com 2 pontos: %.6Lf\nNúmero de iterações: %.0Lf\nNúmero de segmentos: %.0Lf\n", I_a, contador, N);

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
			I_a = I_a + GL3(xi, xf);
		}
		E = (I_a - valor_anterior)/I_a;
		valor_anterior = I_a;
	} while(E > epsilon);

	printf("\nValor da Integral com 3 pontos: %.6Lf\nNúmero de iterações: %.0Lf\nNúmero de segmentos: %.0Lf\n", I_a, contador, N);

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
			I_a = I_a + GL4(xi, xf);
		}
		E = (I_a - valor_anterior)/I_a;
		valor_anterior = I_a;
	} while(E > epsilon);

	printf("\nValor da Integral com 4 pontos: %.6Lf\nNúmero de iterações: %.0Lf\nNúmero de segmentos: %.0Lf\n", I_a, contador, N);


	return 0;
}