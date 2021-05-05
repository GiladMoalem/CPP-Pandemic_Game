#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

class Virologist: public Player{
    public:
        Virologist(pandemic::Board board, City city): Player(board,city){}
        Player& treat();
};