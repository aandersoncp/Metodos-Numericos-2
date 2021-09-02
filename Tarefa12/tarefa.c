// NOME: ANTONIO ANDERSON COSTA PEREIRA
// MATRÍCULA: 422029

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define DIM 5

void identidade(double A[DIM][DIM]){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(i == j){
				A[i][j] = 1;
			} else {
				A[i][j] = 0;
			}
		}
	}
}

void mostrar(double A[DIM][DIM]){
	for(int i = 0; i < DIM; i++){
		for(int j = 0; j < 5; j++){
			printf("%f ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void copiar(double A1[DIM][DIM], double A2[DIM][DIM]){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			A1[i][j] = A2[i][j];
		}
	}
}

void transposta(double A1[DIM][DIM], double A2[DIM][DIM]){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			A1[j][i] = A2[i][j];
		}
	}
}

double comprimento(double *vetor){
	double aux = 0;
	for(int i = 0; i < 5; i++){
		aux += vetor[i]*vetor[i]; 
	}
	aux = sqrt(aux);
	return aux;
}

void multiplica(double A1[DIM][DIM], double A2[DIM][DIM], double A[DIM][DIM]){
	double soma, x[DIM][DIM];
	for(int i = 0; i < 5; i++){
		for(int k = 0; k < 5; k++){
			soma = 0;
			for(int l = 0; l < 5; l++){
				soma += A1[i][l]*A2[l][k];
			}
			x[i][k] = soma;
		}	
	}
	copiar(A, x);
}

void obter_Hj(double A[DIM][DIM], int j, int n, double Hj[DIM][DIM]){
	double v[n], v_l[n], Lv = 0, N[n], aux = 0, m_aux[n][n];

	for(int i = 0; i < n; i++){
		v[i] = 0;
		v_l[i] = 0;
	}

	for(int i = j; i < n; i++){
		v[i] = A[i][j];
	}

	Lv = comprimento(v);
	v_l[j] = Lv;

	for(int i = 0; i < n; i++){
		N[i] = v[i] - v_l[i]; 
	}

	aux = comprimento(N);

	for(int i = 0; i < n; i++){
		if(aux == 0){
			printf("Erro: Divisão por zero!\n");
			exit(0);
		}
		N[i] = N[i]/aux; 
	}

	identidade(Hj);

	for(int i = 0; i < n; i++){ 
		for(int k = 0; k < n; k++){
			m_aux[i][k] = N[i]*N[k];
		}	
	}

	for(int i = 0; i < n; i++){
		for(int k = 0; k < n; k++){
			Hj[i][k] = Hj[i][k] - 2*m_aux[i][k];
		}	
	}

}

void decomposicaoQR(double A[DIM][DIM], int n, double Q[DIM][DIM], double R[DIM][DIM]){
	double A_n[n][n], A_o[n][n], H[n][n], QT[n][n];
	
	copiar(A_n, A);
	identidade(QT);

	for(int j = 0; j < n - 1; j++){
		
		copiar(A_o, A_n);

		obter_Hj(A_o, j, n, H);
		
		multiplica(H, A_o, A_n);

		multiplica(H, QT, QT);
	}

	copiar(R, A_n);

	transposta(Q, QT);

	printf("\nQ: \n");
	mostrar(Q);

	printf("\nR: \n");
	mostrar(R);
}


double somaDeQuadrados(double A[DIM][DIM], int n){
	double L = 0;
	for(int j = 0; j < n - 1; j++){
		for(int i = j + 1; i < n; i++){
			L += A[i][j]*A[i][j];
		}
	}
	return L;
}

void metodoQR(double A[DIM][DIM], int n, double epsilon){
	double Q[n][n], R[n][n], A_o[n][n], A_n[n][n], FI[n][n], L = 1, aux[n][n];

	copiar(A_n, A);

	identidade(FI);
	identidade(Q);
	
	while(L > epsilon){
		copiar(A_o, A_n);

		decomposicaoQR(A_o, n, Q, R);
		
		//A_n = R*Q
		multiplica(R, Q, A_n);

		printf("\nA_n: \n");

		mostrar(A_n);

		multiplica(FI, Q, FI);

		multiplica(Q, R, aux);
		printf("\nQR: \n");
		mostrar(aux);

		L = somaDeQuadrados(A_n, n);
	}

	printf("\nA_n: \n");

	mostrar(A_n);

	printf("\nFI: \n");

	mostrar(FI);
}



int main(int argc, char const *argv[]){

	double A[5][5] = {{40, 8, 4, 2, 1}, {8, 30, 12, 6, 2}, {4, 12, 20, 1, 2}, {2, 6, 1, 25, 4}, {1, 2, 2, 4, 5}};
	metodoQR(A, 5, 0.001);
	
	return 0;
}