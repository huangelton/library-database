#include <string>

class Library {

    private:
        struct Node {
            std::string bookTitle; // book title
            std::string authorName; // author name
            long ID; // ISBN
            double price; // book price
            Node *next; 
        };
        Node *head; // head pointer
   
    public:
    
        Library(); // default constructor
        ~Library(); // destructor
        Library(const Library &objList); // copy constructor
        Library & operator=(const Library &objList); // assignment operator
        void addData(std::string, std::string, long, double); // insert node
        // precondition: valid string, long int, and double 
        // postcondition: none
    
        bool searchData(long); // search node
        // precondition: valid long int
        // postcondition: return true or false
        
        void deleteData(long); // remove node
        // precondition: valid long int
        // postcondition: none
    
        void deleteItem(); // helper function
        // precondition: none
        // postcondition: none
    
        void displayList(); // display list
        // precondition: none
        // postcondition: none
        
        void saveFile(std::string); // save file
        // precondition: valid string
        // postcondition: none

        void displayBook(long); // view book
        // precondition: valid long integer
        // postcondition: none

        bool checkEmpty(); // check empty
        // precondition: none
        // postcondition: none
};