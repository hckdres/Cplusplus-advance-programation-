#ifndef ENVLOADER_H
#define ENVLOADER_H

#include <string>

bool cargarVariableDeEntorno(const std::string& nombre, std::string& valor);
bool cargarArchivoEnv(const std::string& ruta);

#endif
