#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

class Scientist: public Player{
    private:
        int card_num_to_cure;
    public:
        Scientist(pandemic::Board board, City city,int cards_for_cure): Player(board,city){
            card_num_to_cure = cards_for_cure; //how many card he need to cure a sike.            
        }
        Player& discover_cure();
        
};