#include "DataTransformer.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

string** leerCSV(const char* ruta, size_t& filas, size_t& columnas) {
    ifstream archivo(ruta);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo CSV." << endl;
        filas = 0;
        columnas = 0;
        return nullptr;
    }

    string linea;
    filas = 0;
    columnas = 0;

    // Contar columnas (cabecera)
    if (getline(archivo, linea)) {
        stringstream ss(linea);
        string celda;
        while (getline(ss, celda, ',')) {
            columnas++;
        }
        filas++;
    }

    // Contar filas (restantes)
    while (getline(archivo, linea)) {
        filas++;
    }

    archivo.clear();              // Reiniciar lectura
    archivo.seekg(0);             // Volver al inicio

    // Crear tabla dinámica de strings
    string** tabla = new string*[filas];
    for (size_t i = 0; i < filas; i++) {
        tabla[i] = new string[columnas];
    }

    // Rellenar la tabla
    size_t filaActual = 0;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string celda;
        size_t col = 0;

        while (getline(ss, celda, ',') && col < columnas) {
            tabla[filaActual][col] = celda;
            col++;
        }

        filaActual++;
    }

    archivo.close();
    return tabla;
}

void liberarTabla(string** tabla, size_t filas) {
    for (size_t i = 0; i < filas; i++) {
        delete[] tabla[i];
    }
    delete[] tabla;
}
