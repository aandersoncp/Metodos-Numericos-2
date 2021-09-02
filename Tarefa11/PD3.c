#include<stdio.h>
#include <math.h>

#define DIM 5

void substituicaoSucessivas(int n, double A[DIM][DIM], double b[], double x[]){
	double soma;
	x[0] = b[0]/A[0][0];
	for(int i = 1; i < n; i++){
		soma = 0;
		for(int j = 0; j < i; j++){
			soma = soma + A[i][j]*x[j];
		}
		x[i] = (b[i] - soma)/A[i][i];
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

void fatoracaoLUPivoteamentoParcial(int n, double A[DIM][DIM], double b[], double x[]){
	double L[DIM][DIM], U[DIM][DIM];
	double y[n], temp;

	for(int linha = 0; linha < n; linha++){
		for(int coluna = 0; coluna < n; coluna++){
			U[linha][coluna] = A[linha][coluna];
		}
	}

	for(int linha = 0; linha < n; linha++){
		for(int coluna = 0; coluna < n; coluna++){
			if(linha > coluna){
				L[linha][coluna] = A[linha][coluna]/A[coluna][coluna];
			} else if(linha == coluna){
				L[linha][coluna] = 1;
			} else{
				L[linha][coluna] = 0;
			}
		}
	}

	//GAUSS COM PIVOTEAMENTO PARCIAL
	double max, aux, m, aux3;
	int p, index, vetor_aux[n], aux2;

	for(int i = 0; i < n; i++){
		vetor_aux[i] = i;
	}

	for(int j = 0; j < n - 1; j++){ 
		max = U[j][j];
		index = j;
		//PROCURAR O PIVO
		for(p = j; p < n; p++){
			if(U[p][j] < 0){
				temp = -U[p][j];
			} else {
				temp = U[p][j];
			}
			if(temp > max){
				max = U[p][j];
				index = p;
			}
		}
		if(max == 0){
			return;
		}

		if(index != j){
			//TROCANDO A LINHA[J] PELA LINHA[INDEX]
			for(int s = 0; s < n; s++){ 
				aux = U[index][s];
				U[index][s] = U[j][s];
				U[j][s] = aux;

				aux = L[index][s];
				L[index][s] = L[j][s];
				L[j][s] = aux;

				aux = A[index][s];
				A[index][s] = A[j][s];
				A[j][s] = aux;
			}
			//TROCANDO A B[J] PELO B[INDEX]
			aux3 = b[index];
			b[index] = b[j];
			b[j] = aux3;


			//GUARDANDO AS ALTERAÇÕES
			aux2 = vetor_aux[index];
			vetor_aux[index] = vetor_aux[j];
			vetor_aux[j] = aux2;
		}


		//PARTE DA ELIMINAÇÃO DE GAUSS
		for(int i = j + 1; i < n; i++){
			m = U[i][j]/((double)U[j][j]);
			L[i][j] = m;
			U[i][j] = 0;
			for(int k = j + 1; k < n; k++){
				U[i][k] = U[i][k] - m*U[j][k];
			}
			//b[i] = b[i] - m*b[j];
		}
	}

	for(int linha = 0; linha < n; linha++){
		for(int coluna = 0; coluna < n; coluna++){
			if(linha == coluna){
				L[linha][coluna] = 1;
			} else if(coluna > linha){
				L[linha][coluna] = 0;
			}
		}
	}

	substituicaoSucessivas(n, L, b, y);

	substituicaoRetroativas(n, U, y, x);

}


double normatizacao(double *vetor){
	double comp = 0;
	for(int i = 0; i < 5; i++){
		comp += vetor[i]*vetor[i];
	}
	return sqrt(comp);
}

void uniVector(double *vetor){
	double sum;
	sum = normatizacao(vetor);
	for(int i = 0 ; i < 5; i++){
		vetor[i] = vetor[i]/sum;
	}
}

double produto(double *vetor1, double *vetor2){
	return(vetor1[0]*vetor2[0] + vetor1[1]*vetor2[1] + vetor1[2]*vetor2[2] + vetor1[3]*vetor2[3] + vetor1[4]*vetor2[4]);
}

void mostrar_vetor(double *vetor){
	printf("{");
		for(int i = 0; i < 5; i++){
			if( i == 4){
				printf("%f", vetor[4]);
			}else{
				printf("%f | ", vetor[i]);
			}
		}
		printf("}\n");
}

int main(){

	double A[5][5] = {{40, 8, 4, 2, 1}, {8, 30, 12, 6, 2}, {4, 12, 20, 1, 2}, {2, 6, 1, 25, 4}, {1, 2, 2, 4, 5}};
	double v_velho[5] = {0.0, 0.0, 0.0, 0.0, 0.0}, v_novo[5] = {1.0, 1.0, 1.0, 1.0, 1.0}, lambda_novo = 0.0, lambda_velho = 0.0, epsilon = 0.000001, erro, mi = 10;
	int n = 5, cont = 0;
	double x[n];
	x[0] = 0;
	x[1] = 0;
	x[2] = 0;
	x[3] = 0;
	x[4] = 0;

	for(int i = 0; i < n; i++){
		A[i][i] = A[i][i] - mi;
	}

	do{
		cont++;
		lambda_velho = lambda_novo;
		
		uniVector(v_novo);
		
		v_velho[0] = v_novo[0];
		v_velho[1] = v_novo[1];
		v_velho[2] = v_novo[2];
		v_velho[3] = v_novo[3];
		v_velho[4] = v_novo[4];

		fatoracaoLUPivoteamentoParcial(n, A, v_novo, x);

		for(int k = 0; k < 5; k++){
			v_novo[k] = x[k];
		}
		
		lambda_novo = 1/produto(v_velho, v_novo);
		
		erro = (lambda_novo - lambda_velho)/lambda_novo;
		
		if(erro < 0){
			erro = -erro;
		}

	}while(erro > epsilon && cont < 10000);

	printf("Autovetor: ");
	mostrar_vetor(v_velho);
	printf("Autovalor: %f\n", lambda_novo + mi);

	return 0;
}