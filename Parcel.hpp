#ifndef Parcel_hpp
#define Parcel_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <regex>
// 8 bodu
class Parcel {
private:
    /// Cislo baliku
    std::string m_number;
    
    /// Váha baliku
    float m_weight;
    
    // 6 bodu
    /// Pomoci regularu overte spravny format cisla baliku.
    /// Format je podle vzoru 1A3F-23FD4-0001
    /// Format ma tri skupiny povinne oddelene pomlckou.
    /// V kazde skupine muze byt 4 az 5 cislic nebo pismen.
    /// V posledni skupine mohou byt pouze cislice.
    std::string validateNumber(const std::string number) const;
    
public:
    
    std::string getNumber()const;
    float getWeight()const;
    
    // 2 body
    /// V konstruktoru vyuzijte metodu validateNumber().
    /// Pokud je format cisla neplatny, vyhodte vyjimku.
    Parcel(const std::string name, const float weight);
    
};

#endif /* Parcel_hpp */
