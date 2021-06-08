#include<stdio.h>
#include <MLV/MLV_all.h>
#include <getopt.h>
#include"grid.h"
#include "getlong.h"

int main(int argc, char *argv[]){


    Grid* test = allocate_grid(22,36);
    test->nbl = 22;
    test->nbc = 36;

    debug(test);

    char line[test->nbl][test->nbc+1];
	char *fname = argv[2];
	int ligne = 0;
	int resultat;
	FILE *fl = NULL;



/*
	fl = fopen(fname, "r");

	while(fgets(*line, sizeof(line), fl)){
		strncpy(test->grid[i], *line, sizeof(*line));
                i++;
	}
	fclose(fl);
*/

    int colonne_count( FILE *const file ){
        int c, count;
        count = 0;
        for( ;; )
        {
            c = fgetc( file );
            if( c == EOF || c == '\n' )
                break;
            count++;
        }
        return count;
    }
    int line_count( FILE *const file ) {
        int lines = 0;
        while (EOF != (fscanf(file, "%*[^\n]"), fscanf(file, "%*c")))
            ++lines;
        return lines;
    }

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
            fl = fopen(fname, "r");
            printf("\n  Nb de colonne : %d", colonne_count(fl));
            printf("\n  Nb de ligne : %d", line_count(fl)+2);
         /*
            while(fgets(*line, sizeof(line), fl)){
                ///compter le nb de ligne puis le nb colonne
                //// revenir début fichier pour commencer lecture (rewind)
                strncpy(test->grid[ligne], *line, sizeof(*line));
                ligne++;
            }
            while (test->grid[i-1][colonne] != '\0') {
                    colonne++;
                }
*/


                fclose(fl);
                break;
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
    for(int i=0;i<test->nbl;i++){
        for(int j=0;j<test->nbc+1;j++){
            if(test->grid[i][j] == 'f'){
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


        /*
    	draw_grid(grid);
    	place_snake(grid, tab);
	    elem = move_snake(&tab, grid);

         */
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
