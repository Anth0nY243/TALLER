#include <stdio.h>
#include <string.h>

int main() {
    char id[20], nombre[30];
    int stock = 0, cantidad, opcion, producto_registrado = 0;
    float precio = 0, total_ganancias = 0;
    int tieneLetra, tieneNumero, valido;

    do {
        printf("\nMenu de Opciones:\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar información del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer

        switch (opcion) {
            case 1: // Registrar producto
                do {
                    printf("Ingrese el ID del producto (Debe contener letras y números): ");
                    scanf("%s", id);
                    getchar(); // Limpiar buffer

                    // Validación del ID
                    tieneLetra = 0;
                    tieneNumero = 0;
                    valido = 0;

                    for (int i = 0; id[i] != '\0'; i++) {
                        if ((id[i] >= 'A' && id[i] <= 'Z') || (id[i] >= 'a' && id[i] <= 'z')) {
                            tieneLetra = 1;
                        }
                        if (id[i] >= '0' && id[i] <= '9') {
                            tieneNumero = 1;
                        }
                    }

                    if (tieneLetra && tieneNumero) {
                        valido = 1;
                    } else {
                        printf("Error: El ID debe contener al menos una letra y un número. Intente nuevamente.\n");
                    }
                } while (!valido);

                printf("Ingrese el nombre del producto: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = 0;

                printf("Ingrese la cantidad inicial en stock: ");
                scanf("%d", &stock);
                printf("Ingrese el precio unitario del producto: ");
                scanf("%f", &precio);

                producto_registrado = 1; // Marcar que hay un producto registrado
                printf("Producto registrado con exito.\n");
                break;

            case 2: // Vender producto
                if (!producto_registrado) {
                    printf("Error: No hay un producto registrado. Registre un producto primero.\n");
                    break;
                }
                printf("Ingrese la cantidad a vender: ");
                scanf("%d", &cantidad);
                if (cantidad > 0 && cantidad <= stock) {
                    stock -= cantidad;
                    total_ganancias += cantidad * precio;
                    printf("Venta realizada con éxito.\n");
                } else {
                    printf("Error: Cantidad invalida o insuficiente en stock.\n");
                }
                break;

            case 3: // Reabastecer producto
                if (!producto_registrado) {
                    printf("Error: No hay un producto registrado. Registre un producto primero.\n");
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
                if (!producto_registrado) {
                    printf("Error: No hay un producto registrado. Registre un producto primero.\n");
                    break;
                }
                printf("\nInformación del producto:\n");
                printf("ID: %s\n", id);
                printf("Nombre: %s\n", nombre);
                printf("Stock disponible: %d\n", stock);
                printf("Precio unitario: %.2f\n", precio);
                break;

            case 5: // Mostrar total de ganancias
                printf("Total de ganancias: $%.2f\n", total_ganancias);
                break;

            case 6: // Salir
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción invalida. Intente nuevamente.\n");
        }
    } while (opcion != 6);
    return 0;
}