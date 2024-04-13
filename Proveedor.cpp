#include "Proveedor.h"
#include <iostream>

using namespace std;

Proveedor::Proveedor(const string& ruc, 
                    const string& razonSocial, 
                    const string& categoria, 
                    const string& direccion, 
                    const string& telefono)
                    : ruc(ruc), 
                    razonSocial(razonSocial), 
                    categoria(categoria), 
                    direccion(direccion), 
                    telefono(telefono) {}

string Proveedor::getRuc() const {
    return ruc;
}

string Proveedor::getRazonSocial() const {
    return razonSocial;
}

string Proveedor::getCategoria() const {
    return categoria;
}

string Proveedor::getDireccion() const {
    return direccion;
}

string Proveedor::getTelefono() const {
    return telefono;
}

void Proveedor::setRuc(const string& newRuc) {
    ruc = newRuc;
}

void Proveedor::setRazonSocial(const string& newRazonSocial) {
    razonSocial = newRazonSocial;
}

void Proveedor::setCategoria(const string& newCategoria) {
    categoria = newCategoria;
}

void Proveedor::setDireccion(const string& newDireccion) {
    direccion = newDireccion;
}

void Proveedor::setTelefono(const string& newTelefono) {
    telefono = newTelefono;
}

void Proveedor::mostrarInformacion() const {
    cout << "RUC: " << ruc << "\nRazon Social: " << razonSocial << "\nCategoria: " << categoria << "\nDireccion: " << direccion << "\nTelefono: " << telefono << endl;
}
