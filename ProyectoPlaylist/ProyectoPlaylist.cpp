#include <iostream>
#include "Lista.h"
#include "cancion.h" 
#include <string>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

Lista<cancion> cancionesList;


void mostrarListaDeCanciones()
{
    cancion lookatSong;
    int number;
    string display;
    if (cancionesList.GetCount() > 0) 
    {
        for (int i = 0; i < cancionesList.GetCount(); i++)
        {
            number = i + 1;
            display = to_string(number);
            lookatSong = cancionesList.GetItem(i)->data;
            cout << display + "| " + lookatSong.getTitulo() + " - " + lookatSong.getArtista() + "\n";
        }
    }
    else 
    {
        cout << "No hay canciones en la lista\n";
    }
}

void listaDelMenu() 
{
    string selection;
    int select;

    do 
    {
        cout << "\033[2J\033[1;1H";
        cout << "Eliminar cancion de la lista\n";
        cout << "canciones en la lista:\n";
        mostrarListaDeCanciones();
        cout << "----------------------------------------\n";
        cout << "Seleccione la cancion que desea elimianar\n";
        cout << "0| Regresar\n";

        getline(cin, selection);
        select = stoi(selection);

        if (select == 0) 
        {
            return;
        }

        if (select > cancionesList.GetCount())
        {
            "No se ingreso una entrada valida\n";
        }
        else 
        {
            cancionesList.RemoveAt(select - 1);
            listaDelMenu();
        }

    } while (select != 0);

    
}

void listaShowMenu() 
{
    string selection;
    int select;

    do
    {
        cout << "\033[2J\033[1;1H";
        cout << "canciones en la lista:\n";
        mostrarListaDeCanciones();
        cout << "----------------------------------------\n";
        cout << "Seleccione una opcion\n";
        cout << "1| Agregar cancion a la lista de reproduccion\n";
        cout << "2| Ordenar lista segun titulo A-Z\n";
        cout << "3| Ordenar lista segun titulo Z-A\n";
        cout << "4| Ordenar lista segun artista A-Z\n";
        cout << "5| Ordenar lista segun artista Z-A\n";
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
        case 4:
            break;
        case 5:
            break;
        case 0:
            return;
            break;
        default:
            listaShowMenu();
            break;
        }
    } while (select != 0);

}

void listaCancionesMenu()
{
    string selection;
    int select;

    do
    {
        cout << "\033[2J\033[1;1H";
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
        ifstream archivo;
        string linea;
        string posicion;
        string cancionArt;

        getline(cin, selection);
        select = stoi(selection);


        switch (select)
        {
        case 1:
            listaShowMenu();

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

            listaDelMenu();
            break;
        case 4:
            cout << "Ingrese lugar donde se encuentra el archivo" << endl;
            getline(cin, posicion);
            archivo.open(posicion, ios::in);

            while (getline(archivo, linea)) {
                stringstream stream(linea);
                getline(stream, cancionArt, ',');
                cout << cancionArt << endl;
            }
            break;
        case 5:
            break;
        case 0:
            return;
            break;
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
        cout << "\033[2J\033[1;1H";
        cout << "Lista de reproduccion\n";
        cout << "Seleccione una opcion\n";
        cout << "1| Mostrar lista de reproduccion\n";
        cout << "2| Agregar cancion a la lista de reproduccion\n";
        cout << "0| Regresar\n";

        getline(cin, selection);
        select = stoi(selection);

        switch (select)
        {
        case 1:
            break;
        case 2:
            break;
        case 0:
            return;
            break;
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
        cout << "\033[2J\033[1;1H";
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
            listaRepMenu();
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
    return 0;
}



