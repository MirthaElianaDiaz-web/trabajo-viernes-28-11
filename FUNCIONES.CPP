#include <iostream>
#include"FUNCIONES.h"
#include <string>
#include<vector>
using namespace std;

struct MARCA Marca[10];
struct PRODUCTOS Productos[20];
struct FORMAPAGO Formapago[5];

int mostrarmenu()
    {
        int opcion;
        system("cls");
    cout<< "UTN. FRGP"<<endl;
    cout<< "TECNICATURA UNIVERSITARIA EN PROGRAMACION"<<endl<<endl;
    cout<< "ELEGIR UNA OPCION"<<endl<<endl;
    cout<< "1_Cargar lote de marcas."<<endl;
    cout<< "2_Cargar lote de productos."<<endl;
    cout<< "3_Cargar lote de formas de pago."<<endl;
    cout<< "4_Cargar lote de ventas."<<endl;
    cout<< "5_Mostrar reportes."<<endl;
    cout<< "0_Salir"<<endl;
    cin>> opcion;

    return opcion;
    }

void elegiropcion(int opcion, bool &salir)
    {
    switch(opcion)
    {
    case 1:
    {
        system("cls");
        cout<<"Usted esta en la carga de Marcas"<<endl<<endl;

        int tam = 10;
        cargarLoteMarca(Marca, tam);
        system("cls");
        cout<< "Datos de las marcas" << endl<<endl;

        for(int i = 0; i < 10; i++)
        {
        cout<<Marca[i].codMarca << " ---- ";
        cout<<Marca[i].nombre<<endl;

        system("pause");
        }
        break;
    }

    case 2:
     {

        system("cls");
        cout<<"Usted està en la carga de Productos"<<endl<<endl;

        int tam=20;
        cargarLoteProd (Productos, tam);

        cout<< "Datos de los productos" << endl<<endl;

        for(int i = 0; i < 20; i++)
        {
        cout<<Productos[i].codProd << " ---- ";
        cout<<Productos[i].nombreProd<<endl;
        cout<<Productos[i].preVenta<<endl;
        cout<<Productos[i].preCompra<<endl;
        cout<<Productos[i].stock<<endl;
        cout<<Productos[i].codMarca<<endl;

        system("pause");
        }
    break;
        }

    case 3:
        {system("cls");
        cout<<"Usted està en la carga de Formas de Pago"<<endl<<endl;
        int tam=5;
        cargarLoteFP (Formapago, tam);

        for(int i = 0; i < 5; i++)
        {
        cout<<Formapago[i].codPago<<" ---- "<<endl;
        cout<<Formapago[i].nombreFP<<endl;
        cout<<Formapago[i].porcentaje<<endl;

        system("pause");
        }
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

   case 0:
        {
        system("cls");
          cout<<"Salir"<<endl<<endl;

          salir=true;
    break;
        }

    default:
    {     system("cls");
          cout << "Por favor, vuelva a elegir" << endl << endl;

    break;
    }

    }}

void IniciarMenu()
    {
    bool salir = false;
    while (salir!= true)
    {
    int opcion = mostrarmenu();
    elegiropcion(opcion, salir);
    }
    }


   //FUNCIONES INDIVIDUALES DESDE ACA//

bool cargarLoteMarca(MARCA Marca[], int tam)
       {
        int aux, i, codmarca;
        std:: string nombre;
        for (i = 0; i < 10; i++)
        {
        cout << "Ingrese el codigo de la marca: ";
        cin >> codmarca;
        codmarca = validarCeroMarca(codmarca);
        codmarca = validaCodMarca(codmarca);
        Marca[i].codMarca=codmarca;
        cin.ignore(100, '\n');
        cout << "Ingrese el nombre de la marca: ";
        getline (cin, nombre);
        nombre= validaString(nombre);
        Marca[i].nombre=nombre;
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
        cout << "Ingrese el codigo del producto: ";
        cin >>codprod;
        codprod= validarCeroProducto(codprod);
        Productos[i].codProd=codprod;
        cin.ignore();
        cout << "Ingrese el nombre del producto: ";
        getline(cin, nombreprod);
        Productos[i].nombreProd=nombreprod;
        cout << "Ingrese el precio de venta del producto: ";
        cin >> preventa;
        preventa= validarCeroProducto(preventa);
        Productos[i].preVenta=preventa;
        cout << "Ingrese el precio de compra del producto: ";
        cin >> precompra;
        precompra= validarCeroProducto(precompra);
        Productos[i].preCompra=precompra;
        cout << "Ingrese el stock del producto: ";
        cin >> stock;
        stock= validarCeroProducto(stock);
        Productos[i].stock=stock;
        cout << "Ingrese el codigo de marca: ";
        cin >> codmarca;
        codmarca= validarCeroProducto(codmarca);
        codmarca = validaCodMarcaIngresado(codmarca, Marca);
        Productos[i].codMarca=codmarca;
        }
        return true;
        }


bool cargarLoteFP(FORMAPAGO FormaPago[], int tam) {
        int porcentajes;
        std::string nombrepago, codpago;
        for (int i = 0; i < tam; i++) {
        cout << "Ingrese el codigo de la forma de pago: " << endl;
        getline(cin, codpago);
        codpago= repetidosFP(codpago, FormaPago, tam);
        while (!(codpago=="EF" || codpago=="MP" || codpago=="TR" || codpago=="TC" || codpago=="CT")) {
        cout << "Código inválido, ingreselo nuevamente: ";
        cin >> codpago;
        cin.ignore(100, '\n');
        }
        FormaPago[i].codPago = codpago;
        cout << "Ingrese el nombre de la forma de pago: " << endl;
        getline(cin, nombrepago);
        FormaPago[i].nombreFP = nombrepago;
        cout << "Ingrese el porcentaje de descuento (numero negativo) o interes (numero positivo): " << endl;
        cin >> porcentajes;
        FormaPago[i].porcentaje = porcentajes;
        cin.ignore(100, '\n');
                                    }
        return true;
}

int validarCeroMarca(int codmarca)
{
        while (codmarca==0){
        cout<<"El valor ingresado no es valido, intentelo nuevamente"<< endl;
        cin>>codmarca;
                        }
        return codmarca;
}

int validarCeroProducto(int valor)
{
        while (valor ==0){
        cout<<"El valor ingresado no es valido, intentelo nuevamente"<< endl;
        cin>>valor;
                        }
        return valor;
}

int validaCodMarca(int codmarca)
{
        while (codmarca<1 || codmarca>10){
        cout<<"El valor ingresado no es válido, intentelo nuevamente"<< endl;
        cin>>codmarca;
                                    }
        return codmarca;
}

string validaString(string nombre)
{
        cin.ignore();

        while (nombre==""){
        cout<<"El valor ingresado no es válido, intentelo nuevamente"<< endl;
        getline(cin,nombre);
                        }
        return nombre;
}

int validaCodMarcaIngresado(int codmarca, MARCA Marca[])
{
        int i = 0;
        while (true){
        for (i = 0; i<10; i++) {
        if (codmarca==Marca[i].codMarca)
            {
        return codmarca;
            }
                                        }
        cout << "Código de marca no encontrado en el lote de marcas. Ingreselo nuevamente: ";
        cin >> codmarca;
                    }
}

//repetidosFP
std::string repetidosFP(std::string FP, FORMAPAGO vFormaPago[], int tamFP)
{
        while(true){

        for(int i = 0; i < tamFP; i++){
        if (FP == vFormaPago[i].codPago){
        cout << "Código de forma de pago ya guardado. Ingreselo nuevamente: ";
        cin >> FP;
        i = -1; // es importante para reiniciar el for
                                        }
        }
        //si no se repitió ningun codFP:
        return FP;
                    }
}


