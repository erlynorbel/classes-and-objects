#include <iostream> 

using namespace std; 

const int MAX_BOOKS = 100; 

class Book {
    private: 
        string title; 
        string author; 
        int year; 
    
    public:

        Book(string userTitle = "", string userAuthor = "", int userYear = 0){
            title = userTitle;
            author = userAuthor;
            year = userYear;
        }

        void displayBook(){
            cout << "Title: " << title << endl; 
            cout << "Author: " << author << endl;
            cout << "Year: " << year << endl;
        }
};

class Library{
    private: 
        Book books[MAX_BOOKS]; 
        int bookCount;

    public: 
        Library() : bookCount(0) {}



    void addBook(string title, string author, int year){
        if (bookCount < MAX_BOOKS){
            books[bookCount] = Book(title, author, year);
            bookCount++;
            cout << "Book addedd succesfully!" << endl; 
        } else {
            cout << "Library is full. Cannot add more books." << endl; 
        }
    } 

    void displayBooks(){

        if (bookCount == 0){
            cout << "No books in the library." << endl;
        }

        for (int i = 0; i < bookCount; i++){ 
            books[i].displayBook();
        }
    }

    void addBook(){ 

    }
};


int main(){

    Library myLibrary; 

}