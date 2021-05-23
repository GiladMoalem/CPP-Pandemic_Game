#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Medic.hpp"
using namespace pandemic;


    Player& Medic::treat(City city){ 
        Player::treat(city);
        board[city] = 0;
        return *this;
    }

    Player& Medic::drive(City city){
        // cout<<"MEDIC DRIVE\n";
        Player::drive(city); 
        if(board.discovered_cure.find( Board::citys_color[city] )!=board.discovered_cure.end()){
            board[city] = 0;
        }        
        return *this;
    }
    
    Player& Medic::fly_direct(City city){
        Player::fly_direct(city);
        if(board.discovered_cure.find( Board::citys_color[city] )!=board.discovered_cure.end()){
            board[city] = 0;
        } 
        return *this;
    }
    Player& Medic::fly_charter(City city){
        Player::fly_charter(city);
        if(board.discovered_cure.find( Board::citys_color[city] )!=board.discovered_cure.end()){
            board[city] = 0;
        }  
        return *this;
    }
    Player& Medic::fly_shuttle(City city){
        Player::fly_shuttle(city);
        if(board.discovered_cure.find( Board::citys_color[city] )!=board.discovered_cure.end()){
            board[city] = 0;
        }
        return *this;
    }
    
