//
//  Author.h
//  PartB
//
//  Created by Ege Ozan Özyedek on 12/9/19.
//  Copyright © 2019 ohnochateau. All rights reserved.
//

#ifndef Author_h
#define Author_h

#include <string>

using namespace std;

class Author{
public:
    
    Author();
    Author(const int id, const string name);
    int getID() const;
    void setID(const int id);
    string getName() const;
    void setName(const string name);
    
private:
    
    string name;
    int id;
    
};


#endif
