// Listar productos del carrito
void listarCarrito(Usuario* usuarioActual) {
    CarritoDeCompras* carritoUsuario = NULL;
    
    for (int i = 0; i < carritos.size(); i++) {
        if (carritos[i].usuario.idUsuario == usuarioActual->idUsuario) {
            carritoUsuario = &carritos[i];
            break;
        }
    }
    
    if (carritoUsuario == NULL) {
        cout << "No tiene productos en el carrito" << endl;
        return;
    }
    
    cout << "\n=== CARRITO DE COMPRAS ===" << endl;
    cout << "ID Carrito: " << carritoUsuario->idCarrito << endl;
    
    for (int i = 0; i < carritoUsuario->productos.size(); i++) {
        cout << "- " << carritoUsuario->productos[i].nombre << " | $" << carritoUsuario->productos[i].precio << endl;
    }
    
    cout << "Subtotal: $" << carritoUsuario->subtotal << endl;
    cout << "Impuestos: $" << carritoUsuario->impuestos << endl;
    cout << "Total: $" << carritoUsuario->subtotal + carritoUsuario->impuestos << endl;
}

void menuUsuario(Usuario* usuario) {
    int opcion;
    
    do {
        cout << "\n=== MENÚ PRINCIPAL ===" << endl;
        cout << "1. Listar Productos con stock bajo" << endl;
        cout << "2. Comentarios de una fecha en adelante" << endl;
        cout << "3. Listar usuarios" << endl;
        cout << "4. Adicionar productos al carrito" << endl;
        cout << "5. Listar productos del carrito" << endl;
        cout << "0. Cerrar sesión" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                listarProductosBajoStock();
                break;
            case 2:
                listarComentariosDesdeFecha();
                break;
            case 3:
                listarUsuarios();
                break;
            case 4:
                agregarAlCarrito(usuario);
                break;
            case 5:
                listarCarrito(usuario);
                break;
            case 0:
                cout << "Cerrando sesión..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
    } while (opcion != 0);
}

int main() {
	
	setlocale(LC_ALL, "spanish");
	
    cargarDatos();
    
    int opcion;
    do {
        cout << "\n=== SISTEMA E-COMMERCE ===" << endl;
        cout << "1. Iniciar sesión" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        if (opcion == 1) {
            Usuario* usuario = iniciarSesion();
            if (usuario != NULL) {
                menuUsuario(usuario);
            }
        } else if (opcion != 0) {
            cout << "Opción inválida" << endl;
        }
    } while (opcion != 0);
    
    cout << "Gracias por usar el sistema!" << endl;
    return 0;
}
