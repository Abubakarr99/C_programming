#include<stdio.h>
#include <stdlib.h>

int** alloue(int n, int m){
	int i,j;
	int **tab = (int**)malloc(sizeof(int)*n*m);
	if (tab == NULL) {
		fprintf(stderr,"probleme d'allocation dans creer_tableau");
        	exit(1);
    	}

	return tab;
}

int main()
{
	int n = 3;
	int m = 3;
	int **tab;
	tab = alloue( 3, 3);
	free(tab);
	return 0;
}
