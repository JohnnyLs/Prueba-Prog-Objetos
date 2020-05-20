#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cctype>

using namespace std;

int validar_num(char numero[50]);//prototipo de la funcion
int validar_cadena(char cadena[50]);//proptotipo de la funcion

int main()
{
 int sw;
 char numero[50], nombre[50];
 fflush(stdin);
 cout<<"Ingrese Numero: \n";
 cin>>numero;

 sw = validar_num(numero);

 if (sw==0)
 {
  cout<<"Numero Valido\n";
 }
 else
 {
  cout<<"Numero Invalido\n";
 }
 fflush(stdin);
 cout<<"Ingrese Nombre\n";
 cin>>nombre;

 sw = validar_cadena(nombre);

 if(sw==0)
 {
  cout<<"Nombre Valido \n";
 }
 else
 {
  cout<<"Nombre Invalido \n";
 }
return 0;
}

int validar_num(char numero[50])
//Desarrollo de la Funcion
{
 int i = 0, sw = 0, j;

 j=strlen(numero);
 while (i<j && sw==0)
 {
  if(isdigit(numero[i])!=0)
  {
   i++;
  }
  else
  {
   sw = 1;
  }
 }
return sw;
}

int validar_cadena(char cadena[50])
//Desarrollo de la Funcion
{
 int i=0, sw=0, j;
 j = strlen(cadena);
 while (i<j && sw==0)
 {
 if (isalpha(cadena[i])!=0)
 {
  i++;
 }
 else
 {
  sw=1;
 }
 }
}
