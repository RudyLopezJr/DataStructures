#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
    int valor;
    nodo *siguiente;
};
void insertarelemento(nodo *&, int);
void mostrarelementos(nodo *);
void eliminar(nodo *&, int);

int main(){
    nodo *lista = NULL;
    int n,k ,a ;
    do{
        cout<<"\t.:MENU:.\n";
        cout<<"1. Presiona para insertar dato\n";
        cout<<"2. Presiona para mostrar la lista\n";
        cout<<"3. Eliminar elemento\n";
        cout<<"4. Presiona para salir\n";
        cout<<"Opcion: ";
        cin>>a;
        switch(a){
            case 1:
                cout<<"Digite un numero: ";
                cin>>n;
                insertarelemento(lista, n);
                cout<<"\n";
                system("pause");
            break;
            case 2:
                mostrarelementos(lista);
                system("pause");
            break;
            case 3:
                cout<<"Digite el valor que desea borrar: ";
                cin>>n;
                eliminar(lista, n);
                system("pause");
            break;
        }
        system("cls");
    }while(a!=4);


    return 0;
}

void insertarelemento(nodo *&lista, int n){
    nodo *nuevo_nodo = new nodo ();
    nuevo_nodo->valor = n;

    nodo *aux1 = lista;
    nodo *aux2;

    while((aux1!=NULL) && (aux1->valor < n)){
        aux2 = aux1;
        aux1= aux2->siguiente;
    }
    if(aux1 == lista){
        lista = nuevo_nodo;
    }
    else{
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;
    cout<<"El elemento: "<<n<<" se ha agregado con exito\n";
}
void mostrarelementos(nodo *lista){
    nodo *actual = new nodo();
    actual = lista;
    cout<<"mostrando valores\n";
    while(actual!=NULL){
        if(actual->siguiente != NULL)
        cout<<actual->valor<<"->";
        else{
            cout<<actual->valor<<".\n";
        }
        actual=actual->siguiente;
    }
}
void eliminar(nodo *&lista, int b){
    if(lista != NULL){
        nodo *aux_borrar = lista;
        nodo *anterior=NULL;

        while((aux_borrar!=NULL) && (aux_borrar->valor!=b)){
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }
        if(aux_borrar == NULL){
            cout<<"El elemento no se ha encontrado \n";
        }
        else if(anterior==NULL){
            lista= aux_borrar->siguiente;
            delete aux_borrar;
        }
        else{
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }
    }
    else{
        cout<<"La lista esta vacia \n";
    }
}

