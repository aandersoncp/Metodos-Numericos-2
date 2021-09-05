#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define g 10

void F(double *F_a, double v_a, double m, double k){
	F_a[0] = -g - (k/m)*v_a;
	F_a[1] = v_a;
}

void S_(double *s_i, double *s_a, double m, double k, double delta_t){
	double aux[2];
	F(aux, s_a[0], m, k);
	s_i[0] = s_a[0] + (delta_t/2)*aux[0];
	s_i[1] = s_a[1] + (delta_t/2)*aux[1];
}

void NC(double *Si, double *Sa, double delta_t, double *aux, double m, double k){
	double aux_[2], aux_1[2], c1 = 0.1666667, c2 = 0.666667;
	aux[0] = 0;
	aux[1] = 0;

	F(aux_, Sa[0], m, k);
	aux[0] += c1*aux_[0];
	aux[1] += c1*aux_[1];
	
	S_(aux_1, Sa, m, k, delta_t); 
	F(aux_, aux_1[0], m, k);
	aux[0] += c2*aux_[0];
	aux[1] += c2*aux_[1];
	
	S_(aux_1, Sa, m, k, 2*delta_t);
	F(aux_, aux_1[0], m, k);
	aux[0] += c1*aux_[0];
	aux[1] += c1*aux_[1];
	
	aux[0] *= delta_t;
	aux[1] *= delta_t;

}

void S(double *Si, double *Sa, double delta_t, double m, double k){
	double aux[2];
	NC(Si, Sa, delta_t, aux, m, k);

	Si[0] = Sa[0] + aux[0];
	Si[1] = Sa[1] + aux[1];
	printf("Yi: %f\n\n", Si[1]);

}

void tabela(double s, ){

}

void passo_simples(double *s_i, double t_0, double k, double m, double delta_t, double objetivo, double hmax){
	double s_a[2]; 

	s_a[0] = s_i[0];
	s_a[1] = s_i[1];

	while(s_i[1] > objetivo){
		s_a[0] = s_i[0];
		s_a[1] = s_i[1];
		S(s_i, s_a, delta_t, m, k);
		if(s_i[1] > hmax){
			hmax = s_i[1];
			tmax = t_0;
		}
		t_0 += delta_t;
	}
}


int main(int argc, char const *argv[]){
	double s_a[2], t_0 = 0, k = 0.5, m = 0.5;
	double s_i[2], delta_t = 0.1, hmax = s_a[1], tmax; 
	s_a[0] = 3;
	s_a[1] = 150;
	
	s_i[0] = 3;
	s_i[1] = 150;

	while(s_i[1] > 0){
		s_a[0] = s_i[0];
		s_a[1] = s_i[1];
		S(s_i, s_a, delta_t, m, k);
		if(s_i[1] > hmax){
			hmax = s_i[1];
			tmax = t_0;
		}
		t_0 += delta_t;
	}
	printf("Vi: %f\n", s_i[0]);
	printf("Yi: %f\n", s_i[1]);
	printf("Altura máxima: %f\n", hmax);
	printf("Tempo total: %f\n\n", t_0);
	return 0;
}