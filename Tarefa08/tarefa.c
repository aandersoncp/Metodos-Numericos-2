//NOME: ANTÔNIO ANDERSON COSTA PEREIRA
//MATRÍCULA: 422029

#include<stdio.h>
#include<math.h>

#define PI 3.1415926

int main(){
	long double gama[9], teta[9], w[9], alfa, beta, X, Y, ponto, soma;
	gama[0] = -sqrt(0.6);
	gama[1] = 0;
	gama[2] = sqrt(0.6);
	gama[3] = -sqrt(0.6);
	gama[4] = 0;
	gama[5] = sqrt(0.6);
	gama[6] = -sqrt(0.6);
	gama[7] = 0;
	gama[8] = sqrt(0.6);

	teta[0] = -sqrt(0.6);
	teta[1] = -sqrt(0.6);
	teta[2] = -sqrt(0.6);
	teta[3] = 0;
	teta[4] = 0;
	teta[5] = 0;
	teta[6] = sqrt(0.6);
	teta[7] = sqrt(0.6);
	teta[8] = sqrt(0.6);

	w[0] = 0.308641975;
	w[1] = 0.493827161;
	w[2] = 0.308641975;
	w[3] = 0.493827161;
	w[4] = 0.790123457;
	w[5] = 0.493827161;
	w[6] = 0.308641975;
	w[7] = 0.493827161;
	w[8] = 0.308641975;

	soma = 0;
	
	for(int i = 0; i < 9; i++){
		alfa = 0.5*(1 + gama[i]);
		beta = PI*(1 + teta[i]);
		X = alfa*40*cos(beta);
		Y = alfa*40*sin(beta);
		ponto = w[i]*sqrt(pow((0.4*X), 2) + pow((0.4*Y), 2) + 1)*(alfa*1600)*(PI*0.5);
		soma = soma + ponto;
	}
	printf("A = %Lf\n", soma);
	return 0;
}