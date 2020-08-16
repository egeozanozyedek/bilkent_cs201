//
//  SimpleBookCollection.cpp
//  HW3
//
//  Created by Ege Ozan Özyedek on 12/8/19.
//  Copyright © 2019 ohnochateau. All rights reserved.
//

#include "SimpleBookCollection.h"
#include <algorithm>

BookCollection::BookCollection() :head(new GenreNode) ,genreCount(0), name(""){
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
    name = right.name;
    
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

void BookCollection::displayGenres() const {
    
    if (head->next == NULL)
        cout << "--EMPTY--\n";

    for (GenreNode* cur = head->next; cur != NULL; cur = cur->next)
        cout << "Genre " << cur->g.getGenreName() << "\n";

    cout << "Genre amount: " << genreCount << "\n";
    
}

bool BookCollection::addGenre(const string genreName) {
    
    if (!findGenre(genreName)) {

        GenreNode *cur;
        
        for (cur = head; cur->next != NULL; cur = cur->next) { }
        
        cur->next = new GenreNode;
        cur = cur->next;
        cur->g.setGenreName(genreName);
        cur->next = NULL;
        genreCount++;
        return true;
        
    }

    cout << "Genre already exists in the collection.\n";
    return false;
}

bool BookCollection::removeGenre(const string genreName) {
    
    string name = genreName;
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    
    for (GenreNode *prev = head, *cur = head->next; cur != NULL; cur = cur->next) {
        string curName = cur->g.getGenreName();
        transform(curName.begin(), curName.end(), curName.begin(), ::toupper);
        
        if (curName == name) {
            prev->next = cur->next;
            delete cur;
            genreCount--;
            return true;
        }
        prev = cur;
    }
    
    cout << "No genre with given name found.\n";
    return false;
}

string BookCollection::getName() const {
    return name;
}

void BookCollection::setName(const string bcName) {
    name = bcName;
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

