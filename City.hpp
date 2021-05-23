#pragma once
#include <string>

namespace pandemic{
enum City{
Algiers, // Black Madrid Paris Istanbul Cairo
Atlanta, // Blue Chicago Miami Washington
Baghdad, // Black Tehran Istanbul Cairo Riyadh Karachi
Bangkok, // Red Kolkata Chennai Jakarta HoChiMinhCity HongKong
Beijing, // Red Shanghai Seoul
Bogota, // Yellow MexicoCity Lima Miami SaoPaulo BuenosAires
BuenosAires, // Yellow Bogota SaoPaulo
Cairo, // Black Algiers Istanbul Baghdad Khartoum Riyadh
Chennai, // Black Mumbai Delhi Kolkata Bangkok Jakarta
Chicago, // Blue SanFrancisco LosAngeles MexicoCity Atlanta Montreal
Delhi, // Black Tehran Karachi Mumbai Chennai Kolkata
Essen, // Blue London Paris Milan StPetersburg
HoChiMinhCity, // Red Jakarta Bangkok HongKong Manila
HongKong, // Red Bangkok Kolkata HoChiMinhCity Shanghai Manila Taipei
Istanbul, // Black Milan Algiers StPetersburg Cairo Baghdad Moscow
Jakarta, // Red Chennai Bangkok HoChiMinhCity Sydney
Johannesburg, // Yellow Kinshasa Khartoum
Karachi, // Black Tehran Baghdad Riyadh Mumbai Delhi
Khartoum, // Yellow Cairo Lagos Kinshasa Johannesburg
Kinshasa, // Yellow Lagos Khartoum Johannesburg
Kolkata, // Black Delhi Chennai Bangkok HongKong
Lagos, // Yellow SaoPaulo Khartoum Kinshasa
Lima, // Yellow MexicoCity Bogota Santiago
London , //Blue NewYork Madrid Essen Paris
LosAngeles ,//Yellow SanFrancisco Chicago MexicoCity Sydney
Madrid ,//Blue London NewYork Paris SaoPaulo Algiers
Manila ,//Red Taipei SanFrancisco HoChiMinhCity Sydney
MexicoCity ,//Yellow LosAngeles Chicago Miami Lima Bogota
Miami ,//Yellow Atlanta MexicoCity Washington Bogota
Milan ,//Blue Essen Paris Istanbul
Montreal ,//Blue Chicago Washington NewYork
Moscow ,//Black StPetersburg Istanbul Tehran
Mumbai ,//Black Karachi Delhi Chennai
NewYork ,//Blue Montreal Washington London Madrid
Osaka ,//Red Taipei Tokyo
Paris ,//Blue Algiers Essen Madrid Milan London
Riyadh ,//Black Baghdad Cairo Karachi
SanFrancisco ,//Blue LosAngeles Chicago Tokyo Manila
Santiago ,//Yellow Lima
SaoPaulo ,//Yellow Bogota BuenosAires Lagos Madrid
Seoul ,//Red Beijing Shanghai Tokyo
Shanghai ,//Red Beijing HongKong Taipei Seoul Tokyo
StPetersburg ,//Blue Essen Istanbul Moscow
Sydney ,//Red Jakarta Manila LosAngeles
Taipei ,//Red Shanghai HongKong Osaka Manila
Tehran ,//Black Baghdad Moscow Karachi Delhi
Tokyo ,//Red Seoul Shanghai Osaka SanFrancisco
Washington //Blue Atlanta NewYork Montreal Miami
};

inline std::string city_toString(City c){

    switch (c){
        case Algiers: return "Algiers"; break;
        case Atlanta: return "Atlanta"; break;
        case Baghdad: return "Baghdad"; break;
        case Bangkok: return "Bangkok"; break;
        case Beijing: return "Beijing"; break;
        case Bogota: return "Bogota"; break;
        case BuenosAires: return "BuenosAires"; break;
        case Cairo: return "Cairo"; break;
        case Chennai: return "Chennai"; break;
        case Chicago: return "Chicago"; break;
        case Delhi: return "Delhi"; break;
        case Essen: return "Essen"; break;
        case HoChiMinhCity: return "HoChiMinhCity"; break;
        case HongKong: return "HongKong"; break;
        case Istanbul: return "Istanbul"; break;
        case Jakarta: return "Jakarta"; break;
        case Johannesburg: return "Johannesburg"; break;
        case Karachi: return "Karachi"; break;
        case Khartoum: return "Khartoum"; break;
        case Kinshasa: return "Kinshasa"; break;
        case Kolkata: return "Kolkata"; break;
        case Lagos: return "Lagos"; break;
        case Lima: return "Lima"; break;
        case London: return "London"; break;
        case LosAngeles: return "LosAngeles"; break;
        case Madrid: return "Madrid"; break;
        case Manila: return "Manila"; break;
        case MexicoCity: return "MexicoCity"; break;
        case Miami: return "Miami"; break;
        case Milan: return "Milan"; break;
        case Montreal: return "Montreal"; break;
        case Moscow: return "Moscow"; break;
        case Mumbai: return "Mumbai"; break;
        case NewYork: return "NewYork"; break;
        case Osaka: return "Osaka"; break;
        case Paris: return "Paris"; break;
        case Riyadh: return "Riyadh"; break;
        case SanFrancisco: return "SanFrancisco"; break;
        case Santiago: return "Santiago"; break;
        case SaoPaulo: return "SaoPaulo"; break;
        case Seoul: return "Seoul"; break;
        case Shanghai: return "Shanghai"; break;
        case StPetersburg: return "StPetersburg"; break;
        case Sydney: return "Sydney"; break;
        case Taipei: return "Taipei"; break;
        case Tehran: return "Tehran"; break;
        case Tokyo: return "Tokyo"; break;
        case Washington: return "Washington"; break;
        default: return "no city!"; break;
    }
}
}
