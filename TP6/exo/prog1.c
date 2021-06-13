#include<stdio.h>
#include<stdlib.h>

typedef struct _cell Cell;
struct _cell
{
	int v;
	Cell *next;
};
typedef struct _liste Liste;
struct _liste
{
	Cell *first;
};

typedef enum{
	FALSE = 1,
	TRUE = 0
}Boolean;

Liste* empty_list(){
	Liste *liste = malloc(sizeof(*liste));
	Cell *element = malloc(sizeof(*element));


	if (liste == NULL || element == NULL)
	{
		exit(1);
	}
	//element->v=1;
	//element->next = NULL;
	liste->first = NULL;
	return liste;
}

Boolean is_empty (Liste* l)
{
	if (l->first == NULL)
	{
		return TRUE;
	}
	else{
		return FALSE;
	}
	
}
void add_first(int data, Liste *l)
{
	Cell *new = malloc(sizeof(*new));
	if (l == NULL || new == NULL)
	{
		exit(1);
	}
	new->v = data;
	new->next = l->first;
	l->first = new;
}

void remove_first(Liste *l)
{
	if (l == NULL)
	{
		exit(1);
	}
	if (l->first != NULL)
	{
		Cell *toDelete = l->first;
		l->first = l->first->next;
		free(toDelete);
	}
}



void print_list(Liste *liste)
{
	if (liste == NULL)
	{
		exit(1);
	}
	Cell *actuel = liste->first;
	while(actuel != NULL){
		printf("%d->", actuel->v);
		actuel = actuel->next;
	}
	printf("\n");
}

Cell* get(int v, Liste *l)
{
	if (l == NULL)
	{
		exit(1);
	}
	Cell *element;

	Cell *actuel = l->first;
	while(actuel != NULL){
		if(actuel->v == v){
			actuel->v = 0;
			element=actuel;
			break;
		}
		actuel = actuel->next;
	}
	return element;
}

void add_cell(Cell *c, Liste *l)
{
	printf("%d\n", c->v);

}





int main(){
	Liste* maliste = empty_list();
	Boolean a;
	int i;
	for(i=5;i>0;i--)
		add_first(i, maliste);
	print_list(maliste);
	a = is_empty(maliste);
	print_list(maliste);
	add_cell(get(1, maliste), maliste);
	/*for (i=0;i<5;i++)
		remove_first(maliste);
	print_list(maliste);
	a = is_empty(maliste);
	printf("%d\n", a);*/
	return 0;
}
