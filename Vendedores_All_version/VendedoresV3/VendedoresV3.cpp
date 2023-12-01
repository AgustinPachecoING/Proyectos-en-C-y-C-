#include <iostream>
#include <array>
#include <fstream>
using namespace std;
using BaseDeDatos = array<array<array<int,12>,3>,4>;
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
  int region{},vendedor{},mes{},importe{}; 
  for (;cin>>region>>vendedor>>mes>>importe;) 
  {
    total.at(region-1).at(vendedor-1).at(mes-1)+=importe;
  } 
}
void mostrar_datos (BaseDeDatos & total)
{
    ofstream flujo;
    flujo.open("OutputV3.txt",ios::out);
    for(int k{};k<4;k++)
    {
     cout<<"La region: "<<k+1<<'\n';
     flujo<<"La region: "<<k+1<<'\n';
        for(int j{};j<3;j++)
        {
          cout<<"El vendedor: "<<j+1<<" "<<'\n';
          flujo<<"El vendedor: "<<j+1<<" "<<'\n';
            for(int i{};i<12;++i)
            {
              cout<<"En el mes: "<<i+1<<" se vendio: "<<total.at(k).at(j).at(i)<<'\n';
              flujo<<"En el mes: "<<i+1<<" se vendio: "<<total.at(k).at(j).at(i)<<'\n';
            }
        }
    }
}