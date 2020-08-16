//
//  Genre.cpp
//  HW3
//
//  Created by Ege Ozan Özyedek on 12/8/19.
//  Copyright © 2019 ohnochateau. All rights reserved.
//

#include "Genre.h"
#include <algorithm>

Genre::Genre(const string gname): genreName(gname), head(new BookNode), bookCount(0) {
    head->next = NULL;
}

Genre::Genre(const Genre &genreToCopy): genreName(genreToCopy.genreName), head(new BookNode), bookCount(genreToCopy.bookCount){
    
    BookNode* cur = head;
    
    for (BookNode* ptr = genreToCopy.head->next; ptr != NULL; ptr = ptr->next) {
        cur->next = new BookNode;
        cur = cur->next;
        cur->b = ptr->b;
    }
    
    cur->next = NULL;
    
}

Genre::~Genre() {
    
    BookNode* ptr = head;
    for (BookNode* cur = ptr ; cur != NULL; cur = ptr) {
        ptr = cur->next;
        delete cur;
    }
    
}

void Genre::operator=(const Genre &right) {
    genreName = right.genreName;
    
    BookNode *cur = head, *rcur = right.head, *n;
    
    while (rcur->next != NULL and cur->next != NULL) {
        cur = cur->next;
        rcur = rcur->next;
        cur->b = rcur->b;
    }
    
    
    if (cur->next == NULL) {
        
        while(rcur->next != NULL) {
            rcur = rcur->next;
            cur->next = new BookNode;
            cur = cur->next;
            cur->b = rcur->b;
        }
        
        cur->next = NULL;
    }
    
    else {
        
        while (cur->next != NULL) {
            n = cur->next;
            cur->next = n->next;
            delete n;
        }
        
    }
}


bool Genre::addBook(const string bookName) {
    
    if (!findBook(bookName)) {
        
        BookNode* cur;
        
        for (cur = head; cur->next != NULL; cur = cur->next) {}
        
        cur->next = new BookNode;
        cur = cur->next;
        cur->b.setName(bookName);
        cur->next = NULL;
        
        return true;
    }
    
    cout << "Book with given name already exists in the collection.\n";
    return false;
    
}

bool Genre::removeBook(const string bookName) {
    string name = bookName;
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    
    for (BookNode *prev = head, *cur = head->next; cur != NULL; cur = cur->next) {
        
        string curName = cur->b.getName();
        transform(curName.begin(), curName.end(), curName.begin(), ::toupper);
        
        if(curName == name) {
            prev->next = cur->next;
            delete cur;
            return true;
        }
        prev = cur;
    }
    
    cout << "No book with given name found.\n";
    return false;
}


void Genre::displayBook() const {
    
    if (head->next == NULL)
        cout << "--EMPTY--\n";
    
    for (BookNode* cur = head->next; cur != NULL; cur = cur->next) {
        cout << cur->b.getName() << "\n";
        cur->b.displayAuthors();
    }
    
}

bool Genre::addAuthor(string bookName, const int id, const string authorName) {
    BookNode* found = findBook(bookName);
    if (found)
        return found->b.addAuthor(id, authorName);
    else {
        cout << "Book with specified name not found in genre.\n";
        return NULL;
    }
}

bool Genre::removeAuthor (string bookName, const int id) {
    BookNode* found = findBook(bookName);
    if (found)
        return found->b.removeAuthor(id);
    else {
        cout << "Book with specified name not found in genre.\n";
        return NULL;
    }
}

string Genre::getGenreName() const {
    return genreName;
}
void Genre::setGenreName(const string gName) {
    genreName = gName;
}


Genre::BookNode* Genre::findBook(string bookName) {
    
    transform(bookName.begin(), bookName.end(), bookName.begin(), ::toupper);
    
    for (BookNode* cur = head->next; cur != NULL; cur = cur->next) {
        string curName = cur->b.getName();
        transform(curName.begin(), curName.end(), curName.begin(), ::toupper);
        
        if (curName == bookName)
            return cur;
    }
    
    
    return NULL;
}


void Genre::displayAuthor(int id, bool& exists) {
    
    string authorName;
    bool control = false;
    
    for (BookNode* cur = head->next; cur != NULL; cur = cur->next) {
        
        if (cur->b.authorCheck(id, authorName)) {
            if (!exists) {
                cout << authorName << ", " << id << "\n";
                exists = true;
            }
            if (!control) {
                cout << genreName << "\n";
                control = true;
            }
            cout << "\t" << cur->b.getName() << "\n";
        }
        
        
    }
    
    
    
}
