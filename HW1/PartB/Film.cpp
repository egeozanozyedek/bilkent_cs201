//
// Created by Ege Ozan Özyedek on 30.10.2019.
//

#include "Film.h"

/*
Film Constructor
Assigns the given values to the data members of the object instnce
Pre allocates actors array with starting size 5 and sets the noOfActors to 0
*/
Film::Film(string fTitle, string fDirector, const unsigned int fYear, const unsigned int fDuration) {
    title = fTitle;
    director = fDirector;
    year = fYear;
    duration = fDuration;
    size = 5;
    actors = new Actor[size];
    noOfActors = 0;
}

/*
Copy Constructor
Assigns the given data members of the reference object to the data members of this instance
Also deep copies the actors array
*/
Film::Film(const Film &fToCopy) {
    
    title = fToCopy.title;
    director = fToCopy.director;
    year = fToCopy.year;
    duration = fToCopy.duration;

    size = fToCopy.size;
    noOfActors = fToCopy.noOfActors;
    actors = new Actor[size];
    for (int i = 0; i < noOfActors; i++)
       actors[i] = fToCopy.actors[i];

}

/*
 Destructor
 deallocates the actors array
 */
Film::~Film() {
    delete [] actors;
}

/*
Overloaded Assignment Operator
Assigns right hand side's given data members
Similar to FC, it prevents self assignment
Compares sizes and if they are not the same deallocates the actors array to prevent memory leaks and creates a new array with the new size
Equates the noOfActors and deep copies the actors array of the rhs
*/
void Film::operator=(const Film &right) {
    if( &right != this) {
        title = right.title;
        director = right.director;
        year = right.year;
        duration = right.duration;
    
       if (size != right.size) {
          delete [] actors;
          size = right.size;
          actors = new Actor[size];
      }
              
      noOfActors = right.noOfActors;

      for (int i = 0; i < noOfActors; i++)
          actors[i] = right.actors[i];
  }
}

/*
get... Functions
returns the private data member of the object so that other code can access these members
*/
string Film::getFilmTitle() const {
    return title;
}

string Film::getFilmDirector() const {
    return director;
}

unsigned int Film::getFilmYear() const {
    return year;
}

unsigned int Film::getFilmDuration() const {
    return duration;
}

/*
 addActor function
 Similar implementation to FC
 Checks if actor already exists, if it does returns false
 Creates a temp Actor pointer which points to the same adress as actors array
 Doubles size if needed
 Deep copy
 Appends the given actor to the end of the array
 Deletes temp if temp and films point to different addresses (aka if films have allocated a new space)
 */
bool Film::addActor(string aName, string aBirthPlace, const unsigned int aBirthYear) {

     for (int i = 0; i < noOfActors; i++) {
           if (actors[i].getName() == aName and actors[i].getBirthPlace() == aBirthPlace
           and actors[i].getBirthYear() == aBirthYear)
           return false;
       }
       
       Actor* temp = actors;
       
       if ( (noOfActors + 1) > size ) {
           size *= 2;
           actors = new Actor[size];
       }

       for(int i = 0; i < noOfActors; i++)
           actors[i] = temp[i];

       Actor newActor(aName, aBirthPlace, aBirthYear);
       actors[noOfActors++] = newActor;

       if(actors != temp)
           delete [] temp;

       return true;

}

/*
 removeActors function
 If there exists no actors then returns false
 Deallocates the space the actors array held
 Creates a new Actor array with starting size 5, so basically resetting the actors array
 */
bool Film::removeActors() {
    if (noOfActors == 0)
        return false;
    
    delete [] actors;
    actors = new Actor[size];
    size = 5;
    noOfActors = 0;
    return true;
}

/*
 Overloaded << operator
 Similar to toString() in java, when cout << Film is coded this member function will be called
 Prints out important values of the object
 Prints each actors information
*/
ostream &operator<<(ostream &out, const Film &f) {
    out << f.title << ", ";
    out << f.year << ", ";
    out << f.director << ", ";
    out << f.duration << " min\n";

    for (int i = 0; i < f.noOfActors; i++)
            out << "\t" << f.actors[i];

    return out;
}

/*
 calculateAverageActorAge function
 Simple arithmetic function that computes the age of actors the year the movie was released and then returns the average
 */
unsigned int Film::calculateAverageActorAge() const {

    unsigned int sum = 0;
    
        for (int i = 0; i < noOfActors; i++){
            sum += (year - actors[i].getBirthYear());
        }
    if (noOfActors != 0)
        return (sum/noOfActors);
    
    return 0;
}



