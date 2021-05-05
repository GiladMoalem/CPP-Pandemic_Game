#include <string>
#include <iostream>

#include "doctest.h"

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#define CITYS 48

TEST_CASE("init board test - get & set city's disease cubes"){
    Board board;

    for (size_t i = 0; i < CITYS; i++){
        CHECK_EQ( board[City(i)] ,0 );
    }
    CHECK(board.is_clean());

    board[City::London] = 0;
    board[City::Miami] = 0;
    board[City::Taipei] = 0;
    CHECK(board.is_clean());
    
    CHECK_EQ( board[City::London] ,0 );
    CHECK_EQ( board[City::Miami] ,0 );
    CHECK_EQ( board[City::Taipei] ,0 );

    board[City::London] = 1;
    CHECK_EQ(board[City::London], 1);
    board[City::London] = 2;
    CHECK_EQ(board[City::London], 2);
    board[City::LosAngeles] = 2;
    CHECK_EQ(board[City::LosAngeles], 2);
    board[City::Milan] = 3;
    CHECK_EQ(board[City::Milan], 3);
    board[City::Mumbai] = 1;
    CHECK_EQ(board[City::Mumbai], 1);
    board[City::Paris] = 1;
    CHECK_EQ(board[City::Paris], 1);
    board[City::Santiago] = 1;
    CHECK_EQ(board[City::Santiago], 1);
    board[City::StPetersburg] = 1;
    CHECK_EQ(board[City::StPetersburg], 1);
    CHECK_FALSE(board.is_clean());

    SUBCASE("che"){
        
    }
}

TEST_CASE("board conection test - check if player can drive to connected city"){
    Board board;
	OperationsExpert player {board, City::Atlanta};  // initialize an "operations expert" player on the given board, in Atlanta.
    CHECK_NOTHROW(player.drive(City::Chicago));
    CHECK_NOTHROW(player.drive(City::SanFrancisco));
    CHECK_NOTHROW(player.drive(City::Chicago));
    
    CHECK_THROWS(player.drive(City::Miami));
    CHECK_THROWS(player.drive(City::Lagos));
    CHECK_THROWS(player.drive(City::Cairo));

    CHECK_NOTHROW(player.drive(City::Montreal));
    CHECK_NOTHROW(player.drive(City::NewYork));
    CHECK_NOTHROW(player.drive(City::London));
    CHECK_NOTHROW(player.drive(City::Paris));
    CHECK_NOTHROW(player.drive(City::Milan));
    CHECK_NOTHROW(player.drive(City::Istanbul));
    CHECK_NOTHROW(player.drive(City::Baghdad));
    CHECK_NOTHROW(player.drive(City::Karachi));
    CHECK_NOTHROW(player.drive(City::Delhi));
    CHECK_NOTHROW(player.drive(City::Kolkata));
    CHECK_NOTHROW(player.drive(City::HongKong));

// check player move from HongKong to all the citys.
    for (size_t i = 0; i < CITYS; i++){
        if((i!=City::Kolkata)&&(i!=City::Bangkok)&&(i!=City::HoChiMinhCity)&&(i!=City::Manila)&&(i!=City::Taipei)&&(i!=City::Shanghai)&&(i!=City::HongKong) ){//driving from HongKong to HongKong is legale? 
            CHECK_THROWS(player.drive(City(i)));
        }
    }
}

TEST_CASE("board conection test - check complicated connection"){
    Board board;
    Medic med{board, City::Seoul};
    CHECK_NOTHROW(med.drive(City::Tokyo));

// check player move from Tokyo to all the citys.
    for (size_t i = 0; i < CITYS; i++){
        if((i!=City::Tokyo)&&(i!=City::Seoul)&&(i!=City::Shanghai)&&(i!=City::Osaka)&&(i!=City::SanFrancisco) ){
            CHECK_THROWS(med.drive(City(i)));
        }
    }
    CHECK_NOTHROW(med.drive(City::SanFrancisco));
    CHECK_NOTHROW(med.drive(City::Manila));
    CHECK_NOTHROW(med.drive(City::SanFrancisco));
    CHECK_NOTHROW(med.drive(City::LosAngeles));
    CHECK_NOTHROW(med.drive(City::Sydney));
}
