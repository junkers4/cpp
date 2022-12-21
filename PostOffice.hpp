#ifndef PostOffice_hpp
#define PostOffice_hpp

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <map>
#include <algorithm>
#include "Parcel.hpp"

// 28 bodu
class PostOffice {
private:
    /// Struktura ukladajici baliky ulozene na poste.
    std::vector<Parcel> m_parcels;
    
public:
    
    void insertParcel(Parcel parcel);
    
    PostOffice();
    // 7 bodu
    /// Zapiste do textoveho souboru parcels.txt cisla vsech baliku, ktere maji vahu vetsi nez je zadany parametr.
    /// Osetrete neexistujici soubor a vypiste info uzivateli.
    /// Soubor obsahuje data ve formatu:
    /// cislo1,cislo2,cislo3
    void saveParcelNumbersWithWeightOver(const float weight);
    
    // 6 bodu
    /// Vrati baliky, jejichz posledni skupina v cisle (sekvence znaku za posledni pomlckou) odpovida suffixu.
    /// Pouzije STL algoritmus a lambda vyraz.
    std::vector<Parcel> getParcelsWithSuffix(const std::string suffix) const;
    
    // 4 bodu
    /// Vratte celkovou vahu vsech baliku.
    /// Pouzije STL algoritmus a lambda vyraz.
    float getTotalWeight() const;
    
    // 6 body
    /// Vraťte std::map, kde klicem bude posledni cast cisla baliku (sekvence znaku za posledni pomlckou) a hodnotou bude balik.
    std::map<std::string, Parcel> getParcelsMap() const;
    
    // 5 bodu
    /// Vratte vahu baliku, jehoz ID odpovida parametru.
    /// Pouzije STL algoritmus a lambda vyraz.
    /// Pokud ID neexistuje, vyhodte vyjimku.
    float getWeightByNumber(const std::string number) const;
    
};

#endif /* PostOffice_hpp */
