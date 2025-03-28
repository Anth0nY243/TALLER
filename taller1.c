#include <stdio.h>
#include <string.h>

int validarID(const char *id) {
    int tieneLetra = 0, tieneNumero = 0;
    
    for (int i = 0; id[i] != '\0'; i++) {
        if ((id[i] >= 'A' && id[i] <= 'Z') || (id[i] >= 'a' && id[i] <= 'z')) {
            tieneLetra = 1;
        }
        if (id[i] >= '0' && id[i] <= '9') {
            tieneNumero = 1;
        }
    }
    
    return tieneLetra && tieneNumero;
}

int main() {
    char id[20], nombre[30];
    int stock, cantidad, opcion;
    float precio, total_ganancias = 0;
    int productoRegistrado = 0; // Variable para verificar si hay un producto registrado

    do {
        printf("\nMenu de Opciones:\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar informacion del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer

        switch (opcion) {
            case 1: // Registrar producto
                do {
                    printf("Ingrese el ID del producto (Debe contener letras y numeros): ");
                    scanf("%s", id);
                    if (!validarID(id)) {
                        printf("Error: El ID debe contener al menos una letra y un numero. Intente nuevamente.\n");
                    }
                } while (!validarID(id));

                getchar(); // Limpiar buffer
                printf("Ingrese el nombre del producto: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = 0; 

                printf("Ingrese la cantidad inicial en stock: ");
                scanf("%d", &stock);
                printf("Ingrese el precio unitario del producto: ");
                scanf("%f", &precio);

                total_ganancias = 0;
                productoRegistrado = 1; // Se marca que hay un producto registrado
                printf("Producto registrado con éxito.\n");
                break;

            case 2: // Vender producto
                if (!productoRegistrado) {
                    printf("Primero debe registrar un producto.\n");
                    break;
                }
                printf("Ingrese la cantidad a vender: ");
                scanf("%d", &cantidad);
                if (cantidad > 0 && cantidad <= stock) {
                    stock -= cantidad;
                    total_ganancias += cantidad * precio;
                    printf("Venta realizada con exito.\n");
                } else {
                    printf("Error: Cantidad invalida o insuficiente en stock.\n");
                }
                break;

            case 3: // Reabastecer producto
                if (!productoRegistrado) {
                    printf("Primero debe registrar un producto.\n");
                    break;
                }
                printf("Ingrese la cantidad a agregar al stock: ");
                scanf("%d", &cantidad);
                if (cantidad > 0) {
                    stock += cantidad;
                    printf("Stock actualizado con éxito.\n");
                } else {
                    printf("Error: La cantidad debe ser mayor que cero.\n");
                }
                break;

            case 4: // Mostrar información del producto
                if (!productoRegistrado) {
                    printf("Primero debe registrar un producto.\n");
                    break;
                }
                printf("\nInformacion del producto:\n");
                printf("ID: %s\n", id);
                printf("Nombre: %s\n", nombre);
                printf("Stock disponible: %d\n", stock);
                printf("Precio unitario: %.2f\n", precio);
                break;

            case 5: // Mostrar total de ganancias
                if (!productoRegistrado) {
                    printf("Primero debe registrar un producto.\n");
                    break;
                }
                printf("Total de ganancias: $%.2f\n", total_ganancias);
                break;

            case 6: // Salir del programa
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 6);
    return 0;
}