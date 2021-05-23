#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "FieldDoctor.hpp"
using namespace pandemic;


    Player& FieldDoctor::treat(City city){ 
        if(this->city != city&& !board.is_connected(this->city, city)) throw invalid_argument("you are not in or connected the city: "+city_toString(city));
        if(board.citys_disease.find(city)==board.citys_disease.end() || board.citys_disease.at(city) <= 0 )
        throw invalid_argument("city disease = 0 already");
        if(board.discovered_cure.find( board.citys_color.at(city) ) != board.discovered_cure.end()  ){ //cure fuond already
            board.citys_disease.at(city) = 0;
        }else{
            board.citys_disease.at(city)--;
        }
        return *this;
    }
