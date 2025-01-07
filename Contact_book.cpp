#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <cctype> // For isdigit() and isalpha()
using namespace std;

struct Node {
    string name;
    long long int phone_number;
    Node* next;
    Node* prev;
};

class ContactBook {
    Node* head;
    string x;
    long long int y;

public:
    ContactBook() {
        head = NULL;
        x = "";
        y = 0;
    }

    bool isValidName(const string& name) {
        for (size_t i = 0; i < name.size(); ++i) { // Traditional loop
            char ch = name[i];
            if (!isalpha(ch) && ch != ' ') { // Allow alphabets and spaces
                return false;
            }
        }
        return true;
    }

    bool isValidPhoneNumber(const string& phoneStr) {
        for (size_t i = 0; i < phoneStr.size(); ++i) { // Traditional loop
            char ch = phoneStr[i];
            if (!isdigit(ch)) { // Allow only digits
                return false;
            }
        }
        return true;
    }

    void CreateNode() {
        Node* newer = new Node;

        // Validate Name
        while (true) {
            cout << "  Name of Contact: ";
            cin.ignore(); // Clear input buffer
            getline(cin, x); // Allow spaces in names
            if (isValidName(x)) {
                newer->name = x;
                break;
            } else {
                cout << "  Invalid name! Name should contain only alphabets and spaces. Try again.\n";
            }
        }

        // Validate Phone Number
        while (true) {
            cout << "  Phone Number: ";
            string phoneStr;
            cin >> phoneStr;
            if (isValidPhoneNumber(phoneStr)) {
                stringstream convert(phoneStr);
                convert >> y;
                newer->phone_number = y;
                break;
            } else {
                cout << "  Invalid phone number! Phone number should contain only digits. Try again.\n";
            }
        }

        newer->next = NULL;
        newer->prev = NULL;

        if (head == NULL) {
            head = newer;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newer;
            newer->prev = temp;
        }

        cout << "  Contact Added" << endl;
    }

    void Display() {
        Node* temp = head;
        int count = 0;

        if (temp == NULL) {
            cout << "  No Contacts... Please Add Some Contacts" << endl;
            cout << "  Thanks" << endl;
        } else {
            BubbleSort();
            cout << "  Name: " << "      Number: \n" << endl;
            while (temp != NULL) {
                count++;
                cout << "  " << temp->name;
                cout << "          " << temp->phone_number << endl;
                temp = temp->next;
            }
            cout << "  Total contacts: " << count << endl;
        }
    }

    void Search() {
        bool check = false;
        Node* temp = head;
        cout << "" << endl;
        cout << "  Press 1 if you want to Search By Name." << endl;
        cout << "  Press 2 if you want to Search By Number." << endl;
        cout << "" << endl;
        int command;
        cout << "  Enter the Command: ";
        cin >> command;

        if (command == 1 && temp != NULL) {
            cout << "  Enter the Name to Search: ";
            cin.ignore();
            getline(cin, x);
            if (!isValidName(x)) {
                cout << "  Invalid name! Name should contain only alphabets and spaces.\n";
                return;
            }
            while (temp != NULL) {
                if (temp->name == x) {
                    cout << "" << endl;
                    cout << "  Name: " << temp->name << endl;
                    cout << "  Phone Number: " << temp->phone_number << endl;
                    cout << "" << endl;
                    check = true;
                    break;
                }
                temp = temp->next;
            }
            if (!check) {
                cout << "  Name Not Found" << endl;
            }
        } else if (command == 2) {
            cout << "  Enter the Number to Search: ";
            string phoneStr;
            cin >> phoneStr;
            if (!isValidPhoneNumber(phoneStr)) {
                cout << "  Invalid phone number! Phone number should contain only digits.\n";
                return;
            }
            stringstream convert(phoneStr);
            convert >> y;
            while (temp != NULL) {
                if (temp->phone_number == y) {
                    cout << "*" << endl;
                    cout << "  Name: " << temp->name << endl;
                    cout << "  Phone Number: " << temp->phone_number << endl;
                    cout << "*" << endl;
                    check = true;
                    break;
                }
                temp = temp->next;
            }
            if (!check) {
                cout << "  Number Not Found" << endl;
            }
        } else {
            cout << "  Invalid Command" << endl;
        }
    }

    void DeleteAllContacts() {
        Node* temp = head;
        Node* temp2;
        if (head == NULL) {
            cout << "*" << endl;
            cout << "  Already Contact Book is Empty" << endl;
            cout << "*" << endl;
        } else {
            while (temp != NULL) {
                temp2 = temp;
                temp = temp->next;
                delete temp2;
            }
            head = NULL;
            cout << "*" << endl;
            cout << "  Successfully Deleted All Contacts" << endl;
            cout << "*" << endl;
        }
    }

    void DeleteContactBySearch() {
        Node* temp = head;
        cout << "*" << endl;
        cout << "  Press 1 if you want to Search By Name" << endl;
        cout << "  Press 2 if you want to Search By Number" << endl;
        cout << "*" << endl;
        int command;
        cout << "  Enter the Command: ";
        cin >> command;

        if (command == 1) {
            bool Dcheck = false;
            cout << "  Enter the Name to Delete: ";
            cin.ignore();
            getline(cin, x);
            if (!isValidName(x)) {
                cout << "  Invalid name! Name should contain only alphabets and spaces.\n";
                return;
            }
            while (temp != NULL) {
                if (temp->name == x) {
                    cout << "*" << endl;
                    cout << "  Name: " << temp->name << endl;
                    cout << "  Phone Number: " << temp->phone_number << endl;
                    cout << "*" << endl;
                    Dcheck = true;
                    break;
                }
                temp = temp->next;
            }
            if (Dcheck) {
                int command;
                cout << "  Press 1 to Delete the Contact: ";
                cin >> command;
                if (command == 1) {
                    if (temp == head) {
                        head = temp->next;
                        if (head != NULL) {
                            head->prev = NULL;
                        }
                    } else if (temp->next == NULL) {
                        temp->prev->next = NULL;
                    } else {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                    }
                    delete temp;
                    cout << "  Contact Deleted Successfully" << endl;
                } else {
                    cout << "  You Entered Wrong Command ... Try Again" << endl;
                }
            } else {
                cout << "  Contact of This Name Not Found." << endl;
            }
        } else if (command == 2) {
            bool Dcheck = false;
            cout << "  Enter the Number to Delete: ";
            string phoneStr;
            cin >> phoneStr;
            if (!isValidPhoneNumber(phoneStr)) {
                cout << "  Invalid phone number! Phone number should contain only digits.\n";
                return;
            }
            stringstream convert(phoneStr);
            convert >> y;
            while (temp != NULL) {
                if (temp->phone_number == y) {
                    cout << "*" << endl;
                    cout << "  Name: " << temp->name << endl;
                    cout << "  Phone Number: " << temp->phone_number << endl;
                    cout << "*" << endl;
                    Dcheck = true;
                    break;
                }
                temp = temp->next;
            }
            if (Dcheck) {
                int command;
                cout << "  Press 1 to Delete the Contact: ";
                cin >> command;
                if (command == 1) {
                    if (temp == head) {
                        head = temp->next;
                        if (head != NULL) {
                            head->prev = NULL;
                        }
                    } else if (temp->next == NULL) {
                        temp->prev->next = NULL;
                    } else {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                    }
                    delete temp;
                    cout << "  Contact Deleted Successfully" << endl;
                } else {
                    cout << "  You Entered Wrong Command ... Try Again" << endl;
                }
            } else {
                cout << "  Contact of This Number Not Found." << endl;
            }
        } else {
            cout << "  You Entered Wrong Command" << endl;
        }
    }

    void BubbleSort() {
        Node* temp = head;
        Node *i, *j;
        string n;
        long long int n2;
        if (temp == NULL) {
            cout << "  Empty Contact Book" << endl;
        } else {
            for (i = head; i->next != NULL; i = i->next) {
                for (j = i->next; j != NULL; j = j->next) {
                    if (i->name > j->name) {
                        n = i->name;
                        i->name = j->name;
                        j->name = n;

                        n2 = i->phone_number;
                        i->phone_number = j->phone_number;
                        j->phone_number = n2;
                    }
                }
            }
        }
    }

    void EditContacts() {
        Node* temp = head;
        cout << "*" << endl;
        cout << "  Press 1 if you want to Search By Name" << endl;
        cout << "  Press 2 if you want to Search By Number" << endl;
        cout << "*" << endl;
        int Ecommand;
        cout << "  Enter the Command: ";
        cin >> Ecommand;

        if (Ecommand == 1) {
            bool Echeck = false;
            cout << "  Enter the Name to Edit: ";
            cin.ignore();
            getline(cin, x);
            if (!isValidName(x)) {
                cout << "  Invalid name! Name should contain only alphabets and spaces.\n";
                return;
            }
            while (temp != NULL) {
                if (temp->name == x) {
                    cout << "" << endl;
                    cout << "  Name: " << temp->name << endl;
                    cout << "  Phone Number: " << temp->phone_number << endl;
                    cout << "" << endl;
                    Echeck = true;
                    break;
                }
                temp = temp->next;
            }
            if (Echeck) {
                int command;
                cout << "  Press 1 to Edit the Contact: ";
                cin >> command;
                if (command == 1) {
                    // Validate New Name
                    while (true) {
                        cout << "  Enter New Name: ";
                        cin.ignore();
                        getline(cin, x);
                        if (isValidName(x)) {
                            temp->name = x;
                            break;
                        } else {
                            cout << "  Invalid name! Name should contain only alphabets and spaces. Try again.\n";
                        }
                    }

                    // Validate New Phone Number
                    while (true) {
                        cout << "  Enter New Number: ";
                        string phoneStr;
                        cin >> phoneStr;
                        if (isValidPhoneNumber(phoneStr)) {
                            stringstream convert(phoneStr);
                            convert >> y;
                            temp->phone_number = y;
                            break;
                        } else {
                            cout << "  Invalid phone number! Phone number should contain only digits. Try again.\n";
                        }
                    }

                    cout << "  Contact Edited Successfully" << endl;
                } else {
                    cout << "  You Entered Wrong Command ... Try Again" << endl;
                }
            } else {
                cout << "  Contact Not Found" << endl;
            }
        } else if (Ecommand == 2) {
            bool Echeck = false;
            cout << "  Enter the Number to Edit: ";
            string phoneStr;
            cin >> phoneStr;
            if (!isValidPhoneNumber(phoneStr)) {
                cout << "  Invalid phone number! Phone number should contain only digits.\n";
                return;
            }
            stringstream convert(phoneStr);
            convert >> y;
            while (temp != NULL) {
                if (temp->phone_number == y) {
                    cout << "*" << endl;
                    cout << "  Name: " << temp->name << endl;
                    cout << "  Phone Number: " << temp->phone_number << endl;
                    cout << "*" << endl;
                    Echeck = true;
                    break;
                }
                temp = temp->next;
            }
            if (Echeck) {
                int command;
                cout << "  Press 1 to Edit the Contact: ";
                cin >> command;
                if (command == 1) {
                    // Validate New Name
                    while (true) {
                        cout << "  Enter New Name: ";
                        cin.ignore();
                        getline(cin, x);
                        if (isValidName(x)) {
                            temp->name = x;
                            break;
                        } else {
                            cout << "  Invalid name! Name should contain only alphabets and spaces. Try again.\n";
                        }
                    }

                    // Validate New Phone Number
                    while (true) {
                        cout << "  Enter New Number: ";
                        string phoneStr;
                        cin >> phoneStr;
                        if (isValidPhoneNumber(phoneStr)) {
                            stringstream convert(phoneStr);
                            convert >> y;
                            temp->phone_number = y;
                            break;
                        } else {
                            cout << "  Invalid phone number! Phone number should contain only digits. Try again.\n";
                        }
                    }

                    cout << "  Contact Edited Successfully" << endl;
                } else {
                    cout << "  You Entered Wrong Command ... Try Again" << endl;
                }
            } else {
                cout << "  Contact Not Found" << endl;
            }
        } else {
            cout << "  You Entered Wrong Command ... Try Again" << endl;
        }
    }

    void OflineSave() {
        Node* temp = head;
        ofstream myfile("contactbook.txt");
        if (myfile.is_open()) {
            while (temp != NULL) {
                myfile << temp->name << endl;
                myfile << temp->phone_number << endl;
                temp = temp->next;
            }
            myfile.close();
            Structure();
        } else {
            cout << "  Thanks file is empty." << endl;
        }
    }

    void reopenCB() {
        bool isEmpty;
        ifstream myfile("contactbook.txt");
        if (myfile.is_open() && myfile.peek() != EOF) {
            int i = 0;
            while (getline(myfile, x)) {
                if (i % 2 == 0) {
                    if (head == NULL) {
                        Node* newer = new Node;
                        newer->name = x;
                        newer->next = NULL;
                        newer->prev = NULL;
                        head = newer;
                    } else {
                        Node* newer = new Node;
                        newer->name = x;
                        newer->next = NULL;
                        Node* temp = head;
                        while (temp->next != NULL) {
                            temp = temp->next;
                        }
                        temp->next = newer;
                        newer->prev = temp;
                    }
                } else {
                    Node* temp = head;
                    if (temp->phone_number == 0) {
                        stringstream convert(x);
                        convert >> y;
                        temp->phone_number = y;
                    } else {
                        Node* temp = head;
                        while (temp->next != NULL) {
                            temp = temp->next;
                        }
                        stringstream convert(x);
                        convert >> y;
                        temp->phone_number = y;
                    }
                }
                i++;
            }
            myfile.close();
        } else {
            cout << "  File is Empty so Cannot open...Sorry" << endl;
        }
    }

    void BackupContacts() {
        Node* temp = head;
        ofstream backupFile("contactbook_backup.txt");
        if (backupFile.is_open()) {
            while (temp != NULL) {
                backupFile << temp->name << endl;
                backupFile << temp->phone_number << endl;
                temp = temp->next;
            }
            backupFile.close();
            cout << "Backup created successfully in 'contactbook_backup.txt'.\n";
        } else {
            cout << "Error creating backup file.\n";
        }
    }

    void RestoreContacts() {
        ifstream backupFile("contactbook_backup.txt");
        if (backupFile.is_open() && backupFile.peek() != EOF) {
            string name;
            long long int phone_number;
            head = NULL; // Clear the current contact list

            while (getline(backupFile, name)) {
                backupFile >> phone_number;
                backupFile.ignore(); // Ignore the newline character after phone number

                Node* newContact = new Node;
                newContact->name = name;
                newContact->phone_number = phone_number;
                newContact->next = NULL;

                if (head == NULL) {
                    newContact->prev = NULL;
                    head = newContact;
                } else {
                    Node* temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newContact;
                    newContact->prev = temp;
                }
            }
            backupFile.close();
            cout << "Contacts restored successfully from 'contactbook_backup.txt'.\n";
        } else {
            cout << "Backup file not found or is empty.\n";
        }
    }

    void Structure() {
    cout << "\n==========================================" << endl;
    cout << "|         CONTACT MANAGEMENT MENU        |" << endl;
    cout << "==========================================" << endl;
    cout << "|  1. Add a New Contact                  |" << endl;
    cout << "|  2. Edit an Existing Contact           |" << endl;
    cout << "|  3. Delete a Contact                   |" << endl;
    cout << "|  4. Search for a Contact               |" << endl;
    cout << "|  5. Display All Contacts               |" << endl;
    cout << "|  6. Delete All Contacts                |" << endl;
    cout << "|  7. Create a Backup                    |" << endl;
    cout << "|  8. Restore Contacts from Backup       |" << endl;
    cout << "|  9. Exit                               |" << endl;
    cout << "==========================================" << endl;


        int command;
        cout << "Enter the Command: ";
        cin >> command;

        try {
            if (command >= 1 && command <= 9) {
                if (command == 1) {
                    CreateNode();
                    OflineSave();
                    Structure();
                } else if (command == 2) {
                    EditContacts();
                    OflineSave();
                    Structure();
                } else if (command == 3) {
                    DeleteContactBySearch();
                    Structure();
                } else if (command == 4) {
                    Search();
                    Structure();
                } else if (command == 5) {
                    Display();
                    OflineSave();
                    Structure();
                } else if (command == 6) {
                    DeleteAllContacts();
                    OflineSave();
                    Structure();
                } else if (command == 7) {
                    BackupContacts();
                    Structure();
                } else if (command == 8) {
                    RestoreContacts();
                    Structure();
                } else if (command == 9) {
                cout << "\n==========================================" << endl;
                cout << "|         EXITING CONTACT BOOK           |" << endl;
                cout << "==========================================" << endl;
                cout << "|   Thank you for using the Contact Book |" << endl;
                cout << "|   Your session has ended.              |" << endl;
                cout << "|   Goodbye and have a great day!        |" << endl;
                cout << "==========================================" << endl;
                cout << "|   Exiting the Contact Book... Goodbye! |" << endl;
                cout << "==========================================" << endl;
                exit(0); 
                }
            } else {
                throw(command);
            }
        } catch (int command) {
            cout << "You Entered an Invalid Command... Try Again" << endl;
            Structure();
        }
    }
};

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main() {
    setColor(2);
    string username = "Admin";
    string password = "pass";
    string enteredUsername, enteredPassword;

    // Admin Login
    cout << "\n\t\t\t\t\t\t---------------------------------";
    cout << "\n\t\t\t\t\t\t| Admin Login |\n";
    cout << "\t\t\t\t\t\t---------------------------------\n";
    cout << "\t\t\t\t\t\t| Enter username: ";
    cin >> enteredUsername;
    cout << "\t\t\t\t\t\t| Enter password: ";
    cin >> enteredPassword;
    cout << "\t\t\t\t\t\t---------------------------------\n\n";

    if (enteredUsername != username || enteredPassword != password) {
        cout << "\n\t\t\t\t\t\tLogin Failed! Access Denied.\n\n\n";
        return 0;
    }

    cout << "\n\t\t\t\t\t\t\tLogin Successful!\n\n\n";
    setColor(5);
    ContactBook cb;
    cb.reopenCB();

  
    cout << "\t\t\t\t\t\t  **********************************************" << endl;
    cout << "\t\t\t\t\t\t  *                                            *" << endl;
    cout << "\t\t\t\t\t\t  *      WELCOME TO YOUR CONTACT BOOK          *" << endl;
    cout << "\t\t\t\t\t\t  *      YOUR CONTACTS, ALWAYS ORGANIZED       *" << endl;
    cout << "\t\t\t\t\t\t  *                                            *" << endl;
    cout << "\t\t\t\t\t\t  **********************************************" << endl;


    cb.Structure();

    return 0;
}
