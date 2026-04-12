#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Book {
private:
    string Title;
    string Author;
    string ISBN;
    bool Availability;
    string DateAdd;

public:
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

    void borrowBook() {
        if (Availability) {
            Availability = false;
            cout << "Success: You have successfully borrowed '" << Title << "'." << endl;
        } else {
            cout << "Error: The book '" << Title << "' is currently unavailable." << endl;
        }
    }

    void returnBook() {
        Availability = true;
        cout << "Success: '" << Title << "' has been returned." << endl;
    }

    string getISBN() { return ISBN; }
    bool isAvailable() { return Availability; }

    static void sortBookData(Book books[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (books[j].getISBN() > books[j + 1].getISBN()) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    const int SIZE = 5;
    Book library[SIZE];

    library[0].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "9780743273", true, "2023-01-15");
    library[1].setBookDetails("1984", "George Orwell", "9780451524", true, "2023-02-20");
    library[2].setBookDetails("To Kill a Mockingbird", "Harper Lee", "9780060935", false, "2022-11-05");
    library[3].setBookDetails("Moby Dick", "Herman Melville", "9781503280", true, "2023-03-10");
    library[4].setBookDetails("Pride and Prejudice", "Jane Austen", "9781503290", true, "2023-04-01");

    Book::sortBookData(library, SIZE);

    string inputISBN;

    while (true) {
        cout << "\n--- Library Book System ---" << endl;
        cout << left << setw(30) << "Title" << setw(20) << "Author" << setw(15) << "ISBN" << setw(15) << "Date Added" << "Status" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < SIZE; i++) {
            library[i].displayBookDetails();
        }
        
        cout << "\nEnter the ISBN of the book you wish to borrow (Enter '0' to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        }

        bool found = false;
        for (int i = 0; i < SIZE; i++) {
            if (library[i].getISBN() == inputISBN) {
                found = true;
                library[i].borrowBook();
                break;
            }
        }

        if (!found) {
            cout << "Error: No book found with ISBN " << inputISBN << "." << endl;
        }
    }

    return 0;
}

//commit