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
using namespace std;
class Genre {
public:
    Genre(const string gname = "");
    ~Genre ();
    Genre (const Genre &genreToCopy);
    void operator=(const Genre &right);
    string getGenreName() const;
    void setGenreName(const string gName);
private:
    string genreName;
};

#endif 
