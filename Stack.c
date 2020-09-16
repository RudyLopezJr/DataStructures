/* Hecho por Rudyard Humberto Aguilera López   Fecha: 12/03/2020
Aprendí a crear pilas y algunas rutinas
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

typedef struct T_Pila{
    int tope;
    int arr[MAX];
}T_Pila;

T_Pila *iniciarPila();
T_Pila *push(T_Pila *, int); //Prototipo para la función añadir
int pop(T_Pila *); //Prototipo para la función pop
void imprimir_head(T_Pila *); //Prototipo para imprimir la pila completa

int pila_vacia(T_Pila *); //Prototipo para verificar si la pila está vacía
int pila_llena(T_Pila *); //Prototipo para verificar si la pila esta llena

int Aleatorio(int , int); //Prototipo para generar un número xatorio
void imprime_pila(T_Pila *); //Prototipo para imprimir la pila
void imprimeLinea();

int main(){
    srand(time(NULL));
    T_Pila *pila;
    int result;
    pila = iniciarPila();

    //Verifico si la pila está vacía
    result = pila_vacia(pila);
    if(result == 1)
        printf("Pila Vacia\n");
    else
        printf("La pila no esta vacia\n");

    imprimeLinea();
    //Agrego a su capacidad máxima la pila
    printf("Ciclo de MAX de vueltas con push\n");
    int x=0; //Creo la variable donde se almacenan los aleatorios
    for(int i=1 ; i<=MAX ; i++){
        x=Aleatorio(0,99);
        push(pila, x);
    }
    imprime_pila(pila);
    imprimeLinea();
    //Verifico que la pila está llena
    result = pila_llena(pila);
    if(result == 1)
        printf("Pila llena\n");
    else
        printf("La pila no esta llena\n");
    imprimeLinea();

    //Saco la mitad de los elementos de la pila
    printf("Ciclo de MAX/2 vueltas con pop\n");
    for(int i=0 ; i<MAX/2 ; i++){
        x = pop(pila);
        printf("El elemento extraido es: %i\n", x);
    }
    imprime_pila(pila);
    imprimeLinea();

    //Ciclo de MAX/4 vueltas con push
    printf("Ciclo de MAX/4 vueltas con push\n");
    for(int i=0 ; i<MAX/4 ; i++){
        x = Aleatorio(0,99);
        push(pila,x);
    }
    imprime_pila(pila);
    imprimeLinea();

    //Vacio la pila
    printf("Vaciando pila\n");
    while(pila->tope!= -1){
        x = pop(pila);
        printf("El elemento extraido es: %i\n", x);
    }
    imprime_pila(pila);
    imprimeLinea();

    //libero la memoria
    free(pila);
    printf("Memoria liberada\n");
    imprimeLinea();

    return 0;
}

T_Pila *iniciarPila(){
    T_Pila *pila = malloc(sizeof(T_Pila)); //Reservo la memoria para la pila
    pila->tope = -1; //Igualo la pila a 0
    for(int i=0 ; i<MAX ; i++){
        pila->arr[i] = 0 ;
    }
    return pila;
}

T_Pila *push(T_Pila *pila, int valor){ //Función para añadir un valor
    if(pila_vacia(pila) == 1){ //Primero checo que la pila este vacía
        pila->arr[0] = valor;
        pila->tope = 0;
    }
    else if(pila_llena(pila) == 1){ //Verifico que la pila no esté llena
        printf("Desbordamiento de memoria\n");
    }
    else{
        pila->tope++; //Le subo uno al tope de la pila
        pila->arr[pila->tope] = valor;
    }
    return pila; //Regreso el valor de la pila
}

int pop(T_Pila *pila){ //Función para eliminar un elemento de la pila
    int x = pila->arr[pila->tope];
    pila->arr[pila->tope] = 0; //Igualo el valor anterior únicamente para declarar que ya no tiene un valor
    pila->tope--;
    return x;
}

int pila_vacia(T_Pila *pila){
    if(pila->tope == -1){
        return 1;     //verifico que el inicio de la lista este en 0
    }
    else{
        return 0;
    }

}

int pila_llena(T_Pila *pila){
    if(pila->tope+1 == MAX)
        return 1;   //Verifico que la pila este igual que el tope
    else
        return 0;
}


void imprimir_head(T_Pila *pila){
    printf("%i", pila->arr[pila->tope]);
}

int devolver_head(T_Pila *pila){
    return pila->arr[pila->tope];
}

int Aleatorio(int n, int k){    //Función para crear un número aleatorio entre un rango dado
    int rando , aux;
    aux = k-n+1;
    rando = n + rand()%aux;
    return rando;
}

void imprime_pila(T_Pila *pila){
    if(pila_vacia(pila) == 1){            //Verifico primero que la pila no este vacía
        printf("La pila esta vacia\n");
    }
    else {
        for(int i=pila->tope ; i>0 ; i--){
            printf("%i->" , pila->arr[i]); //Imprimo cada elemento de la pila
        }
        printf("%i" , pila->arr[0]);
    }
    printf("\n");
}

void imprimeLinea(){ //Función para imprimir una línea que separe cada parte del ejercicio
    printf("------------------------------------------------------------------------------\n");
}


