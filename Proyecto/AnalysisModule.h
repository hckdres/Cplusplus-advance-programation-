#ifndef ANALYSISMODULE_H
#define ANALYSISMODULE_H

#include <string>

void mostrarInfo(std::string** tabla, size_t filas, size_t columnas);
void mostrarHead(std::string** tabla, size_t filas, size_t columnas, size_t n);
void mostrarDescribe(std::string** tabla, size_t filas, size_t columnas);
void mostrarCorrelacion(std::string** tabla, size_t filas, size_t columnas);
void exportToText(const char* ruta, std::string** tabla, size_t filas, size_t columnas);
void mostrarMenu(std::string** tabla, size_t filas, size_t columnas);

#endif
