// NOME: ANTÔNIO ANDERSON COSTA PEREIRA 
// MATRÍCULA: 422029

#include<stdio.h>
#include<math.h>

#define PI 3.1415926

long double x_s_simples(long double a, long double b, long double x){
	long double resultado, p1, p2;
	p1 = (a + b)/2 + (tanhl(x)*(b - a))/2;
	p1 = 1/(pow(p1, 0.666667));
	p2 = (b - a)/(2*pow((coshl(x)),2));
	resultado = p1*p2;
	return resultado;
}

long double x_s_dupla(long double a, long double b, long double x){
	long double resultado, p1, p2;
	p1 = (a + b)/2 + tanhl(sinhl(x)*(PI/2))*((b - a)/2);
	
	p1 = 1/(pow(p1, 0.666667));
	
	p2 = ((b - a)*PI*coshl(x))/(4*pow(coshl((PI/2)*sinhl(x)), 2));
	
	resultado = p1*p2;
	
	return resultado;
}

void GL4s(long double limite_inferior, long double limite_superior, long double a, long double b){
	long double gl_s, gl_d;
	long double x1, x2, x3, x4;
	long double w1, w3;
	x1 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(sqrt((15 + 2*sqrt(30))/35));
	x2 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(-sqrt((15 + 2*sqrt(30))/35));
	x3 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(sqrt((15 - 2*sqrt(30))/35));
	x4 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(-sqrt((15 - 2*sqrt(30))/35));
	w1 = ((-5 + 3*sqrt(30))/(6*sqrt(30)));
	w3 = ((5 + 3*sqrt(30))/(6*sqrt(30)));

	gl_s = ((limite_superior - limite_inferior)/2)*(x_s_simples(a, b, x1)*w1 + x_s_simples(a, b, x2)*w1 + x_s_simples(a, b, x3)*w3 + x_s_simples(a, b, x4)*w3);
	printf("\nGLS: %Lf\n\n", 2*gl_s);
}

void GL4d(long double limite_inferior, long double limite_superior, long double a, long double b){
	long double gl_s, gl_d;
	long double x1, x2, x3, x4;
	long double w1, w3;
	x1 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(sqrt((15 + 2*sqrt(30))/35));
	x2 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(-sqrt((15 + 2*sqrt(30))/35));
	x3 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(sqrt((15 - 2*sqrt(30))/35));
	x4 = (limite_superior + limite_inferior)/2 + ((limite_superior - limite_inferior)/2)*(-sqrt((15 - 2*sqrt(30))/35));
	w1 = ((-5 + 3*sqrt(30))/(6*sqrt(30)));
	w3 = ((5 + 3*sqrt(30))/(6*sqrt(30)));

	gl_d = ((limite_superior - limite_inferior)/2)*(x_s_dupla(a, b, x1)*w1 + x_s_dupla(a, b, x2)*w1 + x_s_dupla(a, b, x3)*w3 + x_s_dupla(a, b, x4)*w3);
	printf("\nGLD: %Lf\n", 2*gl_d);
}

long double integral_numerica_fechada_s(long double xi, long double xf, long double c, long double b){
	long double valor, a = 45, h;
	h = (xf - xi)/4;
	valor = (2/a)*h*(7*x_s_simples(c, b, xi) + 32*x_s_simples(c, b, xi + h) + 12*x_s_simples(c, b, xi + 2*h) + 32*x_s_simples(c, b, xi + 3*h) + 7*x_s_simples(c, b, xi + 4*h));
	return 2*valor;
}

long double integral_numerica_fechada_d(long double xi, long double xf, long double c, long double b){
	long double valor, a = 45, h;
	h = (xf - xi)/4;
	valor = (2/a)*h*(7*x_s_dupla(c, b, xi) + 32*x_s_dupla(c, b, xi + h) + 12*x_s_dupla(c, b, xi + 2*h) + 32*x_s_dupla(c, b, xi + 3*h) + 7*x_s_dupla(c, b, xi + 4*h));
	return 2*valor;
}


int main(){
	long double valor_anterior, delta, limite_inferior, limite_superior, epsilon = 0.000001, xi, xf, I_a, I_b, N, E, contador;
	limite_inferior = -9;
	limite_superior = 5;
	
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
			I_a = I_a + integral_numerica_fechada_s(xi, xf, 0, 1);
		}
		E = (I_a - valor_anterior)/I_a;
		valor_anterior = I_a;
	} while(E > epsilon);

	printf("\nFECHADA simples:\nValor: %.6Lf\nNúmero de iterações: %.0Lf\nNúmero de segmentos: %.0Lf\n", I_a, contador, N);

	limite_inferior = -3;
	limite_superior = 2;
	
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
			I_b = I_b + integral_numerica_fechada_s(xi, xf, 0, 1);
		}
		E = (I_b - valor_anterior)/I_b;
		valor_anterior = I_b;
	} while(E > epsilon);
	
	printf("\nFECHADA dupla: \nValor: %.6Lf\nNúmero de iterações: %.0Lf\nNúmero de segmentos: %.0Lf\n", I_b, contador, N);

	GL4s(-9, 5, 0, 1);
	GL4d(-3, 2, 0, 1);
	return 0;
}