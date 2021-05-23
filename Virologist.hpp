#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic{

class Virologist: public Player{
    public:
        Virologist(pandemic::Board& board, City city): Player(board,city, "Virologist"){}
        Player& treat(City city)override;
};

}