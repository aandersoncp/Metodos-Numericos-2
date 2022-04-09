#include<stdio.h>
#include<math.h>

#define DIM 49

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
	printf("Vetor: \n");
	for(int j = 0; j < DIM; j++){
		printf("%d:  %f\n", j, vetor[j]);
	}
	printf("\n");
}

void preenchimento_matriz(double A[DIM][DIM], int n){
	double esquerda = 64, direita = 64, centro = -256, acima = 64, abaixo = 64;
	//double esquerda = 16, direita = 16, centro = -64, acima = 16, abaixo = 16;
	int v_esquerdo, v_direito, v_acima, v_abaixo, aux1, aux2, aux3, index;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			index = i*n + j;
			v_esquerdo = index - 1;
			v_direito = index + 1;
			v_abaixo = index - n; 
			v_acima = index + n;

			A[index][index] = centro;

			if(j == 0 && i == 0){
				A[index][v_direito] = direita;
				A[index][v_acima] = acima;
			} else if(j == (n - 1) && i == 0){
				A[index][v_acima] = acima;
				A[index][v_esquerdo] = esquerda;
			} else if(j == 0 && i == (n - 1)){
				A[index][v_direito] = direita;
				A[index][v_abaixo] = abaixo;
			} else if( j == (n - 1) && i == (n - 1)){
				A[index][v_abaixo] = abaixo;
				A[index][v_esquerdo] = esquerda;
			} else if(j > 0 && j < (n - 1) && i == 0){
				A[index][v_acima] = acima;
				A[index][v_esquerdo] = esquerda;
				A[index][v_direito] = direita;
			} else if(j > 0 && j < (n - 1) && i == (n - 1)){
				A[index][v_abaixo] = abaixo;
				A[index][v_direito] = direita;
				A[index][v_esquerdo] = esquerda;
			} else if(j == 0 && i > 0 && i < (n - 1)){
				A[index][v_abaixo] = abaixo;
				A[index][v_acima] = acima;
				A[index][v_direito] = direita;
			} else if(j == (n - 1) && i > 0 && i < (n - 1)){
				A[index][v_esquerdo] = esquerda;
				A[index][v_acima] = acima;
				A[index][v_abaixo] = abaixo;
			} else{
				A[index][v_abaixo] = abaixo;
				A[index][v_acima] = acima;
				A[index][v_esquerdo] = esquerda;
				A[index][v_direito] = direita;
			}

		}
	}
}

void preenchimento_vetor(double *vetor){	
	for(int i = 0; i < DIM; i++){
		vetor[i] = 4;
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

	
	preenchimento_matriz(A, 7);
	
	preenchimento_vetor(vetor);

	eliminacaoGaussiana(49, A, vetor);

	substituicaoRetroativas(49, A, vetor, x);

	mostrar_vetor(x);

	return 0;
}
