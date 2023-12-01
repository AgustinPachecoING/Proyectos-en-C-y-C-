#include <iostream>
#include <array>
#include <fstream>
using namespace std;
using BaseDeDatos = array<array<int,12>,3>;
void cargar_datos (BaseDeDatos &);
void mostrar_datos (BaseDeDatos &);
int main ()
{
  BaseDeDatos total{};
  cargar_datos(total);
  mostrar_datos(total);
}
void cargar_datos ( BaseDeDatos & total)
{
  int vendedor{},mes{},importe{}; 
  for (;cin>>vendedor>>mes>>importe;) 
  {
    total.at(vendedor-1).at(mes-1)+=importe; //.at() verifica el rango.  
  }
}
void mostrar_datos (BaseDeDatos & total)
{
    ofstream flujo;
    flujo.open("OutputV2.txt",ios::out);
    for(int j{};j<3;j++)
    {
      cout<<"El vendedor: "<<j+1<<" "<<'\n';
      flujo<<"El vendedor: "<<j+1<<" "<<'\n';
        for(int i{};i<12;++i)
        {
          cout<<"En el mes: "<<i+1<<" se vendio: "<<total.at(j).at(i)<<'\n';
          flujo<<"En el mes: "<<i+1<<" se vendio: "<<total.at(j).at(i)<<'\n';
        }
    }
}