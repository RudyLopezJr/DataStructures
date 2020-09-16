/* Hecho por Rudyard Humberto Aguilera López   Fecha: 21/04/2020
Aprendí a crear tablas hash y modificar su contenido
*/


#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CANT 20     //cantidad de términos a copiar en la tabla hash;
#define TAMANIO (CANT)*(2) //Tamanaño máximo



typedef struct nodo_termino{
    char clave[20];           // Aquí se asigna el valor de la clave
    char valor[200];          // Aquí se asigna el valor de le definición
    struct nodo_termino *sig;    //Para aquellos terminos que colisionen agregar su termino siguiente
}Termino;

//Prototipos de las funciones
void iniciar_tabla_hash(Termino *[]);
void copiar_datos(Termino *[]);
Termino * buscar_head(Termino *, int );
void carga_glosario(Termino []);
int funcion_hash(char []);
int funcion_hash2(char []);
int ascii(char);
void display(char[], Termino *[]);
void imprimir_tabla(Termino *[]);
void liberar(Termino *[]);
void imprimirLinea();

int main(){
    Termino *tabla_hash[TAMANIO+2];  //arreglo de apuntadores a cabeceras ( de listas de términos)
    copiar_datos(tabla_hash);

    // buscar 3 términos que sepas existan en la tabla hash, para desplegar(busca y despliega) , y 1 termino sepas no existe en la tabla hash;
    char buscar[20];

    imprimirLinea();
    strcpy(buscar, "BMP");
    display(buscar , tabla_hash);    //busca e imprime definición de BMP

    imprimirLinea();
    strcpy(buscar, "FTP");
    display(buscar, tabla_hash); //Busca e imprime definición de FTP

    imprimirLinea();
    strcpy(buscar, "HTML");
    display(buscar, tabla_hash); //Busca e imprime definición de HTML

    imprimirLinea();
    strcpy(buscar, "Hzz");
    display(buscar , tabla_hash);   //no existe, el que existe es “Hzz”,

    imprimirLinea();
    printf("Se imprimira la tabla hash\n");
    imprimirLinea();
    imprimir_tabla(tabla_hash);  // Imprime la tabla hash
    imprimirLinea();

    liberar(tabla_hash);
}


void iniciar_tabla_hash(Termino *tabla_hash[]){
    for(int i=0 ; i<TAMANIO ; i++){
        tabla_hash[i] = NULL;
    }
}

void copiar_datos(Termino *tabla_hash[]){
    int indice_hash;
    Termino glosario[CANT+2];     //no se requiere memoria dinamica (apuntador), pues en el glosario solo hay un término por celda
    carga_glosario(glosario);
    iniciar_tabla_hash(tabla_hash);  //pone  NULL en cada celda;
    Termino *head ; //Inicializo el puntero head


    for(int i=0 ; i<CANT ; i++) {
        indice_hash = funcion_hash( glosario[i].clave ); //Transforma la clave en un valor númerico
        Termino *nodo = new Termino;    //Reservo la memoria para el nodo;
        strcpy( nodo->clave ,  glosario[i].clave );
        strcpy ( nodo->valor , glosario[i].valor );
        nodo->sig = NULL;


        if (tabla_hash[indice_hash] == NULL ){ //Verifico si no se ha usado el índice hash
            tabla_hash[indice_hash] = nodo;
        }
        else {                      // si hubo colision, entonces agregar a la lista
            head = buscar_head(tabla_hash[indice_hash] , indice_hash);
            head->sig = nodo;
        }
    }
}

Termino *buscar_head(Termino *tabla_hash, int j){ //Busco la cabeza para agregar el siguiente elemento
    Termino *aux = tabla_hash;   //
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    return aux;
}


void carga_glosario(Termino glosario[]) {  //Aquí se asignan las palabras al glosario

    strcpy(glosario[0].clave, "AMD");
    strcpy(glosario[0].valor, "Empresa que fabrica los procesadores K6 o K6-2, competencia de Pentium y Pentium II");


    strcpy(glosario[1].clave, "BMP");
    strcpy(glosario[1].valor, "Formato de fichero grafico por excelencia de los ordenadores PC, inventado por Microsoft, que tiene mucha calidad");



    strcpy(glosario[2].clave, "CPU");
    strcpy(glosario[2].valor, "Carcasa donde van montados los principales componentes del ordenador. Puede ser de sobremesa, minitorre, semitorre y torre.");


    strcpy(glosario[3].clave, "DNS");
    strcpy(glosario[3].valor, "Sistema de Nombres por Dominio utilizado en Internet y basado en una estructura jerarquica y mediante el cual comunicamos \ncon otro ordenador que puede encontrarse en otra parte del mundo");


    strcpy(glosario[4].clave, "Encriptar ");
    strcpy(glosario[4].valor, "Mezclar los datos para protegerlos como medida de seguridad, es decir, convertir texto normal a texto cifrado, que es ininteligible\nhasta que no se desencripta");

    strcpy(glosario[5].clave, "Escalabilidad");
    strcpy(glosario[5].valor, "Capacidad de ampliacion de los ordenadores.");

    strcpy(glosario[6].clave, "FTP");
    strcpy(glosario[6].valor, "Transferir ficheros entre ordenadores en Internet.");

    strcpy(glosario[7].clave, "GIF");
    strcpy(glosario[7].valor, "Formato de fichero grafico muy utilizado en Internet, ya que ocupa muy poco espacio y, con un programa especial, podemos\nensamblar varias imagenes y crear un fichero animado");

    strcpy(glosario[8].clave, "Gigabyte");
    strcpy(glosario[8].valor, "Medida de 1.000 Mb (unos 1.000 millones de caracteres).");

    strcpy(glosario[9].clave, "HTML");
    strcpy(glosario[9].valor, "Lenguaje utilizado para crear paginas Web");

    strcpy(glosario[10].clave, "HTTP");
    strcpy(glosario[10].valor, "Protocolo de Transferencia de Hipertexto o entorno grafico de las paginas Web.");

    strcpy(glosario[11].clave, "IP");
    strcpy(glosario[11].valor, "Direccion numerica y unica de cada ordenador en Internet.");

    strcpy(glosario[12].clave, "Multicasting");
    strcpy(glosario[12].valor, "Tecnica de transmision de datos a traves de Internet, en la que se envian paquetes desde un punto a varios destinatarios\nsimultaneamente");

    strcpy(glosario[13].clave, "Protocolo");
    strcpy(glosario[13].valor, "Conjunto de normas que los equipos utilizan para comunicarse entre si a traves de una red y poder hablar el mismo idioma.");

    strcpy(glosario[14].clave, "RAM");
    strcpy(glosario[14].valor, "Memoria de Acceso Aleatorio que mantiene vivos los datos hasta que se desconecta el ordenador.");

    strcpy(glosario[15].clave, "Scripts");
    strcpy(glosario[15].valor, "Conjunto de instrucciones que se ejecutan como una macro.");

    strcpy(glosario[16].clave, "Telnet");
    strcpy(glosario[16].valor, "Servicio que permite la conexión remota con cualquier ordenador de la red situado en cualquier parte del mundo como si\nde una terminal mas se tratase");

    strcpy(glosario[17].clave, "UNIX");
    strcpy(glosario[17].valor, "Sistema operativo de 32 bits empleado principalmente en entornos cientificos e industriales. Permite el trabajo de muchos\nusuarios y utiliza el sistema multitarea.");

    strcpy(glosario[18].clave, "URL");
    strcpy(glosario[18].valor, "Localizador Uniforme de Recurso, dicese de la direccion de una pagina Web de Internet.");

    strcpy(glosario[19].clave, "USB");
    strcpy(glosario[19].valor, "Conector de dispositivos externos que hace de via de ampliacion de los nuevos ordenadores.");

}




int funcion_hash(char clave[]){ //Funcion para regresar la posicion en la tabla hash
    int largo ,val = 0;
    largo = strlen(clave) ; //Asigno el valor del tamaño de clave
    for(int i=0 ; i<largo ; i++){
        val += ascii(clave[i]);     //Voy sumando cada valor de la clave
    }
    return (val%TAMANIO);   //Retorno el modulo de val/TAMANIO
}


int funcion_hash2(char clave[]){  //Funcion para regresar la posicion en la tabla hash
    int largo ,val = 0;
    largo = strlen(clave) ;
    for(int i=0 ; i<largo ; i++){
        val += ascii(clave[i])*(i+1); //Voy sumando y también multiplico por el valor de i
    }
    return (val%TAMANIO);  //Retorno el modulo de val/TAMANIO
}

//RESPUESTA: son equivalentes, la diferencia en un programa de este tipo no es considerable ¿?

int ascii(char i){  //Función para regresar su código en ascii
    int numero;
    numero = i; //paso la variable a un entero
    return numero; //Retorno ese entero
}

void display(char clave_char[], Termino *tabla_hash[]){ //Función para mostrar el valor de una clave
    int indice_hash;
    Termino *head; //Creo una variable head como un auxiliar
    indice_hash= funcion_hash(clave_char);
    head = tabla_hash[indice_hash]; //Le asigno el valor de la posición que voy a buscar
    if (head != NULL) { //Verifico primero que este ocupado
        while(head != NULL){ //Recorro esa posición para verificar que exista el número
            if(strcmp(head->clave, clave_char)){ //Comparo si es igual a algún valor
                printf("%s\n%s\n\n", head->clave, head->valor); //Imprimo la clave y el  valor
                return; //Finalizo la función
            }
            head = head->sig; //Actualizo el valor de headp, para que vaya avanzando
        }
        printf("No existe la clave: %s\n\n", clave_char); //En dado caso que finalice el ciclo sin entrar al retorno, imprimir que no existe la clave
    }
    else
        printf("No existe la clave: %s\n\n", clave_char); //Como está en nulo, sabemos que no existe la clave

}




void imprimir_tabla(Termino *tabla_hash[]){  //Función que imprime la tabla hash
    Termino *aux; //Creamos una varible auxiliar
    for(int i=0 ; i<TAMANIO; i++){ //Recorremos todas las posiciones hasta TAMANIO-1
        aux = tabla_hash[i];    //asignamos el valor de la posicion en la tabla hash a auxiliar
        printf("Index %i: ",i); //imprimimos el index
        if(aux != NULL){    //Verificamos que no este vacío
            printf("%s ", aux->clave); //Imprimimos el primer valor
            if(aux->sig != NULL){   //Comprobamos que no exista algún otro valor
                aux = aux->sig; //Actualizamos para ir avanzando
                while(aux != NULL){ //Mientras que no caigamos a una posición en NULL seguirá el ciclo
                    printf("-> %s ", aux->clave);   //Imprimimos el siguiente valor
                    aux = aux->sig; //Vamos actualizando donde nos ubicamos
                }
            }
            printf("\n");
        }
        else{
            printf("\n"); //Si está vacío solo debemos imprimir un salto de línea
        }

    }
}

void liberar(Termino *tabla_hash[]){ //Liberar memoria
   Termino *aux , *aux2; //Creamos dos variables auxiliares
    for(int i=0 ; i<TAMANIO; i++){ //Recorremos todas las posiciones hasta TAMANIO-1
        aux = tabla_hash[i];    //asignamos el valor de la posicion en la tabla hash a auxiliar
        if(aux != NULL){    //Verificamos que no este vacío
            if(aux->sig != NULL){   //Comprobamos que no exista algún otro valor
                aux2 = aux->sig; //Actualizamos aux2 para ir avanzando
                free(aux); //Liberamos aux
                aux = aux2; //Avanzamos aux
                while(aux != NULL){ //Mientras que no caigamos a una posición en NULL seguirá el ciclo
                    aux2 = aux->sig; //Actualizamos aux2 para ir avanzando
                    free(aux); //Liberamos aux
                    aux = aux2; //Avanzamos aux
                }
            }
        }
        else{
            free(aux);
        }

    }

}

void imprimirLinea(){ //Función que imprime una línea
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
}


