#pragma once
#include <string>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic{

class Player{
public:
    Player(Board& board, City city, string role="player"):board(board) ,city(city),_role(role) {}

protected:
Board& board;
City city;
std::string _role;
set<City> cards;

public:
// 1 drive
    virtual Player& drive(City city);
    
// 2 fly direct
    virtual Player& fly_direct(City city);

// 3 fly charter
    virtual Player& fly_charter(City city);

// 4 fly shuttle
    virtual Player& fly_shuttle(City city);

// 5 build
    virtual Player& build();

// 6 discover cure
    virtual Player& discover_cure(Color color);

// 7 treat
    virtual Player& treat(City city);

// general functions
    Player& take_card(City city);
    std::string role()const;

    friend std::ostream& operator<<(std::ostream& os,const Player& p);
};

}