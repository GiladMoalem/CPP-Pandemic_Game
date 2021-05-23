#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic{

class GeneSplicer: public Player{
    public:
        GeneSplicer(pandemic::Board& board, City city): Player(board,city,"GeneSplicer"){}
        Player& discover_cure(Color color)override;
};

}