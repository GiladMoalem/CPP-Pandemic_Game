#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic{

class FieldDoctor: public Player{
    public:
        FieldDoctor(pandemic::Board& board, City city): Player(board,city,"FieldDoctor"){}
        Player& treat(City city)override;
};

}