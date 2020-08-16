//
// Created by Ege Ozan Özyedek on 30.10.2019.
//

#include "SimpleFilm.h"

/*
 Film Constructor
 Assigns the given values to the data members of the object instnce
 */
Film::Film(string fTitle, string fDirector, const unsigned int fYear, const unsigned int fDuration) {
    title = fTitle;
    director = fDirector;
    year = fYear;
    duration = fDuration;
}


/*
 Copy Constructor
 Assigns the given data members of the reference object to the data members of this instance
 */
Film::Film(const Film &fToCopy) {
    title = fToCopy.title;
    director = fToCopy.director;
    year = fToCopy.year;
    duration = fToCopy.duration;
}

Film::~Film() {

}

/*
 Overloaded Assignment Operator
 Assigns right hand side's given data members
 */
void Film::operator=(const Film &right) {
    title = right.title;
    director = right.director;
    year = right.year;
    duration = right.duration;
}

/*
 get... Functions
 returns the private data member of the object so that other code can access these members
 */
string Film::getTitle() const {
    return title;
}
string Film::getDirector() const {
    return director;
}
unsigned int Film::getYear() const {
    return year;
}
unsigned int Film::getDuration() const {
    return duration;
}

/*
 Overloaded << operator
 Similar to toString() in java, when cout << Film is coded this member function will be called
 Prints out important values of the object
*/
ostream &operator<<(ostream &out, const Film &f) {
    out << f.title << ", ";
    out << f.year << ", ";
    out << f.director << ", ";
    out << f.duration << " min\n";
    return out;
}


