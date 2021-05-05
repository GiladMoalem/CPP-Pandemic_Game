#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


class Medic: public Player{
    public:
        Medic(pandemic::Board board, City city): Player(board,city){}
        Player& treat();
};