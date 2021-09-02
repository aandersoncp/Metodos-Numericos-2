#include<stdio.h>
#include<math.h>
#include<stdlib.h>

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
	double A[5][5] = {{40.0, 8.0, 4.0, 2.0, 1.0}, {8.0, 30.0, 12.0, 6.0, 2.0}, {4.0, 12.0, 20.0, 1.0, 2.0}, {2.0, 6.0, 1.0, 25.0, 4.0}, {1.0, 2.0, 2.0, 4.0, 5.0}};
	double  v_velho[5]= {0.0, 0.0, 0.0, 0.0, 0.0};
	double  v_novo[5] = {1.0, 1.0, 1.0, 1.0, 1.0};
	double  lambda_novo = 1.0, lambda_velho = 0.0, epsilon = 0.0000001, sum, erro;

	do{

		lambda_velho = lambda_novo;
		
		uniVector(v_novo);
		
		v_velho[0] = v_novo[0];
		v_velho[1] = v_novo[1];
		v_velho[2] = v_novo[2];
		v_velho[3] = v_novo[3];
		v_velho[4] = v_novo[4];

		//mostrar_vetor(v_velho);

		for(int i = 0; i < 5; i++){
			sum = 0;
			for(int k = 0; k < 5; k++){
				sum += A[i][k]*v_velho[k];
			}
			v_novo[i] = sum;
		}
		lambda_novo = produto(v_velho, v_novo);
		
		erro = (lambda_novo - lambda_velho)/lambda_novo;
		
		if(erro < 0){
			erro = -erro;
		}

	}while(erro > epsilon);

	printf("Autovetor: ");
	mostrar_vetor(v_velho);
	printf("Autovalor: %f\n", lambda_novo);

	return 0;
}