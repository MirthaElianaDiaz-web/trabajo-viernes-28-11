#include <iostream>
#include"FUNCIONES.h"
#include <string>
#include<vector>
using namespace std;

struct MARCA Marca[10];
struct PRODUCTOS Productos[20];
struct FORMAPAGO Formapago[5];

void mostrarmenu(int opcion)
    {
    cout<< "ELEGIR UNA OPCION"<<endl<<endl;
    cout<< "1_Cargar lote de marcas."<<endl;
    cout<< "2_Cargar lote de productos."<<endl;
    cout<< "3_Cargar lote de formas de pago."<<endl;
    cout<< "4_Cargar lote de ventas."<<endl;
    cout<< "5_Mostrar reportes."<<endl;
    cout<< "0_Salir"<<endl;
    cin>> opcion;
    }

void elegiropcion(int opcion)
{
    switch(opcion)
    {
    case 1:
{
        system("cls");
        cout<<"Usted está en la carga de Marcas"<<endl<<endl;
        MARCA Marca[10];
        cargarLoteMarca(Marca, int tam);

        cout<< "Datos de las marcas" << endl<<endl;

        for(int i = 0; i < 10; i++)
        {
        cout<<Marca[i].codMarca << " ---- ";
        cout<<Marca[i].nombre<< endl<<endl;
        }

    break;
}
    case 2:
     {

        system("cls");
          cout<<"Usted està en la carga de Productos"<<endl<<endl;
        cargarLoteProd (Productos, 20);

        cout<< "Datos de los productos" << endl<<endl;

    for(int i = 0; i < 20; i++)
        {
        cout<<Productos[i].codProd << " ---- ";
        cout<<Productos[i].nombreProd<<endl;
        cout<<Productos[i].preVenta<<endl;
        cout<<Productos[i].preCompra<<endl;
        cout<<Productos[i].stock<<endl;
        cout<<Productos[i].codMarca<<endl;
        }
    break;
     }
    case 3:
        {system("cls");
        cout<<"Usted està en la carga de Formas de Pago"<<endl<<endl;

        cargarLoteFP (Formapago, 5);

    break;
        }
    case 4:
        {

        system("cls");
          cout<<"Carga de Compras:"<<endl<<endl;
    break;
        }
    case 5:
       {

         system("cls");
          cout<<"Seleccione un informe:"<<endl<<endl;
    break;
       }
    case 6:
        {

        system("cls");
          cout<<"Salir"<<endl<<endl;
    break;
        }
    default:
    {     system("cls");
          cout << "Por favor, vuelva a elegir" << endl << endl;

    break;
    }

    }}

   //FUNCIONES INDIVIDUALES DESDE ACA//

bool cargarLoteMarca(MARCA Marca[], int codmarca, string nombre)
       {
        int aux, i;
        for (i = 0; i < 10; i++)
        {
        cout << "Ingrese el código de la marca: ";
        cin >> codmarca;
        aux=codmarca;
        Marca[aux].codMarca=codmarca;
        cin.ignore();
        cout << "Ingrese el nombre de la marca: ";
        getline (cin, nombre);
        Marca[aux].nombre=nombre;
        }
        return true;
        }

bool cargarLoteProd(PRODUCTOS Productos [], int tam)
        {
        int i, stock, codmarca, codprod;
        float preventa, precompra;
        std:: string nombreprod;
        for (i = 0; i < 20; i++)
        {
        cout << "Ingrese el código del producto: ";
        cin >>codprod;
        Productos[i].codProd=codprod;
        cin.ignore();
        cout << "Ingrese el nombre del producto: ";
        cin>>nombreprod;
        Productos[i].nombreProd=nombreprod;
        cout << "Ingrese el precio de venta del producto: ";
        cin >> preventa;
        Productos[i].preVenta=preventa;
        cout << "Ingrese el precio de compra del producto: ";
        cin >> precompra;
        Productos[i].preCompra=precompra;
        cout << "Ingrese el stock del producto: ";
        cin >> stock;
        Productos[i].stock=stock;
        cout << "Ingrese el codigo de marca: ";
        cin >> codmarca;
        Productos[i].codMarca=codmarca;
        }
        return true;
        }

bool cargarLoteFP( FORMAPAGO FormaPago[], int tam)
        {
        int i, porcentajes;
        std::string nombrepago, codpago;
        for (i = 0; i < 5; i++)
        {
        cout << "Ingrese el código de la forma de pago: ";
        cin >> codpago;
        FormaPago[i].codPago=codpago;
        cout << "Ingrese el nombre de la forma de pago ";
        cin>>nombrepago;
        FormaPago[i].nombreFP=nombrepago;
        cout << "Ingrese el porcentaje de descuento (número negativo) o interés (número positiv;o) ";
        cin >> porcentajes;
        FormaPago[i].porcentaje=porcentajes;
        }
        return true;
        }
