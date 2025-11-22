#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <string>

void IniciarMenu();
int mostrarmenu ();
void elegiropcion(int opcion, bool &salir);

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

//carga de lotes
bool cargarLoteMarca(MARCA Marca[], int tam);
bool cargarLoteProd(PRODUCTOS Productos[], int tam);
bool cargarLoteFP(FORMAPAGO FormaPago[], int tam);

//validaciones
std::string validarDistintosFP();
int validarCero(int codmarca);
int validaCodMarca(int codmarca);
std:: string validaString(std:: string nombre);

#endif // FUNCIONES_H_INCLUDED

