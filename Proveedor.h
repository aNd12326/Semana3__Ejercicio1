#pragma once
#ifndef PROVEEDOR_HPP
#define PROVEEDOR_HPP

#include <string>

using namespace std;

class Proveedor {
private:
    string ruc;
    string razonSocial;
    string categoria;
    string direccion;
    string telefono;

public://constructor con 5 parametros de tipos const string&:

    /*Los parámetros se pasan como referencias constantes (const string&) para evitar realizar copias innecesarias de los valores
    de cadena al llamar al constructor, lo que puede ser más eficiente en términos de rendimiento y uso de memoria.*/
    
    /*Proveedor proveedor1("123456789", "Empresa ABC", "A", "Calle 123", "987654321");
    Este código crea un nuevo objeto Proveedor llamado proveedor1 y lo inicializa con los valores proporcionados.
    El constructor se encarga de asignar estos valores a los miembros de datos ruc, razonSocial, categoria, direccion y
    telefono del objeto proveedor1.*/
    
    // constructor
    Proveedor(const string& ruc, 
              const string& razonSocial, 
              const string& categoria, 
              const string& direccion, 
              const string& telefono);

    // Getters
    string getRuc() const;
    string getRazonSocial() const;
    string getCategoria() const;
    string getDireccion() const;
    string getTelefono() const;

    // Setters
    void setRuc(const string& ruc);
    void setRazonSocial(const string& razonSocial);
    void setCategoria(const string& categoria);
    void setDireccion(const string& direccion);
    void setTelefono(const string& telefono);

    void mostrarInformacion() const;//metodos
};

#endif

