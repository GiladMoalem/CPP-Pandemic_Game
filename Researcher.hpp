#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic{

class Researcher: public Player{
    public:
        Researcher(pandemic::Board& board, City city): Player(board,city,"Researcher"){}
        Player& discover_cure(Color color);

};
}