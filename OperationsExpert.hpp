#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

class OperationsExpert: public Player{
    public:
        OperationsExpert(pandemic::Board board, City city): Player(board,city){}
        Player& build();
};