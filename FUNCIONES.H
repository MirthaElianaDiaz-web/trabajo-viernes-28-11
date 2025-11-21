#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <string>


void mostrarmenu (int opcion);
void elegiropcion (int opcion);



struct MARCA
{
int codMarca;
std::string nombre;
};
MARCA Marca[10];



struct PRODUCTOS
{
int codProd;
std::string nombreProd;
float preVenta;
float preCompra;
int stock;
int codMarca;
};
PRODUCTOS Productos[20];

struct FORMAPAGO
{
std::string codPago;
std::string nombreFP;
int porcentaje;
};
FORMAPAGO FormaPago[5];

void cargarLoteMarca(MARCA Marca[], int tam);
void cargarLoteProd(PRODUCTOS Productos[],int codprod, int stock, int codmarcaprod, std::string nombreprod, float preventa, float precompra, int tam);
void cargarLoteFP(FORMAPAGO FormaPago[], int tam);
void mostrarLoteProd(PRODUCTOS Productos[], int tam);
void mostrarLoteFP(FORMAPAGO FormaPago[], int tam);

#endif // FUNCIONES_H_INCLUDED
