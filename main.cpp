#include <iostream>
#include "Library.h"

using namespace std;

int main() {
    // 1. Initialize Author instances with full details
    Author a1, a2, a3;
    a1.setAuthorDetails("George", "Orwell", "1903-06-25", "Male");
    a2.setAuthorDetails("Scott", "Fitzgerald", "1896-09-24", "Male");
    a3.setAuthorDetails("Herman", "Melville", "1819-08-01", "Male");

    // 2. Initialize Books
    Book bLow, bMed, bHigh;
    bLow.setBookDetails("1984", a1, "101", true, "2023");
    bMed.setBookDetails("Gatsby", a2, "505", true, "2023");
    bHigh.setBookDetails("Moby", a3, "909", true, "2023");

    // 3. Create Library Scenarios for Testing
    Library libMixed;
    libMixed.addBook(bHigh); // 909
    libMixed.addBook(bLow);  // 101
    libMixed.addBook(bMed);  // 505

    cout << "=== BEFORE SORTING (Mixed Order) ===" << endl;
    libMixed.displayLibrary();

    libMixed.sortCatalog();

    cout << "\n=== AFTER SORTING (Ascending ISBN) ===" << endl;
    libMixed.displayLibrary();

    return 0;
}