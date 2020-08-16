//
//  Book.cpp
//  PartB
//
//  Created by Ege Ozan Özyedek on 12/9/19.
//  Copyright © 2019 ohnochateau. All rights reserved.
//

#include <iostream>
#include "Book.h"
using namespace std;

Book::Book(): head(new AuthorNode), name("") {
    head->next = NULL;
}

Book::Book(const string name): head(new AuthorNode), name(name) {
    head->next = NULL;
}

Book::~Book() {
    
    AuthorNode* ptr = head;
    for (AuthorNode* cur = ptr ; cur != NULL; cur = ptr) {
         ptr = cur->next;
         delete cur;
    }
    
}

Book::Book(const Book& bookToCopy): name(bookToCopy.name), head(new AuthorNode) {
    
    AuthorNode* cur = head;
    
    for (AuthorNode* ptr = bookToCopy.head->next; ptr != NULL; ptr = ptr->next) {
        cur->next = new AuthorNode;
        cur = cur->next;
        cur->a = ptr->a;
    }
    cur->next = NULL;
}


void Book::operator=(const Book& right) {
    name = right.name;
    AuthorNode *cur = head, *rcur = right.head, *n;

    while (rcur->next != NULL and cur->next != NULL) {
       cur = cur->next;
       rcur = rcur->next;
       cur->a = rcur->a;
    }


    if (cur->next == NULL) {
       
       while(rcur->next != NULL) {
           rcur = rcur->next;
           cur->next = new AuthorNode;
           cur = cur->next;
           cur->a = rcur->a;
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

string Book::getName() const {
    return name;
}

void Book::setName(const string bookName) {
    name = bookName;
}

bool Book::addAuthor(const int id, const string name) {
    
    if (!findAuthor(id)) {

        AuthorNode* cur;
        
        for (cur = head; cur->next != NULL; cur = cur->next) {}
        
        cur->next = new AuthorNode;
        cur = cur->next;
        cur->a.setID(id);
        cur->a.setName(name);
        cur->next = NULL;
        return true;
    }
    
    cout << "Author with given id already exists in the collection.\n";
    return false;
}

bool Book::removeAuthor (const int id) {
        
    for (AuthorNode *prev = head, *cur = head->next; cur != NULL; cur = cur->next) {
        if(cur->a.getID() == id) {
            prev->next = cur->next;
            delete cur;
            return true;
        }
        prev = cur;
    }
    
    cout << "No author with given id found.\n";
    return false;
}

void Book::displayAuthors() const {
   if (head->next == NULL)
       cout << "--EMPTY--\n";
    
   for (AuthorNode* cur = head->next; cur != NULL; cur = cur->next)
       cout << "\t" << cur->a.getID() << ", " << cur->a.getName() << "\n";
}

Book::AuthorNode* Book::findAuthor(int id) {
    
    for (AuthorNode* cur = head->next; cur != NULL; cur = cur->next) {
        if (cur->a.getID() == id)
            return cur;
    }
    
    return NULL;
}

bool Book::authorCheck(int id, string& authorName) {
    
    AuthorNode* authorNode = findAuthor(id);
    
    if (authorNode) {
        authorName = authorNode->a.getName();
        return true;
    }
    
    return false;
}
