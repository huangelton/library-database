#include <iostream>
#include <fstream>
#include "system.h"

using namespace std;

int main() {

    Library manage; // creates class object
    const char YES = 'Y'; 
    char ask = YES;
    string title, name; // book title and author's name
    long id; // ISBN
    double prices; // book price
    int option;
    string choose;
    cout << "\n*  * Library Database Management System *  *\n";
    cout << "\n--------------------------------------------\n";

    do { // do-while loop to re-modify the database

        cout << "\nMenu: Select your option\n";
        cout << "\n(1) Add a book to the database\n";
        cout << "(2) Delete a book by ISBN\n";
        cout << "(3) Search for a book by ISBN\n";
        cout << "(4) Save to a file\n";
        cout << "(5) Display list of books\n";
        cout << "(6) Exit the library database\n";
        cout << "\nChoose an option (1-6): ";
        cin >> option; // choose option from 1-7
        cin.ignore();
        
        switch(option) { // switch statement for readability

            case 1: // add book to system

                cout << "\nTitle: ";
                getline(cin, title);
                cout << "\nAuthor: ";
                getline(cin, name);
                cout << "\nISBN: ";
                cin >> id;
                cout << "\nPrice($): ";
                cin >> prices;
                manage.addData(title, name, id, prices);
                cout << "\nThe book has now been added to the library database.\n";
                break;
                
            case 2: // remove book from system

                cout << "\nEnter the ISBN of the book: ";
                cin >> id;
            
                if (manage.searchData(id)) {

                    manage.deleteData(id);
                    cout << "\nThe book has been deleted.\n";
                }
                break;

            case 3: // searches a book based on ISBN

                cout << "\nEnter the ISBN of the book: ";
                cin >> id;
                cout << endl;
                manage.displayBook(id);
                break;
            
            case 4: // save data to a file

                cout << "\nEnter a filename: ";
                cin >> choose;

                if (fstream(choose)) { // runs if file exists

                    cout << "\nOverwriting '" << choose << "' file.\n";
                }

                else { // new file

                    cout << "\nCreating '" << choose << "' file.\n";
                }
                manage.saveFile(choose); // writes to file
                break;

            case 5: // display entire library catalog

                if (manage.checkEmpty()) { // check if empty

                    cout << "\nThe library catalog is currently empty.\n";
                }

                else { // otherwise display library

                    manage.displayList();
                }
                break;

            default: // exits out of database

                cout << "\n\nExiting out of the library database.\n\n";
                exit(1);
        }
        cout << endl;
        cout << "\nDo you want to manage the library database again? (y/n): ";
        cin >> ask;
        cout << endl;
        
    } while (ask == 'Y' || ask == 'y'); // runs again if input is Y or y

    return 0;
} // end of program



