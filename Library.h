#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"

class Library {
private:
    Book catalog[3]; 
    int count = 0;

public:
    void addBook(const Book& b) {
        if (count < 3) {
            catalog[count] = b;
            count++;
        }
    }

    void sortCatalog() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (catalog[j].getISBN() > catalog[j + 1].getISBN()) {
                    Book temp = catalog[j];
                    catalog[j] = catalog[j + 1];
                    catalog[j + 1] = temp;
                }
            }
        }
    }

    void displayLibrary() const {
        for (int i = 0; i < count; i++) {
            catalog[i].displayBookDetails();
        }
    }
};

#endif