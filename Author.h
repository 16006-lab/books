#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>

using namespace std;

class Author {
private:
    string Name;

public:
    // Constructors
    Author() : Name("") {}
    Author(string n) : Name(n) {}

    // Setters and Getters
    void setName(string n) { Name = n; }
    string getName() const { return Name; }
};

#endif