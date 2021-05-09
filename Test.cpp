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
/*___________________________________________________________________________________________________*/

// fly_charter 
TEST_CASE("fly charter function - uses card for fly"){
    Board board;
    OperationsExpert player{board,City::Atlanta};

    for (size_t i = 0; i < CITYS; i++){
        CHECK_THROWS(player.fly_charter(City(i)));
    }

    player.take_card(City::Delhi);
    CHECK_NOTHROW(player.fly_charter(City::Delhi));
    CHECK_NOTHROW(player.drive(City::Tehran));
    // used the card Delhi
    CHECK_THROWS(player.fly_charter(City::Delhi));
}
/*___________________________________________________________________________________________________*/

// fly_shuttle
TEST_CASE("fly shuttle function - before & after build stations"){
    Board board;
    Scientist scient_player{board,City::Atlanta,4};//must be not Dispatcher!
    OperationsExpert ex_player1{board,City::Atlanta};
    OperationsExpert ex_player2{board,City::Bogota};
    
    CHECK_THROWS(scient_player.fly_shuttle(City::Chennai));
    
    CHECK_NOTHROW(ex_player1.build());
    for (size_t i = 0; i < CITYS; i++){
        CHECK_THROWS(scient_player.fly_shuttle(City(i)));
    }

    CHECK_NOTHROW(ex_player2.build());

    //now the player can fly shuttle between Atlanta and Bogota how many time he wants.
    CHECK_THROWS(scient_player.fly_shuttle(City::Bogota));
    CHECK_THROWS(scient_player.fly_shuttle(City::Atlanta));
    CHECK_THROWS(scient_player.fly_shuttle(City::Bogota));
}

/*___________________________________________________________________________________________________*/

// build
TEST_CASE("build function - basic regular player"){
    Board board;
    Dispatcher dis_player{board,City::Atlanta};
    CHECK_THROWS(dis_player.build());
    dis_player.take_card(City::Bangkok);
    CHECK_THROWS(dis_player.build());
    dis_player.take_card(City::Atlanta);
    CHECK_NOTHROW( dis_player.build());

// cant fly charter because he drop the card 'Atlanta'.
    CHECK_THROWS( dis_player.fly_charter(City::Baghdad));
    CHECK_NOTHROW( dis_player.fly_direct(City::Bangkok));//without drop the card.
    CHECK_NOTHROW( dis_player.build());
    CHECK_NOTHROW( dis_player.fly_direct(City::Essen));
}

/*___________________________________________________________________________________________________*/

// build
TEST_CASE("build function - build in builded city: should do nothing!"){
    Board board;
    OperationsExpert ex_player{board,City::Atlanta};
    Dispatcher dis_player{board,City::Atlanta};
    
    CHECK_NOTHROW( ex_player.build());
    dis_player.take_card(City::Atlanta);
    CHECK_NOTHROW( dis_player.build());  // does nothing!

// can fly charter because he didnt drop the card 'Atlanta'!!.
    CHECK_NOTHROW( dis_player.fly_charter(City::Baghdad));
    
    CHECK_THROWS( dis_player.fly_direct(City::Atlanta));
    
    OperationsExpert temp_player{board,City::Atlanta};
    temp_player.take_card(City::Cairo);
    CHECK_NOTHROW( temp_player.build());
    CHECK_NOTHROW( temp_player.build());
    CHECK_NOTHROW( temp_player.build());
    // didnt drop the 'Cairo' card.
    CHECK_NOTHROW( temp_player.fly_direct(City::Cairo));
}

/*___________________________________________________________________________________________________*/
TEST_CASE("build function - with OperationExpert player"){
    Board board;
    OperationsExpert ex_player{board,City::Atlanta};
    
    ex_player.take_card(City::Atlanta);
    CHECK_NOTHROW( ex_player.build());//without using the 'Atlanta' card.
    CHECK_NOTHROW( ex_player.fly_charter(City::Riyadh));
    CHECK_NOTHROW( ex_player.build());

    Virologist viro{board,City::Atlanta};
    CHECK_NOTHROW( viro.fly_shuttle(City::Riyadh));
}
/*___________________________________________________________________________________________________*/
// discover_cure
TEST_CASE("discover_cure function - need 5 cards, color and station"){
    Board board;
    OperationsExpert ex{board,City::Atlanta};
    
    CHECK_THROWS( ex.discover_cure(Color::Blue));//not station & 5 cards.
    
    // build but not 5 cards.
    ex.build();
    ex.take_card(City::Lagos)
      .take_card(City::Kinshasa)
      .take_card(City::Khartoum)
      .take_card(City::Johannesburg);
    CHECK_THROWS( ex.discover_cure(Color::Yellow));//need 5 cards.
    ex .take_card(City::Lima);
    CHECK_THROWS( ex.discover_cure(Color::Blue));//not the color of the cards.
    CHECK_NOTHROW( ex.discover_cure(Color::Yellow));

    // 5 cards but not build.
    ex.drive(City::Washington);
    ex.take_card(City::SanFrancisco)
      .take_card(City::Washington)
      .take_card(City::Atlanta)
      .take_card(City::Chicago)
      .take_card(City::Montreal);
    CHECK_THROWS( ex.discover_cure(Color::Blue));

    // build and 5 cards but not color.
    ex.build();
    CHECK_THROWS( ex.discover_cure(Color::Black));

    ex.fly_direct(City::SanFrancisco);// make sure the cards didnt thraw.
}
/*___________________________________________________________________________________________________*/
TEST_CASE("discover_cure function - discover cure cuple time"){
    Board board;
    OperationsExpert ex{board, City::Atlanta};
    
    ex.build();
    ex.take_card(City::SanFrancisco)
      .take_card(City::Washington)
      .take_card(City::Atlanta)
      .take_card(City::Chicago)
      .take_card(City::Montreal);
    CHECK_NOTHROW(ex.discover_cure(Color::Blue));
    CHECK_THROWS( ex.fly_direct(City::SanFrancisco));

    Dispatcher dis_player{board,City::Washington};
    dis_player.take_card(City::SanFrancisco)
              .take_card(City::Washington)
              .take_card(City::Atlanta)
              .take_card(City::Chicago)
              .take_card(City::Montreal);

    CHECK_NOTHROW( dis_player.discover_cure(Color::Blue));//should does nothing.
    CHECK_NOTHROW( dis_player.fly_charter(City::Sydney));
}
/*___________________________________________________________________________________________________*/
TEST_CASE("discover_cure function - not need to be in the curent city"){
    Board board;
    OperationsExpert ex{board, City::Atlanta};
    
    ex.build();    
    CHECK_THROWS(ex.discover_cure(Color::Black));
    ex.take_card(City::Beijing)
      .take_card(City::Shanghai)
      .take_card(City::Seoul)
      .take_card(City::Tokyo)
      .take_card(City::Osaka);
    CHECK_NOTHROW(ex.discover_cure(Color::Red));
}
/*___________________________________________________________________________________________________*/
TEST_CASE("discover_cure function - Scientist"){
    Board board;
    Scientist scient{board, City::Atlanta, 4};
    OperationsExpert ex{board, City::Atlanta};
    
    ex.build();
    CHECK_THROWS( scient.discover_cure(Color::Red));
    scient.take_card(City::Beijing)
          .take_card(City::Shanghai)
          .take_card(City::Seoul)
          .take_card(City::Tokyo);
    CHECK_NOTHROW( scient.discover_cure(Color::Red));
    CHECK_THROWS(scient.fly_direct(City::Shanghai));//make sure the card droped.

    Scientist scient2{board, City::Atlanta, 1};
    CHECK_THROWS(scient2.discover_cure(Color::Red));
    scient2.take_card(City::SanFrancisco)
            .take_card(City::Washington)
            .take_card(City::Atlanta);
    CHECK_NOTHROW( scient2.discover_cure(Color::Blue));
    
    int count = 0;//cant fly_direct becouse droped the card.
    try{
        scient2.fly_direct(City::SanFrancisco);
	} catch (const exception& ex) {
    count++;
    }try{
        scient2.fly_direct(City::Washington);
	} catch (const exception& ex) {
    count++;
    }try{
        scient2.fly_direct(City::Atlanta);
	} catch (const exception& ex) {
    count++;
    }
    CHECK_EQ(count, 1);
    

}
/*___________________________________________________________________________________________________*/
TEST_CASE("discover_cure function - Researcher"){
    Board board;
    Researcher player{board, City::Atlanta};
    player.take_card(City::Beijing)
          .take_card(City::Shanghai)
          .take_card(City::Seoul)
          .take_card(City::Tokyo);
    CHECK_THROWS( player.discover_cure(Color::Red));
    player.take_card(City::Osaka);
    CHECK_NOTHROW(player.discover_cure(Color::Red));
}
/*___________________________________________________________________________________________________*/
TEST_CASE("discover_cure function - GeneSplicer"){
    Board board;
    GeneSplicer gene_player{board, City::Atlanta};
    OperationsExpert ex{board, City::Atlanta};
    ex.build();
    
    // discover without 5 cards.
    CHECK_THROWS( gene_player.discover_cure(Color::Blue));
    gene_player.take_card(City::Beijing)
               .take_card(City::Shanghai)
               .take_card(City::Seoul)
               .take_card(City::Tokyo);
    CHECK_THROWS( gene_player.discover_cure(Color::Red));
    gene_player.take_card(City::Beijing);
    CHECK_THROWS( gene_player.discover_cure(Color::Red));
    gene_player.fly_direct(City::Beijing).fly_direct(City::Shanghai);
    // now he in 'Shanchai' with 2 cards.

    OperationsExpert ex2{board, City::Shanghai};
    ex2.build();
    
    gene_player.take_card(City::Sydney)
                .take_card(City::Tehran)
                .take_card(City::Washington);
    CHECK_NOTHROW( gene_player.discover_cure(Color::Yellow));
    CHECK_THROWS( gene_player.fly_direct(City::Sydney));//make sure drop all the cards.

    // make sure the cure discovered.    
    board[City::Lima] = 2;
    ex2.take_card(City::Lima)
    .fly_direct(City::Lima)
    .treat(City::Lima);
    CHECK_EQ( board[City::Lima], 0);    
}

/*___________________________________________________________________________________________________*/
// treat
TEST_CASE("treat function - not in current city and without disease throws exception"){
    Board board;
    OperationsExpert ex1{board,City::Atlanta};
    OperationsExpert ex2{board,City::Kolkata};
    OperationsExpert ex3{board,City::Essen};

    CHECK_THROWS( ex1.treat(City::Atlanta));
    CHECK_THROWS( ex2.treat(City::Kolkata));
    CHECK_THROWS( ex3.treat(City::Essen));

    board[City::Atlanta] = 1;
    board[City::Kolkata] = 2;
    CHECK_THROWS( ex1.treat(City::Lima));
    CHECK_THROWS( ex3.treat(City::Atlanta));

    CHECK_NOTHROW( ex1.treat(City::Atlanta));
    CHECK_NOTHROW( ex2.treat(City::Kolkata));
    CHECK_FALSE( board.is_clean());
    CHECK_NOTHROW( ex2.treat(City::Kolkata));
    CHECK( board.is_clean());
}
/*___________________________________________________________________________________________________*/
TEST_CASE("treat function - after discover_cure"){
    Board board;
    OperationsExpert ex{board,City::Atlanta};
    
    // discover cure
    ex.build();
    ex.take_card(City::Washington)
        .take_card(City::London)
        .take_card(City::Montreal)
        .take_card(City::Chicago)
        .take_card(City::SanFrancisco);
    CHECK_NOTHROW( ex.discover_cure( Color::Blue));

    // treat
    board[City::Atlanta] = 3;
    CHECK_NOTHROW (ex.treat(City::Atlanta));
    CHECK_EQ( board[City::Atlanta], 0);
    CHECK_THROWS( ex.treat(City::Atlanta));
}

/*___________________________________________________________________________________________________*/
TEST_CASE("treat function - with Medic player before & after discover cure"){
    Board board;
    Medic med_player{board,City::Atlanta};
    CHECK_THROWS( med_player.treat(City::Atlanta));
    board[City::Atlanta] = 3;
    CHECK_NOTHROW( med_player.treat(City::Atlanta));
    CHECK_EQ( board[City::Atlanta], 0);
    
    // discover cure
    OperationsExpert ex{board,City::Washington};
    ex.build();
    ex.take_card(City::Washington)
        .take_card(City::London)
        .take_card(City::Montreal)
        .take_card(City::Chicago)
        .take_card(City::SanFrancisco);
    CHECK_NOTHROW( ex.discover_cure( Color::Blue));

    board[City::Chicago] = 2;
    board[City::SanFrancisco] = 2;
    board[City::London] = 2;
    

    //automatic treat of Medic by drive
    med_player.drive(City::Chicago);
    CHECK_EQ(board[City::Chicago], 0);
    CHECK_THROWS( med_player.treat(City::Chicago));
    
    //automatic treat of Medic by fly_charter
    med_player.take_card(City::Chicago);
    med_player.fly_charter(City::SanFrancisco);
    CHECK_EQ( board[City::SanFrancisco], 0);

    //automatic treat of Medic by fly_direct
    med_player.take_card(City::London);
    med_player.fly_direct(City::London);
    CHECK_EQ( board[City::London], 0);

    board[City::Cairo] = 3;
    med_player.take_card(City::Cairo);
    med_player.fly_direct(City::Cairo);
    CHECK_EQ( board[City::Cairo], 3);
}

/*___________________________________________________________________________________________________*/
TEST_CASE("treat function - Virologist"){
    Board board;
    Virologist viro{board,City::Atlanta};
    board[City::Washington] = 3;
    CHECK_THROWS( viro.treat(City::Washington));//no have the card.
    
    viro.take_card(City::Washington);
    CHECK_NOTHROW( viro.treat(City::Washington));
    CHECK_EQ(board[City::Washington], 2);


    srand(time(NULL)); //for the rand func
    City city;
    for (size_t i = 0; i < 10; i++){   
        city = City(rand()%CITYS);
        viro.take_card(city);
        board[city] = 2;
        CHECK_NOTHROW( viro.treat(city));
        CHECK_EQ( board[city], 1);
    }
    CHECK_THROWS( viro.fly_direct(city));//cant because he drop the card by treating the city.
}
/*___________________________________________________________________________________________________*/
TEST_CASE("treat function - Virologist treat the all world"){
    Board board;
    Virologist viro{board, City::BuenosAires};
    
    // the all world sick with 1 disease
    for (size_t i = 0; i < CITYS; i++){ board[City(i)] = 1; }
    
    for (size_t i = 0; i < CITYS; i++){
        viro.take_card(City(i));
        CHECK_NOTHROW( viro.treat(City(i)));
    }
    // 'BuenosAires' card didnt used.
    CHECK_NOTHROW( viro.fly_charter(City::HongKong)); 
    
    CHECK( board.is_clean());
}

/*___________________________________________________________________________________________________*/
TEST_CASE("treat function - FieldDoctor"){
    Board board;
    FieldDoctor doc{board,City::Atlanta};

    CHECK_THROWS( doc.treat(City::Atlanta));

    doc.take_card(City::Baghdad).fly_direct(City::Baghdad);
    for (size_t i = 0; i < CITYS; i++){ board[City(i)] = 1; }
    
    for (size_t i = 0; i < CITYS; i++)
    {
        if(i==City::Baghdad||i==City::Istanbul
        ||i==City::Cairo||i==City::Riyadh
        ||i==City::Karachi||i==City::Tehran)
            CHECK_NOTHROW( doc.treat(City(i)));
        else
            CHECK_THROWS( doc.treat(City(i)));
    }

    int count_disease = 0;
    for (size_t i = 0; i < CITYS; i++)
    {
        count_disease += board[City(i)];
    }
    CHECK_EQ( count_disease, CITYS-6);//treated 6 city.
}
/*___________________________________________________________________________________________________*/
TEST_CASE("treat after discover cure by cuple players"){
    Board board;
    OperationsExpert ex_player{board, City::Cairo};
    Dispatcher dis_player{board, City::Cairo};
    Virologist viro_player{board, City::Milan};
    
    for (size_t i = 0; i < CITYS; i++){ board[City(i)] = 3; }//the all world sick.

// discover cure
    ex_player.build();
    dis_player.take_card(City::Washington)
        .take_card(City::London)
        .take_card(City::Montreal)
        .take_card(City::Chicago)
        .take_card(City::SanFrancisco);
    CHECK_THROWS( dis_player.discover_cure( Color::Red));
    CHECK_NOTHROW( dis_player.discover_cure( Color::Blue));
    
    dis_player.fly_direct(City::SanFrancisco);
    CHECK_NOTHROW( dis_player.treat(City::SanFrancisco));
    CHECK_EQ( board[City::SanFrancisco], 0);
    
    viro_player.take_card(City::NewYork);
    CHECK_NOTHROW( viro_player.treat(City::NewYork));
    CHECK_EQ( board[City::NewYork], 0);

    viro_player.take_card(City::HongKong);
    CHECK_NOTHROW( viro_player.treat(City::HongKong));
    CHECK_EQ( board[City::HongKong], 2);

    ex_player.take_card(City::Cairo);
    CHECK_NOTHROW( ex_player.treat( City::Cairo));
    CHECK_EQ( board[City::Cairo], 2);

    ex_player.drive(City::Algiers).drive(City::Madrid);
    CHECK_NOTHROW( ex_player.treat(City::Madrid));
    CHECK_EQ( board[City::Madrid], 0);
}
/*___________________________________________________________________________________________________*/
