#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <map>
#include <set>



namespace pandemic{
    class Board{
        
        protected:
        
        
        static std::map<City, std::set<City> > connections;        
        public:
        static std::map<City, Color> citys_color;
        std::map<City, int> citys_disease;
        std::set<City> research_stations;
        std::set<Color> discovered_cure;
        // City cards;
        
    
        public:
        Board():research_stations(){} // constructor
        Board(const Board& b){
            *this = b;
        } // constructor
        
        int& operator[](const City& city);//
        const int& operator[](const City& city) const;
        bool is_clean();
        void remove_cures();
        friend std::ostream& operator<<(std::ostream& os, const pandemic::Board board);
        bool is_connected(City c1,City c2);

        

    };

}