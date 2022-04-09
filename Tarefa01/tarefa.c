#include<stdio.h>
#include<math.h>

long double f(long double x){
	long double resultado = sqrt(exp(3*x) + 4*x*x);
	return resultado;
}

long double derivada_numerica(long double x, long double delta){
	long double valor = (1/(delta*delta))*((4/3)*f(x + delta) + (4/3)*f(x - delta) - (1/12)*f(x + 2*delta) - (1/12)*f(x - 2*delta) - (5/2)*f(x));
	return valor;
}

long double derivada(long double x){
	long double valor1 = (9*exp(3*x) + 8)/(2*sqrt(exp(3*x) + 4*x*x)); 
	long double valor2 = pow((8*x + 3*exp(3*x)), 2)/(4*pow((exp(3*x) + 4*x*x), 1.5));
	long double valor = valor1 - valor2;
	return valor;
}

int main(){
	long double x = 2, delta = 0.5, erro = 1, valor2;
	valor2 = derivada(x);
	
	printf("f(%.Lf) = %.6Lf e f''(%.1Lf) = %.6Lf para e delta = %.6Lf.\n", x, f(x), x, derivada_numerica(x, delta), delta);
	delta = delta /2;	

	while((erro) > 0.00001){
		printf("f(%.Lf) = %.6Lf e f''(%.1Lf) = %.6Lf para e delta = %.6Lf.\n", x, f(x), x, derivada_numerica(x, delta), delta);
		erro = ((derivada_numerica(x, delta) - derivada_numerica(x, delta*2))/derivada_numerica(x, delta));
		if(erro < 0){
			erro = -erro;
		}	
		printf("e(x) = %.5Lf, para delta = %.5Lf\n", erro, delta);
		printf("\n");
		delta = delta/2;
	}
	printf("\nf''(%.1Lf) = %.6Lf.\n", x, valor2);

	delta = 0.5;
	while(delta > 0.00001){
		erro = ((derivada_numerica(x, delta) - derivada_numerica(x, delta*2))/derivada_numerica(x, delta));
		printf("f(%.Lf) = %.6Lf e f''(%.1Lf) = %.6Lf para e Δ = %.6Lf e(x) = %.6Lf\n", x, f(x), x, derivada_numerica(x, delta), delta, erro);
		delta = delta/2;
	}
	printf("\nf''(%.1Lf) = %.10Lf.\n", x, valor2);

	return 0;
}
