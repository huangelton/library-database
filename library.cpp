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
    int option, total;
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
        cout << "(6) View number of book(s)\n";
        cout << "(7) Exit the library database\n";
        cout << "\nChoose an option (1-7): ";
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
                cout << "\nPrices: ";
                cin >> prices;
                manage.addData(title, name, id, prices);
                cout << "\nThe book has now been added to the library database.\n";
                break;
                
            case 2: // remove book from system

                cout << "\nEnter the ISBN of the book to remove: ";
                cin >> id;
            
                if (manage.searchData(id)) {

                    manage.deleteData(id);
                    cout << "The book has been deleted.\n";
                }
                break;

            case 3: // searches a book based on ISBN

                cout << "\nSearch for the book by entering the ISBN: ";
                cin >> id;
                manage.searchData(id);
                break;
            
            case 4: // save data to a file

                cout << "Enter a filename: ";
                cin >> choose;

                if (fstream(choose)) { // runs if file exists

                    cout << "Overwriting '" << choose << "' file.\n";
                }

                else { // new file

                    cout << "Creating '" << choose << "' file.\n";
                }
                manage.saveFile(choose); // writes to file
                break;

            case 5: // display entire library catalog

                manage.displayList();
                break;

            case 6: // view total number books

                total = manage.getTotalBooks();

                if (total == 1) {

                    cout << "\nThere is currently a total of " << total << " book in the database.\n";
                }

                else if (total > 1) {

                    cout << "\nThere is currently a total of " << total << " books in the database.\n";
                }

                else {

                    cout <<"\nThe database is currently empty.\n";
                }
                break;

            default: // exits out of database

                cout << "\nExiting out of the library database.\n";
                exit(1);
        }
        cout << endl;
        cout << "\nDo you want to manage the library database again? (y/n): ";
        cin >> ask;
        cout << endl;
        
    } while (ask == 'Y' || ask == 'y'); // runs again if input is Y or y

    return 0;
} // end of program



