#include <iostream>
#include "Lista.h"
#include "cancion.h" 
#include <string>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

Lista<cancion> cancionesList;

void listaCancionesMenu()
{
    string selection;
    int select;

    do
    {
        cout << "Lista de canciones\n";
        cout << "Seleccione una opcion\n";
        cout << "1| Mostrar lista de canciones\n";
        cout << "2| Agregar cancion a la lista\n";
        cout << "3| Quitar cancion de la lista\n";
        cout << "4| Leer una lista guardada\n";
        cout << "5| guardar lista en un archivo\n";
        cout << "0| Regresar\n";

        string titulo;
        string artista;
        cancion addSong;
        getline(cin, selection);
        select = stoi(selection);
        ifstream archivo;
        string linea;
        string posicion;
        string cancionArt;

        switch (select)
        {
        case 1:

            for (int i = 0; i < cancionesList.GetCount(); i++)
            {
                cancionesList.GetItem(i);
                //cout<<
            }

            break;
        case 2:
            cout << "Ingrese el titulo\n";
            getline(cin, titulo);
            cout << "Ingrese el artista\n";
            getline(cin, artista);
            addSong = cancion(titulo, artista);
            cancionesList.Add(addSong);

            cout << "Cancion agregada exitosamente";
            listaCancionesMenu();
            break;
        case 3:
            break;
        case 4:
            cout << "Ingrese lugar donde se encuentra el archivo" << endl;
            getline(cin, posicion);
            archivo.open(posicion, ios::in);

            while (getline(archivo, linea)) {
                stringstream stream(linea);
                getline(stream, cancionArt, ',');
                cout << cancionArt << endl;
                //uwu
            }
            break;
        case 5:
            break;
        case 0:
            return;
        default:
            listaCancionesMenu();
        }
    } while (select != 0);
}

void listaRepMenu()
{
    string selection;
    int select;

    do
    {
        cout << "Lista de reproduccion\n";
        cout << "Seleccione una opcion\n";
        cout << "1| Mostrar lista de reproduccion\n";
        cout << "2| \n";
        cout << "3| Quitar cancion de la lista\n";
        cout << "0| Regresar\n";

        getline(cin, selection);
        select = stoi(selection);

        switch (select)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 0:
            return;
        default:
            listaRepMenu();
        }
    } while (select != 0);
}

void menuPrincipal()
{
    string selection;
    int select;

    do
    {
        cout << "Proyecto Playlist CastaRito\n";
        cout << "Seleccione una opcion\n";
        cout << "1| Lista de canciones\n";
        cout << "2| Lista de reproduccion\n";
        cout << "0| Salir del programa\n";

        getline(cin, selection);
        select = stoi(selection);

        switch (select)
        {
        case 1:
            listaCancionesMenu();
            break;
        case 2:
            break;
        case 0:
            return;
        default:
            menuPrincipal();
        }
    } while (select != 0);
}

int main()
{
    menuPrincipal();

}



