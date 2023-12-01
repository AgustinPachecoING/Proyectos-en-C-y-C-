#include <iostream>
#include <array>
#include <fstream>
using namespace std; 
using BaseDeDatos = array<int,12>;
void cargar_datos (BaseDeDatos &);
void mostrar_datos (BaseDeDatos &);
int main()
{
     BaseDeDatos total{};
     cargar_datos (total);
     mostrar_datos(total);
}
void cargar_datos(BaseDeDatos & total)
{
  int mes{},importe{}; 
  for (;cin>>mes>>importe;) 
  {
    total.at(mes-1)+=importe;
  }
}
void mostrar_datos (BaseDeDatos & total)
{
    ofstream flujo;
    flujo.open("OutputV1.txt",ios::out);
    for(int i{};i<12;++i)
    {
    cout<<"En el mes: "<<i+1<<" se vendio: "<<total.at(i)<<'\n';
    flujo<<"En el mes: "<<i+1<<" se vendio: "<<total.at(i)<<'\n';
    } 
}