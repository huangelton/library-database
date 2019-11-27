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
        Library & operator=(const Library &objList); // copy assignment
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
    
        int getTotalBooks(); // find total books
        // precondition: none
        // postcondition: return integer
    
        void displayList() const; // display list
        // precondition: none
        // postcondition: none
        
        void saveFile(std::string);
        // precondition: valid string
        // postcondition: none
};





