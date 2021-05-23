#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic{

class Medic: public Player{
    public:
        Medic(pandemic::Board& board, City city): Player(board,city, "Medic"){}
        Player& treat(City city)override;

        Player& drive(City city)override;
        Player& fly_direct(City city)override;
        Player& fly_charter(City city)override;
        Player& fly_shuttle(City city)override;

};

}