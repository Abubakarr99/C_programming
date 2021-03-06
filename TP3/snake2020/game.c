#include<stdio.h>
#include"grid.h"
#include <MLV/MLV_all.h>
#include <getopt.h>
#include "getlong.h"

int main(int argc, char *argv[])
{
	int next_option;
	program_name = argv[0];
	const char* const short_options = "ho:v";
  	const struct option long_options[] = {
    		{ "help",     0, NULL, 'h' },
    		{ "output",   1, NULL, 'o' },
    		{ "verbose", 0, NULL, 'v' },
    		{ NULL,       0, NULL, 0   }   /* Requis à la fin du tableau.  */
	};
	do {
   		next_option = getopt_long (argc, argv, short_options,
                              long_options, NULL);
   		switch (next_option)
   	{
   		case 'h':   /* -h or --help */
     		print_usage (stdout, 0);
	}
	}
	while (next_option != -1);
	Coord Coord1 = {1, 3};
	Coord Coord2 = {1, 2};
	Coord Coord3 = {1, 1};
	Coord Coord4 = {1, 0};
	Snake tab  = {  Coord1, Coord2, Coord3, Coord4 };
	/*for(int i=0; i<4; i++){

		printf("%d %d\n", tab.pos[i].x, tab.pos[i].y);
	}*/
        char grid[NBL][NBC+1] = {
        "w                                  w",
        "                                    ",
        "               f                    ",
        "                                    ",
        "     f               f              ",
        "                                    ",
        "                                    ",
        "               f                    ",
        "                                    ",
        "                                    ",
        "         wwwwwwwwww                 ",
        "                                    ",
        "                                    ",
        "                                    ",
        "                                    ",
        "                                    ",
        "                  f                 ",
        "                                    ",
        "         f                f         ",
        "                                    ",
        "                 f                  ",
        "w                                  w"
    };
            MLV_Keyboard_button touche = MLV_KEYBOARD_NONE;
    int width = 900, height = 700;


    /* Ouverture de la fenêtre graphique */
    place_snake(grid, tab);
    debug(grid, 22, 36);
    MLV_create_window( "SNAKE", "3R-IN1B", width, height );
    MLV_change_frame_rate( 24 );

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



        draw_grid(grid);


        MLV_actualise_window();
        touche = MLV_KEYBOARD_NONE;
        MLV_delay_according_to_frame_rate();
    }


    MLV_free_window();
    return 0;

}
