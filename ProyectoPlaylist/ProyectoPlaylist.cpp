#include <iostream>
#include "Lista.h"
#include "cancion.h" 
#include "Stack.h"
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

Lista<cancion> cancionesList;
Stack<cancion> repList;
Stack<cancion> histRepList;
cancion reproduciendo;
int playNum = 0;

void listaShowMenu();
void menuPrincipal();
void listaCancionesMenu();
void GuardarFile();
void LeerFile();

void ordenarListaDesconocidos()
{
    int i, j, min_idx;
    cancion tmp;
    int n = cancionesList.GetCount();

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (cancionesList.GetItem(j)->data.getArtista() != "Desconocido")
            {
                min_idx = j;
            }
        }
        tmp = cancionesList.GetItem(min_idx)->data;
        cancionesList.GetItem(min_idx)->data = cancionesList.GetItem(i)->data;
        cancionesList.GetItem(i)->data = tmp;
    }
}

void ordenarListaPorTituloAZ() 
{
    ordenarListaDesconocidos();
    int i, j, min_idx;
    cancion tmp;
    int n = cancionesList.GetCount();

    for (i = 0; i < n - 1; i++) 
    {
        min_idx = i;
        for (j = i + 1; j < n; j++) 
        {
            if (cancionesList.GetItem(j)->data.getTitulo().compare(cancionesList.GetItem(min_idx)->data.getTitulo()) < 0 && cancionesList.GetItem(j)->data.getArtista() != "Desconocido")
            {
                min_idx = j;
            }
        }
        tmp = cancionesList.GetItem(min_idx)->data;
        cancionesList.GetItem(min_idx)->data = cancionesList.GetItem(i)->data;
        cancionesList.GetItem(i)->data = tmp;
    }
}

void ordenarListaPorTituloZA()
{
    ordenarListaDesconocidos();
    int i, j, min_idx;
    cancion tmp;
    int n = cancionesList.GetCount();

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (cancionesList.GetItem(j)->data.getTitulo().compare(cancionesList.GetItem(min_idx)->data.getTitulo()) > 0 && cancionesList.GetItem(j)->data.getArtista() != "Desconocido")
            {
                min_idx = j;
            }
        }
        tmp = cancionesList.GetItem(min_idx)->data;
        cancionesList.GetItem(min_idx)->data = cancionesList.GetItem(i)->data;
        cancionesList.GetItem(i)->data = tmp;
    }
}

void ordenarListaPorArtistaAZ()
{
    ordenarListaDesconocidos();
    int i, j, min_idx;
    cancion tmp;
    int n = cancionesList.GetCount();

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (cancionesList.GetItem(j)->data.getArtista().compare(cancionesList.GetItem(min_idx)->data.getArtista()) < 0 && cancionesList.GetItem(j)->data.getArtista() != "Desconocido")
            {
                min_idx = j;
            }
        }
        tmp = cancionesList.GetItem(min_idx)->data;
        cancionesList.GetItem(min_idx)->data = cancionesList.GetItem(i)->data;
        cancionesList.GetItem(i)->data = tmp;
    }
}

void ordenarListaPorArtistaZA()
{
    ordenarListaDesconocidos();
    int i, j, min_idx;
    cancion tmp;
    int n = cancionesList.GetCount();

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (cancionesList.GetItem(j)->data.getArtista().compare(cancionesList.GetItem(min_idx)->data.getArtista()) > 0 && cancionesList.GetItem(j)->data.getArtista() != "Desconocido")
            {
                min_idx = j;
            }
        }
        tmp = cancionesList.GetItem(min_idx)->data;
        cancionesList.GetItem(min_idx)->data = cancionesList.GetItem(i)->data;
        cancionesList.GetItem(i)->data = tmp;
    }
}

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
        return;
    }
    else 
    {
        cout << "No hay canciones en la lista\n";
        return;
    }
}

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
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

        if (is_number(selection)) 
        {
            select = stoi(selection);
        }
        else { select = 100000000; }

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
    listaShowMenu();

    
}

void listaShowMenu() 
{
    string selection, songSelection;
    int select, songSelect;

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

        if (is_number(selection))
        {
            select = stoi(selection);
        }
        else { select = 100000000; }

        switch (select) 
        {
        case 1:

            cout << "Ingrese la cancion que desea agregar a la lista de reproduccion\n";

            getline(cin, songSelection);

            if (is_number(songSelection))
            {
                songSelect = stoi(songSelection);
            }
            else { songSelect = 100000000; }

            if (songSelect > cancionesList.GetCount() || songSelect == 0)
            {
                "No se ingreso una entrada valida\n";
            }
            else
            {
                repList.push(cancionesList.GetItem(songSelect - 1)->data);
                listaShowMenu();
            }
            break;
        case 2: 
            ordenarListaPorTituloAZ();
            listaShowMenu();
            break;
        case 3:
            ordenarListaPorTituloZA();
            listaShowMenu();
            break;
        case 4:
            ordenarListaPorArtistaAZ();
            listaShowMenu();
            break;
        case 5:
            ordenarListaPorArtistaZA();
            listaShowMenu();
            break;
        case 0:
            listaCancionesMenu();
            return;
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
        
        if (is_number(selection))
        {
            select = stoi(selection);
        }
        else { select = 100000000; }

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
            LeerFile();
            break;
        case 5:
            GuardarFile();
            break;
        case 0:
            menuPrincipal();
            return;
            break;
        default:
            listaCancionesMenu();
        }
    } while (select != 0);
}

void GuardarFile() {
    string posarchiv;
    cout << "Ingrese lugar donde desea guardar el archivo" << endl;
    getline(cin, posarchiv);
    ofstream archivo;
    archivo.open(posarchiv, ios::out);
    if (archivo.fail()) {
        cout << "no se puede crear archivo" << endl;
    }
    for (int i = 0; i < cancionesList.GetCount(); i++) {
        archivo << cancionesList.GetItem(i)->data.getTitulo() << "-" << cancionesList.GetItem(i)->data.getArtista() << endl;
    }
    archivo.close();
}

void LeerFile() {
    ifstream archivo;
    string linea;
    string posarchiv;
    string cancionArt;
    
    const char* ptr;
    

    system("cls");
    cancionesList.Clear();
    cout << "Ingrese lugar donde se encuentra el archivo" << endl;
    getline(cin, posarchiv);
    if (posarchiv == "")
    {
        cout << "No ingreso correctamente la posicion del archivo que quiere leer, vuelva a intentarlo \n" << endl;
    }
    else {
        archivo.open(posarchiv, ios::in);
        cout << "-----------------------------------" << endl;
        cout << "---------------Lista---------------" << endl;

        while (getline(archivo, linea)) {
            stringstream stream(linea);
            getline(stream, cancionArt, ',');
            cout << cancionArt << endl;
            string delm1 = "-";
            size_t pos = 0;
            string token;
            while ((pos = cancionArt.find(delm1)) != string::npos) {
                token = cancionArt.substr(0, pos);
                cancionArt.erase(0, pos + delm1.length());
                string nombre = token;
                string artsts = cancionArt;
                cancion añadir = cancion(nombre, artsts);
                cancionesList.Add(añadir);
            }
            
            
        }
        cout << "----------------------------------" << endl;
        archivo.close();
    }
}


void listaRepMenu()
{
    string selection;
    int select;

    do
    {
        cout << "\033[2J\033[1;1H";
        cout << "Lista de reproduccion\n";
        if (reproduciendo.getTitulo() == "")
        {
            cout << "---------------------------------\n";
            cout << "No se esta reproduciendo ninguna cancion\n";
            cout << "---------------------------------\n";
        }
        else
        {
            cout << "---------------------------------\n";
            cout << "Reproduciendo: " + reproduciendo.getTitulo() + " - " + reproduciendo.getArtista() + "\n";
            cout << "---------------------------------\n";
        }
        if (repList.get_size() == 0) 
        {
            cout << "---------------------------------\n";
            cout << ">> No hay mas canciones despues de esta\n";
            cout << "---------------------------------\n";
        }
        else 
        {
            cout << "---------------------------------\n";
            cout << ">> Siguiente cancion: " + repList.peek().getTitulo() + " - " + repList.peek().getArtista() + "\n";
            cout << "---------------------------------\n";
        }
        if (histRepList.get_size() == 0)
        {
            cout << "---------------------------------\n";
            cout << "<< No hay mas canciones antes de esta\n";
            cout << "---------------------------------\n";
        }
        else
        {
            cout << "---------------------------------\n";
            cout << "<< Cancion anterior: " + histRepList.peek().getTitulo() + " - " + histRepList.peek().getArtista() + "\n";
            cout << "---------------------------------\n";
        }
        cout << "Seleccione una opcion\n";
        cout << "1| Reproducir siguiente cancion\n";
        cout << "2| Reproducir cancion anterior\n";
        cout << "0| Regresar\n";

        getline(cin, selection);

        if (is_number(selection))
        {
            select = stoi(selection);
        }
        else { select = 100000000; }

        cancion canciontmp;

        if (selection == "")
        {
            select = 10;
        }

        switch (select)
        {
        case 1:

            if (repList.get_size() == 0) 
            {
                reproduciendo.setTitulo("");
            }
            else 
            {
                if (playNum > 0) 
                {
                    canciontmp = repList.pop();
                    histRepList.push(reproduciendo);
                    reproduciendo = canciontmp;
                    playNum++;
                }
                else 
                {
                    canciontmp = repList.pop();
                    reproduciendo = canciontmp;
                    playNum++;
                }
            }
            listaRepMenu();
            break;
        case 2:

            if (histRepList.get_size() == 0)
            {
                reproduciendo.setTitulo("");
            }
            else
            {
                canciontmp = histRepList.pop();
                repList.push(reproduciendo);
                reproduciendo = canciontmp;
                if (playNum != 0) 
                {
                    playNum--;
                }
            }
            listaRepMenu();
            break;
        case 0:
            menuPrincipal();
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
        
        if (is_number(selection))
        {
            select = stoi(selection);
        }
        else { select = 100000000; }

        if (selection == "") 
        {
            select = 10;
        }

        switch (select)
        {
        case 1:
            listaCancionesMenu();
            break;
        case 2:
            listaRepMenu();
            break;
        case 0:
            exit(0);
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



