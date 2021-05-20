#include<stdio.h>
#include<stdlib.h>

typedef struct {
	float *v;
	int degre;
}Polynome;


Polynome* create_polynome(int degre){
	Polynome *p;
	p = (Polynome*)malloc(sizeof(Polynome));
	if(p == NULL){exit(1);}
	(*p).degre=degre;
	(*p).v = (float*)malloc((degre+1)*sizeof(float));
	if ((*p).v == NULL){exit(1);}
	return p;
}

Polynome* sum_poly(Polynome *a, Polynome *b){
	Polynome *sum;
	int i;
	sum = create_polynome(a->degre);

	if (b->degre > a->degre){
		return sum_poly(b, a);
	}
	for (i=0; i<=b->degre; i++){
		sum->v[i] = a->v[i] + b->v[i];
	}
	for (; i <=a->degre; i++){
		sum->v[i] = a->v[i];
	}
	return sum;
}




void destruct_polynome(Polynome *p){
	free(p->v);
	free(p);
}
int main()
{
	Polynome *somme;
	Polynome *p1 = create_polynome(2);
	Polynome *p2 = create_polynome(3);
	p1->v[0] = 1.1;
	p1->v[1] = 2.2;
	p1->v[2] = 3.3;
	p1->v[0] = 0.0;
	p1->v[1] = 1.1;
	p1->v[2] = 2.2;
	p1->v[3] = 3.3;
	somme = sum_poly(p1, p2);
	destruct_polynome(p1);
	destruct_polynome(p2);
	destruct_polynome(somme);

	return 0;
}
