//
//  SimpleBookCollection.cpp
//  HW3
//
//  Created by Ege Ozan Özyedek on 12/8/19.
//  Copyright © 2019 ohnochateau. All rights reserved.
//

#include "BookCollection.h"
#include <algorithm>

BookCollection::BookCollection() :head(new GenreNode) ,genreCount(0){
    head->next = NULL;
}

BookCollection::~BookCollection() {
    
    GenreNode* ptr = head;
    for (GenreNode* cur = ptr ; cur != NULL; cur = ptr) {
        ptr = cur->next;
        delete cur;
    }
    
}

BookCollection::BookCollection(const BookCollection& bcToCopy) :genreCount(bcToCopy.genreCount), head(new GenreNode) {
    
    GenreNode* cur = head;
    
    for (GenreNode* ptr = bcToCopy.head->next; ptr != NULL; ptr = ptr->next) {
        cur->next = new GenreNode;
        cur = cur->next;
        cur->g = ptr->g;
    }
    
    cur->next = NULL;
    
}

void BookCollection::operator=(const BookCollection& right){
    
    genreCount = right.genreCount;
    
    GenreNode *cur = head, *rcur = right.head, *n;
    
    while (rcur->next != NULL and cur->next != NULL) {
        cur = cur->next;
        rcur = rcur->next;
        cur->g = rcur->g;
    }
    
    
    if (cur->next == NULL) {
        
        while(rcur->next != NULL) {
            rcur = rcur->next;
            cur->next = new GenreNode;
            cur = cur->next;
            cur->g = rcur->g;
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

void BookCollection::displayAllGenres() const {
    
    if (head->next == NULL)
        cout << "--EMPTY--\n";
    
    for (GenreNode* cur = head->next; cur != NULL; cur = cur->next)
        cout << cur->g.getGenreName() << "\n";
    
}


void BookCollection::displayGenre(string genreName) {
    
    GenreNode* node = findGenre(genreName);
    
    if(!node)
        cout << "--EMPTY--\n";
    
    else {
        Genre genre = node->g;
        cout << genre.getGenreName() << "\n";
        genre.displayBook();
    }
    
}



void BookCollection::addGenre(string genreName) {
    
    if (!findGenre(genreName)) {
        
        GenreNode *cur;
        
        for (cur = head; cur->next != NULL; cur = cur->next) { }
        
        cur->next = new GenreNode;
        cur = cur->next;
        cur->g.setGenreName(genreName);
        cur->next = NULL;
        genreCount++;
        return;
        
    }
    
    cout << "Genre already exists in the collection.\n";
}

void BookCollection::removeGenre( string genreName) {
    
    
    string name = genreName;
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    
    for (GenreNode *prev = head, *cur = head->next; cur != NULL; cur = cur->next) {
        string curName = cur->g.getGenreName();
        transform(curName.begin(), curName.end(), curName.begin(), ::toupper);
        if (curName == name) {
            prev->next = cur->next;
            delete cur;
            genreCount--;
            return;
        }
        prev = cur;
    }
    
    cout << "No genre with given name found.\n";
}


void BookCollection::addBook(string genreName, string bookName) {
    GenreNode* found = findGenre(genreName);
    if (!found)
        cout << "Genre with specified name not found.\n";
    else
        found->g.addBook(bookName);
            
}


void BookCollection::removeBook(string genreName, string bookName) {
    GenreNode* found = findGenre(genreName);
    if (!found)
        cout << "Genre with specified name not found.\n";
    else
        found->g.removeBook(bookName);
}


void BookCollection::addAuthor(string genreName, string bookName, int authorID, string authorName){
    
    GenreNode* found = findGenre(genreName);
    if (!found)
        cout << "Genre with specified name not found.\n";
    else
        found->g.addAuthor(bookName, authorID, authorName);
}


void BookCollection::removeAuthor(string genreName, string bookName, int authorID) {
    GenreNode* found = findGenre(genreName);
    if (!found)
        cout << "Genre with specified name not found.\n";
    else
        found->g.removeAuthor(bookName, authorID);
}

void BookCollection::displayAuthor(int authorID) {
    
    bool exists = false;
    
    if (head->next == NULL)
        cout << "--EMPTY--\n";
    
    for (GenreNode* cur = head->next; cur != NULL; cur = cur->next) {
        
        cur->g.displayAuthor(authorID, exists);
        
    }
    
    if (!exists)
        cout << "--EMPTY--\n";
    
}


BookCollection::GenreNode* BookCollection::findGenre(string genreName) {
    
    transform(genreName.begin(), genreName.end(), genreName.begin(), ::toupper);
    for (GenreNode* cur = head->next; cur != NULL; cur = cur->next) {
        
        string curName = cur->g.getGenreName();
        transform(curName.begin(), curName.end(), curName.begin(), ::toupper);
        
        if( curName == genreName )
            return cur;
    }
    
    return NULL;
}




