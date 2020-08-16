//
//  Book.h
//  PartB
//
//  Created by Ege Ozan Özyedek on 12/9/19.
//  Copyright © 2019 ohnochateau. All rights reserved.
//

#ifndef Book_h
#define Book_h

#include <string>
#include "Author.h"
using namespace std;

class Book{
public:
    
    Book();
    Book(const string name);
    ~ Book();
    Book(const Book& bookToCopy);
    void operator=(const Book& right);
    string getName() const;
    void setName(const string bookName);
    bool addAuthor(const int id, const string name);
    bool removeAuthor (const int id);
    void displayAuthors() const;
    
    bool authorCheck(int id, string& authorName);
    
private:
    
    struct AuthorNode {
        Author a;
        AuthorNode* next;
    };
    AuthorNode* head;
    string name;
    AuthorNode* findAuthor(int id);
    
};

#endif
