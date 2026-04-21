#include <iostream>
#include "Library.h"
// Author.h and Book.h are implicitly included via Library.h

using namespace std;

int main() {
    // 1. Create the Author objects
    Author author1("George Orwell");
    Author author2("F. Scott Fitzgerald");
    Author author3("Herman Melville");

    // 2. Create the Book objects and pass the Authors into the setup
    Book bLow, bMed, bHigh;
    bLow.setBookDetails("1984", author1, "101", true, "2023");
    bMed.setBookDetails("The Great Gatsby", author2, "505", true, "2023");
    bHigh.setBookDetails("Moby Dick", author3, "909", true, "2023");

    // --- TEST ARRAY 1: ASCENDING ORDER ADDED ---
    Library libAsc;
    libAsc.addBook(bLow); libAsc.addBook(bMed); libAsc.addBook(bHigh);

    // --- TEST ARRAY 2: DESCENDING ORDER ADDED ---
    Library libDesc;
    libDesc.addBook(bHigh); libDesc.addBook(bMed); libDesc.addBook(bLow);

    // --- TEST ARRAY 3: MIXED ORDER ADDED ---
    Library libMixed;
    libMixed.addBook(bMed); libMixed.addBook(bHigh); libMixed.addBook(bLow);

    cout << "=== BEFORE SORTING ===" << endl;
    cout << "Array 1 (Ascending):" << endl; libAsc.displayLibrary();
    cout << "\nArray 2 (Descending):" << endl; libDesc.displayLibrary();
    cout << "\nArray 3 (Mixed):" << endl; libMixed.displayLibrary();

    // Call sort function on all three arrays
    libAsc.sortCatalog();
    libDesc.sortCatalog();
    libMixed.sortCatalog();

    cout << "\n\n=== AFTER SORTING (All should be 101 -> 505 -> 909) ===" << endl;
    cout << "Array 1 Result:" << endl; libAsc.displayLibrary();
    cout << "\nArray 2 Result:" << endl; libDesc.displayLibrary();
    cout << "\nArray 3 Result:" << endl; libMixed.displayLibrary();

    return 0;
}