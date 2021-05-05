#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


class FieldDoctor: public Player{
    public:
        FieldDoctor(pandemic::Board board, City city): Player(board,city){}
        Player& treat();
};
