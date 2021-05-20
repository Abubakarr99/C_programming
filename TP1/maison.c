#include <MLV/MLV_all.h>


int main(int argc, char* argv[]){
	int coordonnee1_x[3] = {80, 200, 320}; 
	int coordonnee1_y[3] = {50, 15, 50};
	MLV_create_window( "Dream house", "shapes", 600, 400 );
	int a = MLV_get_window_height ();
	printf("%d\n", a);
	MLV_draw_filled_rectangle( 0, 0, 1000, 150 , MLV_COLOR_LIGHTSKYBLUE ); // sky
	MLV_draw_filled_rectangle( 110, 60, 20, 20 , MLV_COLOR_WHITE ); /* une fenêtre*/
	MLV_draw_filled_rectangle( 100, 50, 200, 100, MLV_COLOR_RED ); /*mur principale*/
	MLV_draw_filled_rectangle( 270, 60, 20, 20, MLV_COLOR_WHITE ); /* une fenêtre*/
	MLV_draw_filled_rectangle( 110, 60, 20, 20 , MLV_COLOR_WHITE ); /* une fenêtre*/
	MLV_draw_filled_rectangle( 190, 100, 20, 50 , MLV_COLOR_BLUE ); /* la porte*/
	MLV_draw_filled_rectangle( 0, 150, 1000, 40 , MLV_COLOR_GREEN ); // jardin
	MLV_draw_point( 192, 130, MLV_COLOR_WHITE );
	MLV_draw_text(
                100, 170,
                "Bienvenue chez moi.",
                MLV_COLOR_MAGENTA);
	MLV_draw_filled_polygon( coordonnee1_x, coordonnee1_y , 3, MLV_COLOR_BLUE ); // le toit
	MLV_draw_filled_circle( 50, 50, 10, MLV_COLOR_YELLOW ); // le soleil
	MLV_actualise_window();
	MLV_wait_seconds( 10 );
	MLV_free_window();
        return 0;
}
