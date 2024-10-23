#include "empresa.h"

void mostrarMenu() {
    printf("\n--- Menú de Operaciones ---\n");
    printf("1. Crear organigrama\n");
    printf("2. Añadir un nuevo cargo\n");
    printf("3. Listar jerarquía de cargos\n");
    printf("4. Eliminar organigrama\n");
    printf("5. Salir\n");
    printf("----------------------------\n");
    printf("Seleccione una opción: ");
}

void esperarEnter() {
    printf("Presione Enter para continuar...");
    getchar();
    getchar(); 
}

int main() {
    Empresa empresa;
    InicializarEmpresa(&empresa);

    int opcion;
    char nombreCargo[100], nombreCargoPadre[100];

    do {
        mostrarMenu();
        scanf("%d", &opcion);  

        switch (opcion) {
            case 1:
                if (empresa.raiz != NULL) {
                    printf("Ya existe un organigrama. Elimínalo primero.\n");
                } else {
                    printf("Ingrese el nombre del cargo principal: ");
                    scanf("%s", nombreCargo);
                    if (CrearOrg(&empresa, nombreCargo) == OK) {
                        printf("Organigrama creado con éxito.\n");
                    } else {
                        printf("Error al crear el organigrama.\n");
                    }
                }
                esperarEnter();
                break;

            case 2:
                if (empresa.raiz == NULL) {
                    printf("No existe un organigrama. Cree el organigrama primero.\n");
                } else {
                    printf("Ingrese el nombre del cargo padre: ");
                    scanf("%s", nombreCargoPadre);
                    printf("Ingrese el nombre del nuevo cargo: ");
                    scanf("%s", nombreCargo);
                    if (NuevoCargo(&empresa, nombreCargoPadre, nombreCargo) == OK) {
                        printf("Nuevo cargo añadido con éxito.\n");
                    } else {
                        printf("Error al añadir el nuevo cargo.\n");
                    }
                }
                esperarEnter();
                break;

            case 3:
                if (ListarJerarquia(empresa) == ERROR) {
                    printf("No hay cargos para mostrar.\n");
                }
                esperarEnter();
                break;

            case 4:
                if (EliminarOrg(&empresa) == OK) {
                    printf("Organigrama eliminado.\n");
                } else {
                    printf("No hay un organigrama que eliminar.\n");
                }
                esperarEnter();
                break;

            case 5:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción inválida. Inténtelo de nuevo.\n");
                esperarEnter();
        }
    } while (opcion != 5);

    return 0;
}
