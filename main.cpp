#include <iostream>
#include "Library.h"

using namespace std;

int main() {
    // 1. Create the data objects
    Book low, med, high;
    low.setBookDetails("1984", "Orwell", "111", true, "2023");
    med.setBookDetails("Gatsby", "Scott", "555", true, "2023");
    high.setBookDetails("Moby", "Melville", "999", true, "2023");

    // Scenario A: Ascending Order Added (111, 555, 999)
    Library libAsc;
    libAsc.addBook(low); libAsc.addBook(med); libAsc.addBook(high);

    // Scenario B: Descending Order Added (999, 555, 111)
    Library libDesc;
    libDesc.addBook(high); libDesc.addBook(med); libDesc.addBook(low);

    // Scenario C: Mixed Order Added (555, 999, 111)
    Library libMixed;
    libMixed.addBook(med); libMixed.addBook(high); libMixed.addBook(low);

    cout << "=== BEFORE SORTING ===" << endl;
    cout << "\nArray 1 (Added Ascending):\n"; libAsc.displayLibrary();
    cout << "\nArray 2 (Added Descending):\n"; libDesc.displayLibrary();
    cout << "\nArray 3 (Added Mixed):\n"; libMixed.displayLibrary();

    // Call Sort on all three
    libAsc.sortCatalog();
    libDesc.sortCatalog();
    libMixed.sortCatalog();

    cout << "\n\n=== AFTER SORTING (All should now be 111, 555, 999) ===" << endl;
    cout << "\nArray 1 Results:\n"; libAsc.displayLibrary();
    cout << "\nArray 2 Results:\n"; libDesc.displayLibrary();
    cout << "\nArray 3 Results:\n"; libMixed.displayLibrary();

    return 0;
}