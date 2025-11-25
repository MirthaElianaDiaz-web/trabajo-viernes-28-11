#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <string>

void IniciarMenu();
int mostrarmenu ();
void elegiropcion(int opcion, bool &salir);

void IMenureportes();
int Imostrarreportes();
int Imostrarmenu();
int Ielegirreporte(int Iopcionreporte, bool &Isalirreportes);

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
std::string repetidosFP(std::string FP, FORMAPAGO vFormaPago[], int tamFP);
int validarCeroMarca(int codmarca);
int validarCeroProducto(int valor);
int validaCodMarca(int codmarca);
int validaCodMarcaIngresado(int codmarca, MARCA Marca[]);
std:: string validaString(std:: string nombre);
//FUNCIONES
void mostrarRecaudacion(PRODUCTOS Productos[], int tamp, float Ventaprodcant[], int Montorecaudado[]);
bool Autorizaciones(MARCA Marca[], PRODUCTOS Productos[], FORMAPAGO Formapago[]);
void Burbuja(int Ventaprodcant[], int tamp);
int buscarindice(int codpro, PRODUCTOS Productos[], int tam);
int buscarIndiceFP(std::string codpago, FORMAPAGO FormaPago[], int tamFP);
void Lote_procesos(int nrocompra, int codpro,int cant,int codcliente,int dia, std::string fp);
#endif // FUNCIONES_H_INCLUDED
