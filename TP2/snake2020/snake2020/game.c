#include<stdio.h>
#include"grid.h"
#include <MLV/MLV_all.h>

int main(int argc, char *argv[])
{
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
