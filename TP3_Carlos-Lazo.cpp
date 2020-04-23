#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define tama 100

typedef struct Producto {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
struct Producto *Productos; //El tamaño de este arreglo depende de la variable // “CantidadProductosAPedir”
}clientes;

void cargarC(clientes * cliente,int n);
void cargaP(clientes * cliente,int n,int nproductos);
float costoT(clientes *cliente,int n,int nproductos);
void mostar(clientes *cliente,int n,int nproductos,float total);

int main(){

  srand(time(NULL));

  int n,nproductos;
  float total=0;

  puts("Ingrese la cantidad de clientes");
  fflush(stdin);
  scanf("%i",&n);
  fflush(stdin);

  clientes *cliente= (clientes *) malloc(sizeof(clientes)*n); //Hago la reserva para n clientes    

  cargarC(cliente, n);
  nproductos= (rand() % 5)+ 1 ;
  
  cargaP(cliente,n,nproductos);
  total = costoT(cliente,n,nproductos);
  mostar(cliente,n,nproductos,total);
  
  getchar();  
  
  return 0;
}

void cargarC(clientes * cliente,int n){

  int longi;
  char nombre[tama];
    
  for ( int i = 0; i < n; i++)
  {
    printf("Cliente numero: %i\n",i+1);
    cliente[i].ClienteID = i+1;

    puts("Ingrese el nombre del cliente: "); gets(nombre);
    longi=strlen(nombre);
    cliente[i].NombreCliente=(char*)malloc(sizeof(char)*longi);
    strcpy(cliente[i].NombreCliente,nombre);
    printf("\n");
  }

}


void cargaP(clientes * cliente, int n,int nproductos){
    int longi,cantidad;

  for (int i = 0; i < n; i++)
  {
   
  cliente[i].CantidadProductosAPedir=nproductos;  

  
  cliente[i].Productos=(Producto*)malloc(sizeof(Producto)*nproductos);
 
  
  for (int j = 0; j < nproductos ;j++)
  {       
      char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
      
      cantidad=( rand() % 4) +1;

      cliente[i].Productos[j].ProductoID=j+1;
      cliente[i].Productos[j].Cantidad=cantidad;
      
      longi=strlen(TiposProductos[cantidad]);

      cliente[i].Productos[j].TipoProducto=(char*)malloc(sizeof(char)*longi);
      strcpy(cliente[i].Productos[j].TipoProducto,TiposProductos[cantidad]);
   
      
      float f=(rand( ) % (100-10+1) + 10) * 0.1;
      cliente[i].Productos[j].PrecioUnitario=f;
      
  }

  } 
     
    
}

float costoT(clientes *cliente,int n,int nproductos){
  float total=0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < nproductos; ++j)
    {
      total+=(cliente[i].Productos[j].PrecioUnitario)*(cliente[i].Productos[j].Cantidad);
    }
  }

return total;

}

void mostar(clientes *cliente,int n,int nproductos,float total){

  for (int i = 0; i < n; i++)
  {
    printf("Nombre del cliente: %s\n",cliente[i].NombreCliente);
    printf("Cantidad de productos: %i\n",cliente[i].CantidadProductosAPedir);
    printf("Numero productos:%i \n", nproductos);
    printf("\n");
    for (int j = 0; j < nproductos; j++)
     {  
        printf("ProductoID:",cliente[i].Productos[j].ProductoID);
        printf("Tipo de Producto : %s\n", cliente[i].Productos[j].TipoProducto);
        printf("Cantidad del producto:%i\n",cliente[i].Productos[j].Cantidad);
        printf("Precio unitario : %.2f\n",cliente[i].Productos[j].PrecioUnitario);
        printf("\n");
     } 
     printf("Precio total: %.2f\n",total);
     printf("\n\n");
  }
}
