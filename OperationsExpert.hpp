#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic{

class OperationsExpert: public Player{
    public:
        OperationsExpert(pandemic::Board& board, City city): Player(board,city,"OperationsExpert"){}
        Player& build()override;
};

}