#include "EnvLoader.h"
#include <fstream>
#include <cstdlib>
using namespace std;

bool cargarArchivoEnv(const string& ruta) {
    ifstream archivo(ruta);
    if (!archivo.is_open()) return false;

    string linea;
    while (getline(archivo, linea)) {
        size_t pos = linea.find('=');
        if (pos != string::npos) {
            string clave = linea.substr(0, pos);
            string valor = linea.substr(pos + 1);
            setenv(clave.c_str(), valor.c_str(), 1); // en Windows usar _putenv_s
        }
    }

    archivo.close();
    return true;
}

bool cargarVariableDeEntorno(const string& nombre, string& valor) {
    const char* val = getenv(nombre.c_str());
    if (val) {
        valor = val;
        return true;
    }
    return false;
}
