#include <string>
using namespace std;

class cancion
{
	string Titulo;
	string Artista;

public:
	cancion() {}
	cancion(string titulo, string artista)
	{
		Titulo = titulo;
		Artista = artista;
		if (artista == "") 
		{
			Artista = "Desconocido";
		}
		if (titulo == "") 
		{
			Titulo = "Sin titulo";
		}
	}

	string getArtista()
	{
		return Artista;
	}
	string getTitulo()
	{
		return Titulo;
	}
	void setTitulo(string titulo) 
	{
		Titulo = titulo;
	}
};
