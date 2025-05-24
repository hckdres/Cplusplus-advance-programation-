// ConversionModule.cpp
#include "ConversionModule.h"
#include <fstream>
#include <iostream>
using namespace std;

// Convierte cada fila del CSV (sin cabecera) a Student[]
Student* convertirTablaAEstudiantes(string** tabla, size_t filas, size_t& cantidad) {
    cantidad = filas - 1;  // quitamos la cabecera
    Student* lista = new Student[cantidad];
    for (size_t i = 1; i < filas; ++i) {
        Student& s = lista[i - 1];
        s.id       = stoi(tabla[i][0]);
        s.gre      = stoi(tabla[i][1]);
        s.toefl    = stoi(tabla[i][2]);
        s.rating   = stoi(tabla[i][3]);
        s.sop      = atof(tabla[i][4].c_str());
        s.lor      = atof(tabla[i][5].c_str());
        s.cgpa     = atof(tabla[i][6].c_str());
        s.research = stoi(tabla[i][7]) != 0;
        s.chance   = atof(tabla[i][8].c_str());
    }
    return lista;
}

// Escribe lista de Student en binario: [cantidad][Student0][Student1]...
void guardarBinario(const char* ruta, Student* lista, size_t cantidad) {
    ofstream archivo(ruta, ios::binary);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el binario." << endl;
        return;
    }
    archivo.write(reinterpret_cast<const char*>(&cantidad), sizeof(size_t));
    archivo.write(reinterpret_cast<const char*>(lista), sizeof(Student) * cantidad);
    archivo.close();
}
