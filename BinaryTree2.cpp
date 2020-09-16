/* Hecho por Rudyard Humberto Aguilera Lopez e Inaki Cornejo de la Mora Fecha: 12/05/2020
Aprendimos a hacer árboles binarios, y también como hacer sus recorridos
Igual practicamos recursividad
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
#define MAX 10

//Struct para crear los arboles
struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
	int id;
};

//Prototipos
Nodo *Crear_arbol(int *, int , Nodo *);
void insertarNodo(Nodo *&,int,int  ,Nodo *);
Nodo *crearNodo(int , int ,Nodo *);
int Aleatorio(int , int);
void iniciarArr(int *);
void iniciarArr2(int *, int );
void mostrarArr(int *, int);
void mostrarArbol(Nodo *,int);
void mostrarPreordenIndice(Nodo *, int);
void imprimirlinea();
void mostrarPreorden(Nodo *);
void mostrarInorden(Nodo *);
void mostrarPosorden(Nodo *);
Nodo *liberarMemoria(Nodo *);
Nodo *buscarNodo(Nodo *, int num);
void mostrarPreordenIndice2(Nodo *, int);

int main(){
    srand(time(NULL));
    int contador = 0;  //contador que sirve para mandar los espcios cuando vamos a imprimir
    int *arr = new int[MAX+2]; //Creo un arreglo dinámico

    iniciarArr(arr); //Inicio el arreglo con el ejemplo del libro;
    imprimirlinea();
    cout<<"El arreglo como ejemplo es el siguiente:\n";
    mostrarArr(arr, 9);
    imprimirlinea();

    Nodo *arbol = NULL; //Creo el árbol de inicio
    arbol = Crear_arbol(arr, 9 , arbol); //Mando a llamar a la función recursiva que me devuelve el padre
    imprimirlinea();

    //Imprimo de diferentes formas el árbol
    cout<<"El arbol tiene un tamanio de: "<<9<<" numeros";
    imprimirlinea();
    cout<<"Imprimiendo el arbol de ejemplo con su estructura de arbol:";
    imprimirlinea();
    mostrarArbol(arbol, contador);
    imprimirlinea();

    cout<<"Mostrando el arbol de prueba en preorden en forma de indice:";
    imprimirlinea();
    mostrarPreordenIndice(arbol, 0);
    imprimirlinea();


    cout<<"Liberando memoria";
    arbol = liberarMemoria(arbol);
    imprimirlinea();


    //Aquí el ejercicio
    iniciarArr2(arr , MAX); //Inicio el arreglo con números aleatorios
    imprimirlinea();
    cout<<"El arreglo con los numeros aleatorios es el siguiente:\n";
    mostrarArr(arr, MAX);
    imprimirlinea();

    arbol = Crear_arbol(arr, MAX , arbol); //Mando a llamar a la función recursiva que me devuelve el padre
    imprimirlinea();

    //Imprimo de diferentes formas el árbol
    cout<<"Imprimiendo el arbol de ejemplo con su estructura de arbol:";
    imprimirlinea();
    mostrarArbol(arbol, contador);
    imprimirlinea();

    cout<<"Mostrando el arbol de prueba en preorden en forma de indice:";
    imprimirlinea();
    contador = 0;
    mostrarPreordenIndice(arbol, contador);
    imprimirlinea();

	cout<<"Buscando valor: "<<arr[MAX/2]<<"\n";
	Nodo *numero;
	if((numero = buscarNodo(arbol, arr[MAX/2]))){
		cout<<"Se econtro el valor en la ubicacion: "<<numero<<"\n";
	}
	else{
		cout<<"No se encontro el valor.\n";
	}

	cout<<"Buscando valor: 130\n";
	if((numero = buscarNodo(arbol, 130))){
		cout<<"Se econtro el valor en la ubicacion: "<<numero<<"\n";
	}
	else{
		cout<<"No se encontro el valor.\n";
	}

    imprimirlinea();
	cout<<"Ahora imprime el id de cada nodo en formato indice.\n";
    imprimirlinea();
	mostrarPreordenIndice2(arbol, 0);

    imprimirlinea();

    cout<<"Liberando memoria";
    arbol = liberarMemoria(arbol);
    delete[] arr;
    imprimirlinea();

    return 0;
}


Nodo *Crear_arbol(int *arr, int tamanio , Nodo *arbol){ //Función para crear el árbol
    for(int i=0 ; i<tamanio ; i++){
        insertarNodo(arbol, arr[i] , i , NULL);
    }
    return arbol;
}

Nodo *crearNodo(int n, int id ,Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->id = id;
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;

	return nuevo_nodo;
}

//Funcion para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol,int n,int id ,Nodo *padre){
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(n,id ,padre);
		arbol = nuevo_nodo;
	}
	else{ //Si el arbol tiene un nodo o mas
		if(n == arbol->dato){ //para que no existan números repetidos
            return;
		}
		if(n < arbol->dato){ //Si el elemento es menor a la raiz, insertamos en izq
			insertarNodo(arbol->izq,n, id ,arbol);
		}
		else{//Si el elemento es mayor a la raiz, insertamos en der
			insertarNodo(arbol->der,n, id ,arbol);
		}
	}
}

int Aleatorio(int n, int k){    //Función para crear un número aleatorio entre un rango dado
    int rando , aux;
    aux = k-n+1;
    rando = n + rand()%aux;
    return rando;
}

void iniciarArr(int *arr){ //inicio el arbol con el ejercicio planteado
    arr[0] = 120;
    arr[1] = 87;
    arr[2] = 43;
    arr[3] = 65;
    arr[4] = 140;
    arr[5] = 99;
    arr[6] = 130;
    arr[7] = 22;
    arr[8] = 56;
}

void iniciarArr2(int *arr , int n){ //inicio el arreglo con los elementos dados
    for(int i=0 ; i<n ; i++){
        *(arr+i) = Aleatorio(10 , 50);
    }
}



void mostrarArr(int *arr , int n){ //función para mostrar el arreglo
    for(int i=0 ; i<n ; i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}



void mostrarArbol(Nodo *arbol,int cont){ //este sigue otro tipo de impresión primero visita el hijo derecho, luego la raiz y por último el izquierdo
	if(arbol == NULL){ //Si el arbol esta vacio
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1); //llamo a la función recursiva
		for(int i=0;i<cont;i++){ //imprimo los espacios que  se deben para que se vea bonito
			cout<<"     ";
		}
		cout<<arbol->dato<<endl; //imprime el dato
		mostrarArbol(arbol->izq,cont+1); //vuelvo a llamar la función recursiva
	}
}

void mostrarPreordenIndice(Nodo *arbol, int cont){ // para imprimirlo en preorden pero en forma de indice, siguiendo el ejemplo anterior
    if(arbol == NULL){
            return;
    }
    else{
        for(int i=0 ; i<cont ; i++){
            cout<<"    ";
        }
        cout<<arbol->dato<<endl;
        mostrarPreordenIndice(arbol->izq ,cont+1);
        mostrarPreordenIndice(arbol->der, cont+1);
    }
}

void imprimirlinea(){
    cout<<"\n---------------------------------------------------------------------\n";
}

void mostrarPreorden(Nodo *arbol){ // para imprimirlo en preorden
    if(arbol == NULL){
        return;
    }
    cout<<arbol->dato<<" ";
    mostrarPreorden(arbol->izq);
    mostrarPreorden(arbol->der);
}
void mostrarInorden(Nodo *arbol){ //para imprimirlo en inorden
    if(arbol == NULL){
        return;
    }
    mostrarInorden(arbol->izq);
    cout<<arbol->dato<<" ";
    mostrarInorden(arbol->der);
}
void mostrarPosorden(Nodo *arbol){ //Para imprimirlo en posorden
    if(arbol == NULL){
        return;
    }
    mostrarPosorden(arbol->izq);
    mostrarPosorden(arbol->der);
    cout<<arbol->dato<<" ";
}


Nodo *liberarMemoria(Nodo *arbol){ //Se libera en posorden para eliminar de último la raíz
     if(arbol == NULL){
        return NULL;
    }
    liberarMemoria(arbol->izq);
    liberarMemoria(arbol->der);
    delete arbol;

    return NULL;
}

Nodo *buscarNodo(Nodo *arbol, int num){//Funcion para buscar un valor en un arbol binario y ordenado, retorna NULL si no lo encuentra
	if(!arbol){
		return NULL;
	}

	if(arbol->dato == num){
		return arbol;
	}

	if(arbol->dato > num){
		return buscarNodo(arbol->izq, num);
	}

	else{
		return buscarNodo(arbol->der, num);
	}
}

void mostrarPreordenIndice2(Nodo *arbol, int cont){ // Imprimir los ids de cada nodo en preorden con formato de indice
    if(arbol == NULL){
            return;
    }
    else{
        for(int i=0 ; i<cont ; i++){
            cout<<"    ";
        }
        cout<<arbol->id<<endl;
        mostrarPreordenIndice2(arbol->izq ,cont+1);
        mostrarPreordenIndice2(arbol->der, cont+1);
    }
}

