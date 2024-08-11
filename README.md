# Contact Management System

A simple Contact Management System written in C that allows users to add, display, and search for contacts. The program also includes a login feature for added security.

## Features

- **Add Contact**: Add a new contact to the system.
- **Display Contacts**: Display all stored contacts.
- **Search Contact**: Search for a specific contact by name.
- **Login System**: Simple login functionality to control access to the system.

## Usage

1. **Login**
   - The program prompts for a username and password.
   - Default credentials:
     - Username: `usuario`
     - Password: `contrasena`

2. **Main Menu**
   - After successful login, the user is presented with the following options:
     1. Add Contact
     2. Display Contacts
     3. Search Contact
     4. Exit

3. **Add Contact**
   - The user can enter the name and phone number of a new contact.
   - The contact is saved both in memory and in a text file named `contacts.txt`.

4. **Display Contacts**
   - Displays all contacts stored in the `contacts.txt` file.

5. **Search Contact**
   - Allows the user to search for a contact by name.
   - If found, the contact's details are displayed.

6. **Exit**
   - Exits the program.

## Code Overview

### Data Structures

- **Contact Structure**: Used to store contact information (name and phone number).
  ```c
  typedef struct {
      char name[MAX_NAME_LENGTH];
      char phone[15];
  } Contact;
  ```

### Functions

- **`int login()`**
  - Handles the user login by checking the entered username and password against the hard-coded credentials.

- **`void addContact(Contact contacts[], int *count)`**
  - Adds a new contact to the system.
  - Saves the contact information to a file.

- **`void displayContacts(Contact contacts[], int count)`**
  - Displays all contacts stored in the `contacts.txt` file.

- **`void searchContact(Contact contacts[], int count)`**
  - Searches for a contact by name and displays the details if found.

### System Requirements

- **Operating System**: Windows, Linux, or macOS.
- **Compiler**: Any C compiler (e.g., GCC).

### How to Run

1. **Compile the Program**
   - Use the following command to compile the program:
     ```
     gcc -o contact_manager contact_manager.c
     ```

2. **Run the Program**
   - Execute the compiled binary:
     ```
     ./contact_manager
     ```

## File Structure

- **`contacts.txt`**: Stores the list of contacts. The format is:
  ```
  Name Phone
  ```

## Example

```plaintext
Inicio de Sesion
Usuario: usuario
Contrasena: contrasena
Acceso concedido.

Menu:
1. Agregar Contacto
2. Mostrar Contactos
3. Buscar Contacto
4. Salir
Elige una opcion: 1

Agregar Contacto:
Nombre: Juan
Telefono: 1234567890
Contacto agregado exitosamente.

Menu:
1. Agregar Contacto
2. Mostrar Contactos
3. Buscar Contacto
4. Salir
Elige una opcion: 2

Lista de Contactos:
Nombre: Juan, Telefono: 1234567890
```

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue if you have any suggestions or improvements.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.