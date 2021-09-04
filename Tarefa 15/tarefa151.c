#include<stdio.h>
#include<math.h>

#define DIM 7

void inicia_matriz(double A[DIM][DIM]){
	for(int i = 0; i < DIM; i++){
		for(int j = 0; j < DIM; j++){
			A[i][j] = 0.0;
		}
	}
}

void mostrar_matriz(double A[DIM][DIM]){
	printf("Matriz: \n");
	for(int i = 0; i < DIM; i++){
		for(int j = 0; j < DIM; j++){
			printf("%.3f ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void mostrar_vetor(double vetor[DIM]){
	printf("Vetor: ");
	for(int j = 0; j < DIM; j++){
		printf("%f ", vetor[j]);
	}
	printf("\n");
}

void preenchimento_matriz(double A[DIM][DIM], int index){
	double esquerda = 64, direita = 64, centro = -129;
	int v_esquerdo, v_direito;
	v_esquerdo = index - 1;
	v_direito = index + 1;

	if(v_esquerdo != -1){
		A[index][v_esquerdo] = esquerda;
	}
	
	if(v_direito != 7){
		A[index][v_direito] = direita;
	}

	A[index][index] = centro;
}

void preenchimento_vetor(double *vetor, double y0, double yn){	
	for(int i = 0; i < 7; i++){
		if(i == 0){
			vetor[i] = -64*y0;
		} else if(i == 6){
			vetor[i] = -64*yn;
		} else {
			vetor[i] = 0;
		}
	}
}

void eliminacaoGaussiana(int n, double A[DIM][DIM], double b[]){
	float m;
	for(int k = 0; k < n; k++){
		for(int i = k + 1; i < n; i++){
			m = -A[i][k]/A[k][k];
			A[i][k] = 0;
			for(int j = k + 1; j < n; j++){
				A[i][j] = A[i][j] + m*A[k][j];
			}
		b[i] = b[i] + m*b[k]; 
		}
	}
}

void substituicaoRetroativas(int n, double A[DIM][DIM], double b[], double x[]){
	double soma;
	x[n - 1] = b[n - 1]/A[n - 1][n - 1];
	for(int i = (n - 2); i >= 0; i--){
		soma = 0;
		for(int j = i + 1; j < n; j++){
			soma = soma + A[i][j]*x[j];
		}
		x[i] = (b[i] - soma)/A[i][i];
	}	
}


int main(int argc, char const *argv[]){
	double A[DIM][DIM], vetor[DIM], y0 = 0, yn = 1, b[DIM], x[DIM];
	inicia_matriz(A);

	for(int i = 0; i < 7; i++){
		preenchimento_matriz(A, i);
	}
	
	mostrar_matriz(A);

	preenchimento_vetor(vetor, y0, yn);

	eliminacaoGaussiana(7, A, vetor);

	substituicaoRetroativas(7, A, vetor, x);

	mostrar_vetor(x);

	return 0;
}
