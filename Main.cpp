#include <iostream>
#include <vector>
#include "Proveedor.h"
#include "Producto.h"

using namespace std;

int main() {
    vector<Proveedor> proveedores;
    vector<Producto> productos;

    int opcion;

    do {
        // Mostrar el menú
        cout << "\nMENU\n";
        cout << "1. Insertar producto\n";
        cout << "2. Insertar proveedor\n";
        cout << "3. Modificar Producto\n";
        cout << "4. Eliminar productos vencidos\n";
        cout << "5. Reportes\n";
        cout << "6. Salir\n";
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // Insertar un nuevo producto
        {
            int idProducto;
            string nombre;
            string tipo;
            int cantidad;
            string categoria;
            int año;
            double precio;
            int proveedorIndex;

            // Solicitar los datos del producto al usuario
            cout << "Ingrese el ID del producto: "; cin >> idProducto; cin.ignore(); // Limpiar el buffer del newline
            cout << "Ingrese el nombre del producto: "; getline(cin, nombre);
            cout << "Ingrese el tipo del producto (polvo o liquido): "; cin >> tipo;
            cout << "Ingrese la cantidad del producto: "; cin >> cantidad;
            cout << "Ingrese la categoria del producto (A, B o C): "; cin >> categoria;
            cout << "Ingrese el anio del producto: "; cin >> año;
            cout << "Ingrese el precio del producto: "; cin >> precio;

            // Mostrar los proveedores existentes
            cout << "Proveedores disponibles:\n";
            for (size_t i = 0; i < proveedores.size(); ++i) {
                cout << i << ". " << proveedores[i].getRazonSocial() << endl;
            }

            // Seleccionar el proveedor para el producto
            cout << "Ingrese el índice del proveedor para este producto: "; cin >> proveedorIndex;

            if (proveedorIndex >= 0 && proveedorIndex < proveedores.size()) {
                Producto nuevoProducto(idProducto, nombre, tipo, cantidad, categoria, año, precio, &proveedores[proveedorIndex]);
                productos.push_back(nuevoProducto);
                cout << "Producto agregado exitosamente.\n";
            }
            else {
                cout << "Índice de proveedor inválido.\n";
            }
        }
            break;

        case 2:
            // Insertar un nuevo proveedor
        {
            string ruc;
            string razonSocial;
            string categoria;
            string direccion;
            string telefono;

            // Solicitar los datos del proveedor al usuario
            cout << "Ingrese el RUC del proveedor: "; cin >> ruc;
            cin.ignore(); // Limpiar el buffer del newline
            cout << "Ingrese la razón social del proveedor: ";
            getline(cin, razonSocial);
            cout << "Ingrese la categoría del proveedor: "; cin >> categoria;
            cin.ignore(); // Limpiar el buffer del newline
            cout << "Ingrese la direccion del proveedor: ";
            getline(cin, direccion);
            cout << "Ingrese el telefono del proveedor: "; cin >> telefono;

            Proveedor nuevoProveedor(ruc, razonSocial, categoria, direccion, telefono);
            proveedores.push_back(nuevoProveedor);

            cout << "Proveedor agregado exitosamente.\n";
        }
            break;

        case 3:
            // Lógica para modificar un producto existente
        {
            int productoIndex;

            // Mostrar los productos existentes
            cout << "Productos existentes:\n";
            for (size_t i = 0; i < productos.size(); ++i) {
                cout << i << ". " << productos[i].getNombre() << endl;
            }

            // Seleccionar el producto a modificar
            cout << "Ingrese el indice del producto a modificar: "; cin >> productoIndex;

            if (productoIndex >= 0 && productoIndex < productos.size()) {
                Producto& productoModificar = productos[productoIndex];

                // Solicitar los nuevos datos del producto al usuario
                string nuevoNombre;
                string nuevoTipo;
                int nuevaCantidad;
                string nuevaCategoria;
                int nuevoAño;
                double nuevoPrecio;

                cin.ignore(); // Limpiar el buffer del newline
                cout << "Ingrese el nuevo nombre del producto: "; getline(cin, nuevoNombre);
                cout << "Ingrese el nuevo tipo del producto (polvo o líquido): "; cin >> nuevoTipo;
                cout << "Ingrese la nueva cantidad del producto: "; cin >> nuevaCantidad;
                cout << "Ingrese la nueva categoría del producto (A, B o C): "; cin >> nuevaCategoria;
                cout << "Ingrese el nuevo año del producto: "; cin >> nuevoAño;
                cout << "Ingrese el nuevo precio del producto: "; cin >> nuevoPrecio;

                productoModificar.setNombre(nuevoNombre);
                productoModificar.setTipo(nuevoTipo);
                productoModificar.setCantidad(nuevaCantidad);
                productoModificar.setCategoria(nuevaCategoria);
                productoModificar.setAño(nuevoAño);
                productoModificar.setPrecio(nuevoPrecio);

                cout << "Producto modificado exitosamente.\n";
            }
            else {
                cout << "Indice de producto invalido.\n";
            }
        }
            break;

        case 4:
            // Eliminar productos vencidos
        {
            int añoActual = 2024; // Para obtener el año actual

            // Contador para llevar un registro de productos eliminados
            int productosEliminados = 0;

            for (auto it = productos.begin(); it != productos.end(); ) {
                if (it->getAño() < añoActual) {
                    it = productos.erase(it); // Eliminar producto vencido
                    ++productosEliminados;
                }
                else {
                    ++it;
                }
            }

            cout << productosEliminados << " productos vencidos eliminados.\n";
        }
            break;

        case 5:
            // Lógica para mostrar reportes
        {
            cout << "Reporte de productos en stock:\n";

            for (const auto& producto : productos) {
                if (producto.getCantidad() > 0) {
                    cout << "Nombre: " << producto.getNombre() << "\n";
                    cout << "Tipo: " << producto.getTipo() << "\n";
                    cout << "Cantidad: " << producto.getCantidad() << "\n";
                    cout << "Categoría: " << producto.getCategoria() << "\n";
                    cout << "Año: " << producto.getAño() << "\n";
                    cout << "Precio: " << producto.getPrecio() << "\n";
                    cout << "Proveedor: " << producto.getProveedor()->getRazonSocial() << "\n";
                    cout << "------------------------------------\n";
                }
            }

            cout << "Fin del reporte.\n";
        }
            break;

        case 6:
            cout << "Saliendo del programa. ¡Hasta luego!\n";
            break;

        default:
            cout << "Opcion invalida. Por favor, ingrese una opcion valida.\n";
        }
    } while (opcion != 6);

    return 0;
}
