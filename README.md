# Contact Book Management System

## Overview
The **Contact Book Management System** is a console-based application developed in C++ using Data Structures and Algorithms. It provides an efficient way to manage contact information, allowing users to store, search, sort, update, and delete contacts. The system is designed for individuals and small businesses who want a simple and effective contact management tool.

---

## Key Features
1. **Add New Contacts**  
   - Add a contact with a name and phone number.
   - Automatically updates the contact list.

2. **Display Contacts**  
   - Displays all contacts sorted alphabetically by name.
   - Sorting is handled using the bubble sort algorithm.

3. **Search Contacts**  
   - Search by name or phone number to retrieve detailed information.

4. **Edit Contacts**  
   - Update details of an existing contact by searching with name or phone number.

5. **Delete Contacts**  
   - Remove a contact by searching for it.
   - Option to delete all stored contacts at once.

6. **File Operations**  
   - Save contacts to a file (`contactbook.txt`) for data persistence.
   - Load previously saved contacts when the application restarts.

7. **Backup**  
   - Keeps a backup of contact data for recovery purposes.

---

## Data Structure
The system uses a **doubly linked list**, where each node represents a contact. Each node includes:
- **Name** (string): Contact name.
- **Phone Number** (long long int): Contact's phone number.
- **Next** (pointer): Points to the next contact in the list.
- **Prev** (pointer): Points to the previous contact in the list.

---

## Functional Modules
The application includes the following modules:
1. **CreateNode()**: Adds a new contact.
2. **Display()**: Displays all contacts in alphabetical order.
3. **Search()**: Searches for a contact by name or phone number.
4. **EditContacts()**: Edits the details of an existing contact.
5. **DeleteContactBySearch()**: Deletes a contact by name or phone number.
6. **DeleteAllContacts()**: Clears the entire contact book.
7. **BubbleSort()**: Sorts contacts alphabetically by name.
8. **OfflineSave()**: Saves all contacts to an external file.
9. **ReopenCB()**: Loads contacts from the file on startup.
10. **Backup()**: Maintains a backup of contact data.

---

## Benefits
- **Efficiency**: Linked list structure ensures efficient operations for adding, deleting, and traversing contacts.
- **Data Persistence**: Contacts are saved to a file for future use.
- **User-Friendly**: Simple command-line interface for ease of use.
- **Scalability**: Handles an expanding list of contacts smoothly.
- **Flexibility**: Supports searching by both name and phone number.

---

## Requirements
- **Language**: C++
- **Compiler**: Any C++ compiler (e.g., GCC, Dev C++, Visual Studio)
- **Environment**: Command-line interface

---

## How to Use
1. Clone or download the repository.
2. Compile the source code using a C++ compiler.
3. Run the executable in your terminal.
4. Use the menu options to add, display, search, update, delete, or save contacts.

---

## Sample Outputs

![SCREENSHOT-1](assets/screenshot-1.png)
![SCREENSHOT-2](assets/screenshot-2.png)
![SCREENSHOT-3](assets/screenshot-3.png)
![SCREENSHOT-4](assets/screenshot-4.png)
![SCREENSHOT-5](assets/screenshot-5.png)
![SCREENSHOT-6](assets/screenshot-6.png)
![SCREENSHOT-7](assets/screenshot-7.png)
![SCREENSHOT-8](assets/screenshot-8.png)
![SCREENSHOT-9](assets/screenshot-9.png)
![SCREENSHOT-10](assets/screenshot-10.png)

---

## Contributors  
- **Name: [Wafa Abbas](https://github.com/Malik-WafaAbbas)**  
- **Name: [Abdul Ahad](https://github.com/AbdulAhad56)**  
- **Name: [Muhammad Zaman](https://github.com/ManiXheikh)**  

---

## License
This project is licensed under the Apache License 2.0. You may obtain a copy of the license at:

[Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0)

