#include<ctype.h>
#include<string.h>
#include<cstdlib>
#include<conio.h>
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<string.h>
#include<fstream>
#include<windows.h>
#include<dos.h>


using namespace std;


    char menu_sub();
    char menu2();
    char menu_administrador();
    void crear_contacto();
    void agregar_contacto();
    void visualizar_contacto();
    char configuracion();
    void nuevo_usuario();
    void visualizar_usuario();
    void modificaciones();
    char menu_usuario();
    char menu_usuario1();
    void modificar_clave();
    void eliminar_usuario();
    void modificar_casa();
    void eliminar_casa();
    int alicuota();
    void ingresos(int dinero);
    int ingresar_sistema();
    int egresos();
    void mostrar_egresos();
     void ingresar_egresos();
    int opc;



struct contacto{
    string numero_casa;
    string nombre;
    string apellido;
    string telefono;
    string alicuota;
} datos;

struct user_new{
    string usuario_new;
    string password_new;
}usuario_nuevo;

struct egreso{
    string descripcion;
    string  valor;
    string dia;
    string  mes;
    string  anio;
}gasto;




int main()
{
    int dinero;

    ingresar_sistema();

}

 void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

int ingresar_sistema()
{
    string usuarios[] = {"admin"};
    string claves[] = {"1234"};
    string user,clave,contra,usuario;
    ifstream consulta;

    int contador = 0;
    bool ingresa = false;
    bool encontrar= false ;

    do {
        system("cls");
        cout << "\t\tBIENVENIDO AL SISTEMA DE ADMINISTRACION" << endl;
        cout << "\t\t---------------------------------------" << endl;
        cout << "\n\tUSUARIO: ";
        fflush(stdin);
        getline(cin,user);

        char caracter;
        cout << "\tCONTRASEÑA: ";
        caracter = getch();
        clave = "";
        while (caracter != 13)
            {
                if (caracter != 8)
                 {
                    clave.push_back(caracter);
                    cout << "*";
                 }else {
                     if (clave.length() > 0)
                       {
                         cout << "\b \b";
                         clave = clave.substr(0, clave.length() - 1);
                       }
                     }
                 caracter = getch();
              }


                consulta.open("usuario nuevo.txt",ios::in);
                  if(consulta.is_open()){//si el archivo se abrio corrrectamente entra en el iF
                            consulta>>usuario_nuevo.usuario_new;
                while(!consulta.eof()){

                        consulta>>usuario_nuevo.password_new;

                    if(usuario_nuevo.usuario_new==user && usuario_nuevo.password_new==clave){

                           encontrar=true;

                                break;

                    }
                      consulta>>usuario_nuevo.usuario_new;

                }

        }else{
        cout<<""<<endl;
    }
    consulta.close();



        for (int i = 0; i < user.size(); i++)
        {
            if (usuarios[i] == user && claves[i] == clave)
             {
                ingresa = true;
                break;
             }

        }
        if (!ingresa && !encontrar ) {
            cout << "\n\n\tEl usuario y/o clave son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < 3 && encontrar==false);





    if (ingresa == false && encontrar==false ) {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }

    if(ingresa == true){
        menu_administrador();

    }

     if(encontrar == true){
        menu_usuario1();

    }

    cin.get();
    return 0;
}


char  menu_usuario1(){
      char aux;
      int dinero;
        do{
            system("cls");
            cout <<"\t BIENVENIDO AL MENU DE USUARIO "<<endl;
             cout <<"\t--------------------------------------\n\n"<<endl;
            cout <<"\t1.- INGRESOS"<<endl;
            cout <<"\t2.- EGRESOS"<<endl;
            cout <<"\t3.- IMPRIMIR COMPROBANTE "<<endl;
            cout <<"\t4.- SALIR"<<endl;
            cout <<"\n\t Elija una opcion: ";
            cin>>aux;
            fflush(stdin);

            if ( aux<49 || aux>52){
            cout<<"\n\tHA INTRODUCIDO  UN VALOR NO VALIDO"<<endl;
            cout<<"\n\n\t";system("pause");
            }

       }while( aux<49 || aux>52);

            switch(aux){
               case 49:


               ingresos(dinero);

               break;
               case 50:
                system("cls");
                egresos();
                getch();

               break;
               case 51:


               break;
               case 52:
                   system("cls");
                cout<<"\n\t\t\t|>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|"<<endl;
                cout<<"\n\t\t\t|  HA SALIDO...! DEL SISTEMAS     |"<<endl;
                cout<<"\n\t\t\t|>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|"<<endl;


                break;

            }
}




char  menu_usuario(){
      char aux;
      int dinero;
        do{
            system("cls");
            cout <<"\t BIENVENIDO AL MENU DE USUARIO "<<endl;
             cout <<"\t--------------------------------------\n\n"<<endl;
            cout <<"\t1.- INGRESOS"<<endl;
            cout <<"\t2.- EGRESOS"<<endl;
            cout <<"\t3.- IMPRIMIR COMPROBANTE "<<endl;
            cout <<"\t4.- Atras"<<endl;
            cout <<"\n\t Elija una opcion: ";
            cin>>aux;
            fflush(stdin);

            if ( aux<49 || aux>52){
            cout<<"\n\tHA INTRODUCIDO  UN VALOR NO VALIDO"<<endl;
            cout<<"\n\n\t";system("pause");
            }

       }while( aux<49 || aux>52);

            switch(aux){
               case 49:


                ingresos(dinero);
                break;

               case 50:
                system("cls");
                egresos();
                getch();

               break;

               case 51:
               break;


               case 52:
                   system("cls");
                   menu_administrador();
                   break;

            }
}



char  menu_sub(){
      char aux;
      int din;


        do{
            system("cls");
            cout <<"\t BIENVENIDO AL MENU DE ADMINISTRACION"<<endl;
             cout <<"\t--------------------------------------\n\n"<<endl;
            cout <<"\t1.- CREAR ARCHIVO Y REGISTRO "<<endl;
            cout <<"\t2.- VISUALIZAR CASAS"<<endl;
            cout <<"\t3.- AÑADIR CASAS"<<endl;
            cout <<"\t4.- MODIFICAR EL REGISTREO DE UNA CASA"<<endl;
            cout <<"\t5.- BORRAR REGISTRO DE UNA CASA"<<endl;
            cout <<"\t6.- FIJAR ALICUOTA"<<endl;
            cout <<"\t7.- Atras"<<endl;
            cout <<"\n\t Elija una opcion: ";
            cin>>aux;
            fflush(stdin);
            if ( aux<49 || aux>55){
            cout<<"\n\tHA INTRODUCIDO  UN VALOR NO VALIDO"<<endl;
            cout<<"\n\n\t";system("pause");
            }

       }while( aux<49 || aux>55);

            switch(aux){
               case 49:
                   opc = 1;

                crear_contacto();


                  return menu_sub();
               break;
               case 50:
                   opc = 2;
                   system("cls");
                    cout<<"\n\n\tResidentes\n\n";
                    cout <<"\t------------------------------"<<endl;
                  visualizar_contacto();
                  getch();
                  system("pause");
                   return menu_sub();
               break;
               case 51:
                   opc = 3;
                  agregar_contacto();
                   return menu_sub();
               break;
               case 52:
                   opc = 4;
                   modificar_casa();

                return menu_sub();
               break;
               case 53:
                   opc = 5;

                   eliminar_casa();
                   return menu_sub();

               break;
               case 54:
                   opc = 6;

                     alicuota();


                   return menu_sub();
               case 55:
                   menu_administrador();
               break;
            }
            return din;

}

int alicuota(){
    int dinero;

    cout<<"ingrese la alicuota del año"<<endl;
    getline(cin,datos.alicuota);


}


void crear_contacto(){
	ofstream archivo;
	char rpt;
	 int lvl,tam;
    contacto *pe;

	cout<<"Ingrese el numero de casas:";
    cin>>tam;
     char contacto[tam];

	archivo.open("residentes .txt",ios::out); //Abrimos el archivo en modo escritura

	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}

	for(int i=0;i<tam;i++){

	do{

        system("cls");
		fflush(stdin);
		cout<<"\ncasas registradas: "<<i+1<<endl;
		cout<<"Digite numero de casa: ";
		getline(cin,datos.numero_casa);
		cout<<"Digite su nombre: ";
		getline(cin,datos.nombre);
		cout<<"Digite su Apellido: ";
		getline(cin,datos.apellido);
		cout<<"Digite su Telefono: ";
		getline(cin,datos.telefono);

        archivo<<datos.numero_casa<<endl;
		archivo<<datos.nombre<<endl;
		archivo<<datos.apellido<<endl;
		archivo<<datos.telefono<<endl<<endl;


	}while (i>=tam);
}

	archivo.close();
}

void agregar_contacto(){
	ofstream archivo;
	char rpt;

	archivo.open("residentes .txt",ios::app);

	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}

	do{
		fflush(stdin);
		cout<<"\nDigite numero de casa: ";
		getline(cin,datos.numero_casa);
		cout<<"\nNombre: "; getline(cin,datos.nombre);
		cout<<"Apellido: "; getline(cin,datos.apellido);
		cout<<"Telefono: "; getline(cin,datos.telefono);

        archivo<<datos.numero_casa<<endl;
		archivo<<datos.nombre<<endl;
		archivo<<datos.apellido<<endl;
		archivo<<datos.telefono<<endl<<endl;

		cout<<"\nDesea Agregar otro casa?: ";
		cin>>rpt;
	}while((rpt == 'S') || (rpt == 's'));

	archivo.close();
}

void visualizar_contacto(){
	ifstream archivo;
	string texto;

	archivo.open("residentes .txt",ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
     archivo>>datos.numero_casa;
	while(!archivo.eof()){

		archivo>>datos.nombre;
		archivo>>datos.apellido;
		archivo>>datos.telefono;



		cout<<"Numero de Casa: "<<datos.numero_casa<<endl;
		cout<<"Nombre: "<<datos.nombre<<endl;
		cout<<"Apellido: "<<datos.apellido<<endl;
		cout<<"Telefono: "<<datos.telefono<<endl<<endl;
		cout<<"---------------------------------"<<endl<<endl;


		 archivo>>datos.numero_casa;
	}

	archivo.close();
}




char  menu2(){
      char aux;
        do{
            system("cls");
            cout <<"\t BIENVENIDO AL MENU DE ADMINISTRACION"<<endl;
             cout <<"\t--------------------------------------\n\n"<<endl;
            cout <<"\t1.- CREAR NUEVO USUARIO"<<endl;
            cout <<"\t2.- Verificar ususarios"<<endl;
            cout <<"\t3.- CAMBIAR CLAVE "<<endl;
            cout <<"\t4.- Eliminar Usuario "<<endl;
            cout <<"\t5.- ATRAS"<<endl;
            cout <<"\n\t Elija una opcion: ";
            cin>>aux;
            fflush(stdin);

            if ( aux<49 || aux>53){
            cout<<"\n\tHA INTRODUCIDO  UN VALOR NO VALIDO"<<endl;
            cout<<"\n\n\t";system("pause");
            }

       }while( aux<49 || aux>53);

            switch(aux){
               case 49:
                nuevo_usuario();
                getch();
                menu2();

               break;
               case 50:
                   system("cls");
                    cout<<"\n\tUSUARIOS"<<endl<<endl;
                    cout<<"------------------"<<endl<<endl;
                   visualizar_usuario();

                    getch();
                   menu2();

               break;
               case 51:
                    system("cls");
                    cout<<"\n\tBUSAR USUARIO"<<endl<<endl;

                    modificar_clave();

                   getch();
                   menu2();

               break;
               case 52:
                    system("cls");
                    cout<<"\n\tELIMINAR USUARIO"<<endl<<endl;
                   eliminar_usuario();
                   getch();
                   menu2();

                break;

               case 53:

                    system("cls");
                menu_administrador();
                break;

            }
}


char  menu_administrador(){
      char aux;
        do{
            system("cls");
            cout <<"\t BIENVENIDO AL MENU DE ADMINISTRACION"<<endl;
             cout <<"\t--------------------------------------\n\n"<<endl;
            cout <<"\t1.- INGRESAR AL SISTEMA"<<endl;
            cout <<"\t2.- ADMINISTRAR CUENTAS "<<endl;
            cout <<"\t3.- CONFIGURACION DEL SISTEMA "<<endl;
            cout <<"\t4.- SALIR"<<endl;
            cout <<"\n\t Elija una opcion: ";
            cin>>aux;
            fflush(stdin);
            if ( aux<49 || aux>52){
            cout<<"\n\tHA INTRODUCIDO  UN VALOR NO VALIDO"<<endl;
            cout<<"\n\n\t";system("pause");
            }

       }while( aux<49 || aux>52);

            switch(aux){
               case 49:
                system("cls");
                menu_usuario();
                break;


               case 50:
                menu2();
               break;

               case 51:
                menu_sub();

               case 52:
                      system("cls");
                cout<<"\n\t\t\t|>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|"<<endl;
                cout<<"\n\t\t\t|  HA SALIDO...! VUELVA PRONTO    |"<<endl;
                cout<<"\n\t\t\t|>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|"<<endl;
               break;

            }
}





void nuevo_usuario(){
    ofstream archivo;
    ifstream consulta;
    string nubUsuario,contra,usuario;
    bool repetido=false;
    archivo.open("usuario nuevo.txt",ios::out|ios::app);
    consulta.open("usuario nuevo.txt",ios::in);
    if(archivo.is_open() && consulta.is_open()){//si el archivo se abrio corrrectamente entra en el iF
        cout<<"Ingresa el nuevo usuario: ";//Falta validar cuando se ingresa un caracter
         getline(cin,usuario_nuevo.usuario_new);
        consulta>>usuario;
        while(!consulta.eof()){
            consulta>>contra;
            if(usuario==usuario_nuevo.usuario_new){
                cout<<"Ya Existe un usuario con ese nombre"<<endl;
                repetido=true;
                break;
            }
            consulta>>usuario;
        }
        if(repetido==false){
            cout<<"Ingresa la clave del nuevo usuario: ";
            getline(cin,usuario_nuevo.password_new);
            archivo<<usuario_nuevo.usuario_new<<endl;
            archivo<<usuario_nuevo.password_new<<endl<<endl;
            cout<<"Se creo el nuevo usuario"<<endl;
        }

    }else{
        cout<<"ERROR EL USUARO NO SE HA CREADO"<<endl;
    }
    archivo.close();
    consulta.close();

}

void visualizar_usuario(){
	ifstream archivo;
	string texto;

	archivo.open("usuario nuevo.txt",ios::in); //Abrimos el archivo en modo lectura

	if(archivo.fail()){
		cout<<"El archivo aun no se ha creado\n";
		system("pause");


    }else{


	archivo>>usuario_nuevo.usuario_new;
	while(!archivo.eof()){ //mientras no sea el final de archivo
             archivo>>usuario_nuevo.password_new;
             cout<<"Usuario: "<<usuario_nuevo.usuario_new<<endl;
            cout<<"Password: "<<usuario_nuevo.password_new<<endl<<endl;
            cout<<"------------------"<<endl<<endl;

            archivo>>usuario_nuevo.usuario_new;

	}
	archivo.close(); //Cerramos el archivo
    }
}


void ingresos(int dinero){


    system("cls");

 ofstream archivo;

	string datos_e,alfa,gamma;
	string fecha,o,l;
	int tam;
	char a,b;
	bool x;
	contacto *pe;
    system("cls");

    cout<<"\nAlicuota: ";getline(cin,gamma);
    archivo<<"\nAlicuota: "<<gamma;
    cout<<"Desea realizar un nuevo ingreso Si : ";
    cin>>x;
    switch(x){
    case 1:



	cout<<"Digite el numero de egresos a ingresar:";
    cin>>tam;

    char contacto[tam];


	archivo.open("residentes .txt",ios::app);

	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}

        fflush(stdin);
        for(int i=0;i<tam;i++){

	do{

        system("cls");
		fflush(stdin);
		cout<<"\nIngresos registrados: "<<i+1<<endl;
        cout<<"\nINGRESOS"<<endl;
		cout<<"\nDescripcion: ";getline(cin,datos_e);cout<<"\nValor: ";getline(cin,alfa);cout<<"\nIngrese la fecha: ";getline(cin,fecha);



		cout<<"Los egresos totales del mes son: "<<l<<endl;

        archivo<<"\nTotal de "<<datos_e<<": ";
        archivo<<alfa<<"\t";
        archivo<<fecha<<endl;

	}while (i>=tam);
        }

        }
}


void modificar_clave(){
    ofstream aux;
	ifstream archivo;
	 bool encontrado=false;

	string texto,clave_aux, usuario_aux;

    aux.open("auxiliar.txt",ios::out);
	archivo.open("usuario nuevo.txt",ios::in);


	if(aux.is_open())

    {



		cout<<"USUARIO A MODIFICAR: ";

		getline(cin,usuario_aux);

	archivo>>usuario_nuevo.usuario_new;
	while(!archivo.eof()){ //mientras no sea el final de archivo
             archivo>>usuario_nuevo.password_new;
             if (usuario_nuevo.usuario_new==usuario_aux)
             {
                  encontrado==true;


                     cout <<"\n\tUSUARIO ENCONTRADO\n"<<endl;
                     cout<<"Usuario: "<<usuario_nuevo.usuario_new<<endl;
                     cout<<"Password: "<<usuario_nuevo.password_new<<endl;
                     cout<<"---------------------------"<<endl<<endl;

                        cout <<"INGRESE LA NUEVA- CONTRASEÑA"<<endl;
                        cout <<"\n >>> ";
                        getline(cin,clave_aux);
                        aux<<usuario_nuevo.usuario_new<<endl;
                        aux<<clave_aux<<endl<<endl;

                        cout <<"\n\tClave cambiada"<<endl;



                }else{
                    aux<<usuario_nuevo.usuario_new<<endl<<endl;

                    aux<<usuario_nuevo.password_new<<endl<<endl;

                     }


        archivo>>usuario_nuevo.usuario_new;


	}


    }else
        {
    cout<<"No se pudo abrir el archivo"<<endl;}

if(encontrado==false){
        cout<<"\n\tNo se encontro ningun Usuario"<<endl;
        }

archivo.close();
aux.close();

remove("usuario nuevo.txt");
rename("auxiliar.txt","usuario nuevo.txt");
}


void eliminar_usuario(){
    ofstream aux;
	ifstream archivo;
	bool encontrado=false;

	string texto,clave_aux, usuario_aux;

    aux.open("auxiliar.txt",ios::out);
	archivo.open("usuario nuevo.txt",ios::in);


	if(aux.is_open())

    {



		cout<<"USUARIO A MODIFICAR: ";

		getline(cin,usuario_aux);

	archivo>>usuario_nuevo.usuario_new;
	while(!archivo.eof()){ //mientras no sea el final de archivo
             archivo>>usuario_nuevo.password_new;
             if (usuario_nuevo.usuario_new==usuario_aux)
             {
                    encontrado=true;

                     cout <<"\n\tUSUARIO ENCONTRADO\n"<<endl;
                     cout<<"Usuario: "<<usuario_nuevo.usuario_new<<endl;
                     cout<<"Password: "<<usuario_nuevo.password_new<<endl;
                     cout<<"---------------------------"<<endl<<endl;

                        cout <<"ELIMINANDO"<<endl;
                        Sleep(500);
                        cout <<"ELIMINANDO"<<endl;
                        Sleep(500);
                        cout <<"ELIMINANDO"<<endl;
                        Sleep(500);


                        cout <<"\n\tUSUARIO ELIMINADO"<<endl;
                        Sleep(1500);



                }else{



                    aux<<usuario_nuevo.usuario_new<<endl;
                    aux<<usuario_nuevo.password_new<<endl<<endl;

                     }


        archivo>>usuario_nuevo.usuario_new;


	}


    }else
        {cout<<"No se encontro ningun Usuario"<<endl;}
if(encontrado==false){
        cout<<"\n\tNo se encontro ningun Usuario"<<endl;
        }

archivo.close();
aux.close();

remove("usuario nuevo.txt");
rename("auxiliar.txt","usuario nuevo.txt");
}




void modificar_casa(){
    ofstream aux;
	ifstream archivo;
	 bool encontrado=false;

	string texto,nombre_aux, apellido_aux,telefono_aux,usuario_aux;
	char opc;

    aux.open("auxiliar.txt",ios::out);
	archivo.open("residentes .txt",ios::in);


	if(aux.is_open())

    {


        system("cls");
		cout<<"CASA A MODIFICAR: ";

		getline(cin,usuario_aux);

	archivo>>datos.numero_casa;
	while(!archivo.eof()){ //mientras no sea el final de archivo
             archivo>>datos.nombre;
             archivo>>datos.apellido;
             archivo>>datos.telefono;


             if (datos.numero_casa==usuario_aux)
             {
                  encontrado=true;


                     cout <<"\n\tCASA ENCONTRADO\n"<<endl;
                     cout<<"Numero de Casa: "<<datos.numero_casa<<endl;
                     cout<<"Nombre: "<<datos.nombre<<endl;
                     cout<<"Apellido: "<<datos.apellido<<endl;
                     cout<<"Telefono: "<<datos.telefono<<endl<<endl;
                     cout<<"---------------------------"<<endl<<endl;


                        cout <<"\tQUE DATO DESEA ACTUALIZAR"<<endl;

                        do{

                             cout <<"\t------------------------------"<<endl;

                            cout <<"\t1.- Nombre"<<endl;
                            cout <<"\t2.- ApellidoA "<<endl;
                            cout <<"\t3.- Telefono"<<endl;
                            cout <<"\t4.- Atras"<<endl;

                            cout <<"\n >>> ";
                            cin>>opc;
                            fflush(stdin);
                            if ( opc<49 || opc>52){
                            cout<<"\n\tHA INTRODUCIDO  UN VALOR NO VALIDO"<<endl;
                            cout<<"\n\n\t";system("pause");
                            }

                       }while( opc<49 || opc>52);
                                   switch(opc){
                           case 49:
                                 cout <<"Ingrese el nuevo nombre"<<endl;
                                 cout <<"\n >>> ";
                                 getline(cin,nombre_aux);
                                 aux<<datos.numero_casa<<endl;
                                 aux<<nombre_aux<<endl;
                                 aux<<datos.apellido<<endl;
                                 aux<<datos.telefono<<endl<<endl;
                                break;
                           case 50:
                                cout <<"Ingrese el nuevo apellido"<<endl;
                                 cout <<"\n >>> ";
                                 getline(cin,apellido_aux);
                                 aux<<datos.numero_casa<<endl;
                                 aux<<datos.nombre<<endl;
                                 aux<<apellido_aux<<endl;
                                 aux<<datos.telefono<<endl<<endl;
                           break;

                           case 51:
                            cout <<"Ingrese el nuevo telefono"<<endl;
                                 cout <<"\n >>> ";
                                 getline(cin,telefono_aux);
                                 aux<<datos.numero_casa<<endl;
                                 aux<<datos.nombre<<endl;
                                 aux<<datos.apellido<<endl;
                                 aux<<telefono_aux<<endl<<endl;
                                 break;

                           case 52:

                             menu_sub();
                           break;

                        }

                        cout <<"\n\tDato Cambiado"<<endl;



                }else{
                    aux<<datos.numero_casa<<endl;
                    aux<<datos.nombre<<endl;
                    aux<<datos.apellido<<endl;
                    aux<<datos.telefono<<endl<<endl;


                     }


        archivo>>datos.numero_casa;


	}


    }else
        {
    cout<<"No se pudo abrir el archivo"<<endl;}

if(encontrado==false){
        cout<<"\n\tNo se encontro ningun Usuario"<<endl;
        }

archivo.close();
aux.close();

remove("residentes .txt");
rename("auxiliar.txt","residentes .txt");
}



void eliminar_casa(){
    ofstream aux;
	ifstream archivo;
	 bool encontrado=false;

	string texto,nombre_aux, apellido_aux,telefono_aux,usuario_aux;
	char opc;

    aux.open("auxiliar.txt",ios::out);
	archivo.open("residentes .txt",ios::in);


	if(aux.is_open())

    {


        system("cls");
		cout<<"CASA A ELIMINAR: ";

		getline(cin,usuario_aux);

	archivo>>datos.numero_casa;
	while(!archivo.eof()){ //mientras no sea el final de archivo
             archivo>>datos.nombre;
             archivo>>datos.apellido;
             archivo>>datos.telefono;


             if (datos.numero_casa==usuario_aux)
             {
                  encontrado=true;


                     cout <<"\n\tCASA ENCONTRADO\n"<<endl;
                     cout<<"Numero de Casa: "<<datos.numero_casa<<endl;
                     cout<<"Nombre: "<<datos.nombre<<endl;
                     cout<<"Apellido: "<<datos.apellido<<endl;
                     cout<<"Telefono: "<<datos.telefono<<endl<<endl;
                     cout<<"---------------------------"<<endl<<endl;




                        cout <<"ELIMINANDO"<<endl;
                        Sleep(500);
                        cout <<"ELIMINANDO"<<endl;
                        Sleep(500);
                        cout <<"ELIMINANDO"<<endl;
                        Sleep(500);


                        cout <<"\n\tREGISTRO DE CASA ELIMINADO"<<endl;
                        Sleep(2500);


                }else{
                    aux<<datos.numero_casa<<endl;
                    aux<<datos.nombre<<endl;
                    aux<<datos.apellido<<endl;
                    aux<<datos.telefono<<endl<<endl;


                     }


        archivo>>datos.numero_casa;


	}


    }else
        {
    cout<<"No se pudo abrir el archivo"<<endl;}

if(encontrado==false){
        cout<<"\n\tNo se encontro ningun casa"<<endl;
        }

archivo.close();
aux.close();

remove("residentes .txt");
rename("auxiliar.txt","residentes .txt");
}


int egresos(){
    char opcion;



    do{
            system("cls");
		cout<<"\t.EGRESOS"<<endl;
		cout<<"1. INGRESAR EGRESOS  "<<endl;
		cout<<"2.  VISUALIZAR EGRESO"<<endl;
		cout<<"3. ATRAS"<<endl<<endl;
		cout<<">>> ";
		cin>>opcion;
		 if ( opcion<49 || opcion>51){
            cout<<"\n\tHA INTRODUCIDO  UN VALOR NO VALIDO"<<endl;
            cout<<"\n\n\t";system("pause");
            }
            }while( opcion<49 || opcion>51);

		switch(opcion){
			case 49:
					system("cls");

					ingresar_egresos();
					egresos();


					break;
			case 50:
					system("cls");
					 cout<<"\t\tMOSTRAR EGRESOS"<<endl;
					 cout<<"---------------------------------\n"<<endl;
					mostrar_egresos();
					getch();

					egresos();


					break;
			case 51:

					system("cls");
					menu_usuario();
					getch();

                break;
		}

}







void mostrar_egresos(){

    ifstream archivo;
    int contador=1;
    float numeros[20];
    int cont=0,i=1;
    float suma=0;

	archivo.open("egresos.txt",ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}else{

        getline(archivo,gasto.descripcion);
	    while(!archivo.eof()){


                getline(archivo,gasto.valor);
                getline(archivo,gasto.dia);
                getline(archivo,gasto.mes);
                getline(archivo,gasto.anio);

        cont=cont+1;

        cout<<"\t\tEGRESOS"<<contador++<<endl;

		cout<<"DESCRIPCION: "<<gasto.descripcion;
		cout<<"\t\tVALOR: "<<gasto.valor<<endl;
		cout<<"\nFECHA"<<endl;
        cout<<"DIA: "<<gasto.dia;
        cout<<"  MES: "<<gasto.mes;
		cout<<"  AÑO: "<<gasto.anio<<endl<<endl;

		cout<<"---------------------------------\n"<<endl;

                 numeros[i++]=atoi(gasto.valor.c_str());




		getline(archivo,gasto.descripcion);

	    }


      archivo.close();
	}

        for(int i=1;i<cont+1;i++){
        suma+=(numeros[i]);
	    }


	    cout<<"EL VALOR TOTAL DE LOS INGRESOS ES "<<suma<<endl;

}


void ingresar_egresos(){

    ofstream archivo;
	char rpt;


	archivo.open("egresos.txt",ios::app);

	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}

	do{
		fflush(stdin);
        cout<<"\n\t INGRESE EGRESOS\n";
		cout<<"\nDESCRIPCION: ";getline(cin,gasto.descripcion);
		fflush(stdin);

		cout<<"\t\t\t\tVALOR: "; getline(cin,gasto.valor);
		cout<<"FECHA\n ";
		fflush(stdin);
		cout<<"\nDIA: ";getline(cin,gasto.dia);
		cout<<"\t\tMES: ";getline(cin,gasto.mes);
		cout<<"\t\tAÑO: ";getline(cin,gasto.anio);
		fflush(stdin);


        archivo<<gasto.descripcion<<endl;
		archivo<<gasto.valor<<endl;
		archivo<<gasto.dia<<endl;
		archivo<<gasto.mes<<endl;
		archivo<<gasto.anio<<endl;
		system("cls");
		cout<<"\nDesea Agregar otro egreso?SI(1)/NO(0): ";
		cin>>rpt;
		if ( rpt<48 || rpt>49){

            cout<<"\n\tHA INTRODUCIDO  UN VALOR NO VALIDO"<<endl;
            cout<<"\n\n\t";system("pause");
            }


	}while(rpt==49 );

	archivo.close();
}

