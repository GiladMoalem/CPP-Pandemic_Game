#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Dispatcher.hpp"
using namespace pandemic;


    Player& Dispatcher::fly_direct(City city){ 
        if(board.research_stations.find(this->city)!=board.research_stations.end()){
            this->city = city;
            return *this;
        }

        if(cards.find(city)==cards.end())throw invalid_argument("you have no the card");
        cards.erase(city);
        this->city = city;
        return *this;
    }

      