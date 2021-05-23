#include <string>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <exception>
using namespace std;
using namespace pandemic;


// 1 drive
    Player& Player::drive(pandemic::City city1){
    //   cout<<"PLATER DIRVE\n";
      if(!board.is_connected(this->city, city1)) throw invalid_argument("DRIVE: the two citys not connected");
      this->city=city1;
      return *this;
    }
    

 

// 2 fly direct
    Player& Player::fly_direct(City city){
        if(cards.find(city)==cards.end())throw invalid_argument("you have no the card");
        cards.erase(city);
        this->city = city;
        return *this;
    }




// 3 fly charter
    Player& Player::fly_charter(City city1){

        if(cards.find(this->city)==cards.end())throw invalid_argument("you have no the card: "+city_toString(this->city));
        cards.erase(this->city);
        this->city = city1;
        return *this;}




// 4 fly shuttle
    Player& Player::fly_shuttle(City city1){
        if(board.research_stations.find(this->city)==board.research_stations.end()||
        board.research_stations.find(city1)==board.research_stations.end() )throw invalid_argument("FLY SUTTLE: no station");
        this->city = city1;
        return *this;}




// 5 build
    Player& Player::build(){
        if(board.research_stations.find(this->city)==board.research_stations.end()){
            if(cards.find(this->city)==cards.end()) throw invalid_argument("");
            cards.erase(this->city);
            board.research_stations.insert(this->city);
        }
        return *this;}





// 6 discover cure
    Player& Player::discover_cure(Color color){
        if(board.discovered_cure.find(color)==board.discovered_cure.end()){
            if(this->board.research_stations.find(this->city) == this->board.research_stations.end())throw invalid_argument("there is no research station in this city: "+city_toString(city));
            set<City> to_delete;
            int i=0;
            for( set<City>::iterator it = cards.begin() ; i<5 && it!=cards.end(); it++ ){
                if(board.citys_color.at(*it)==color) {
                    to_delete.insert(*it);
                    i++;
            }}
            
            if(to_delete.size()<5) throw invalid_argument("you have "+to_string(to_delete.size())+"cards but you need 5!");
            
            for(City card:to_delete){
                cards.erase(card);
            }
            board.discovered_cure.insert(color);
        }
        return *this;}




// 7 treat
    Player& Player::treat(City city){
        if(this->city != city) throw invalid_argument("you are not in city "+city_toString(city));
        if(board.citys_disease.find(city)==board.citys_disease.end() || board.citys_disease.at(city) <= 0 )
        throw invalid_argument("city disease = 0 already");
        if(board.discovered_cure.find( board.citys_color.at(city) ) != board.discovered_cure.end()  ){ //cure fuond already
            board.citys_disease.at(city) = 0;
        }else{
            board.citys_disease.at(city)--;
        }
        return *this;}




// general functions
    Player& Player::take_card(City city){
        if(cards.find(city)==cards.end()){
            cards.insert(city);
        } 
        return *this;
        }
    
    
    
    string Player::role()const{return _role;}

    ostream& pandemic::operator<<(ostream& os,const Player& p){
        os<< p._role<<"-> CITY:"<<city_toString(p.city)<<endl;
        os<<"CARDS: ";
        for (auto &&i : p.cards){
            os<<city_toString(i)<<' ';
        }
        return os<<endl<<endl;
    }
