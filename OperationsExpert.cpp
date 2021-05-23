#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "OperationsExpert.hpp"
using namespace pandemic;
 
    Player& OperationsExpert::build(){ 
        if(board.research_stations.find(this->city)==board.research_stations.end()){
            board.research_stations.insert(this->city);
        }
        return *this;}