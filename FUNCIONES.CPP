#include <iostream>
#include"FUNCIONES.h"
#include <cstdlib>
#include <ctime>

using namespace std;

struct MARCA Marca[10];
struct PRODUCTOS Productos[20];
struct FORMAPAGO Formapago[5];

float Montorecaudado[20]={0};
int Ventaprodcant[20]={0};
int burbindice[20]={0};


int tamp=20;
int pceEF=0;
float acuCantEF=0;
int pceMP=0;
float acuCantMP=0;
int pceTR=0;
float acuCantTR=0;
int pceTC=0;
float acuCantTC=0;
int pceCT=0;
float acuCantCT=0;
float acuCant=0;

bool ContadorDeComprasRealizadas[20]={false};
int EFV[10]={0};
int MPV[10]={0};
int TRV[10]={0};
int TCV[10]={0};
int CTV[10]={0};
int nroCliente[50];
float acuClientes[50];
int maximos[10];
int auxCliente;
float auxCompras;

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
        }
        break;
    }

    case 2:
     {

        system("cls");
        cout<<"Usted esta en la carga de Productos"<<endl<<endl;

        int tam=20;
        cargarLoteProd (Productos, tam);

        cout<<endl<< "Datos de los productos" << endl<<endl;

        for(int i = 0; i < 20; i++)
        {
        cout<<"Codigo: "<<Productos[i].codProd << " ---- ";
        cout<<"Nombre: "<<Productos[i].nombreProd<<endl;
        cout<<"Precio/v: "<<Productos[i].preVenta<<endl;
        cout<<"Precio/c: "<<Productos[i].preCompra<<endl;
        cout<<"Unidades: "<<Productos[i].stock<<endl;
        cout<<"Marca: "<<Productos[i].codMarca<<endl;

        system("pause");
        }
    break;
        }

    case 3:
        {system("cls");
        cout<<"Usted esta en la carga de Formas de Pago"<<endl<<endl;
        int tamFP=5;
        cargarLoteFP (Formapago, tamFP);

        for(int i = 0; i < 5; i++)
        {
        cout<<"Codigo: "<<Formapago[i].codPago<<" ---- "<<endl;
        cout<<"Metodo de pago: "<<Formapago[i].nombreFP<<endl;
        cout<<"ajuste del: "<<Formapago[i].porcentaje<<endl;

        system("pause");
        }
    break;
        }

    case 4:
    {  bool Autoriza;
    Autoriza = Autorizaciones(Marca, Productos, Formapago);
    if (Autoriza!=true)
        {system("cls");
    cout<<"Error: No esta autorizado"<<endl;
    cout<<"Debe cargar los lotes de Marcas, Productos y Formas de Pago primero."<<endl<<endl;
    system("pause");
        break;}
        else{

        cout<<"Carga de Compras:"<<endl<<endl;
        struct MARCA Marca[10];
        struct PRODUCTOS Productos[20];
        struct FORMAPAGO Formapago[5];
        int nrocompra;
        int codpro;
        int cant;
        int codcliente;
        int dia;
        std:: string fp;

Lote_procesos(nrocompra,codpro,cant,codcliente,dia, fp);

        }
    break;
        }

    case 5:
   {
    int Iopcionreporte;
    bool Isalirreportes = false;

    while (Isalirreportes!= true)
    {Iopcionreporte= Imostrarmenu();
    Ielegirreporte(Iopcionreporte, Isalirreportes);}


            break;
            }

   case 0:
        {{
        system("cls");
          cout<<"Salir"<<endl<<endl;

          salir=true;}
    break;
        }

    default:
    {     system("cls");
          cout << "Por favor, vuelva a elegir" << endl << endl;}//cierra el default

    break;
    }//CIERRA switch

    }//cierra la funcion completa

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

bool cargarLoteMarca(MARCA Marca[], int tamaño=10)
       {
        int aux, i, codmarca;
        std:: string nombre;
        for (i = 0; i < tamaño; i++)
        {
        cout << "Ingrese el codigo de la marca: ";

        cin >> codmarca;
        cin.ignore(100, '\n');
        codmarca = validarCeroMarca(codmarca);
        codmarca = validaCodMarca(codmarca);
        Marca[i].codMarca=codmarca;

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
        cin.ignore(100, '\n');
        }
        return true;
        }


bool cargarLoteFP(FORMAPAGO FormaPago[], int tamFP)
{
    int porcentajes;
    std::string nombrepago, codpago;

    for (int i = 0; i < tamFP; i++) {
        cout << "Ingrese el codigo de la forma de pago: " << endl;
        cin.ignore();
        getline(cin, codpago);

        codpago = repetidosFP(codpago, FormaPago, tamFP);

        while (!(codpago=="EF" || codpago=="MP" || codpago=="TR" || codpago=="TC" || codpago=="CT")) {
            cout << "Error 1 Codigo invalido, ingreselo nuevamente: ";
            cin.ignore();
            getline(cin, codpago);   // 🔹 usar getline en vez de cin >>
        }
        FormaPago[i].codPago = codpago;

        cout << "Ingrese el nombre de la forma de pago: " << endl;
        getline(cin, nombrepago);
        FormaPago[i].nombreFP = nombrepago;

        cout << "Ingrese el porcentaje de descuento (numero negativo) o interes (numero positivo): " << endl;
        cin >> porcentajes;
        FormaPago[i].porcentaje = porcentajes;
    }
    return true;
}

int validarCeroMarca(int codmarca)
{
        while (codmarca==0){
        cout<<"Error 6. El valor ingresado no es valido, intentelo nuevamente"<< endl;
        cin>>codmarca;
                        }
        return codmarca;
}

int validarCeroProducto(int valor)
{
        while (valor ==0){
        cout<<"Error 5. El valor ingresado no es valido, intentelo nuevamente"<< endl;
        cin>>valor;
                        }
        return valor;
}

int validaCodMarca(int codmarca)
{
        while (codmarca<1 || codmarca>10){
        cout<<"Error 3. El valor ingresado no es válido, intentelo nuevamente"<< endl;
        cin>>codmarca;
                                    }
        return codmarca;
}

string validaString(string nombre)
{
        while (nombre==""){
        cout<<"Error 1. El valor ingresado no es válido, intentelo nuevamente"<< endl;
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
        cout << "Error 4. Codigo de marca no encontrado en el lote de marcas. Ingreselo nuevamente: ";
        cin >> codmarca;
                    }
}

std::string repetidosFP(std::string FP, FORMAPAGO vFormaPago[], int tamFP)
{
        while(true){

        for(int i = 0; i < tamFP; i++){
        if (FP == vFormaPago[i].codPago){
        cout << "error 2. Codigo de forma de pago ya guardado. Ingreselo nuevamente: ";
        getline(cin, FP);
        //cin >> FP; prueba del error de carga
        break;
                                        }
        }
        //si no se repitió ningun codFP:
        return FP;
        }
}


int buscarindice(int codpro, PRODUCTOS Productos[], int tam) {
    for (int i = 0; i < 20; i++) {
        if (Productos[i].codProd == codpro) {
            return i;
        }
    }
    return -1;
}

int buscarIndiceFP(std::string codpago, FORMAPAGO FormaPago[], int tamFP)
        {for (int i = 0; i < 5; i++)
        {if (FormaPago[i].codPago == codpago)
        {return i;}
        }
        return -1;}

void Lote_procesos(int nrocompra,int codpro,int cant, int codcliente,int dia, std::string fp)
    {  int indice;
        int fpindice;
        float Mparcial=0;
        float Mtotal=0;

          while (true)
        {cout << "Ingrese el número de compra";
        cin >> nrocompra;
        if (nrocompra == 0) break;

        cout << "Ingrese el codigo de producto: ";
        cin >>codpro;
        cout << "Ingrese la forma de pago: ";
        cin >>fp;
        cout<< "Ingrese la cantidad: ";
        cin >>cant;
        cout<< " Ingrese el codigo de Cliente: ";
        cin>>codcliente;
        cout<< "ingrese el dia: ";
        cin>>dia;
        system("cls");



            // PROCESOS
            indice = buscarindice(codpro,Productos,tamp);
            fpindice = buscarIndiceFP(fp, Formapago, 5);

            if (indice == -1 || fpindice == -1) {
            cout << "Error 7. Producto o forma de pago no encontrada." << endl;
            continue;}

            // RECAUDACION POR PRODUCTO
            Mparcial = cant * Productos[indice].preVenta;
            Ventaprodcant[indice] += cant;
            Mtotal = Mparcial*((100 + Formapago[fpindice].porcentaje)/100);
            Montorecaudado[indice] += Mtotal;
            Productos[indice].stock-=cant;
            //PRODUCTOS SIN VENTAS
            if (cant>0){
            ContadorDeComprasRealizadas[indice]=true;
            }
            //PORCENTAJE DE VENTAS POR FORMAS DE PAGO Y POR MARCA Y FORMA DE PAGO.
            acuCant+=cant;
                 if (fp == "EF") {acuCantEF += cant;
                EFV[indice]+=cant;
                 }
            else if (fp == "MP") {acuCantMP += cant;
                MPV[indice]+= cant;
            }
            else if (fp == "TR") {acuCantTR += cant;
                TRV[indice]+=cant;
            }
            else if (fp == "TC") {acuCantTC += cant;
                TCV[indice]+=cant;
            }
            else if (fp == "CT") {acuCantCT += cant;
                CTV[indice]+=cant;
            }


            //TOP 10 CLIENTES
            for (int i = 0; i < 50; i++) {
            nroCliente[i] = i + 1;}
            acuClientes[codcliente-1]+=cant;
            burbujaclientes(nroCliente, acuClientes);
            for( int i=0; i<10; i++){
             maximos[i]=nroCliente[i];}
            }

        Burbuja(Ventaprodcant, tamp);

        pceEF=(acuCantEF*100)/acuCant;
        pceMP=(acuCantMP*100)/acuCant;
        pceTR=(acuCantTR*100)/acuCant;
        pceTC=(acuCantTC*100)/acuCant;
        pceCT=(acuCantCT*100)/acuCant;

        //falta hacer el top 10 clientes
    }


bool Autorizaciones(MARCA Marca[], PRODUCTOS Productos[], FORMAPAGO Formapago[]) {
    int a=0;
    int b=0;
    int c=0;
    for (int i = 0; i < 10; i++) {
        if (Marca[i].codMarca == 0) {
            a=0;}
            else {a=1;}
    for (int i = 0; i < 20; i++)
        if(Productos[i].codProd==0){
            b=0;}
            else{b=1;}
    for (int i = 0; i < 5; i++)
        if (Formapago[i].codPago==""){
           c=0;}
            else{c=1;}
        }
        if(a==1 && b==1 && c==1){
                return true;} else {return false;}
        }



   int Imostrarmenu()
   {int Iopcionreporte;
      system("cls");

    cout<< "ELEGIR UNA OPCION"<<endl<<endl;
    cout<< "1_Recaudacion por producto."<<endl;
    cout<< "2_Porcentaje de ventas por forma de pago."<<endl;
    cout<< "3_Venta por marca y forma de pago."<<endl;
    cout<< "4_Productos sin ventas."<<endl;
    cout<< "5_Top 10 clientes + sorteo de cupones."<<endl;
    cout<< "0_Salir"<<endl;
    cin>> Iopcionreporte;

    return Iopcionreporte;
    }

int Ielegirreporte(int Iopcionreporte, bool &Isalirreportes)
{       int i;
        switch (Iopcionreporte)
{       case 1:
        system("cls");
        cout << "Recaudacion por producto" << endl << endl;
        for (int i = 0; i < 20; i++)
    {   cout << "Producto: " << Productos[burbindice[i]].nombreProd << endl;
        cout << "Codigo: " << Productos[burbindice[i]].codProd << endl;
        cout << "Recaudacion total: $" << Montorecaudado[burbindice[i]] << endl;
        cout << "Cantidad vendida: " << Ventaprodcant[burbindice[i]] << endl;
        cout << "Stock remanente: " << Productos[burbindice[i]].stock << endl;
        system("pause");
    }
        break;
        case 2:
        {system("cls");
        cout << "Porcentajes de venta por forma de pago:" << endl << endl;
        cout << "Efectivo: " << pceEF << "%" << endl;
        cout << "MercadoPago: " << pceMP << "%" << endl;
        cout << "Transferencia: " << pceTR << "%" << endl;
        cout << "Tarjeta de Credito: " << pceTC << "%" << endl;
        cout << "Criptomoneda: " << pceCT << "%" << endl;
        system("pause");
        break;}

        case 3:
{

        system("cls");
        cout<<"Ventas por marca y forma de pago"<<endl<<endl<<endl;

        {for (i=0;i<10;i++)
        {cout<<"Medio de pago: Efectivo"<<endl;

        cout<<"Marca: " <<Marca[i].nombre<<endl;
        cout<<"Cantidad: " <<EFV[i]<<endl;}
        for (i=0;i<10;i++)
        {cout<<"Medio de pago: Mercadopago"<<Formapago[i].nombreFP<<endl;

        cout<<"Marca: " <<Marca[i].nombre<<endl;
        cout<<"Cantidad: " <<MPV[i]<<endl;}
        for (i=0;i<10;i++)
        {cout<<"Medio de pago: transferencia"<<Formapago[i].nombreFP<<endl;

        cout<<"Marca: " <<Marca[i].nombre<<endl;
        cout<<"Cantidad: " <<TRV[i]<<endl;}
        for (i=0;i<10;i++)
        {cout<<"Medio de pago: tarjeta de credito"<<Formapago[i].nombreFP<<endl;

        cout<<"Marca: " <<Marca[i].nombre<<endl;
        cout<<"Cantidad: " <<TCV[i]<<endl;}
        for (i=0;i<10;i++)
        {cout<<"Medio de pago: Criptomoneda"<<Formapago[i].nombreFP<<endl;

        cout<<"Marca: " <<Marca[i].nombre<<endl;
        cout<<"Cantidad: " <<CTV[i]<<endl;}}
        system("pause");}
        break;

        case 4:
        {system("cls");


        cout<<"Productos sin ventas:"<<endl<<endl<<endl;
        for (i=0; i<20; i++)
        if(ContadorDeComprasRealizadas[i]==false)
        {cout<<"Producto: "<<Productos[i].nombreProd<<"----Codigo----"<<Productos[i].codProd<<endl;}
        system("pause");


        break;}
        case 5:
        {int maximos[10];
        int acuClientes[10];
        int tam=10;
        cout<<"Top 10 clientes + sorteo de cupones:"<<endl<<endl<<endl;
        for (i=0;i<10;i++){
        cout<<"cliente nro: "<<maximos[i];
        }system("pause");
        cargarAleatorio(maximos, acuClientes, 10);
        cout<<"Ganadores de cupones:";
        cout<<"ganador 1, 2 y 3"<<endl;


        srand(time(0));

        for (int i = 0; i < 5; i++) {
        int numero = rand() % 100 + 1; // Número aleatorio entre 1 y 100
        cout << numero << endl;



        system("pause");}
        break;}

        case 0:

        Isalirreportes = true;
        break;
        default:
        cout << "Opcion invalida." << endl;
        system("pause");
        break;    }
        return 0;}


void Burbuja(int Ventaprodcant[], int tamp)
{   int i,j, posmin, aux;
    for(i=0;i<20;i++){burbindice[i]=i;}
    for(i=0;i<tamp-1;i++){
        posmin=i;
        for(j=i+1;j<tamp;j++){
            if(Ventaprodcant[j]<Ventaprodcant[posmin])
            {posmin=j;}}
             aux = Ventaprodcant[i];
            Ventaprodcant[i] = Ventaprodcant[posmin];
            Ventaprodcant[posmin] = aux;
            aux = burbindice[i];
            burbindice[i] = burbindice[posmin];
            burbindice[posmin] = aux;
    }
}


        // burbuja de mayor a menor usando una variable auxiliar
void burbujaclientes (int nroCliente[], float acuClientes[])
    {int auxCliente;
    float auxCompras;

    for (int i = 0; i < 50 - 1; i++) {
        for (int j = 0; j < 50 - i - 1; j++) {
            if (acuClientes[j] < acuClientes[j + 1]) {
                float auxCompras = acuClientes[j];
                acuClientes[j] = acuClientes[j + 1];
                acuClientes[j + 1] = auxCompras;
                //Intercambio de los números de cliente
                int auxCliente = nroCliente[j];
                nroCliente[j] = nroCliente[j + 1];
                nroCliente[j + 1] = auxCliente;}}}}


void cargarAleatorio(int maximos[], int acuClientes[], int tam)
{// Mostrar 3 números aleatorios del arreglo max10
    for (int i = 0; i < 3; i++)
    {int indice = rand() %10 ;  // Generar un índice aleatorio entre 0 y tam-1
    cout << "Ganador/a del cupon de descuento " << i + 1 << ": Cliente " << maximos[indice] << " - Compras: " << acuClientes[indice] << endl;
    }}
