#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <map>
#include <set>
#include <iostream>
#include <exception>
using namespace pandemic;
using namespace std;

        std::ostream& pandemic::operator<<(std::ostream& os, const Board board){
           
            os << "cities disease:"<<std::endl;
            int count = 0;
            for(const auto& n:board.citys_disease){
                os<< city_toString(n.first)<<" = "<<n.second<<std::endl;
            }
            if(board.citys_disease.size()==0) os<<"-"; 
            os<<std::endl;


            os<< "discovered cure:"<<std::endl;
            for(const auto& n:board.discovered_cure){
                os << color_toString(n)<<" "; 
            }
            if(board.discovered_cure.size()==0) os<<"-";
            os<<std::endl;

            os<< "reseach stations:"<<std::endl;
            for(City n:board.research_stations){
                os << city_toString(n)<<" "; 
            }
            if(board.research_stations.size()==0) os<<"-";
            std::cout<<std::endl<<std::endl;
            return os;
        }
        
        int& Board::operator[](const City& city){
            if(connections.find(city) == connections.end()) throw std::invalid_argument("there are no city");
            return citys_disease[city];
        }

        const int& Board::operator[](const City& city) const{
            if(connections.find(city) == connections.end()) throw std::invalid_argument("there are no city");
            return citys_disease.at(city);
        }

        bool Board::is_clean(){
            for(auto& c: citys_disease ){
                if(c.second > 0)
                return false;
            }
            return true;
        }
        
        void Board::remove_cures(){
            discovered_cure.clear();
        }

        bool Board::is_connected(City c1,City c2){
            
            if((this->connections.find(c1) == this->connections.end() ) || this->connections.find(c2) == this->connections.end())
            return false;
            return  (c1==c2 || this->connections.at(c1).find(c2) != this->connections.at(c1).end()); 
        }



std::map<City, std::set<City>> Board::connections {
    { Algiers, {Madrid, Paris, Istanbul, Cairo } },
    { Atlanta, {Chicago, Miami, Washington } },
    { Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi } },
    { Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong } },
    { Beijing, {Shanghai, Seoul } },
    { Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires } },
    { BuenosAires, {Bogota, SaoPaulo } },
    { Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh } },
    { Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta } },
    { Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal } },
    { Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata } },
    { Essen, {London, Paris, Milan, StPetersburg } },
    { HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila } },
    { HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei } },
    { Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow } },
    { Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney } },
    { Johannesburg, {Kinshasa, Khartoum } },
    { Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi } },
    { Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg } },
    { Kinshasa, {Lagos, Khartoum, Johannesburg } },
    { Kolkata, {Delhi, Chennai, Bangkok, HongKong } },
    { Lagos, {SaoPaulo, Khartoum, Kinshasa } },
    { Lima, {MexicoCity, Bogota, Santiago } },
    { London, {NewYork, Madrid, Essen, Paris } },
    { LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney } },
    { Madrid, {London, NewYork, Paris, SaoPaulo, Algiers } },
    { Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong } },
    { MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota } },
    { Miami, {Atlanta, MexicoCity, Washington, Bogota } },
    { Milan, {Essen, Paris, Istanbul } },
    { Montreal, {Chicago, Washington, NewYork } },
    { Moscow, {StPetersburg, Istanbul, Tehran } },
    { Mumbai, {Karachi, Delhi, Chennai } },
    { NewYork, {Montreal, Washington, London, Madrid } },
    { Osaka, {Taipei, Tokyo } },
    { Paris, {Algiers, Essen, Madrid, Milan, London } },
    { Riyadh, {Baghdad, Cairo, Karachi } },
    { SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila } },
    { Santiago, {Lima } },
    { SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid } },
    { Seoul, {Beijing, Shanghai, Tokyo } },
    { Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo } },
    { StPetersburg, {Essen, Istanbul, Moscow } },
    { Sydney, {Jakarta, Manila, LosAngeles } },
    { Taipei, {Shanghai, HongKong, Osaka, Manila } },
    { Tehran, {Baghdad, Moscow, Karachi, Delhi } },
    { Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco } },
    { Washington, {Atlanta, NewYork, Montreal, Miami } }
};

std::map<City,Color> Board::citys_color {
    { City::Algiers, Color::Black },
    { City::Atlanta, Color::Blue },
    { City::Baghdad, Color::Black },
    { City::Bangkok, Color::Red },
    { City::Beijing, Color::Red },
    { City::Bogota, Color::Yellow },
    { City::BuenosAires, Color::Yellow },
    { City::Cairo, Color::Black },
    { City::Chennai, Color::Black },
    { City::Chicago, Color::Blue },
    { City::Delhi, Color::Black },
    { City::Essen, Color::Blue },
    { City::HoChiMinhCity, Color::Red },
    { City::HongKong, Color::Red },
    { City::Istanbul, Color::Black },
    { City::Jakarta, Color::Red },
    { City::Johannesburg, Color::Yellow },
    { City::Karachi, Color::Black },
    { City::Khartoum, Color::Yellow },
    { City::Kinshasa, Color::Yellow },
    { City::Kolkata, Color::Black },
    { City::Lagos, Color::Yellow },
    { City::Lima, Color::Yellow },
    { City::London, Color::Blue },
    { City::LosAngeles, Color::Yellow },
    { City::Madrid, Color::Blue },
    { City::Manila, Color::Red },
    { City::MexicoCity, Color::Yellow },
    { City::Miami, Color::Yellow },
    { City::Milan, Color::Blue },
    { City::Montreal, Color::Blue },
    { City::Moscow, Color::Black },
    { City::Mumbai, Color::Black },
    { City::NewYork, Color::Blue },
    { City::Osaka, Color::Red },
    { City::Paris, Color::Blue },
    { City::Riyadh, Color::Black },
    { City::SanFrancisco, Color::Blue },
    { City::Santiago, Color::Yellow },
    { City::SaoPaulo, Color::Yellow },
    { City::Seoul, Color::Red },
    { City::Shanghai, Color::Red },
    { City::StPetersburg, Color::Blue },
    { City::Sydney, Color::Red },
    { City::Taipei, Color::Red },
    { City::Tehran, Color::Black },
    { City::Tokyo, Color::Red },
    { City::Washington, Color::Blue }
};


