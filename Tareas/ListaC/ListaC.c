#include "ListaC.h"

    void add(ListaC* l,NodoC* nuevo){
    if(l->head==NULL){
        l->head=nuevo;
    }else if(nuevo->val<=l->head->val){
        nuevo->derecha=l->head;
        l->head->izquierda=nuevo;
        l->head=nuevo;
    }else{
        NodoC* aux=l->head;
        while(aux->derecha!=NULL){
            if(aux->val>nuevo->val){
                    NodoC* ant=aux->izquierda;
                    ant->derecha=nuevo;
                    nuevo->izquierda=ant;
                    nuevo->derecha=aux;
                    aux->izquierda=nuevo;
                    return;
                }else if(nuevo->val<=aux->derecha->val){
                    NodoC *siguiente=aux->derecha;
                    aux->derecha=nuevo;
                    nuevo->derecha=aux;
                    nuevo->derecha=siguiente;
                    siguiente->izquierda=nuevo;
                    return;
                }
            aux=aux->derecha;
        }
        aux->derecha=nuevo;
        nuevo->izquierda=aux;
    }
}

void Liberar(ListaC* l){
    NodoA* aux=l->head;
    NodoA* tmp;
    while(aux!=NULL){
        tmp=aux->derecha;
        free(aux);
        aux=tmp;
    }
}

void imprimir(ListaC* l){
    NodoA* aux=l->head;
    while(aux!=NULL){
        printf("El valor es %i \n",aux->val);
        aux=aux->derecha;
    }
}
ListaC* nuevaLista(){
    ListaC* nueva=(ListaC*) malloc(sizeof(ListaC));
    nueva->head=NULL;
    return nueva;
}
void generar(ListaC* l){
    FILE * fp;
    fp=fopen("./cadigo.txt","w");
    if(fp==NULL){
        printf("Error");
        return;
    }
    char cad[1024];
    sprintf(cad,"digraph G{ \n node[shape=triangle];\n");
    fputs(cad,fp);
    NodoC* aux;
    aux=l->head;
    guardarRecursivo(aux,fp,cad);
    sprintf(cad,"}\n");
    fputs(cad,fp);
    fclose(fp);
}

void guardarRecursivo(NodoC* aux,FILE* fp,char c[]){
    if(aux==NULL){
        return;
    }else{
        if(aux->derecha!=NULL){
            
            sprintf(c,"node%p[label=\"%i\", color= red, style= filled]\n",&(*aux),aux->val);
            fputs(c,fp);
            guardarRecursivo(aux->derecha,fp,c);
            sprintf(c,"node%p->node%p;\n node%p->node%p [color= blue];\n",&(*aux),&(*aux->derecha),&(*aux->derecha),&(*aux));
            fputs(c,fp);
        }else{
            sprintf(c,"node%p[label=\"%i\"]\n",&(*aux),aux->val);
            fputs(c,fp);
        }
    }
}


/*para la posicion lo pense que empezara por 0, 1, 2, ... entones para el nodo 10 
seria el numero en posicion 9*/
void eliminarNodo(ListaC* l,int posicion, NodoC* elim){
    if(posicion == 0){
if(l->head==NULL){
        return ;
    }else if(l->head == elim){
        l->head= elim->derecha; 
    }
    else if (elim->derecha != NULL){
        elim->derecha->izquierda= elim->izquierda;
        }else if(elim->izquierda != NULL){
        elim->izquierda->derecha = elim->derecha;
    }
    free(elim); 
    return; 
    }
    if(elim == NULL){
         elim = l->head;
    }
       // NodoC* aux = l->head->derecha; 
 eliminarNodo(l, posicion-1,elim->derecha );

}
/*al igual que eliminar las pisicion empiezan en 0*/
NodoC* get( ListaC* l,int posicion, NodoC* actual){

if(actual == NULL){
         actual = l->head;
    }
if(posicion == 0){
return actual;
    }
get(l, posicion-1,actual->derecha );
} 