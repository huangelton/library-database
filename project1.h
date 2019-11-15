class Library {

    private:
        struct Node {
            std::string bookTitle;
            std::string authorName;
            long ID;
            double price;
            Node *next;
        };
        Node *head;
   
    public:
        Library();
        ~Library();
        Library(const Library &objList);
        Library & operator=(const Library &objList);
        void addData(std::string, std::string, long, double);   
        bool searchData(long);
        void deleteData(long);
        void deleteItem();
        int getTotalBooks();
        void displayList() const;
        void checkError();
};