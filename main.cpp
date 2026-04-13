#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Class 1: Book (Dependency) - Represents an individual entity
class Book {
private:
    string Title;
    string Author;
    string ISBN;
    bool Availability;
    string DateAdd;

public:
    // Default constructor (required for initializing an array of objects)
    Book() : Title(""), Author(""), ISBN(""), Availability(false), DateAdd("") {}

    void setBookDetails(string t, string a, string i, bool avail, string date) {
        Title = t;
        Author = a;
        ISBN = i;
        Availability = avail;
        DateAdd = date;
    }

    void displayBookDetails() {
        cout << left << setw(30) << Title 
             << setw(20) << Author 
             << setw(15) << ISBN 
             << setw(15) << DateAdd
             << (Availability ? "Available" : "Borrowed") << endl;
    }

    // Getters and state modifiers
    string getTitle() { return Title; }
    string getISBN() { return ISBN; }
    bool isAvailable() { return Availability; }
    
    void markBorrowed() { Availability = false; }
    void markReturned() { Availability = true; }
};

// Class 2: Library - Manages the collection (Aggregation of Books)
class Library {
private:
    static const int MAX_BOOKS = 5;
    Book catalog[MAX_BOOKS]; // The array dependency 
    int bookCount;

public:
    Library() { bookCount = 0; }

    // Adds a book to the library's catalog array
    void addBook(string t, string a, string i, bool avail, string date) {
        if (bookCount < MAX_BOOKS) {
            catalog[bookCount].setBookDetails(t, a, i, avail, date);
            bookCount++;
        }
    }

    // Sorts the catalog by ISBN using Bubble Sort
    void sortBookData() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - i - 1; j++) {
                if (catalog[j].getISBN() > catalog[j + 1].getISBN()) {
                    Book temp = catalog[j];
                    catalog[j] = catalog[j + 1];
                    catalog[j + 1] = temp;
                }
            }
        }
    }

    // Displays all books currently in the catalog
    void displayCatalog() {
        cout << left << setw(30) << "Title" << setw(20) << "Author" << setw(15) << "ISBN" << setw(15) << "Date Added" << "Status" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < bookCount; i++) {
            catalog[i].displayBookDetails();
        }
    }

    // Searches for a book by ISBN and attempts to borrow it
    void borrowBook(string isbn) {
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (catalog[i].getISBN() == isbn) {
                found = true;
                if (catalog[i].isAvailable()) {
                    catalog[i].markBorrowed();
                    cout << "Success: You have successfully borrowed '" << catalog[i].getTitle() << "'." << endl;
                } else {
                    cout << "Error: The book '" << catalog[i].getTitle() << "' is currently unavailable." << endl;
                }
                break;
            }
        }
        if (!found) {
            cout << "Error: No book found with ISBN " << isbn << "." << endl;
        }
    }
};

// Main Application
int main() {
    Library myLibrary;

    // Initialize the library with 5 books
    myLibrary.addBook("The Great Gatsby", "F. Scott Fitzgerald", "9780743273", true, "2023-01-15");
    myLibrary.addBook("1984", "George Orwell", "9780451524", true, "2023-02-20");
    myLibrary.addBook("To Kill a Mockingbird", "Harper Lee", "9780060935", false, "2022-11-05");
    myLibrary.addBook("Moby Dick", "Herman Melville", "9781503280", true, "2023-03-10");
    myLibrary.addBook("Pride and Prejudice", "Jane Austen", "9781503290", true, "2023-04-01");

    // Sort books by ISBN before displaying
    myLibrary.sortBookData();

    string inputISBN;

    while (true) {
        cout << "\n--- Library Book System ---" << endl;
        myLibrary.displayCatalog();
        
        cout << "\nEnter the ISBN of the book you wish to borrow (Enter '0' to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        }

        // The library object handles the searching and validation
        myLibrary.borrowBook(inputISBN);
    }

    return 0;
}