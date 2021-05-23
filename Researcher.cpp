#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Researcher.hpp"
using namespace pandemic;


    Player& Researcher::discover_cure(Color color){
        if(board.discovered_cure.find(color)==board.discovered_cure.end()){
            set<City> to_delete;
            int i=0;
            for( set<City>::iterator it = cards.begin() ; i<5 && it!=cards.end(); it++ ){
                if(board.citys_color.at(*it)==color) {
                    to_delete.insert(*it);
                    i++;
            }}
            if(to_delete.size()<5) throw invalid_argument("cant discover no cards!");
            
            for(City card:to_delete){
                cards.erase(card);
            }
            board.discovered_cure.insert(color);
        }
        return *this;
    }

    