#pragma once
#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include <string>
#include "Proveedor.h"

using namespace std;

class Producto {
private:
    int idProducto;
    string nombre;
    string tipo;
    int cantidad;
    string categoria;
    int año;
    double precio;
    Proveedor* proveedor;

public:
    Producto(int idProducto, const string& nombre, const string& tipo, int cantidad, const string& categoria, int año, double precio, Proveedor* proveedor);

    // Getters
    int getIdProducto() const;
    string getNombre() const;
    string getTipo() const;
    int getCantidad() const;
    string getCategoria() const;
    int getAño() const;
    double getPrecio() const;
    Proveedor* getProveedor() const;

    // Setters
    void setIdProducto(int idProducto);
    void setNombre(const string& nombre);
    void setTipo(const string& tipo);
    void setCantidad(int cantidad);
    void setCategoria(const string& categoria);
    void setAño(int año);
    void setPrecio(double precio);
    void setProveedor(Proveedor* proveedor);

    void mostrarInformacion() const;
};

#endif

