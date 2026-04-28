#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include <cctype>

using namespace std;

class Author {
private:
    string Name;
    string Surname;
    string BirthDate;
    string Gender;

    bool isEmpty(const string& value) const {
        return value.empty();
    }

    bool isOnlyLetters(const string& value) const {
        if (value.empty()) {
            return false;
        }

        for (char c : value) {
            if (!isalpha(c) && c != ' ' && c != '-') {
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

    bool isValidGender(const string& gender) const {
        return gender == "Male" || gender == "Female" || gender == "Other";
    }

public:
    Author() : Name(""), Surname(""), BirthDate(""), Gender("") {}

    bool setAuthorDetails(string n, string s, string dob, string g) {
        if (isEmpty(n) || isEmpty(s) || isEmpty(dob) || isEmpty(g)) {
            return false;
        }

        if (!isOnlyLetters(n) || !isOnlyLetters(s)) {
            return false;
        }

        if (!isValidDate(dob)) {
            return false;
        }

        if (!isValidGender(g)) {
            return false;
        }

        Name = n;
        Surname = s;
        BirthDate = dob;
        Gender = g;

        return true;
    }

    string getFullName() const {
        return Name + " " + Surname;
    }

    string getName() const {
        return Name;
    }

    string getSurname() const {
        return Surname;
    }

    string getBirthDate() const {
        return BirthDate;
    }

    string getGender() const {
        return Gender;
    }

    bool isValid() const {
        return !Name.empty() && !Surname.empty() && !BirthDate.empty() && !Gender.empty();
    }
};

#endif