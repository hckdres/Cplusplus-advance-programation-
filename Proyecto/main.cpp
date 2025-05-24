#include <iostream>
#include <chrono>
#include <limits>
#include "DataTransformer.h"
#include "AnalysisModule.h"
#include "ConversionModule.h"
using namespace std;
using namespace std::chrono;

// Función helper para pausar hasta Enter
void pausa() {
    cout << "\nPresiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    size_t filas, columnas;

    // 1) Extracción / Carga CSV
    auto t1 = high_resolution_clock::now();
    string** tabla = leerCSV("Admission_Predict.csv", filas, columnas);
    auto t2 = high_resolution_clock::now();
    if (!tabla) return 1;
    cout << "\nCSV cargado en "
         << duration_cast<milliseconds>(t2 - t1).count()
         << " ms.\n";
    pausa();

    // 2) Transformación / Análisis interactivo
    mostrarMenu(tabla, filas, columnas);
    pausa();

    // 3) Guardar estadísticas en TXT
    auto t3 = high_resolution_clock::now();
    exportToText("data/transformacion_resultados.txt", tabla, filas, columnas);
    auto t4 = high_resolution_clock::now();
    cout << "\nEstadísticas guardadas en "
         << duration_cast<milliseconds>(t4 - t3).count()
         << " ms.\n";
    pausa();

    // 4) Conversión a Student y escritura binaria
    size_t cantidad;
    Student* lista = convertirTablaAEstudiantes(tabla, filas, cantidad);
    auto t5 = high_resolution_clock::now();
    guardarBinario("data/Admission_Predict_new.bin", lista, cantidad);
    auto t6 = high_resolution_clock::now();
    cout << "\nBinario generado en "
         << duration_cast<milliseconds>(t6 - t5).count()
         << " ms.\n";
    pausa();

    // 5) Lectura y visualización del binario (head/tail manual)
    // Volvemos a cargar los datos desde el CSV para simular lectura
    size_t filas2, columnas2;
    string** tabla2 = leerCSV("Admission_Predict.csv", filas2, columnas2);
    size_t cantidad2;
    Student* lista2 = convertirTablaAEstudiantes(tabla2, filas2, cantidad2);

    cout << "\nPrimeros 5 registros del binario:\n";
    for (size_t i = 0; i < 5 && i < cantidad2; ++i) {
        cout << "[" << i << "] id=" << lista2[i].id
             << ", chance=" << lista2[i].chance << "\n";
    }
    cout << "\nÚltimos 5 registros del binario:\n";
    for (size_t i = (cantidad2>5? cantidad2-5:0); i < cantidad2; ++i) {
        cout << "[" << i << "] id=" << lista2[i].id
             << ", chance=" << lista2[i].chance << "\n";
    }
    pausa();

    // 6) Liberar memoria y terminar
    delete[] lista;
    delete[] lista2;
    liberarTabla(tabla, filas);
    liberarTabla(tabla2, filas2);

    cout << "\nPipeline completado correctamente.\n";
    return 0;
}
