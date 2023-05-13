#include <iostream>
#include <fstream>
#include <filesystem>
#include <windows.h>
using namespace std;
void crearArchivos(int cantidad);
int contarArchivosDeDirectorio();
void listarArchivosDeDirectorio();
void mostrarDetallesArchivos();



int main() {
    int cantidad;
    cout << "Cuantos archivos quiere crear \n";
    cin >> cantidad;

    crearArchivos(cantidad);

    cout << contarArchivosDeDirectorio();
    cout << endl;

    listarArchivosDeDirectorio();
    mostrarDetallesArchivos();

    return 0;
}

void crearArchivos(int cantidad) {
    string nombreArchivo="archivo";
    int i= cantidad;
    if (cantidad%2==0){
        cout<<"Hola elegiste un numero de archivos par saludos: " + to_string(i);

    }
    else{
        ofstream file;
        file.open("C:\\Users\\ROn\\IMAGENES\\Recuperacion2//" + nombreArchivo + to_string(i) +".txt");
        file << "primera línea\n";
        file << "segunda línea\n";
        file << "tercera línea\n";
        file.close();
        cout<<"Archivos creados : " + to_string(i);

    }

}
void listarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    hFind = FindFirstFile("C:\\Users\\Ron\\IMAGENES\\recuperacion2//", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "La ruta es incorrecta";
    else
    {
        cout << findFileData.cFileName << '\n';

        while (FindNextFile(hFind, &findFileData) != 0)
            cout << findFileData.cFileName << '\n';
    }
}

int contarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadDeArchivos=0;
    hFind = FindFirstFile("C:\\Users\\Ron\\IMAGENES\\recuperacion2//", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "Ruta incorrecta";
    else
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadDeArchivos=cantidadDeArchivos+1;
        }
    return cantidadDeArchivos-1;
}

void mostrarDetallesArchivos() {
    std::filesystem::directory_iterator directoryIterator("C:\\Users\\ron\\IMAGENES\\recuperacion2//");
    for (const auto &entry: directoryIterator) {
        if (!std::filesystem::is_directory(entry.status())) {
            std::cout << entry.path().filename() << " "
                      << file_size(entry.path()) << std::endl;
        }

    }
}



