#include "Parcel.hpp"

// 2 body
/// V konstruktoru vyuzijte metodu validateNumber().
/// Pokud je format cisla neplatny, vyhodte vyjimku.
Parcel::Parcel(const std::string name, const float weight){
    if (validateNumber(name)!=name){
        throw std::invalid_argument("Invalid number of Parcel");
    }else{
        m_number=name;
        m_weight=weight;
    }
}


float Parcel::getWeight() const{
    return m_weight;
}

std::string Parcel::getNumber()const{
    return m_number;
}

// 6 bodu
/// Pomoci regularu overte spravny format cisla baliku.
/// Format je podle vzoru 1A3F-23FD4-0001
/// Format ma tri skupiny povinne oddelene pomlckou.
/// V kazde skupine muze byt 4 az 5 cislic nebo pismen.
/// V posledni skupine mohou byt pouze cislice.
std::string Parcel::validateNumber(const std::string number)const {
    std::string result;
    std::regex format("([a-zA-Z0-9]{1,5})-([a-zA-Z0-9]{1,5})-([0-9]{1,5})");
    //alebo proste [:alnum:]
    if(std::regex_match(number, format)) {
        result = number;
    }else{
        result="";
    }
    return result;
}
