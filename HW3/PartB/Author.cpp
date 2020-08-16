//
//  Author.cpp
//  PartB
//
//  Created by Ege Ozan Özyedek on 12/9/19.
//  Copyright © 2019 ohnochateau. All rights reserved.
//

#include "Author.h"

Author::Author(): id(0), name("") { }

Author::Author(const int id, const string name): id(id), name(name) { }

int Author::getID() const {
    return id;
}

void Author::setID(const int id) {
    this->id = id;
}

string Author::getName() const {
    return name;
}

void Author::setName(const string name) {
    this->name = name;
}

