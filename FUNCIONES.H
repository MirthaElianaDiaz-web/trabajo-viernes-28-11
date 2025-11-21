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



struct PRODUCTOS
{
int codProd;
std::string nombreProd;
float preVenta;
float preCompra;
int stock;
int codMarca;
};


struct FORMAPAGO
{
std::string codPago;
std::string nombreFP;
int porcentaje;
};
FORMAPAGO FormaPago[5];
//carga de lotes
bool cargarLoteMarca(MARCA Marca[], int tam);
bool cargarLoteProd(PRODUCTOS Productos[], int tam);
bool cargarLoteFP(FORMAPAGO FormaPago[], int tam);


#endif // FUNCIONES_H_INCLUDED
