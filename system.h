class Library {

    private:
        struct Node {
            std::string bookTitle; // book title
            std::string authorName; // author's name
            long ID; // ISBN
            double price; // book price
            Node *next; 
        };
        Node *head; // head pointer
   
    public:
        Library(); // constructor
        ~Library(); // destructor
        Library(const Library &objList); // copy constructor
        Library & operator=(const Library &objList); // copy assignment
        void addData(std::string, std::string, long, double); // insert node   
        bool searchData(long); // search 
        void deleteData(long); // remove 
        void deleteItem(); // helper function
        int getTotalBooks(); // total books
        void displayList() const; // display books
};