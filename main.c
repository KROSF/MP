#include <stdio.h>
#include <stdlib.h>
//ejemplo para compartir memoria entre estructuras
typedef struct {
    char *a;
    char *b;
}coord;
typedef struct {
    char *c;
    char *d;
}coord2;
typedef struct {
    char *c;
    char *d;
}coord3;

int main(){
    coord *t;
    coord2 *t2;
    t = (coord *) malloc( 2 * sizeof(coord));
    t2 = (coord2 *) malloc( 2 * sizeof(coord2));
    t[0].a= "Hola";
    t[0].b= "Mundo";

    t2->c=t->a;
    t2->d=t->b;

    printf("%s %s",t2[0].c,t2[0].d);
    return 0;
}

