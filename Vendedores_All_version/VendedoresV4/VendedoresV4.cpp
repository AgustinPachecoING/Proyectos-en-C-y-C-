#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using BaseDeDatos = array<array<array<int, 12>, 3>, 4>;
void mostrar(BaseDeDatos&);
void cargar(BaseDeDatos&);
int mayorVenta(BaseDeDatos&, int, int);
void Mejorvendedor(const BaseDeDatos&, int, int);
vector<int> JuntarLosMejores(const BaseDeDatos &, int, int, int);
void MostrarResultado(const vector<int> &, int);
int GetPromedio(const BaseDeDatos&, int, int);
void estadisticas(BaseDeDatos&);
int main()
{
	BaseDeDatos total{};
	cargar(total);
	mostrar(total);
	estadisticas(total);
}
void mostrar(BaseDeDatos &total)
{
	ofstream file;
	file.open("file.bin", ios::out | ios::binary);
	for (int i{}; i < 4; ++i)
	{
		cout << '\n'
			 << '\t' << "LA REGION: " << i+1 << '\n';
		for (int j{}; j < 3; ++j)
		{
			cout << '\n'
				 << j+1 << '\n';
			for (int k{}; k < 12; ++k)
			{
				cout << "En el mes: " << k + 1 << " vendio: "
					 << "$" << total[i][j][k] << '\n';
			}
		}
	}
	file.write(reinterpret_cast<char *>(&total), sizeof(total));
	file.close();
}
void cargar(BaseDeDatos &total)
{
	ifstream file2;
	file2.open("file.bin", ios::in | ios::binary);
	file2.read(reinterpret_cast<char *>(&total), sizeof(total));
	int vendedor{}, mes{}, region{}, importe{};
	for ( ;cin >> region >> vendedor >> mes >> importe; )
	{
		total.at(region - 1).at(vendedor - 1).at(mes - 1) += importe;
	}
	file2.close();
}
void Mejorvendedor(const BaseDeDatos &total, int mes, int region)
{
	BaseDeDatos total1 = total; //para usar total1 de manera local.
	MostrarResultado(	
					 JuntarLosMejores(total,
											mayorVenta(total1, mes, region)
																			,region,mes)
																						,region);
}
void MostrarResultado(const vector <int> &mejores, int region)
{
	if (mejores.size()>1)
	{
		cout << "Los mejores vendedores del mes fueron: ";
		for (int l{}; l < mejores.size(); l++)
			cout << mejores.at(l)+1 << " ";
	}
	else // sino esto
		cout << "El mejor vendedor del mes fue: " << mejores.at(0)+1;
}
vector <int> JuntarLosMejores(const BaseDeDatos &total, int maximo, int region, int mes)
{
	vector<int> mejores{};
	for (int idVendedor{}; idVendedor < 3; idVendedor++)
		if (total.at(region).at(idVendedor).at(mes) == maximo)
			   mejores.push_back(idVendedor);
	return mejores;
}
int mayorVenta(BaseDeDatos &total, int mes, int region)
{
	int max{};
	for (auto vendedoraux : total.at(region))
		if (vendedoraux.at(mes) > max)
			max = vendedoraux.at(mes);
	return max;
}
int GetPromedio(const BaseDeDatos &total, int mes, int region)
{
	int s{};
	for (auto meses : total.at(region))
		s += meses.at(mes);
	return s / total.at(region).size();
}
void estadisticas(BaseDeDatos &total)
{
	for (int i{}; i < 12; ++i)
	{
		for (int j{}; j < 4; ++j)
		{
			cout << '\n' << "El importe maximo en el mes " << i + 1 << " para la region " << j+1 << " es de: " << "$" << mayorVenta(total, i, j) << '\n';
			Mejorvendedor(total, i, j);
			cout << '\n' << "El importe promedio en el mes " << i + 1 << " para la region " << j+1 << " es de: " << "$" << GetPromedio(total, i, j) << '\n';
		}
	}
}
