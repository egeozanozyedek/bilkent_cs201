//
//  Genre.cpp
//  HW3
//
//  Created by Ege Ozan Özyedek on 12/8/19.
//  Copyright © 2019 ohnochateau. All rights reserved.
//

#include "SimpleGenre.h"

Genre::Genre(const string gname) {
    genreName = gname;
}

Genre::Genre (const Genre &genreToCopy) {
    genreName = genreToCopy.genreName;
}

Genre::~Genre() {
    
}

void Genre::operator=(const Genre &right) {
    genreName = right.genreName;
}

string Genre::getGenreName() const {
    return genreName;
}
void Genre::setGenreName(const string gName) {
    genreName = gName;
}
