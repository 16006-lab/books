#include <iostream>
#include <iomanip>
#include "Library.h"

using namespace std;

void printHeader() {
    cout << left << setw(25) << "Title"
         << setw(25) << "Author"
         << setw(15) << "ISBN"
         << setw(15) << "DateAdd"
         << setw(15) << "Availability"
         << setw(10) << "Status"
         << endl;

    cout << string(105, '-') << endl;
}

void printTestResult(string testName, bool result) {
    cout << left << setw(55) << testName
         << (result ? "Pass" : "Fail")
         << endl;
}

int main() {
    cout << "ASSESSMENT 3 TEST APPLICATION" << endl;
    cout << "Book, Author and Library validation and sorting tests" << endl;
    cout << endl;

    Author authorGatsby;
    Author author1984;
    Author authorMockingbird;

    bool authorGatsbyResult = authorGatsby.setAuthorDetails(
        "Scott",
        "Fitzgerald",
        "1896-09-24",
        "Male"
    );

    bool author1984Result = author1984.setAuthorDetails(
        "George",
        "Orwell",
        "1903-06-25",
        "Male"
    );

    bool authorMockingbirdResult = authorMockingbird.setAuthorDetails(
        "Herman",
        "Melville",
        "1819-08-01",
        "Male"
    );

    Book bookGatsby;
    Book book1984;
    Book bookMockingbird;

    bool bookGatsbyResult = bookGatsby.setBookDetails(
        "The Great Gatsby",
        authorGatsby,
        "9780743273",
        true,
        "2023-01-15"
    );

    bool book1984Result = book1984.setBookDetails(
        "1984",
        author1984,
        "9780451524",
        true,
        "2023-02-20"
    );

    bool bookMockingbirdResult = bookMockingbird.setBookDetails(
        "To Kill a Mockingbird",
        authorMockingbird,
        "9780060935",
        false,
        "2022-11-05"
    );

    cout << "CORRECT INITIALIZATION TESTS" << endl;
    cout << string(105, '-') << endl;

    printTestResult("Author: Scott Fitzgerald, 1896-09-24, Male", authorGatsbyResult);
    printTestResult("Author: George Orwell, 1903-06-25, Male", author1984Result);
    printTestResult("Author: Herman Melville, 1819-08-01, Male", authorMockingbirdResult);
    printTestResult("Book: The Great Gatsby, 9780743273, true, 2023-01-15", bookGatsbyResult);
    printTestResult("Book: 1984, 9780451524, true, 2023-02-20", book1984Result);
    printTestResult("Book: To Kill a Mockingbird, 9780060935, false, 2022-11-05", bookMockingbirdResult);

    cout << endl;
    cout << "VALID BOOK OBJECTS" << endl;
    printHeader();
    bookGatsby.displayBookDetails();
    book1984.displayBookDetails();
    bookMockingbird.displayBookDetails();

    Author incorrectAuthor1;
    Author incorrectAuthor2;
    Author incorrectAuthor3;

    bool incorrectAuthor1Result = incorrectAuthor1.setAuthorDetails(
        "12345",
        "6789",
        "Yesterday",
        "Unknown"
    );

    bool incorrectAuthor2Result = false;

    bool incorrectAuthor3Result = incorrectAuthor3.setAuthorDetails(
        "",
        "",
        "",
        ""
    );

    Book incorrectBook1;
    Book incorrectBook2;
    Book incorrectBook3;

    bool incorrectBook1Result = incorrectBook1.setBookDetails(
        "",
        incorrectAuthor1,
        "ABCDEFG",
        true,
        "Yesterday"
    );

    bool incorrectBook2Result = false;

    bool incorrectBook3Result = incorrectBook3.setBookDetails(
        "NULL",
        incorrectAuthor3,
        "0",
        false,
        "null"
    );

    cout << endl;
    cout << "INCORRECT INITIALIZATION TESTS" << endl;
    cout << string(105, '-') << endl;

    printTestResult("Invalid author: 12345, 6789, Yesterday, Unknown", !incorrectAuthor1Result);
    printTestResult("Invalid author: integer 1 cannot be passed into Author constructor", !incorrectAuthor2Result);
    printTestResult("Invalid author: empty name, surname, DOB and gender", !incorrectAuthor3Result);
    printTestResult("Invalid book: empty title, ABCDEFG ISBN, true, Yesterday", !incorrectBook1Result);
    printTestResult("Invalid book: A, invalid Author constructor, 978-0-451, maybe, 00-00-0000", !incorrectBook2Result);
    printTestResult("Invalid book: NULL, empty author, 0, null, null", !incorrectBook3Result);

    cout << endl;
    cout << "SORTING TEST 1: ASCENDING ORDER" << endl;
    cout << endl;

    Library ascendingLibrary;

    bool ascendingAdd1 = ascendingLibrary.addBook(bookMockingbird);
    bool ascendingAdd2 = ascendingLibrary.addBook(book1984);
    bool ascendingAdd3 = ascendingLibrary.addBook(bookGatsby);

    cout << "Before sorting" << endl;
    printHeader();
    ascendingLibrary.displayLibrary();

    ascendingLibrary.sortCatalog();

    cout << endl;
    cout << "After sorting" << endl;
    printHeader();
    ascendingLibrary.displayLibrary();

    cout << endl;
    printTestResult("Ascending add: 9780060935, 9780451524, 9780743273", ascendingAdd1 && ascendingAdd2 && ascendingAdd3);

    cout << endl;
    cout << "SORTING TEST 2: DESCENDING ORDER" << endl;
    cout << endl;

    Library descendingLibrary;

    bool descendingAdd1 = descendingLibrary.addBook(bookGatsby);
    bool descendingAdd2 = descendingLibrary.addBook(book1984);
    bool descendingAdd3 = descendingLibrary.addBook(bookMockingbird);

    cout << "Before sorting" << endl;
    printHeader();
    descendingLibrary.displayLibrary();

    descendingLibrary.sortCatalog();

    cout << endl;
    cout << "After sorting" << endl;
    printHeader();
    descendingLibrary.displayLibrary();

    cout << endl;
    printTestResult("Descending add: 9780743273, 9780451524, 9780060935", descendingAdd1 && descendingAdd2 && descendingAdd3);

    cout << endl;
    cout << "SORTING TEST 3: MIXED ORDER" << endl;
    cout << endl;

    Library mixedLibrary;

    bool mixedAdd1 = mixedLibrary.addBook(book1984);
    bool mixedAdd2 = mixedLibrary.addBook(bookGatsby);
    bool mixedAdd3 = mixedLibrary.addBook(bookMockingbird);

    cout << "Before sorting" << endl;
    printHeader();
    mixedLibrary.displayLibrary();

    mixedLibrary.sortCatalog();

    cout << endl;
    cout << "After sorting" << endl;
    printHeader();
    mixedLibrary.displayLibrary();

    cout << endl;
    printTestResult("Mixed add: 9780451524, 9780743273, 9780060935", mixedAdd1 && mixedAdd2 && mixedAdd3);

    cout << endl;
    cout << "INVALID BOOK ADD TEST" << endl;
    cout << string(105, '-') << endl;

    Library invalidLibrary;
    bool invalidAdd1 = invalidLibrary.addBook(bookGatsby);
    bool invalidAdd2 = invalidLibrary.addBook(incorrectBook1);
    bool invalidAdd3 = invalidLibrary.addBook(incorrectBook3);

    printTestResult("Valid book added to library", invalidAdd1);
    printTestResult("Invalid book with empty title rejected by library", !invalidAdd2);
    printTestResult("Invalid book with empty author rejected by library", !invalidAdd3);

    cout << endl;
    cout << "LIBRARY AFTER INVALID ADD TEST" << endl;
    printHeader();
    invalidLibrary.displayLibrary();

    cout << endl;
    cout << "FINAL SUMMARY" << endl;
    cout << string(105, '-') << endl;

    printTestResult("All valid Author objects accepted", authorGatsbyResult && author1984Result && authorMockingbirdResult);
    printTestResult("All valid Book objects accepted", bookGatsbyResult && book1984Result && bookMockingbirdResult);
    printTestResult("All invalid Author objects rejected", !incorrectAuthor1Result && !incorrectAuthor2Result && !incorrectAuthor3Result);
    printTestResult("All invalid Book objects rejected", !incorrectBook1Result && !incorrectBook2Result && !incorrectBook3Result);
    printTestResult("Ascending sorting scenario completed", ascendingAdd1 && ascendingAdd2 && ascendingAdd3);
    printTestResult("Descending sorting scenario completed", descendingAdd1 && descendingAdd2 && descendingAdd3);
    printTestResult("Mixed sorting scenario completed", mixedAdd1 && mixedAdd2 && mixedAdd3);
    printTestResult("Library rejects invalid books", invalidAdd1 && !invalidAdd2 && !invalidAdd3);

    return 0;
}