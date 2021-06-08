#include<stdio.h>

void majiscule(char *chaine){
	int i;
	for (i=0; chaine[i] != '\0'; i++){
		if(chaine[i] >= 'a' && chaine[i] <= 'z') {
         		chaine[i] = chaine[i] -32;
		}
	}
}


int main(int argc, char* argv[])
{
	int compteur;
	for(compteur=0;compteur<argc; compteur++){
		majiscule(argv[compteur]);
		printf("%s\n", argv[compteur]);
	}
	return 0;
}
