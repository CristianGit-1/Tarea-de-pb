// Función para iniciar sesión
Usuario* iniciarSesion() {
    string correo, clave;
    
    cout << "\n=== INICIAR SESIÓN ===" << endl;
    cout << "Correo electrónico: ";
    cin >> correo;
    cout << "Contraseña: ";
    cin >> clave;
    
    for (int i = 0; i < usuarios.size(); i++) {
        if (usuarios[i].correoElectronico == correo && usuarios[i].contrasena == clave) {
            cout << "¡Bienvenido " << usuarios[i].nombre << "!" << endl;
            return &usuarios[i];
        }
    }
    
    cout << "Usuario invalido" << endl;
    return NULL;
}

// Función para listar productos de bajo stock (<15 unidades)
void listarProductosBajoStock() {
    cout << "\n=== PRODUCTOS CON STOCK BAJO (<15 unidades) ===" << endl;
    bool encontrados = false;
    
    for (int i = 0; i < productos.size(); i++) {
        if (productos[i].stock < 15) {
            cout << "ID: " << productos[i].idProducto << endl;
            cout << "Nombre: " << productos[i].nombre << endl;
            cout << "Descripción: " << productos[i].descripcion << endl;
            cout << "Precio: $" << productos[i].precio << endl;
            cout << "Stock: " << productos[i].stock << endl;
            cout << "------------------------" << endl;
            encontrados = true;
        }
    }
    
    if (!encontrados) {
        cout << "No hay productos con stock bajo" << endl;
    }
}

// Función para filtrar comentarios desde cierta fecha
void listarComentariosDesdeFecha() {
    string fecha;
    cout << "\nIngrese fecha (formato: dd/mm/aaaa): ";
    cin >> fecha;
    
    cout << "\n=== COMENTARIOS DESDE " << fecha << " ===" << endl;
    bool encontrados = false;
    
    for (int i = 0; i < comentarios.size(); i++) {
        if (comentarios[i].fecha >= fecha) {
            cout << "Producto: " << comentarios[i].nombreProducto << endl;
			cout << "Usuario: " << comentarios[i].nombreUsuario << endl;
            cout << "Comentario: " << comentarios[i].comentario << endl;
            cout << "Fecha: " << comentarios[i].fecha << endl;
            cout << "------------------------" << endl;
            encontrados = true;
        }
    }
    
    if (!encontrados) {
        cout << "No hay comentarios desde esa fecha" << endl;
    }
}
