#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>

using namespace std;

class Author {
private:
    string Name;
    string Surname;
    string BirthDate;
    string Gender;

public:
    Author() : Name(""), Surname(""), BirthDate(""), Gender("") {}

    void setAuthorDetails(string n, string s, string dob, string g) {
        Name = n;
        Surname = s;
        BirthDate = dob;
        Gender = g;
    }

    string getFullName() const {
        return Name + " " + Surname;
    }
};

#endif