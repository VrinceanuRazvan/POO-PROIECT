#ifndef OOP_ELEMENTALTYPE_H
#define OOP_ELEMENTALTYPE_H

#include <iostream>

enum class ElementalType{
    None = 0,Fire = 1 ,Water = 2,Earth = 3,Wind = 4
};

/*std::ostream& operator<< (std::ostream& os, const ElementalType& obj)
{
    if(ElementalType::Fire == obj)
        os<<"Fire";
    if(ElementalType::None == obj)
        os<<"None";
    if(ElementalType::Water == obj)
        os<<"Water";
    if(ElementalType::Earth == obj)
        os<<"Earth";
    if(ElementalType::Wind == obj)
        os<<"Wind";
    return os;
}*/

#endif //OOP_ELEMENTALTYPE_H
