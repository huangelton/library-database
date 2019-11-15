#include <iostream>
#include "project1.h"

using namespace std;

int main() {

    Library manage;
    const char YES = 'Y';
    bool comply = false;
    char ask = YES;
    string title, name;
    long id;
    double prices;
    int option;
    cout << "\n*  * Library Database Management System *  *\n";
    cout << "\n--------------------------------------------\n";

    do {

        cout << "\nMenu: Select your option\n";
        cout << "\n(1) Add a book to the database\n";
        cout << "(2) Delete a book by ISBN\n";
        cout << "(3) Search for a book by ISBN\n";
        cout << "(4) Display all books\n";
        cout << "(5) Display number of books\n";
        cout << "(6) Exit the library database\n";
        cout << "\nChoose an option (1-6): ";
        cin >> option;
        cin.ignore();

        if (option == 1) {

            cout << "\nTitle: ";
            getline(cin, title);
            cout << "\nAuthor: ";
            getline(cin, name);
            cout << "\nISBN: ";
            cin >> id;
            cout << "\nPrices: ";
            cin >> prices;
            manage.addData(title, name, id, prices);
            cout << "\nThe book has now been added to the library database.\n";
        }
                
        else if (option == 2) {

            cout << "\nEnter the ISBN of the book to remove: ";
            cin >> id;
            
            if (manage.searchData(id)) {

                manage.deleteData(id);
                cout << "The book has been deleted.\n";
            }
        }

        else if (option == 3) {

            cout << "\nSearch for the book by entering the ISBN: ";
            cin >> id;
            manage.searchData(id);
        }

        else if (option == 4) {

            manage.displayList();
        }

        else if (option == 5) {

            int total = manage.getTotalBooks();

            if (total == 1) {

                cout << "\nThere is currently a total of " << total << " book in the database.\n";
            }

            else {

                cout << "\nThere is currently a total of " << total << " books in the database.\n";
            }
        }

        else {

            break;
        }
        cout << endl;
        cout << "\nDo you want to manage the library database again? (y/n): ";
        cin >> ask;
        cout << endl;
        
    } while (ask == 'Y' || ask == 'y');

    cout << "\nExiting out of the library database.\n";
    return 0;
}