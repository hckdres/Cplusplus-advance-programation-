#include <iostream>
#include <string>
using namespace std;

const int MAX_CONTACTOS = 10; // Máximo número de contactos
const int MAX_MENSAJES = 100; // Máximo número de mensajes por contacto

struct Contacto {
    string nombre; // Nombre del contacto
    string mensajes[MAX_MENSAJES]; // Mensajes enviados
    int num_mensajes = 0; // Contador de mensajes
};

void registrarContactos(Contacto contactos[], int &numContactos);
void enviarMensajes(Contacto contactos[], int numContactos);

int main() {
    Contacto contactos[MAX_CONTACTOS]; // Arreglo de contactos
    int numContactos = 0; // Número actual de contactos

    // Registrar contactos
    registrarContactos(contactos, numContactos);

    // Enviar mensajes en turnos
    enviarMensajes(contactos, numContactos);

    cout << "Programa finalizado." << endl;
    return 0;
}

void registrarContactos(Contacto contactos[], int &numContactos) {
    cout << "Registro de contactos:\n";
    while (numContactos < MAX_CONTACTOS) {
        cout << "Ingrese el nombre del contacto " << numContactos + 1 << " (o escriba 'fin' para terminar): ";
        string nombre;
        getline(cin, nombre);

        if (nombre == "fin") {
            break; // Salir del bucle si el usuario escribe 'fin'
        }

        // Verificar si el contacto ya existe
        bool existe = false;
        for (int i = 0; i < numContactos; i++) {
            if (contactos[i].nombre == nombre) {
                existe = true;
                cout << "El contacto ya existe. Intente con otro nombre.\n";
                break;
            }
        }

        if (!existe) {
            // Registrar el contacto
            contactos[numContactos].nombre = nombre;
            numContactos++;
            cout << "Contacto registrado correctamente.\n";
        }
    }
}

void enviarMensajes(Contacto contactos[], int numContactos) {
    if (numContactos < 2) {
        cout << "Se necesitan al menos 2 contactos para enviar mensajes.\n";
        return;
    }

    int turno = 0; // Turno actual (0 para el primer contacto, 1 para el segundo, etc.)
    char opcion;

    do {
        // Mostrar el contacto actual
        cout << "\nTurno de " << contactos[turno].nombre << ":\n";

        // Pedir el mensaje
        cout << "Ingrese el mensaje: ";
        string mensaje;
        getline(cin, mensaje);

        // Almacenar el mensaje en el contacto actual
        if (contactos[turno].num_mensajes < MAX_MENSAJES) {
            contactos[turno].mensajes[contactos[turno].num_mensajes] = mensaje;
            contactos[turno].num_mensajes++;
        } else {
            cout << "No se pueden almacenar más mensajes para este contacto.\n";
        }

        // Pasar al siguiente contacto
        turno = (turno + 1) % numContactos;

        // Preguntar si desean continuar
        cout << "¿Desea continuar enviando mensajes? (s/n): ";
        cin >> opcion;
        cin.ignore(); // Limpiar el búfer de entrada
    } while (opcion == 's');

    // Mostrar todos los mensajes al final
    cout << "\nMensajes enviados:\n";
    for (int i = 0; i < numContactos; i++) {
        cout << contactos[i].nombre << ":\n";
        for (int j = 0; j < contactos[i].num_mensajes; j++) {
            cout << "  - " << contactos[i].mensajes[j] << endl;
        }
    }
}