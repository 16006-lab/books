#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
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
    Book() : Title(""), Author(""), ISBN(""), Availability(false), DateAdd("") {}

    void setBookDetails(string t, string a, string i, bool avail, string date) {
        Title = t; Author = a; ISBN = i; Availability = avail; DateAdd = date;
    }

    string getISBN() const { return ISBN; }
    
    void displayBookDetails() const {
        cout << left << setw(20) << Title 
             << setw(15) << Author 
             << setw(15) << ISBN 
             << (Availability ? "Available" : "Borrowed") << endl;
    }
};

#endif