#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ListaC.h"
#include "NodoC.h"
int main(){
    NodoA* a=newNodoC(10);
    NodoA* b=newNodoC(3);
    NodoC* c=newNodoC(25);
    NodoC* d=newNodoC(1);
    NodoC* e=newNodoC(2);
    NodoC* f=newNodoC(4);
    NodoC* g=newNodoC(5);
    ListaC* l=nuevaLista();
    add(l,a);
    add(l,b);
    add(l,c);
    add(l,d);
    add(l,e);
    add(l,f);
    add(l,g);
    imprimir(l);
    generar(l);
    eliminarNodo(l,5,NULL);
    eliminarNodo(l,1,NULL);
    eliminarNodo(l,2,NULL);
    eliminarNodo(l,5,NULL);
    printf("-----------\n");
    imprimir(l);
    NodoA* obt=get(l,5,NULL);
    printf("%i",obt->val);
    Liberar(l);
    free(l);
    return 0;
}