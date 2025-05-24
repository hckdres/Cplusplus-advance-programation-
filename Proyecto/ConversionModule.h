#ifndef CONVERSIONMODULE_H
#define CONVERSIONMODULE_H

#include <cstddef>
#include <string>

struct Student {
    size_t id;
    int gre, toefl, rating;
    double sop, lor, cgpa, chance;
    bool research;
};

Student* convertirTablaAEstudiantes(std::string** tabla, size_t filas, size_t& cantidad);
void guardarBinario(const char* ruta, Student* lista, size_t cantidad);

#endif
