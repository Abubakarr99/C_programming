#include <stdio.h>

#define NBL 8
#define NBC 7


int SUM(int *tab, int taille)
{
	int sum = 0;
	for(int i=0; i < taille; i++){
		sum+=tab[i];
	}
	return sum;

}

void affiche_matrix(int matrice[NBL][NBC]){
    	for(int i=0;i<2;i++)
        	for(int j=0;j<2;j++)
			scanf("%d", &matrice[i][j]);
    	for(int i=0;i<NBL;i++)
	{
        	for(int j=0;j<NBC;j++)
		{
			printf("%d", matrice[i][j]);
		}
		printf("\n");
	}
}

void debug(char matrice[][NBC], int ligne, int colonne){
    	for(int i=0;i<ligne;i++)
	{
        	for(int j=0;j<colonne;j++)
		{
			printf("%c", matrice[i][j]);
		}
		printf("\n");
	}

}

int main(int argc, char* argv[])
{
	int i, j;
	int produit = 1;
	int matrice[NBL][NBC];
	int sum;
	char grid[8][7] = {
        "bwrwbw",
        "wrwbwr",
        "bwrwbw",
        "wrwbwr",
        "bwrwbw",
        "wrwbwr",
        "bwrwbw",
        "wrwbwr"
   	 };
	/*affiche_matrix(matrice);
	for(i = 0; i < NBL; i++)
	{
		int *tab = matrice[i];
		sum = SUM(tab, NBC);
		produit = sum * produit;
	}
	printf("%d\n", produit);*/
	debug(grid, 8, 7);
	return 0;
}
