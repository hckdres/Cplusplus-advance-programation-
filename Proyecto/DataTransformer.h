#ifndef DATATRANSFORMER_H
#define DATATRANSFORMER_H

#include <string>

// Lee el archivo CSV y devuelve una tabla dinámica (filas x columnas)
std::string** leerCSV(const char* ruta, size_t& filas, size_t& columnas);

// Libera la memoria reservada para la tabla
void liberarTabla(std::string** tabla, size_t filas);

#endif
