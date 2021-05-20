#include<stdio.h>
#include<string.h>
#define NBL 8
#define NBC 7
#include <MLV/MLV_all.h>

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


int  compute_size(int h, int w)
{
	int i, a;
	for(i=1; i <= h && i <= w; i++)
    	{
        if(h%i==0 && w%i==0)
            a = i;
    	}
	return a;

}

void draw_grid(char grid[][NBC]){
	int h, w, carre;
	h = MLV_get_window_height ();
	w = MLV_get_window_width ();
	carre = compute_size(1000, 900);
	printf("%d", carre );
        for(int i=0;i<=h;i+=carre)
        {
                for(int j=0;j<=w;j+=carre)
                {

			MLV_draw_rectangle( i, j , carre, carre, MLV_COLOR_BLUE );
                }
                printf("\n");
        }
}



int main()
{
	MLV_create_window( "Dream house", "shapes", 1000, 900 );
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
	draw_grid(grid);
	MLV_actualise_window();
	MLV_wait_seconds( 10 );
	MLV_free_window();
	return 0;

}

