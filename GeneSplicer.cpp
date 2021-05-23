#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "GeneSplicer.hpp"
using namespace pandemic;


    Player& GeneSplicer::discover_cure(Color color){ 
        if(board.discovered_cure.find(color)==board.discovered_cure.end()){
            if(this->board.research_stations.find(this->city) == this->board.research_stations.end())throw invalid_argument("there is no research station in this city: "+city_toString(city));
            if(cards.size()<5) throw invalid_argument("you have no 5 cards!");
            

            // delete 5 first cards.
            for(int i=0; i<5; i++){
                set<City>::iterator it = cards.begin();
                cards.erase(*it);
            }
            board.discovered_cure.insert(color);
        }
        return *this;
    }

