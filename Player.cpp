#include <string>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
using namespace std;


// 1 drive
    Player& Player::drive(City city){return *this;}
    

 

// 2 fly direct
    Player& Player::fly_direct(City city){return *this;}




// 3 fly charter
    Player& Player::fly_charter(City city){return *this;}




// 4 fly shuttle
    Player& Player::fly_shuttle(City city){return *this;}




// 5 build
    Player& Player::build(){return *this;}





// 6 discover cure
    Player& Player::discover_cure(Color color){return *this;}




// 7 treat
    Player& Player::treat(City city){return *this;}




// general functions
    Player& Player::take_card(City city){return *this;}
    
    
    
    string Player::role(){return "role";}
