#include <stdio.h>

int m1(int a)
{
    return a*((a<0)-(a>0));
}

int m2(int a, int b)
{
    if(a+=b)
        printf("%d\n", a);
        return a;
    return b;

}

void swap_char(char * x, char * y){
    char temp = *x;
    *x = *y;
    *y = temp;
}
void m3(char * s)
{
    int i;
    int again;
    do{
        again = 0;
        for(i=0;s[i+1]!='\0';i++)
            if (s[i]>s[i+1])
            {
                swap_char(&s[i], &s[i+1]);
                again=1;
            }
    }while(again);
     printf("%s", s);
    //return s;

    }


int main()
{
    char *s = "geeks";
    m3(s);

}
