#include <iostream>
#include <iomanip>
#include "project1.h"

using namespace std;

Library::Library() {

    head = nullptr;
}

Library::~Library() {

    Node* nPtr;
    Node* newNode;
    nPtr = head;
    
    while (nPtr) {

        newNode = nPtr->next;
        delete nPtr;
        nPtr = newNode;
    }
    head = nullptr;
}

Library::Library(const Library &objList) {
    
    Node* nPtr = objList.head;
    head = nullptr;
    
    while (nPtr != nullptr) {
        
        addData(nPtr->bookTitle, nPtr->authorName, nPtr->ID, nPtr->price);
        nPtr = nPtr->next;
    }
}

Library & Library::operator=(const Library &objList) {
    
    while (head != nullptr) {

        Node* temp = head->next;
        delete head;
        head = temp;
    }
    Node* nPtr = objList.head;

    while (nPtr != nullptr) {
        
        addData(nPtr->bookTitle, nPtr->authorName, nPtr->ID, nPtr->price);
        nPtr = nPtr->next;
    }
    return *this;
}

void Library::addData(string book, string author, long num, double cost) {

    Node* prevPtr;
    Node* nPtr;
    Node* newNode = new Node;
    newNode->bookTitle = book;
    newNode->authorName = author;
    newNode->ID = num;
    newNode->price = cost;
    newNode->next = nullptr;
    
    if (head == nullptr) {

        head = newNode;
        newNode->next = nullptr;
    }

    else {

        prevPtr = nullptr;
        nPtr = head;

        while (nPtr != nullptr) {

            prevPtr = nPtr;
            nPtr = nPtr->next;
        }

        if (prevPtr == nullptr) {

            head = nPtr;
            newNode->next = nPtr;
        }

        else {

            prevPtr->next = newNode;
            newNode->next = nPtr;
        }
    }    
}

bool Library::searchData(long num) {

    Node* nPtr;
    nPtr = head;

    while (nPtr != nullptr) {

        if (nPtr->ID == num) {

            cout << endl << nPtr->bookTitle << " by " 
            << nPtr->authorName << " is in the library database.\n";
            return true;
        }
        nPtr = nPtr->next;
    }
    cout << "\nThe book is not found in the library database.\n";
    return false;
}

void Library::deleteData(long num) {

    Node* nPtr;
    Node* prevPtr;

    if (!head)

        return;
    
    if (head->ID == num) {

        nPtr = head->next;
        delete head;
        head = nPtr;
    }

    else {

        nPtr = head;

        while (nPtr != nullptr && nPtr->ID != num) {

            prevPtr = nPtr;
            nPtr = nPtr->next;
        }

        if (nPtr) {

            prevPtr->next = nPtr->next;
            delete prevPtr;
        }
    }
}

int Library::getTotalBooks() {

    Node* nPtr = head;
    int total = 0;

    while (nPtr != nullptr) {

        total++;
        nPtr = nPtr->next;
    }
    return total;
}

void Library::displayList() const {

    Node* nPtr = head;
    cout << endl;
    cout << left << setw(26) << "Book Title" << setw(22) << 
    "Author" << setw(19) << "ISBN" << setw(17) << "Price($)" << endl;

    while (nPtr != nullptr) {

        cout << left << setw(26) << nPtr->bookTitle << setw(22) 
        << nPtr->authorName << setw(19) << nPtr->ID 
        << setw(17) << nPtr->price << endl;
        nPtr = nPtr->next;
    }
}