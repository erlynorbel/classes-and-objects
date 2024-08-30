#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100;  // Maximum number of books the library can hold

class Book {
private:
    string title;
    string author;
    int year;

public:
    // Constructor with default parameters
    Book(string userTitle = "", string userAuthor = "", int userYear = 0) {
        title = userTitle;
        author = userAuthor;
        year = userYear;
    }

    // Method to display book details
    void displayBook() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }

    // Getter for title
    string getTitle() {
        return title;
    }
};

class Library {
private:
    Book books[MAX_BOOKS];  // Array to store Book objects
    int bookCount;          // Keeps track of the number of books in the library

public:
    // Constructor to initialize the library 
    Library() : bookCount(0) {}

    // Method to add a new book to the library
    void addBook(string title, string author, int year) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount] = Book(title, author, year);
            bookCount++;
            cout << "Book added successfully!" << endl;
        } else {
            cout << "Library is full. Cannot add more books." << endl;
        }
    }

    // Method to display all books in the library
    void displayBooks() {
        if (bookCount == 0) {
            cout << "No books in the library." << endl;
            return;  // Return to avoid further processing
        }

        // Display all books
        for (int i = 0; i < bookCount; i++) {
            books[i].displayBook();
        }
    }

    // Method to search for a book by title
    void searchBook(string title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title) {
                cout << "Book found!" << endl;
                books[i].displayBook();
                return;
            }
        }
        cout << "Book not found!" << endl;
    }
};

int main() {
    Library library;  // Create a library object
    int choice;
    string title, author;
    int year;

    while (true) {
        cout << "\nMenu" << endl;
        cout << "1 - Add Book" << endl;
        cout << "2 - Display Books" << endl;
        cout << "3 - Search Book" << endl;
        cout << "4 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:  // Add a new book
                cout << "Enter title: ";
                cin.ignore();  // To ignore the newline character left in the input buffer
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter year: ";
                cin >> year;
                library.addBook(title, author, year);
                break;
            case 2:  // Display all books
                library.displayBooks();
                break;
            case 3:  // Search for a book by title
                cout << "Enter the title of the book to search: ";
                cin.ignore();  // To ignore the newline character left in the input buffer
                getline(cin, title);
                library.searchBook(title);
                break;
            case 4:  // Exit the program
                cout << "Exiting the program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
