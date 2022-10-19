#include <iostream>
#include "Lista.h";
#include "cancion.h" 

int main()
{
    Lista<cancion> cancionesList;
    cancionesList.Add(cancion("tswh", "twehethw"));

    string titulo;
    string artista;

    cout << "Ingrese el titulo";
    getline(cin, titulo);
    cout << "Ingrese el artista";
    getline(cin, artista);

    cancion addSong = cancion(titulo, artista);
    cancionesList.Add(addSong);
    std::cout << "Hello World!\n";

}

