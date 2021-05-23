#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic{

class Dispatcher: public Player{
    public:
        Dispatcher(pandemic::Board& board, City city): Player(board,city,"Dispatcher"){}
        Player& fly_direct(City city);
};

}
