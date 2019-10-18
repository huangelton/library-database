#include <string>

using namespace std;

class Library {

    private:
        struct Node {
            string bookTitle;
            string authorName;
            int ID;
            int price;
            Node *next;
        };
        Node *head;
   
    public:
        Library();
        ~Library();
        void addData(string, string, int, int);   
        void searchData(int);
        void deleteData(int); 
        void displayList() const;
};