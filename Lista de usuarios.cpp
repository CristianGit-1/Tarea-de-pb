void listarUsuarios() {
    cout << "\n=== LISTA DE USUARIOS ===" << endl;
    
    for (int i = 0; i < usuarios.size(); i++) {
        // Convertir nombre a mayúsculas
        string nombreMayus = usuarios[i].nombre;
        for (int j = 0; j < nombreMayus.length(); j++) {
            if (nombreMayus[j] >= 'a' && nombreMayus[j] <= 'z') {
                nombreMayus[j] = nombreMayus[j] - 32;
            }
        }
        
        cout << "ID: " << usuarios[i].idUsuario << endl;
        cout << "Nombre: " << nombreMayus << endl;
        cout << "Correo: " << usuarios[i].correoElectronico << endl;
        cout << "Dirección: " << usuarios[i].direccion << endl;
        cout << "Método de Pago: " << usuarios[i].metodoDePago << endl;
        cout << "------------------------" << endl;
    }
}

// Mostrar productos disponibles
void mostrarProductos() {
    cout << "\n=== PRODUCTOS DISPONIBLES ===" << endl;
    for (int i = 0; i < productos.size(); i++) {
        cout << "ID: " << productos[i].idProducto << " | " 
             << productos[i].nombre << " | $" 
             << productos[i].precio << " | Stock: " 
             << productos[i].stock << endl;
    }
}

// 7. AGREGAR PRODUCTOS
void agregarAlCarrito(Usuario* usuarioActual) {
    mostrarProductos();
    
    int productoId, cantidad;
    cout << "\nIngrese el ID del producto: ";
    cin >> productoId;
    cout << "Ingrese la cantidad: ";
    cin >> cantidad;
    
    // Buscar producto
    Producto* producto = NULL;
    for (int i = 0; i < productos.size(); i++) {
        if (productos[i].idProducto == productoId) {
            producto = &productos[i];
            break;
        }
    }
    
    if (producto == NULL) {
        cout << "Error: Producto no existe" << endl;
        return;
    }
    
    if (producto->stock < cantidad) {
        cout << "Error: Stock insuficiente. Solo hay " << producto->stock << " unidades" << endl;
        return;
    }
    
    // Buscar carrito existente
    CarritoDeCompras* carritoUsuario = NULL;
    for (int i = 0; i < carritos.size(); i++) {
        if (carritos[i].usuario.idUsuario == usuarioActual->idUsuario) {
            carritoUsuario = &carritos[i];
            break;
        }
    }
    
    if (carritoUsuario == NULL) {
        // Crear nuevo carrito
        CarritoDeCompras nuevoCarrito;
        nuevoCarrito.idCarrito = carritos.size() + 1;
        nuevoCarrito.usuario = *usuarioActual;
        
        // Agregar productos
        for (int i = 0; i < cantidad; i++) {
            nuevoCarrito.productos.push_back(*producto);
        }
        
        nuevoCarrito.subtotal = producto->precio * cantidad;
        nuevoCarrito.impuestos = nuevoCarrito.subtotal * 0.19;
        
        carritos.push_back(nuevoCarrito);
        cout << "Nuevo carrito creado!" << endl;
    } else {
        // Agregar al carrito existente
        for (int i = 0; i < cantidad; i++) {
            carritoUsuario->productos.push_back(*producto);
        }
        carritoUsuario->subtotal += producto->precio * cantidad;
        carritoUsuario->impuestos = carritoUsuario->subtotal * 0.19;
        cout << "Producto agregado al carrito existente!" << endl;
    }
    
    // Actualizar stock
    producto->stock -= cantidad;
    cout << "Stock actualizado. Quedan " << producto->stock << " unidades" << endl;
}