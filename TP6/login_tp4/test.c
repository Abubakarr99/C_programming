#include <stdio.h>
#define LONG 36

int main()
{

	char ligne[LONG];
	FILE *fi = fopen("grid.txt", "r");
	while (fgets(ligne,LONG,fi) != NULL)   /*  stop sur fin de fichier ou erreur  */
   	{
	   printf("%s", ligne);
   	}
	return 0;

}
