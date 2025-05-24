// AnalysisModule.cpp
#include "AnalysisModule.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

// Función auxiliar: ¿es número?
static bool esNumero(const string& s) {
    char* end;
    strtod(s.c_str(), &end);
    return *end=='\0';
}

// Detecta índices de columnas numéricas
static size_t* obtenerColumnasNumericas(string** tabla, size_t filas, size_t columnas, size_t& outCount) {
    size_t* nums = new size_t[columnas];
    outCount = 0;
    if (filas < 2) return nums;
    for (size_t j = 0; j < columnas; ++j) {
        if (esNumero(tabla[1][j])) nums[outCount++] = j;
    }
    return nums;
}

void mostrarInfo(string** tabla, size_t filas, size_t columnas) {
    cout << "Filas: " << filas << ", Columnas: " << columnas << "\nEncabezados:\n";
    for (size_t j = 0; j < columnas; ++j)
        cout << "- " << tabla[0][j] << "\n";
}

void mostrarHead(string** tabla, size_t filas, size_t columnas, size_t n) {
    for (size_t i = 0; i < n && i < filas; ++i) {
        for (size_t j = 0; j < columnas; ++j)
            cout << tabla[i][j] << (j+1<columnas?", ": "\n");
    }
}

void mostrarDescribe(string** tabla, size_t filas, size_t columnas) {
    size_t numCount;
    size_t* nums = obtenerColumnasNumericas(tabla, filas, columnas, numCount);
    cout << "\nDESCRIBE (solo numéricas):\n";
    for (size_t k = 0; k < numCount; ++k) {
        size_t idx = nums[k];
        double sum=0, sum2=0, minv=0, maxv=0;
        size_t cnt=0; bool first=true;
        for (size_t i = 1; i < filas; ++i) {
            double v = atof(tabla[i][idx].c_str());
            if (first) { minv=maxv=v; first=false; }
            minv = min(minv, v);
            maxv = max(maxv, v);
            sum += v; sum2 += v*v; cnt++;
        }
        double mean = sum/cnt;
        double var = (sum2/cnt) - mean*mean;
        double stdv = sqrt(var);
        cout << tabla[0][idx]
             << ": mean="<<mean
             <<", std="<<stdv
             <<", min="<<minv
             <<", max="<<maxv<<"\n";
    }
    delete[] nums;
}

void mostrarCorrelacion(string** tabla, size_t filas, size_t columnas) {
    size_t numCount;
    size_t* nums = obtenerColumnasNumericas(tabla, filas, columnas, numCount);
    cout << "\nCORRELACION (solo numéricas):\n";
    // cabecera
    for (size_t k=0;k<numCount;++k)
        cout<<tabla[0][nums[k]]<<(k+1<numCount?", ": "\n");
    size_t n=filas-1;
    for (size_t a=0;a<numCount;++a) {
        for (size_t b=0;b<numCount;++b) {
            double sumA=0,sumB=0,sumAB=0,sumA2=0,sumB2=0;
            for (size_t i=1;i<filas;++i) {
                double x=atof(tabla[i][nums[a]].c_str());
                double y=atof(tabla[i][nums[b]].c_str());
                sumA+=x; sumB+=y; sumAB+=x*y; sumA2+=x*x; sumB2+=y*y;
            }
            double num = n*sumAB - sumA*sumB;
            double den = sqrt((n*sumA2 - sumA*sumA)*(n*sumB2 - sumB*sumB));
            double corr = den? num/den : 0;
            cout << corr << (b + 1 < numCount ? ", " : "\n");

        }
    }
    delete[] nums;
}

void exportToText(const char* ruta, string** tabla, size_t filas, size_t columnas) {
    // redirige cout a archivo
    ofstream out(ruta);
    auto old = cout.rdbuf(out.rdbuf());
    mostrarDescribe(tabla, filas, columnas);
    mostrarCorrelacion(tabla, filas, columnas);
    cout.rdbuf(old);
    out.close();
}

void mostrarMenu(string** tabla, size_t filas, size_t columnas) {
    int op;
    do {
        cout<<"\n1) Info\n2) Head\n3) Describe\n4) Correlacion\n5) Salir\nOpcion: ";
        cin>>op;
        if(op==1)mostrarInfo(tabla,filas,columnas);
        else if(op==2){ size_t n; cout<<"Cuantas filas? ";cin>>n; mostrarHead(tabla,filas,columnas,n); }
        else if(op==3)mostrarDescribe(tabla,filas,columnas);
        else if(op==4)mostrarCorrelacion(tabla,filas,columnas);
    } while(op!=5);
}
