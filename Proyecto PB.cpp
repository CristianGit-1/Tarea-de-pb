#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

struct Usuario {
    int idUsuario;
    string nombre;
    string correoElectronico;
    string contrasena;
    string direccion;
    string metodoDePago;
};

struct Producto {
    int idProducto;
    string nombre;
    string descripcion;
    double precio;
    int stock;
};

struct Categoria {
    int idCategoria;
    string nombre;
};

struct Comentario {
    int idComentario;
    string nombreProducto; 
    string nombreUsuario; 
    string comentario;
    string fecha;
};

struct CarritoDeCompras {
    int idCarrito;
    Usuario usuario;
    vector<Producto> productos;
    double subtotal;
    double impuestos;
};

struct OrdenDeCompra {
    int idOrden;
    vector<Producto> productos;
    double subtotal;
    double impuestos;
    double envio;
    double total;
};

// Vectores globales
vector<Usuario> usuarios;
vector<Producto> productos;
vector<Comentario> comentarios;
vector<CarritoDeCompras> carritos;

// 1. INICIALIZACIÓN 
void cargarDatos() {
    cout << "Cargando datos iniciales..." << endl;
    Sleep(3000);
    // Cargar usuarios
    usuarios.push_back((Usuario){1, "Juan Pérez", "juan.perez@email.com", "Qwerty123", "Carrera 45 #10-20", "Tarjeta de crédito"});
    usuarios.push_back((Usuario){2, "Ana Gómez", "ana.gomez@email.com", "Pass456", "Calle 21 #35-50", "PayPal"});
    usuarios.push_back((Usuario){3, "Carlos Ruiz", "carlos.ruiz@email.com", "Segura789", "Avenida Principal #100", "Transferencia bancaria"});
    usuarios.push_back((Usuario){4, "Sofía Martínez", "sofia.martinez@email.com", "Clave987", "Calle 8 #20-30", "Efectivo"});
    usuarios.push_back((Usuario){5, "Diego Fernández", "diego.fernandez@email.com", "Contra654", "Carrera 77 #40-60", "Tarjeta débito"});

    // Cargar productos
    productos.push_back((Producto){1, "Laptop", "Portátil con pantalla Full HD y SSD de 512GB", 89999, 10});
    productos.push_back((Producto){2, "Smartphone", "Teléfono con cámara de 108MP y carga rápida", 49950, 20});
    productos.push_back((Producto){3, "Tablet", "Dispositivo con pantalla táctil de 10 pulgadas", 29999, 15});
    productos.push_back((Producto){4, "Auriculares", "Audífonos inalámbricos con cancelación de ruido", 12999, 25});
    productos.push_back((Producto){5, "Teclado", "Teclado mecánico con iluminación RGB", 8999, 30});
    productos.push_back((Producto){6, "Mouse", "Ratón inalámbrico con sensor óptico de alta precisión", 5999, 50});
    productos.push_back((Producto){7, "Monitor", "Pantalla LED 4K de 27 pulgadas", 49900, 12});
    productos.push_back((Producto){8, "Impresora", "Láser multifuncional con Wi-Fi", 17999, 18});
    productos.push_back((Producto){9, "Cámara", "Cámara digital con lente profesional", 79999, 8});
    productos.push_back((Producto){10, "Smartwatch", "Reloj inteligente con GPS y monitoreo cardíaco", 19999, 22});
    productos.push_back((Producto){11, "Silla Gamer", "Silla ergonómica ajustable con soporte lumbar", 29999, 14});
    productos.push_back((Producto){12, "Microondas", "Horno microondas con múltiples funciones", 12999, 40});
    productos.push_back((Producto){13, "Refrigerador", "Frigorífico doble puerta con sistema No Frost", 119999, 5});
    productos.push_back((Producto){14, "Lavadora", "Lavadora automática con capacidad de 10kg", 59999, 7});
    productos.push_back((Producto){15, "Cafetera", "Cafetera express con vaporizador de leche", 14999, 35});
    productos.push_back((Producto){16, "Drone", "Drone con cámara 4K y estabilizador", 69999, 9});
    productos.push_back((Producto){17, "Bocina Bluetooth", "Altavoz portátil con sonido envolvente", 8999, 33});
    productos.push_back((Producto){18, "Videocámara", "Videocámara profesional con grabación en 4K", 99999, 6});
    productos.push_back((Producto){19, "TV LED", "Televisor inteligente de 55 pulgadas con HDR", 74999, 11});
    productos.push_back((Producto){20, "Batería Externa", "Batería de 20000mAh con carga rápida", 3999, 45});
    productos.push_back((Producto){21, "Disco Duro", "Disco duro externo de 2TB", 12999, 28});
    productos.push_back((Producto){22, "Memoria USB", "Pendrive de 128GB", 2999, 60});
    productos.push_back((Producto){23, "Router", "Router Wi-Fi 6 de alta velocidad", 19999, 16});
    productos.push_back((Producto){24, "Joystick", "Control inalámbrico para videojuegos", 7999, 20});
    productos.push_back((Producto){25, "Fuente de Poder", "Fuente de alimentación para PC de 750W", 8999, 17});
    productos.push_back((Producto){26, "SSD", "Unidad de almacenamiento SSD de 1TB", 14999, 32});
    productos.push_back((Producto){27, "Altavoces", "Par de bocinas estéreo con subwoofer", 13999, 23});
    productos.push_back((Producto){28, "Webcam", "Cámara web Full HD con micrófono integrado", 6999, 37});
    productos.push_back((Producto){29, "Procesador", "CPU Intel i7 de última generación", 34999, 9});
    productos.push_back((Producto){30, "Motherboard", "Placa base compatible con procesadores modernos", 19999, 13});
    productos.push_back((Producto){31, "Memoria RAM", "Módulo de RAM DDR4 de 16GB", 7999, 41});
    productos.push_back((Producto){32, "Fuente Solar", "Panel solar portátil con batería integrada", 24999, 4});
    productos.push_back((Producto){33, "Control Remoto", "Mando universal para TV y dispositivos", 2499, 50});
    productos.push_back((Producto){34, "Termostato", "Termostato digital programable", 9999, 22});
    productos.push_back((Producto){35, "Smart Lock", "Cerradura electrónica con huella digital", 19999, 6});
    productos.push_back((Producto){36, "Proyector", "Proyector LED con resolución Full HD", 29999, 12});
    productos.push_back((Producto){37, "Switch Ethernet", "Switch de red de 8 puertos", 5999, 38});
    productos.push_back((Producto){38, "Reloj Digital", "Reloj inteligente con pantalla AMOLED", 8999, 26});
    productos.push_back((Producto){39, "Luces LED", "Tiras LED RGB con control remoto", 3999, 55});
    productos.push_back((Producto){40, "Estabilizador", "Estabilizador de voltaje para dispositivos electrónicos", 15999, 10});
    productos.push_back((Producto){41, "Cargador Inalámbrico", "Base de carga inalámbrica rápida", 4999, 30});
    productos.push_back((Producto){42, "HDD Externo", "Disco duro portátil de 4TB", 17999, 15});
    productos.push_back((Producto){43, "Micrófono", "Micrófono profesional para grabación", 14999, 7});
    productos.push_back((Producto){44, "Altavoz Inteligente", "Asistente de voz con altavoz integrado", 12999, 20});
    productos.push_back((Producto){45, "Antena Wi-Fi", "Amplificador de señal inalámbrico", 7999, 33});
    productos.push_back((Producto){46, "Climatizador", "Aire acondicionado portátil con control remoto", 29999, 5});
    productos.push_back((Producto){47, "Raspberry Pi", "Kit de desarrollo con Raspberry Pi 4", 12999, 19});
    productos.push_back((Producto){48, "Capturadora", "Placa de captura de video en alta resolución", 19999, 8});
    productos.push_back((Producto){49, "Smart Plug", "Enchufe inteligente compatible con asistentes virtuales", 3999, 42});
    productos.push_back((Producto){50, "Timbre Inteligente", "Timbre con cámara y conexión a Wi-Fi", 14999, 10});



	// Cargar comentarios
	comentarios.push_back((Comentario){1, "Laptop", "Juan Pérez", "Excelente rendimiento; muy rápida. ¡Me encanta!", "01/05/2025"});
	comentarios.push_back((Comentario){2, "Smartphone", "Ana Gómez", "Buena cámara pero la batería dura poco.", "03/05/2025"});
	comentarios.push_back((Comentario){3, "Tablet", "Carlos Ruiz", "No me gustó; pantalla de baja calidad.", "05/05/2025"});
	comentarios.push_back((Comentario){4, "Auriculares", "Sofía Martínez", "Sonido aceptable pero el material parece frágil.", "06/05/2025"});
	comentarios.push_back((Comentario){5, "Teclado", "Diego Fernández", "Muy buen teclado mecánico; excelente respuesta.", "08/05/2025"});
	comentarios.push_back((Comentario){6, "Mouse", "Ana Gómez", "El sensor no es tan preciso como esperaba.", "10/05/2025"});
	comentarios.push_back((Comentario){7, "Monitor", "Carlos Ruiz", "Colores vibrantes y buena resolución. Muy satisfecho.", "12/05/2025"});
	comentarios.push_back((Comentario){8, "Impresora", "Juan Pérez", "Tarda mucho en imprimir; no me convence.", "13/05/2025"});
	comentarios.push_back((Comentario){9, "Cámara", "Sofía Martínez", "Increíble calidad de imagen; fotos súper nítidas.", "15/05/2025"});
	comentarios.push_back((Comentario){10, "Smartwatch", "Diego Fernández", "Buena batería; pero la pantalla no es muy brillante.", "18/05/2025"});
	comentarios.push_back((Comentario){11, "Silla Gamer", "Lucía Rodríguez", "Comodidad espectacular; perfecto para largas sesiones de juego.", "20/05/2025"});
	comentarios.push_back((Comentario){12, "Microondas", "Andrés Ramírez", "Calienta bien pero hace mucho ruido.", "22/05/2025"});
	comentarios.push_back((Comentario){13, "Refrigerador", "María García", "Espacioso y enfría rápido; muy recomendado.", "24/05/2025"});
	comentarios.push_back((Comentario){14, "Lavadora", "Javier Martínez", "Lava bien pero el ciclo es muy largo.", "26/05/2025"});
	comentarios.push_back((Comentario){15, "Cafetera", "Carolina López", "Hace café delicioso; fácil de usar.", "28/05/2025"});
	comentarios.push_back((Comentario){16, "Drone", "Daniel Castro", "Muy divertido pero la batería dura poco.", "30/05/2025"});
	comentarios.push_back((Comentario){17, "Bocina Bluetooth", "Paola Herrera", "Sonido potente y buena conexión Bluetooth.", "01/06/2025"});
	comentarios.push_back((Comentario){18, "Videocámara", "Esteban Rojas", "Perfecta para grabaciones profesionales.", "03/06/2025"});
	comentarios.push_back((Comentario){19, "TV LED", "Fernanda Sánchez", "Imagen excelente pero el sonido podría mejorar.", "05/06/2025"});
	comentarios.push_back((Comentario){20, "Batería Externa", "Camilo Torres", "Carga bien pero es un poco pesada.", "07/06/2025"});
	comentarios.push_back((Comentario){21, "Disco Duro", "Gabriela Suárez", "Gran capacidad de almacenamiento; funciona rápido.", "09/06/2025"});
	comentarios.push_back((Comentario){22, "Memoria USB", "Raúl Espinosa", "Buen tamaño pero la velocidad de transferencia es baja.", "11/06/2025"});
	comentarios.push_back((Comentario){23, "Router", "Verónica Mendoza", "Señal potente; cubre toda la casa.", "13/06/2025"});
	comentarios.push_back((Comentario){24, "Joystick", "Fablo Jiménez", "Comodo y resistente; ideal para gaming.", "15/06/2025"});
	comentarios.push_back((Comentario){25, "Fuente de Poder", "Ricardo Vargas", "Funciona bien pero los cables son muy cortos.", "17/06/2025"});
	comentarios.push_back((Comentario){26, "SSD", "Silvia Gómez", "Velocidad increíble; mi PC va mucho más rápido ahora.", "19/06/2025"});
	comentarios.push_back((Comentario){27, "Altavoces", "Martín Aguilar", "Sonido envolvente; muy buena compra.", "21/06/2025"});
	comentarios.push_back((Comentario){28, "Webcam", "Valentina Pérez", "Imagen clara pero el micrófono es deficiente.", "23/06/2025"});
	comentarios.push_back((Comentario){29, "Procesador", "José Ramírez", "Rendimiento impecable; ideal para gaming y diseño.", "25/06/2025"});
	comentarios.push_back((Comentario){30, "Motherboard", "Natalia Correa", "Buenas prestaciones pero la instalación fue complicada.", "27/06/2025"});
	comentarios.push_back((Comentario){31, "Memoria RAM", "Julio Fernández", "Expande muy bien el rendimiento del sistema.", "29/06/2025"});
	comentarios.push_back((Comentario){32, "Fuente Solar", "Amanda Castro", "Energía confiable pero la batería es pequeña.", "01/07/2025"});
	comentarios.push_back((Comentario){33, "Control Remoto", "Pedro Duarte", "Fácil de usar; reconoce muchos dispositivos.", "03/07/2025"});
	comentarios.push_back((Comentario){34, "Termostato", "Isabela Medina", "Regula bien la temperatura; intuitivo de usar.", "05/07/2025"});
	comentarios.push_back((Comentario){35, "Smart Lock", "Oscar Rodríguez", "Seguridad y tecnología en un solo dispositivo.", "07/07/2025"});
	comentarios.push_back((Comentario){36, "Proyector", "Cristina Vargas", "Imagen nítida pero requiere una sala oscura.", "09/07/2025"});
	comentarios.push_back((Comentario){37, "Switch Ethernet", "Mario Hernández", "Buena velocidad de conexión; estable.", "11/07/2025"});
	comentarios.push_back((Comentario){38, "Reloj Digital", "Sofía Ramírez", "Pantalla atractiva pero la batería dura poco.", "13/07/2025"});
	comentarios.push_back((Comentario){39, "Luces LED", "Andrea Gutiérrez", "Buenas opciones de colores; buen diseño.", "15/07/2025"});
	comentarios.push_back((Comentario){40, "Estabilizador", "Pablo Medina", "Protege bien contra variaciones de voltaje.", "17/07/2025"});
	comentarios.push_back((Comentario){41, "Cargador Inalámbrico", "Patricia López", "Carga rápido pero requiere posicionamiento preciso.", "19/07/2025"});
	comentarios.push_back((Comentario){42, "HDD Externo", "Gonzalo Espinoza", "Mucho espacio; resistente y confiable.", "21/07/2025"});
	comentarios.push_back((Comentario){43, "Micrófono", "Elena Herrera", "Calidad de sonido profesional; ideal para podcast.", "23/07/2025"});
	comentarios.push_back((Comentario){44, "Altavoz Inteligente", "Diego Soto", "Responde bien a comandos de voz; útil en casa.", "25/07/2025"});
	comentarios.push_back((Comentario){45, "Antena Wi-Fi", "Miguel Rojas", "Amplifica bien la señal pero el rango es limitado.", "27/07/2025"});
	comentarios.push_back((Comentario){46, "Climatizador", "Esteranía Carrillo", "Enfría rápido pero es algo ruidoso.", "29/07/2025"});
	comentarios.push_back((Comentario){47, "Raspberry Pi", "Manuel Vargas", "Perfecto para proyectos electrónicos y programación.", "31/07/2025"});
	comentarios.push_back((Comentario){48, "Capturadora", "Luisa Mejía", "Ideal para streaming y grabaciones en alta calidad.", "02/08/2025"});
	comentarios.push_back((Comentario){49, "Smart Plug", "Victoria Torres", "Muy práctico; fácil de conectar y configurar.", "04/08/2025"});
	comentarios.push_back((Comentario){50, "Timbre Inteligente", "Federico Montoya", "Buena cámara; útil para seguridad.", "06/08/2025"});
    
	cout << "Datos cargados correctamente!" << endl;
    cout << "- Usuarios: " << usuarios.size() << endl;
    cout << "- Productos: " << productos.size() << endl;
    cout << "- Comentarios: " << comentarios.size() << endl;
}

// 2. INICIAR SESIÓN - Buscar usuario
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

// 3. LISTAR PRODUCTOS con stock bajo (<15 unidades)
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

// 4. COMENTARIOS desde fecha
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

// 5. LISTAR USUARIOS
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

// 6. MOSTRAR PRODUCTOS
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

// 8. LISTAR PRODUCTOS
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
