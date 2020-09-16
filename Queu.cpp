#include <iostream>
using namespace std;

struct nodo{
    int valor;
    nodo *siguiente;
};

void ingresar(nodo *&, nodo *& ,int);
bool colavacia(nodo *);
void eliminar(nodo *&, nodo *&);

int main(){
    int n,k;
    nodo *inicio = NULL;
    nodo *fin = NULL ;
    cout<<"Ingrese la cantidad de datos que va a ingresar: ";
    cin>>k;
    for(int i=0; i<k ; i++){
        cout<<"Ingrese el valor: ";
        cin>>n;
        ingresar(inicio, fin, n);
    }
    cout<<"Ingrese la cantidad de datos que va a eliminar: ";
    cin>>k;
    for(int i=0; i<k ; i++){
        eliminar(inicio, fin);
    }
    return 0;
}

void ingresar(nodo *&inicio, nodo *&fin, int n){
    nodo *nuevo_nodo = new nodo();
    nuevo_nodo->valor = n ;
    nuevo_nodo->siguiente=NULL;

    if(colavacia(inicio)){
        inicio = nuevo_nodo;
    }
    else{
        fin->siguiente = nuevo_nodo;
    }

    fin = nuevo_nodo;
    cout<<"El valor: "<<n<<" se ha agregado correctamente\n";
}
bool colavacia(nodo *inicio){
    return (inicio==NULL) ? true : false ;
}

void eliminar(nodo *&inicio , nodo *&fin){
    int x;
    x=inicio->valor;
    nodo *aux = inicio;
    if(inicio == fin ){
        inicio=NULL;
        fin=NULL;
    }
    else{
        inicio = aux->siguiente;
    }
    delete aux;
    cout<<"Se ha eliminado el valor: "<<x<<" correctamente\n";
}

