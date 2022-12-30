/* INTEGRANTES : 

CLESSI HECTOR, CARRILLO LAUTARO, DIAZ LUCAS, FERNANDEZ MATIAS, FERREIRA MILAGROS, ALBORNOZ FRANCO*/ 


#include<stdio.h>
#include <stdlib.h>

//*Parte de la funcion del metodo QuickSort*//

void qs(int lista[],int limite_izq,int limite_der){
	
	int izq,der,temporal,pivote;

    izq=limite_izq;

    der = limite_der;

    pivote = lista[(izq+der)/2];

 
    do{
        while(lista[izq]<pivote && izq<limite_der)izq++;

        while(pivote<lista[der] && der > limite_izq)der--;

        if(izq <=der)

        {

            temporal= lista[izq];

            lista[izq]=lista[der];

            lista[der]=temporal;

            izq++;

            der--;

 

        }

 

    }while(izq<=der);

    if(limite_izq<der){qs(lista,limite_izq,der);}

    if(limite_der>izq){qs(lista,izq,limite_der);}
	
}

void quicksort(int lista[],int n){

    qs(lista,0,n-1);

}//*Fin De Las Funciones QuickSort*//

//*Funciones del Metodo Barajas*//

void cargar(int n1,float vec1[100]);
void baraja(int n1,float vec1[100]);
void mostrar(int n1,float vec1[100]);
//*desarrollo de las funciones del metodo de barajas*//
void cargar(int n1,float vec1[100])
{
	for(int i=0;i<n1;i++)
	{
		printf("\nIngrese arreglo [%d]: ",i); scanf("%f", &vec1[i]);
	}
}

void baraja(int n1,float vec1[100])
{
	
    int i, j;
	float temp;
    for(i=0; i<n1; i++)
    {
        temp=vec1[i];  /* Guarda el contenido del vector en la posicion exacta */
        j=i-1; /* Guarda la posicion de i-1*/
        while(j>=0 && vec1[j] >temp)/* Se compara si j>=0, porque cuando es 0 no hay nada a la izquierda y no se puede comparar con otro elemento
		vec1[j]> temp es para ver si el numero de la izquierda es mayor al actual */
        {
            vec1[j+1] = vec1[j];/* Entonces si eso se cumple, se hace el intercambio de dichos numeros */
            j--; /* La posicion va hacia atras */
        }

    vec1[j+1] = temp; /* Va actualizando en cada interacion del ciclo, en que numero vamos */
    }
}

void mostrar(int n1,float vec1[100])
{
	for(int i=0;i<n1;i++)
	{
		printf("\nArreglo [%d]: %.2f",i,vec1[i]);
	}
}

//*Inicio de funciones para el Metodo de Seleccion*//

// Función de utilidad para intercambiar valores en dos índices en una array
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
 
// Función para realizar la ordenación por selección en `arr[]`
void selectionSort(int arr[], int n)
{
    // ejecutar `n-1` veces
    for (int i = 0; i < n - 1; i++)
    {
        // encuentra el elemento mínimo en el subarray no ordenado `[i…n-1]`
        // y cambiarlo por `arr[i]`
        int min = i;
 
        for (int j = i + 1; j < n; j++)
        {
            // si `arr[j]` es menor, entonces es el nuevo mínimo
            if (arr[j] < arr[min]) {
                min = j;    // actualiza el índice del elemento mínimo
            }
        }
 
        // intercambiar el elemento mínimo en el subarray `arr[i…n-1]` con `arr[i]`
        swap(arr, min, i);
    }
}
 
// Función para imprimir `n` elementos de la array `arr`
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}


//*Inicio del menu para la seleccion de demostracion de metodos*//

main(){

int Opn;

printf("Seleccione el metodo que desea probar:\n");
printf("_______________________________________");

printf("\n\nOpcion 1: Metodo Burbuja");
printf("\n*****************************");
printf("\n\nOpcion 2: Quick Sort");
printf("\n*****************************");
printf("\n\nOpcion 3: Insercion o Metodo Baraja");
printf("\n*****************************");
printf("\n\nOpcion 4: Seleccion");
printf("\n*****************************");
printf("\n\nOpcion 5: Merge Sort\n\n");

printf("__");
scanf("%d",&Opn);

if (Opn == 1){
	
	int i,j,aux,c,vector[c];

	i=1;

	j=1;

	aux=0;
	
	printf("Escribe la cantidad de numeros: ");

		scanf("%i",&c);

	printf("Escribe tu numeros: \n");

	for (i=1;i<=c;i++){

	printf("%i numero: ",i);
	
	scanf("%i",&vector[i]);
    }
 
    
	for(i=1;i<=c;i++){
    
		for(j=1;j<=c;j++){
    	
			if(vector[j]>vector[j+1]){
    		
				aux=vector[j];
    		
				vector[j]=vector[j+1];
    			
				vector[j+1]=aux;
			}
		}
 
	}
		printf("\n Numeros de manera ordenada: \n");
  
   for (i=1;i<=c;i++){

	printf("%i|",vector[i]);
    }
	
	}
	else if(Opn ==2){
		
		
	int lista[] ={100,56,0,1,-45,2,46,5,9,6,67,23,5};

    int size = sizeof(lista)/sizeof(int);

 

    printf("Lista Desordenada \n");

 

    for (int i=0; i<size; i++) {
        printf("%d",lista[i]);

        if(i<size-1)
            printf(",");
    }
    printf("\n");
    
	quicksort(lista,size);
	

 
    printf("Lista Ordenada \n");
    for (int i=0; i<size; i++) {
        printf("%d",lista[i]);
        if(i<size-1)
            printf(",");
    }
		
		
		
	} 
	else if(Opn == 3){
		
	int n;
	float vec[100];
	
	printf("Ingrese el tamaño del arreglo: "); scanf("%d", &n);
	
	cargar(n,vec);
	baraja(n,vec);
	mostrar(n,vec);
		
	}
	else if(Opn ==4){
		
		int arr[] = { 3, 5, 8, 4, 1, 9, -2 };
		
    int n = sizeof(arr) / sizeof(arr[0]);
    
 printf("Conjunto Desordenado=3, 5, 8, 4, 1, 9, -2\n\n Conjunto Ordenado =");
 
    selectionSort(arr, n);
    
    printArray(arr, n);
		
	}
}




 

	
