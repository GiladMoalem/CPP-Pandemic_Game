#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Virologist.hpp"
using namespace pandemic;


    Player& Virologist::treat(City city){ 
        if(board.citys_disease.find(city)==board.citys_disease.end() || board.citys_disease.at(city) <= 0 )
        throw invalid_argument("city disease = 0 already");
        if(this->city != city){
            if(cards.find(city)==cards.end()) throw invalid_argument{"you have no the city's card: "+city_toString(city) 
            +"  and you are not in city "+city_toString(city)};
            cards.erase(city); 
        } 
        // VV anyway.
        if(board.discovered_cure.find( board.citys_color.at(city) ) != board.discovered_cure.end()  ){ //cure fuond already
            board.citys_disease.at(city) = 0;
        }else{
            board.citys_disease.at(city)--;
        }
        return *this;
    }