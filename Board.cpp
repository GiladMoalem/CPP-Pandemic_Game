#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <map>
#include <set>
using namespace pandemic;


        std::ostream& pandemic::operator<<(std::ostream& os, const Board board){
            return os;
        }
        int& Board::operator[](const City& city){
            return disease[city];
        }

        bool Board::is_clean(){
            return true;
        }
        void Board::remove_cures(){}
