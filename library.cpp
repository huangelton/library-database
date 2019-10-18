#include <iostream>
#include "project_1.h"

using namespace std;

int main() {

    Library manage;
    int option;
    const char YES = 'Y';
    char ask = YES;
    string title, name;
    int id, prices;
    cout << "\n*  * Library Database Management System *  *\n";
    cout << "\n--------------------------------------------\n";

    do {

        cout << "\nMenu: Select your option\n";
        cout << "\n(1) Add a book to the database\n";
        cout << "(2) Delete a book by ISBN\n";
        cout << "(3) Search for a book by ISBN\n";
        cout << "(4) Display all books\n";
        cout << "(5) Exit the library database\n";
        cout << "\nChoose an option (1-5): ";
        cin >> option;
        cin.ignore();

        if (option == 1) {

            cout << "\nTitle: ";
            getline(cin, title);
            cout << "\nAuthor: ";
            getline(cin, name);
            cout << "\nISBN: ";
            cin >> id;
            cout << "\nPrice: ";
            cin >> prices;
            manage.addData(title, name, id, prices);
        }

        else if (option == 2) {

            cout << "\nEnter the ISBN of the book to delete: ";
            cin >> id;
            manage.deleteData(id);
        }

        else if (option == 3) {

            cout << "\nSearch for the book by entering the ID: ";
            cin >> id;
            manage.searchData(id);
        }

        else if (option == 4) {

            manage.displayList();
        }

        else {

            break;
        }
        cout << endl;
        cout << "\nDo you want to manage the library database again? (y/n): ";
        cin >> ask;
        cout << endl;
        
    } while (ask == 'Y' || ask == 'y');

    cout << "\n\nExiting out of the database.\n";
    return 0;
}