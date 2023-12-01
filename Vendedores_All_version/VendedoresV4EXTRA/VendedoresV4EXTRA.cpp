#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using Cubo = array<array<array<int, 12>, 3>, 4>;
void mostrar(Cubo&);
void cargar(Cubo&);
int mayorVenta(Cubo&, int, int);
void Mejorvendedor(const Cubo&, int, int);
vector<int> JuntarLosMejores(const Cubo &, int, int, int);
void MostrarResultado(const vector<int> &, int);
int GetPromedio(const Cubo&, int, int);
void Crear_txt (Cubo&);
string nombres(int, int);
string N_regiones(int);
void estadisticas(Cubo&);
int main()
{
	Cubo total{};
	cargar(total);
	mostrar(total);
	estadisticas(total);
	Crear_txt(total);
}
void Crear_txt(Cubo &total)
{
	ofstream file;
	file.open("OutputV4EXTRA.txt", ios::out);
	for (int i{}; i < 4; ++i)
	{
		file << '\n'
			 << '\t' << "LA REGION: " << N_regiones(i) << '\n';
		for (int j{}; j < 3; ++j)
		{
			file << '\n'
				 << nombres(j, i) << '\n';
			for (int k{}; k < 12; ++k)
			{
				file << "En el mes: " << k + 1 << " vendio: "
					 << "$" << total[i][j][k] << '\n';
			}
		}
	}
	file.close();
}
void mostrar(Cubo &total)
{
	ofstream file;
	file.open("file.bin", ios::out | ios::binary);
	for (int i{}; i < 4; ++i)
	{
		cout << '\n'
			 << '\t' << "LA REGION: " << N_regiones(i) << '\n';
		for (int j{}; j < 3; ++j)
		{
			cout << '\n'
				 << nombres(j, i) << '\n';
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
void cargar(Cubo &total)
{
	vector<int> ventasCapo{};
	ifstream file2, input;
	file2.open("file.bin", ios::in | ios::binary);
	input.open("datosV4EXTRA.txt",ios::in);
	file2.read(reinterpret_cast<char *>(&total), sizeof(total));
	int v{}, m{}, r{}, importe{};
	for ( ;input >> r >> v >> m >> importe; )
	{
		total.at(r - 1).at(v - 1).at(m - 1) += importe;
        if (r==1 && v==1)
		{
			ventasCapo.push_back(importe);
		}
	}
	for (auto v : ventasCapo)
	{
		cout<<"Las ventas del capo son: "<<v<<'\n';
	}
	file2.close();
}
void Mejorvendedor(const Cubo &total, int mes, int region)
{
	Cubo total1 = total; //para usar total1 de manera local.
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
			cout << nombres(mejores.at(l),region) << " ";
	}
	else // sino esto
		cout << "El mejor vendedor del mes fue: " << nombres(mejores.at(0), region);
}
vector <int> JuntarLosMejores(const Cubo &total, int maximo, int region, int mes)
{
	vector<int> mejores{};
	for (int idVendedor{}; idVendedor < 3; idVendedor++)
		if (total.at(region).at(idVendedor).at(mes) == maximo)
			   mejores.push_back(idVendedor);
	return mejores;
}
int mayorVenta(Cubo &total, int mes, int region)
{
	int max{};
	for (auto vendedoraux : total.at(region))
		if (vendedoraux.at(mes) > max)
			max = vendedoraux.at(mes);
	return max;
}
int GetPromedio(const Cubo &total, int mes, int region)
{
	int s{};
	for (auto meses : total.at(region))
		s += meses.at(mes);
	return s / total.at(region).size();
}
void estadisticas(Cubo &total)
{
	for (int i{}; i < 12; ++i)
	{
		for (int j{}; j < 4; ++j)
		{
			cout << '\n' << "El importe maximo en el mes " << i + 1 << " para la region " << N_regiones(j) << " es de: " << "$" << mayorVenta(total, i, j) << '\n';
			Mejorvendedor(total, i, j);
			cout << '\n' << "El importe promedio en el mes " << i + 1 << " para la region " << N_regiones(j) << " es de: " << "$" << GetPromedio(total, i, j) << '\n';
		}
	}
}
string nombres(int vendedor, int region)
{
	static const array<array<string, 3>, 4> vendedores{{{{"Agustin", "Dante", "Barza"}},
														{{"Virna", "Lucas", "Facundo"}},
														{{"Sebas", "Jose Maria", "Juan Cruz"}},
														{{"Ame", "Oliver", "Logan"}}}};
	return vendedores.at(region).at(vendedor);
}
string N_regiones(int region)
{
	array<string, 4> regiones{"ESTE", "OESTE", "NORTE", "SUR"};
	return regiones.at(region);
}