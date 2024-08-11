#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define FILENAME "contacts.txt"
#define print printf
#define scan scanf

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[15];
} Contact;

void addContact(Contact contacts[], int *count);
void displayContacts(Contact contacts[], int count);
void searchContact(Contact contacts[], int count);
int login();

int main() {
    Contact contacts[MAX_CONTACTS];
    int contactCount = 0;
    int option;

    if (!login()) {
        print("Acceso denegado.\n");
        return 0;
    }

    do {
        system("cls");
        print("\nMenu:\n");
        print("1. Agregar Contacto\n");
        print("2. Mostrar Contactos\n");
        print("3. Buscar Contacto\n");
        print("4. Salir\n");
        print("Elige una opcion: ");
        scan("%d", &option);

        system("cls");
        switch (option) {
            case 1:
                addContact(contacts, &contactCount);
                break;
            case 2:
                displayContacts(contacts, contactCount);
                break;
            case 3:
                searchContact(contacts, contactCount);
                break;
            case 4:
                print("Saliendo...\n");
                break;
            default:
                print("Opcion invalida. Intenta de nuevo.\n");
        }
    } while (option != 4);

    return 0;
}

int login() {
    char username[20];
    char password[20];

    char correctUsername[] = "usuario";
    char correctPassword[] = "contrasena";
    print("Inicio de Sesion\n");
    print("Usuario: ");
    scan("%s", username);
    print("Contrasena: ");
    scan("%s", password);

    if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0) {
        print("Acceso concedido.\n");
        return 1;
    }

    return 0;
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        print("La lista de contactos está llena.\n");
        return;
    }
    print("Agregar Contacto:\n");
    print("Nombre: ");
    scan("%s", contacts[*count].name);
    print("Telefono: ");
    scan("%s", contacts[*count].phone);

    FILE *file = fopen(FILENAME, "a");
    if (file != NULL) {
        fprintf(file, "%s %s\n", contacts[*count].name, contacts[*count].phone);
        fclose(file);
        print("Contacto agregado exitosamente.\n");
    } else {
        print("Error al abrir el archivo.\n");
    }

    (*count)++;
}

void displayContacts(Contact contacts[], int count) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        print("Error al abrir el archivo.\n");
        return;
    }

    printf("Lista de Contactos:\n");
    char name[MAX_NAME_LENGTH], phone[15];
    while (fscanf(file, "%s %s", name, phone) != EOF) {
        print("Nombre: %s, Telefono: %s\n", name, phone);
    }

    fclose(file);
}


void searchContact(Contact contacts[], int count) {
    char searchName[MAX_NAME_LENGTH];
    print("Buscar Contacto\n");
    print("Nombre: ");
    scan("%s", searchName);

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        print("Error al abrir el archivo.\n");
        return;
    }

    char name[MAX_NAME_LENGTH], phone[15];
    int found = 0;
    while (fscanf(file, "%s %s", name, phone) != EOF) {
        if (strcmp(name, searchName) == 0) {
            print("Contacto encontrado: Nombre: %s, Telefono: %s\n", name, phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        print("Contacto no encontrado.\n");
    }

    fclose(file);
}