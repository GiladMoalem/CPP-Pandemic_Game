#pragma once
#include "City.hpp"
#include <iostream>
#include <map>
#include <set>


namespace pandemic{
    class Board{
        
        private:
        std::map<City, std::set<City>> connections;
        std::map<City, int> disease;

        public:
        Board(){} // constructor
        int& operator[](const City& city);
        bool is_clean();
        void remove_cures();
        friend std::ostream& operator<<(std::ostream& os, const pandemic::Board board);

    };

}