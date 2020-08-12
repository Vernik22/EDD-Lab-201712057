#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ListaC.h"
#include "NodoC.h"
int main(){
    NodoA* a=newNodoC(10);
    NodoA* b=newNodoC(3);
    NodoC* c=newNodoC(25);
    ListaC* l=nuevaLista();
    add(l,a);
    add(l,b);
    add(l,c);
    imprimir(l);
    generar(l);
    eliminarNodo(l,1,NULL);
    get(l,1,NULL);
    Liberar(l);
    free(l);
    return 0;
}