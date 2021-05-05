#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


class GeneSplicer: public Player{
    public:
        GeneSplicer(pandemic::Board board, City city): Player(board,city){}
        Player& discover_cure();
};