#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


class Researcher: public Player{
    public:
        Researcher(pandemic::Board board, City city): Player(board,city){}
        Player& discover_cure();

};