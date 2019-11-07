#include <iostream>
#include "project1.h"

using namespace std;

int main() {

    Library manage;
    bool comply = false;
    const char YES = 'Y';
    char ask = YES;
    string title, name;
    double id, prices;
    int option;
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

            comply = false;

            cout << "\nTitle: ";
            getline(cin, title);
            cout << "\nAuthor: ";
            getline(cin, name);

            while (!comply) {

                comply = true;
                cout << "\nISBN: ";
                cin >> id;

                if (cin.fail()) {

                    cin.clear();
                    cin.ignore();
                    cout << "Invalid input. Try again.";
                    comply = false;
                }
            }

            while (comply) {

                comply = false;
                cout << "\nPrices: ";
                cin >> prices;

                if (cin.fail()) {

                    cin.clear();
                    cin.ignore();
                    cout << "Invalid input. Try again.";
                    comply = true;;
                }
            }
            manage.addData(title, name, id, prices);
        }

        else if (option == 2) {

            comply = false;

            while (!comply) {

                comply = true;
                cout << "\nEnter the ISBN of the book to delete: ";
                cin >> id;

                if (cin.fail()) {

                    cin.clear();
                    cin.ignore();
                    cout << "Invalid input. Try again.";
                    comply = false;
                }
            }
            manage.deleteData(id);
        }

        else if (option == 3) {

            comply = false;

            while (!comply) {

                comply = true;
                cout << "\nSearch for the book by entering the ID: ";
                cin >> id;

                if (cin.fail()) {

                    cin.clear();
                    cin.ignore();
                    cout << "Invalid input. Try again.";
                    comply = false;
                }
            }
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