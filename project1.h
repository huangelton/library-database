#include <string>

using namespace std;

class Library {

    private:
        struct Node {
            string bookTitle;
            string authorName;
            double ID;
            double price;
            Node *next;
        };
        Node *head;
   
    public:
        Library();
        ~Library();
        Library(const Library &objList);
        Library & operator=(const Library &objList);
        void addData(string, string, double, double);   
        void searchData(int);
        void deleteData(int);
        void deleteItem();
        int getTotalBooks();
        void displayList() const;
};