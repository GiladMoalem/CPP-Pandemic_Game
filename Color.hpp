#pragma once
#include <string>

namespace pandemic{
enum Color{
    Yellow,
    Red,
    Black,
    Blue
};

inline std::string color_toString(Color c){
    switch (c)
    {
    case Color::Yellow: return "YELLOW"; break;
    case Color::Red : return "Red"; break;
    case Color::Black : return "Black"; break;
    case Color::Blue: return "Blue"; break;
    
    default: return "no color!"; break;
    }
}
}



