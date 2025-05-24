# Proyecto ETL en C++ - Pipeline de Transformación de Datos

Este documento describe detalladamente la implementación del pipeline ETL realizado en C++ durante la primera entrega del proyecto. Se desarrolla un flujo secuencial que incluye extracción local (desde archivo CSV), transformación de los datos con análisis estadístico, y carga en formato binario estructurado. Todo se implementa sin vectores ni librerías modernas, siguiendo el enfoque de arreglos dinámicos y punteros.

### Integrantes
```
- Juan Baez Parra
- Juliana Aguirre
- Juan Diego Funeme
- Andres Cortes
```

---

## Estructura del Proyecto

```
cpp/
├── Admission_Predict.csv         # Archivo fuente de datos en formato CSV
├── AnalysisModule.h/.cpp         # Análisis de datos: info, head, describe, correlación y exportación a TXT
├── ConversionModule.h/.cpp       # Conversión de tabla a estructuras Student y escritura binaria
├── DataTransformer.h/.cpp        # Lectura del CSV a matriz dinámica (string**)
├── EnvLoader.h/.cpp              # (Opcional) Carga de variables de entorno desde archivo .env para uso SFTP
├── main.cpp                      # Flujo principal del programa
├── pipeline                      # Ejecutable generado tras la compilación
├── README.md                     # Documento de descripción y guía del pipeline
```

---

## 1. Carga del Archivo CSV (Extracción local)

* Se utiliza la función `leerCSV()` para cargar el archivo `Admission_Predict.csv` desde el directorio de trabajo.
* El contenido se convierte en una matriz de strings (`string**`) y se registran el número de filas y columnas.
* Se mide el tiempo de carga utilizando `std::chrono`.

**Ejemplo de código:**

```cpp
auto t1 = high_resolution_clock::now();
string** tabla = leerCSV("Admission_Predict.csv", filas, columnas);
auto t2 = high_resolution_clock::now();
```

---

## 2. Transformación: Análisis Interactivo

Se ofrece un menú que permite al usuario interactuar con los datos cargados:

### Opciones del menú:

1. **Info:** Muestra filas, columnas y nombres de columnas.
2. **Head:** Imprime las primeras `n` filas de la tabla.
3. **Describe:** Calcula para cada columna numérica:

   * Media
   * Desviación estándar
   * Mínimo y Máximo
4. **Correlación:** Muestra una matriz de correlación entre columnas numéricas utilizando la fórmula de Pearson.

   * Los valores se muestran con 4 decimales, excepto si son exactamente 0, donde se imprime solo "0".

**Ejemplo:**

```
CORRELACION (solo numéricas):
GRE Score, TOEFL Score, CGPA
1.0000, 0.8324, 0.7821
0.8324, 1.0000, 0.7456
0.7821, 0.7456, 1
```

---

## 3. Guardado del Análisis en Archivo de Texto

Se exportan los resultados de `describe` y `correlación` a un archivo llamado `data/transformacion_resultados.txt`.

**Módulo:** `exportToText()` redirige temporalmente `cout` a un archivo `ofstream`.

**Ubicación del archivo:** `data/transformacion_resultados.txt`

---

## 4. Conversión y Escritura Binaria

* Se convierte cada fila de la tabla (excepto la cabecera) a una estructura `Student`, que contiene:

  ```cpp
  struct Student {
    size_t id;
    int gre, toefl, rating;
    double sop, lor, cgpa, chance;
    bool research;
  };
  ```

* Se guarda la información en formato binario:

  * Encabezado: número de registros (`size_t`)
  * Registros: arreglo binario de estructuras `Student`

**Archivo generado:** `data/Admission_Predict_new.bin`

---

## 5. Validación de la Escritura

Para validar la carga del archivo binario:

* Se vuelve a usar la función de conversión y se muestran los primeros y últimos 5 registros.

**Ejemplo de salida:**

```
[0] id=1, chance=0.92
[1] id=2, chance=0.76
...
[395] id=400, chance=0.94
```

---

## 6. Medición de Tiempos y Pausas

Todas las etapas críticas del pipeline miden su duración con `std::chrono`. Además, el programa espera al usuario con un mensaje "Presiona Enter para continuar..." después de cada etapa.

Esto facilita la inspección de resultados en consola antes de avanzar a la siguiente fase.

---

## 7. Características del Proyecto

* **Modularidad:** Cada etapa (lectura, análisis, conversión, binario) está implementada en su propio archivo.
* **Sin vectores:** Se utilizan arreglos dinámicos (con `new[]` y `delete[]`) para todo manejo de colecciones.
* **Formato estricto:** El binario cumple con el orden y tipo de campos solicitados.
* **Compatible con C++11**

---

## Pendiente / Opcional

* **Extracción SFTP**: no se implementó en esta entrega (por decisión del estudiante). Para incluirla, se deben utilizar los módulos `EnvLoader` y `SFTPClient`, junto con `libcurl`.

---

## Entregables

* `data/transformacion_resultados.txt`
* `data/Admission_Predict_new.bin`

Ambos archivos se generan correctamente siguiendo el formato exigido por la guía del proyecto.

---

### 🌟 Proyecto completado correctamente

