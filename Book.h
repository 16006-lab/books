#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Author.h"

using namespace std;

class Book {
private:
    string Title;
    Author bookAuthor;
    string ISBN;
    bool Availability;
    string DateAdd;

public:
    Book() : Title(""), ISBN(""), Availability(false), DateAdd("") {}

    void setBookDetails(string t, Author a, string i, bool avail, string date) {
        Title = t;
        bookAuthor = a;
        ISBN = i;
        Availability = avail;
        DateAdd = date;
    }

    string getISBN() const { return ISBN; }
    
    void displayBookDetails() const {
        cout << left << setw(20) << Title 
             << setw(20) << bookAuthor.getFullName() 
             << setw(15) << ISBN 
             << (Availability ? "Available" : "Borrowed") << endl;
    }
};

#endif