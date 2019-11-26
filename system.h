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
        bool searchData(long); // search node
        void deleteData(long); // remove node
        void deleteItem(); // helper function
        int getTotalBooks(); // find total books
        void displayList() const; // display list
};