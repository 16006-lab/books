#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Author.h" // Import the new Author class

using namespace std;

class Book {
private:
    string Title;
    Author bookAuthor; // Changed from string to Author object
    string ISBN;
    bool Availability;
    string DateAdd;

public:
    // Default constructor
    Book() : Title(""), ISBN(""), Availability(false), DateAdd("") {}

    // Updated initialization method taking an Author object
    void setBookDetails(string t, Author a, string i, bool avail, string date) {
        Title = t;
        bookAuthor = a;
        ISBN = i;
        Availability = avail;
        DateAdd = date;
    }

    string getISBN() const { return ISBN; }
    
    void displayBookDetails() const {
        // We use bookAuthor.getName() to extract the author's string value for display
        cout << left << setw(20) << Title 
             << setw(20) << bookAuthor.getName() 
             << setw(15) << ISBN 
             << (Availability ? "Available" : "Borrowed") << endl;
    }
};

#endif