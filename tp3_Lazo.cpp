#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define tama 100

struct Producto {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
};

typedef struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
struct Pruducto *Productos; //El tamaño de este arreglo depende de la variable // “CantidadProductosAPedir”
}clientes;

void cargaC(clientes *cliente, int n);
void cargaP(Producto *pvec, int nproductos);
float costo(Producto *pvec);
void mostrar(clientes *cliente, int n);

int main(){

    srand(time(NULL));
    int n;
    
    puts("Ingrese la cantidad de clientes");
    fflush(stdin);
    scanf("%i",&n);
    fflush(stdin);
    clientes *cliente[n];    
    cargaC(*cliente, n);  
    getchar();  
    return 0;
}

void cargaC(clientes *cliente, int n){
    char nombre[tama];
    int longi, nproductos;
    

    for (int i = 0; i < n; i++){
        cliente[i];
        nproductos= rand() % 6;
        
        printf("Cliente numero: %i.\n",i+1);
        fflush(stdin);
        cliente->ClienteID = i+1;
        
        puts("Nombre del cliente: ");
        fflush(stdin);
        gets(nombre);
        
        longi = strlen(nombre);
        cliente->NombreCliente=(char*)malloc(sizeof(longi));
        
        strcpy(cliente->NombreCliente,nombre);
        
        cliente->CantidadProductosAPedir=nproductos;
        
        Producto * pvec= (Producto*)malloc(sizeof(Producto)*nproductos);
        cargaP(pvec,nproductos);
        
    
    }
    mostrar(cliente, n);
}        

void cargaP(Producto *pvec, int nproductos){

    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int cantidad,ntipo,tproducto,costo_prod;


    for (int i = 0; i < nproductos; i++)
    {
        cantidad = rand() % 10 +1;
        ntipo=  rand() % 5 ;
        pvec->ProductoID=i+1;
        pvec->Cantidad=cantidad;
        
        tproducto=strlen(TiposProductos[ntipo]);
        pvec->TipoProducto=(char*)malloc(sizeof(tproducto));
        strcpy(pvec->TipoProducto,TiposProductos[ntipo]);

        pvec->PrecioUnitario = ( rand( ) % (100-10+1) + 10 )  / 100.0f ;
        costo_prod=costo(pvec);
        pvec++;

    }

}

float costo(Producto *pvec){
 return ((pvec->Cantidad) * (pvec->PrecioUnitario));   
 
}

void mostrar(clientes *cliente, int n){
    Producto produ;
    float total;
    
    for (int i = 0; i < n; i++){
        cliente[i];
        printf("clienteID : %i\n",cliente->ClienteID);
        printf("Nombre del cliente : %s\n",cliente->NombreCliente);
        printf("Cantidad de producto : %i\n\n",cliente->CantidadProductosAPedir);
        printf("ProductoID : %i\n",produ.ProductoID);
        printf("Cantidad : %i\n",produ.Cantidad);
        printf("Tipo: %s\n",produ.TipoProducto);
        printf("Costo por producto: %.2f\n",produ.PrecioUnitario);
        total+=produ.PrecioUnitario;
    }
    printf("Costo total : %.2f",total);
}