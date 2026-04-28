#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include "Author.h"

using namespace std;

class Book {
private:
    string Title;
    Author bookAuthor;
    string ISBN;
    bool Availability;
    string DateAdd;
    bool ValidBook;

    bool isEmpty(const string& value) const {
        return value.empty();
    }

    bool isValidISBN(const string& isbn) const {
        if (isbn.empty()) {
            return false;
        }

        if (isbn.length() != 10 && isbn.length() != 13) {
            return false;
        }

        for (char c : isbn) {
            if (!isdigit(c)) {
                return false;
            }
        }

        return true;
    }

    bool isValidDate(const string& date) const {
        if (date.length() != 10) {
            return false;
        }

        if (date[4] != '-' || date[7] != '-') {
            return false;
        }

        for (int i = 0; i < date.length(); i++) {
            if (i != 4 && i != 7 && !isdigit(date[i])) {
                return false;
            }
        }

        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        if (month < 1 || month > 12) {
            return false;
        }

        if (day < 1 || day > 31) {
            return false;
        }

        return true;
    }

public:
    Book() : Title(""), ISBN(""), Availability(false), DateAdd(""), ValidBook(false) {}

    bool setBookDetails(string t, Author a, string i, bool avail, string date) {
        if (isEmpty(t)) {
            ValidBook = false;
            return false;
        }

        if (!a.isValid()) {
            ValidBook = false;
            return false;
        }

        if (!isValidISBN(i)) {
            ValidBook = false;
            return false;
        }

        if (!isValidDate(date)) {
            ValidBook = false;
            return false;
        }

        Title = t;
        bookAuthor = a;
        ISBN = i;
        Availability = avail;
        DateAdd = date;
        ValidBook = true;

        return true;
    }

    string getISBN() const {
        return ISBN;
    }

    string getTitle() const {
        return Title;
    }

    string getDateAdd() const {
        return DateAdd;
    }

    bool isAvailable() const {
        return Availability;
    }

    bool isValid() const {
        return ValidBook;
    }

    void displayBookDetails() const {
        cout << left << setw(25) << Title
             << setw(25) << bookAuthor.getFullName()
             << setw(15) << ISBN
             << setw(15) << DateAdd
             << setw(15) << (Availability ? "true" : "false")
             << setw(10) << (ValidBook ? "Valid" : "Invalid")
             << endl;
    }
};

#endif