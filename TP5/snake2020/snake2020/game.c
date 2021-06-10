#include<stdio.h>
#include <MLV/MLV_all.h>
#include <getopt.h>
#include"grid.h"
#include "getlong.h"
#include<strings.h>


int count_nb_line(FILE *stream){
	char c;
	int nombre_c = 1;
	int count = 0;
	for (c = getc(stream); c!= EOF; c = getc(stream))
		if (c == '\n')
			count = count + 1;
	return count;
}

int count_nb_colonne(FILE *stream){
	char c;
	int nombre_c = 0;
	for (c = getc(stream); c!= EOF && c != '\n'; c = getc(stream))
			nombre_c++;
	return nombre_c;
}

void copy(char *src, char *dst){
	int i = 0;
	for(i=0; src[i]!='\0';i++){
		dst[i]=src[i];
	}
}



int main(int argc, char *argv[]){
	int nbl, nbc;
	size_t size_buf=0;
	FILE * stream;
	char *tmp= "hello";
	char * buf=NULL;
	int resultat = -1;
	Grid *g;
	int i, j;
	stream = fopen(argv[1], "r");
	nbl = count_nb_line(stream);
	rewind(stream);
	nbc = count_nb_colonne(stream);
	g = allocate_grid(nbc, nbl);
	g->nbl = nbl;
	g->nbc = nbc;
	rewind(stream);
	for (i=0;i<nbl;i++)
	{
		int size_tmp = getline(&buf, &size_buf, stream);
		if (size_tmp!=nbc+1){
			printf("y a un probleme");
			exit(1);
		}
		copy(buf, g->grid[i]);
	}
	free(buf);
	debug(g, nbl, nbc);
	int nb_fruits= 0;
	int colonne = 0;
	int elem;
	int next_option;
	program_name = argv[0];
	const char* const short_options = "hoi:v";
  	const struct option long_options[] = {
    		{ "help",     0, NULL, 'h' },
    		{ "output",   1, NULL, 'o' },
    		{ "verbose", 0, NULL, 'v' },
            {"input", 0, NULL, 'i'},
    		{ NULL,       0, NULL, 0}
	};
	do {
   		next_option = getopt_long (argc, argv, short_options,
                              long_options, NULL);
   		switch (next_option){
        case 'h':
            print_usage (stdout, 0);
            break;
        case 'i':
	    printf("ok");
	    }
	}
	while (next_option != -1);
	Coord Coord1 = {1, 3};
	Coord Coord2 = {1, 2};
	Coord Coord3 = {1, 1};
	Coord Coord4 = {1, 0};
	Snake tab  = {  Coord1, Coord2, Coord3, Coord4 };
            MLV_Keyboard_button touche = MLV_KEYBOARD_NONE;
    int width = 900, height = 700;


    /* Ouverture de la fenêtre graphique */
    MLV_create_window( "SNAKE", "3R-IN1B", width, height );
    MLV_change_frame_rate( 10 );
    for(int i=0;i<nbl;i++){
        for(int j=0;j<nbc+1;j++){
            if(g->grid[i][j] == 'f'){
                nb_fruits++;
            }
        }
    }
    
    while(
        MLV_get_event (
            &touche, NULL, NULL,
            NULL, NULL,
            NULL, NULL, NULL,
            NULL
        ) == MLV_NONE ||
        touche != MLV_KEYBOARD_ESCAPE
    ){


        MLV_clear_window( MLV_COLOR_BROWN );


        
    	draw_grid(g);
    	place_snake(g, tab);
	elem = move_snake(&tab, g);

	    MLV_actualise_window();
	switch (elem) {
            case FRUIT:
                nb_fruits--;
            if (nb_fruits == 0)
                 resultat = 0;
                break;
            case WALL:
                resultat = 1;
                break;
            case SNAKE:
                resultat = 1;
                break;
        }




	switch (touche) {
            case MLV_KEYBOARD_DOWN:
                tab.dir = 'x';
                break;
            case MLV_KEYBOARD_UP:
                tab.dir = 'z';
                break;
            case MLV_KEYBOARD_RIGHT:
                tab.dir = 'd';
                break;
            case MLV_KEYBOARD_LEFT:
                tab.dir = 'q';
                break;
        }

        touche = MLV_KEYBOARD_NONE;
        MLV_delay_according_to_frame_rate();


        if(resultat == 1 || resultat == 0 ){
            MLV_free_window();
            break;
        }
    }


    if(resultat == 0) {
        MLV_create_window("VICTOIRE", "3R-IN1B", width, height);
        MLV_draw_text(10, 10, "Vous avez gagné !!", MLV_COLOR_YELLOW);
        MLV_actualise_window();
        MLV_wait_seconds( 15 );
        MLV_free_window();
        }
    if (resultat == 1) {
        MLV_create_window("DÉFAITE", "3R-IN1B", width, height);
        MLV_draw_text(10, 10, "Vous avez perdu !!", MLV_COLOR_RED);
        MLV_actualise_window();
        MLV_wait_seconds( 15 );
        MLV_free_window();
    }

    return 0;

}
