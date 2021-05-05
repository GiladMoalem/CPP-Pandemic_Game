#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

class Dispatcher: public Player{
    public:
        Dispatcher(pandemic::Board board, City city): Player(board,city){}
        Player& fly_direct();
};


