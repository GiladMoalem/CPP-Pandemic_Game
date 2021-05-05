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


/*___________________________________________________________________________________________________*/

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
/*___________________________________________________________________________________________________*/

// basic drive funcion
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
/*___________________________________________________________________________________________________*/

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

/*___________________________________________________________________________________________________*/

// basic fly direct 
TEST_CASE("fly direct function"){
    Board board;
    OperationsExpert player{board,City::Atlanta};
    
    for (size_t i = 0; i < CITYS; i++){
        CHECK_THROWS(player.fly_direct(City(i)));
    }
    CHECK_NOTHROW(
    player.take_card(City::Cairo)
          .take_card(City::Lima)
          .take_card(City::Moscow);
    );

    for (size_t i = 0; i < CITYS; i++){
        if( i==City::Cairo || i==City::Lima || i==City::Moscow ){
            CHECK_NOTHROW(player.fly_direct(City(i)));
        }else{
            CHECK_THROWS(player.fly_direct(City(i)));
        }
    }
// need check what apand if player fly_direct to the city he been?
    CHECK_THROWS(player.fly_direct(City::Moscow));
    CHECK_THROWS(player.fly_direct(City::Lima));
    CHECK_THROWS(player.fly_direct(City::Cairo));

    CHECK_THROWS(player.fly_direct(City::Atlanta));
}
/*___________________________________________________________________________________________________*/

TEST_CASE("fly direct function with Dispatcher"){
    Board board;
    Dispatcher dis_player{board,City::Atlanta};
    
    for (size_t i = 0; i < CITYS; i++){
        CHECK_THROWS(dis_player.fly_direct(City(i)));
    }

    CHECK_NOTHROW( 
        dis_player.take_card(City::Beijing)
                  .take_card(City::Chicago)
    );

    for (size_t i = 0; i < CITYS; i++){
        if(i==City::Chicago||i==City::Beijing){
            CHECK_NOTHROW(dis_player.fly_direct(City(i)));
        }else{
            CHECK_THROWS(dis_player.fly_direct(City(i)));
        }
    }
}
/*___________________________________________________________________________________________________*/
TEST_CASE("fly direct function with Dispatcher & OperationsExpert - dis' can fly direct after expert' build a station"){
    Board board;
    Dispatcher dis_player{board, City::Atlanta};
    OperationsExpert expert_player{board,City::Washington};
    
    CHECK_NOTHROW(expert_player.build());
    
    for (size_t i = 0; i < CITYS; i++){
        CHECK_THROWS(dis_player.fly_direct(City(i)));
    }

    CHECK_NOTHROW( dis_player.drive(City::Washington));
    
    srand(time(NULL)); //for the rand func
    CHECK_NOTHROW( dis_player.fly_direct(City(rand()%CITYS)));//what apand if he fly direct to woshington?
}
/*___________________________________________________________________________________________________*/

TEST_CASE("fly direct function with Dispatcher & OperationsExpert - dis' can fly direct after expert' build a station - RANDOM - "){
    Board board;
    OperationsExpert expert_player{board, City::Washington};
    CHECK_NOTHROW (expert_player.build());
    srand(time(NULL)); //for the rand func

    for (size_t i = 0; i < 100; i++){
        Dispatcher dis_player_temp{board,City::Washington};
        int city = City::Washington;
        while(city == City::Washington) { city = rand()%CITYS;  }
        
        CHECK_NOTHROW (dis_player_temp.fly_direct(City(city)));
        CHECK_THROWS (dis_player_temp.fly_direct(City::Washington));
    }
}