//
// Created by Ege Ozan Özyedek on 11/5/19.
//

#include "Actor.h"

/*
Actor Constructor
Assigns the given values to the data members of the object instnce
*/
Actor::Actor(string aName, string aBirthPlace, const unsigned int aBirthYear) {
    name = aName;
    birthPlace = aBirthPlace;
    birthYear = aBirthYear;
}

/*
Copy Constructor
Assigns the given data members of the reference object to the data members of this instance
*/
Actor::Actor(const Actor &actorToCopy) {
    name = actorToCopy.name;
    birthPlace = actorToCopy.birthPlace;
    birthYear = actorToCopy.birthYear;
}

Actor::~Actor() {}

/*
Overloaded Assignment Operator
Assigns right hand side's given data members
*/
void Actor::operator=(const Actor &right) {
    name = right.name;
    birthPlace = right.birthPlace;
    birthYear = right.birthYear;
}

/*
get... Functions
returns the private data member of the object so that other code can access these members
*/
string Actor::getName() const {
    return name;
}
string Actor::getBirthPlace() const {
    return birthPlace;
}
unsigned int Actor::getBirthYear() const {
    return birthYear;
}

/*
 Overloaded << operator
 Similar to toString() in java, when cout << Actor is coded this member function will be called
 Prints out important values of the object
*/
ostream &operator<<(ostream &out, const Actor &a) {

    out << a.name << ", ";
    out << a.birthPlace << ", ";
    out << a.birthYear << "\n";

    return out;
}



