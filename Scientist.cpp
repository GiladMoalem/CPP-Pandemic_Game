#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Scientist.hpp"
using namespace pandemic;


    Player& Scientist::discover_cure(Color color){
       if(board.discovered_cure.find(color)==board.discovered_cure.end()){
            if(this->board.research_stations.find(this->city) == this->board.research_stations.end())throw invalid_argument("there is no research station in this city!");
            set<City> to_delete;
            int i=0;
            for( set<City>::iterator it = cards.begin() ; i<card_num_to_cure && it!=cards.end(); it++ ){
                if(board.citys_color.at(*it)==color) {
                    to_delete.insert(*it);
                    i++;
            }}
            if(to_delete.size()<card_num_to_cure) throw invalid_argument("cant discover no cards!");
            
            for(City card:to_delete){
                cards.erase(card);
            }
            board.discovered_cure.insert(color);
        }
        return *this;}