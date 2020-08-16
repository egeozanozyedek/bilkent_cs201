//
//  Genre.h
//  HW3
//
//  Created by Ege Ozan Özyedek on 12/8/19.
//  Copyright © 2019 ohnochateau. All rights reserved.
//

#ifndef Genre_h
#define Genre_h

#include <iostream>
#include <string>
#include "Book.h"

using namespace std;
class Genre {
public:
    Genre(const string gname = "");
    ~Genre ();
    Genre (const Genre &genreToCopy);
    void operator=(const Genre &right);
    string getGenreName() const;
    void setGenreName(const string gName);
    bool addBook(const string bookName);
    bool removeBook (const string bookName);
    bool addAuthor(string bookName, const int id, const string authorName);
    bool removeAuthor (string bookName, const int id);
    void displayBook() const;
    
    void displayAuthor(int id, bool& exists);
    
private:
    
    struct BookNode {
        Book b;
        BookNode* next;
    };
    
    BookNode* head;
    BookNode* findBook(string bookName);
    string genreName;
    int bookCount;
};

#endif 
