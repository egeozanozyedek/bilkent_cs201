//
// Created by Ege Ozan Özyedek on 30.10.2019.
//

#include "SimpleFC.h"

/*
 Constructor of FC
 Pre allocates a dynamically allocated array with starting size 5
 Sets noOfFilms to 0 as there exists no films as of yet
 */
FC::FC() {
    noOfFilms = 0;
    size = 5; //start size
    films = new Film[size];
}

/*
 Copy Constructor of FC
 Copies elements of referenced FC to *this
 Deep copies elements of the array
 */
FC::FC(const FC &fcToCopy) {
    size = fcToCopy.size;
    noOfFilms = fcToCopy.noOfFilms;
    films = new Film[size];
    for (int i = 0; i < noOfFilms; i++)
        films[i] = fcToCopy.films[i];
}

/*
 Destructor
 Deallocates the films array
 */
FC::~FC() {
    delete [] films;
}

/*
 Overloaded assignment operator
 If its the same instance of the object does no operation
 If they are different then compares the size of two object instances, if same continues
 If sizes are different then deletes the already allocated array so that there exists no memory leak
    equates (*this).size = right.size and creates a new allocated array with the new size
 Deep copies the elements of the array
 */
void FC::operator=(const FC &right) {
    
    if( &right != this) {
        
        if (size != right.size) {
            delete [] films;
            size = right.size;
            films = new Film[size];
        }
        
        noOfFilms = right.noOfFilms;

        for (int i = 0; i < noOfFilms; i++)
            films[i] = right.films[i];
    }
}

/*
 addFilm function
 Checks whether the film has already been added, if it has been returns false
 If a new film is being added then a film pointer temp is created which points to the same loaction as films
 The size is doubled if noOfFilms + 1 is greated than the current size
 Deep copy operation
 A new film object is created and then it is equated to the end of the array
 noOfFilms is increased
 If temp still points to the same location as films then it shall not be deleted, if films points to a newly allocated space then temp is deleted to prevent memory leak
 */
bool FC::addFilm(const string fTitle, const string fDirector, const unsigned int fYear, const unsigned int fDuration) {
    
    for (int i = 0; i < noOfFilms; i++) {
        if (films[i].getTitle() == fTitle and films[i].getDirector() == fDirector)
            return false;
    }
    
    Film* temp = films;
    
    if ( (noOfFilms + 1) > size ) {
        size *= 2;
        films = new Film[size];
    }

    for(int i = 0; i < noOfFilms; i++)
        films[i] = temp[i];

    Film newFilm(fTitle, fDirector,fYear, fDuration);
    films[noOfFilms++] = newFilm;

    if(films != temp)
        delete [] temp;

    return true;
    }

/*
 removeFilm function
 An index varibale is created and is set to an unreachable index (-1) for checking whether the film exists in films or not
 If it exists then the index is set to be the index i of the film in the films array
 Otherwise return 0
 Create a film pointer called temp which points to the same location as films
 If noOfFilms - 1 < size/2 then the size of the array is halved and a new space is allocated
 Deep copy, when i = index the program does not copy which means the movie is removed
 Reduce the noOfFilms
 If films points to the same location as temp, do not delete temp. If films points to a newly allocated location, delete temp. (I did this for cleaner code, there are other ways of implementing this such as not creating temp for the case of noOfFilms - 1 > size/2 but for less lines i decided to create temp and check for where the two pointers were pointing to at the end. The code should work.)
 */
bool FC::removeFilm(const string fTitle, const string fDirector) {
    
    unsigned int index = -1;
    
    for (int i = 0; i < noOfFilms; i++) {
    
        if (films[i].getTitle() == fTitle and films[i].getDirector() == fDirector){
            index = i;
            break;
        }
    }

    if (index == -1)
        return false;

    Film* temp = films;
    
    if ( (noOfFilms - 1) <= (size/2) and size > 5 ) {
        size /= 2;
        films = new Film[size];
    }
    
    int j = 0;
    
    // the program will assign
    for (int i = 0; i < noOfFilms; i++) {
        // at the index of the film to be removed no assignment operation is held
        if (i == index)
            continue;
        films[j++] = temp[i];
    }
    
    // reduce noOfFilms
    noOfFilms--;

    // if temp and films do not point to the same location
    if(films != temp)
        delete [] temp;
    
    return true;
}

/*
 getFilms function
 If there exists no films then return NULL by pass by reference
 Else allocate space for allFilms with the size of the instance of this object
 Deep copy if noOfFilms > 0
 return the noOfFilms
 */
unsigned int FC::getFilms(Film *&allFilms) const {
    
    if (noOfFilms == 0)
        allFilms = NULL;
    else
        allFilms = new Film[size];

    for (int i = 0; i < noOfFilms; i++)
        allFilms[i] = films[i];
    
    return noOfFilms;
}





