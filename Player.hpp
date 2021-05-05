#pragma once
#include <string>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace std;

class Player{
public:
Player(pandemic::Board board, City city){
    this->board = board;
    this->city = city;
}

protected:
pandemic::Board board;
City city;

public:
// 1 drive
    Player& drive(City city);
    
// 2 fly direct
    Player& fly_direct(City city);

// 3 fly charter
    Player& fly_charter(City city);

// 4 fly shuttle
    Player& fly_shuttle(City city);

// 5 build
    Player& build();

// 6 discover cure
    Player& discover_cure(Color color);

// 7 treat
    Player& treat(City city);

// general functions
    Player& take_card(City city);
    string role();
};