#include <iostream>
#include <iomanip>
#include <fstream>
#include "system.h"

using namespace std;

Library::Library() { // default constructor

    head = nullptr; // initialize head to nullptr
}

Library::~Library() { // destructor

    Node* nPtr;
    Node* newNode;
    nPtr = head;
    
    while (nPtr) {

        newNode = nPtr->next; // move to next node
        delete nPtr; // deletes node
        nPtr = newNode; // change position to next node
    }
    head = nullptr;
}

Library::Library(const Library &objList) { // copy constructor
    
    Node* nPtr = objList.head;
    head = nullptr;
    
    while (nPtr != nullptr) { // while list not empty
        
        addData(nPtr->bookTitle, nPtr->authorName, nPtr->ID, nPtr->price); // inserts node
        nPtr = nPtr->next; // traverse next node
    }
}

Library & Library::operator=(const Library &objList) { // copy assignment
    
    while (head != nullptr) {

        Node* temp = head->next; // set temp to next node
        delete head; // deletes head
        head = temp;
    }
    Node* nPtr = objList.head;

    while (nPtr != nullptr) { // while list not empty
        
        addData(nPtr->bookTitle, nPtr->authorName, nPtr->ID, nPtr->price);
        nPtr = nPtr->next; // traverse
    }
    return *this;
}

void Library::addData(string book, string author, long num, double cost) {
    // implementation of insert using doubly linked list
    Node* prevPtr;
    Node* nPtr;
    Node* newNode = new Node; // creates new node
    newNode->bookTitle = book; // stores title
    newNode->authorName = author; // stores name
    newNode->ID = num; // stores ISBN
    newNode->price = cost; // stores book price
    newNode->next = nullptr;
    
    if (head == nullptr) {

        head = newNode;
        newNode->next = nullptr; // newNode is first node
    }

    else { // add node

        prevPtr = nullptr; // initialize to nullptr
        nPtr = head;

        while (nPtr != nullptr) {

            prevPtr = nPtr;
            nPtr = nPtr->next;
        }
        // insert before the node
        if (prevPtr == nullptr) {

            head = nPtr;
            newNode->next = nPtr;
        }
        // insert after the previous node
        else {

            prevPtr->next = newNode;
            newNode->next = nPtr;
        }
    }    
}

bool Library::searchData(long num) { // search function

    Node* nPtr;
    nPtr = head;

    while (nPtr != nullptr) { 

        if (nPtr->ID == num) { // run this if num is found

            return true;
        }
        nPtr = nPtr->next; // next node
    }
    cout << "\nThe book is not found in the library database.\n";
    return false;
}

void Library::deleteData(long num) { // delete function

    Node* nPtr;
    Node* prevPtr;

    if (!head) { // empty list

        return;
    }

    if (head->ID == num) {

        nPtr = head->next;
        delete head;
        head = nPtr;
    }

    else { // traverses the list

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

void Library::displayList() { // display function

    Node* nPtr = head;
    // shows readable interface

    while (nPtr != nullptr) { // while list not empty

        cout << "\nTitle: " << nPtr->bookTitle;
        cout << "\nAuthor: " << nPtr->authorName;
        cout << "\nISBN: " << nPtr->ID;
        cout << "\nPrice($): " << nPtr->price;
        cout << endl;
        nPtr = nPtr->next;
    }
}

void Library::displayBook(long num) {

  Node* nPtr = head;  

  if (searchData(num)) {

    cout << "Title: " << nPtr->bookTitle << endl;
    cout << "Authors: " << nPtr->authorName << endl;
    cout << "ISBN: " << nPtr->ID << endl;
    cout << "Price($): " << nPtr->price;
  }
}

void Library::saveFile(string choose) {

    Node* nPtr = head;
    ofstream file;
    file.open(choose);

    while (nPtr != nullptr) {

        file << nPtr->bookTitle << " ";
        file << nPtr->authorName << " ";
        file << nPtr->ID << " ";
        file << nPtr->price << endl;
        nPtr = nPtr->next;
    }
    file.close();
}

bool Library::checkEmpty() {

    return head == nullptr;
}
