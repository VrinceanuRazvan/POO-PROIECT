#ifndef OOP_TYPE_H
#define OOP_TYPE_H

#include <iostream>

enum class Type{
    None = 0,Fire = 1 ,Water = 2,Earth = 3,Wind = 4
};

std::ostream& operator<< (std::ostream& os, const Type& obj)
{
    if(Type::Fire == obj)
        os<<"Fire";
    if(Type::None == obj)
        os<<"None";
    if(Type::Water == obj)
        os<<"Water";
    if(Type::Earth == obj)
        os<<"Earth";
    if(Type::Wind == obj)
        os<<"Wind";
    return os;
}

#endif //OOP_TYPE_H
