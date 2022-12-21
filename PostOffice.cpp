#include "PostOffice.hpp"


PostOffice::PostOffice(){
    m_parcels=std::vector<Parcel>();
}

void PostOffice::insertParcel(Parcel parcel){
    m_parcels.push_back(parcel);
}

// 7 bodu
/// Zapiste do textoveho souboru parcels.txt cisla vsech baliku, ktere maji vahu vetsi nez je zadany parametr.
/// Osetrete neexistujici soubor a vypiste info uzivateli.
/// Soubor obsahuje data ve formatu:
/// cislo1,cislo2,cislo3
void PostOffice::saveParcelNumbersWithWeightOver(const float weight){
    std::vector<Parcel> parcelsoverWeight;
    for(int i=0;i<m_parcels.size();i++){
        if(m_parcels.at(i).getWeight()>weight){
            parcelsoverWeight.push_back(m_parcels.at(i));
        }
    }
    
    std::ofstream out("parcels.txt",std::ios::out);
    
    if(out.is_open()){
        // while(out){
        for(int k=0;k<parcelsoverWeight.size();k++){
            std::string input=parcelsoverWeight.at(k).getNumber();
        
            out << input << ",";
        }
        out.close();
    }
    else{
        std::cerr << "Couldn't open file" << std::endl;
    }
}


// 6 bodu
/// Vrati baliky, jejichz posledni skupina v cisle (sekvence znaku za posledni pomlckou) odpovida suffixu.
/// Pouzije STL algoritmus a lambda vyraz.
std::vector<Parcel> PostOffice::getParcelsWithSuffix(const std::string suffix) const{
    std::vector<Parcel> suffixedParcels;

    std::for_each(m_parcels.begin(), m_parcels.end(),[&suffix,&suffixedParcels](Parcel parcelPom){
        std::size_t foundLast = parcelPom.getNumber().find_last_of("-");
        std::size_t size=parcelPom.getNumber().size();
        std::string gettingString= parcelPom.getNumber();
        std::string compareString= gettingString.substr(foundLast+1,size);
        if(compareString==suffix){
            suffixedParcels.push_back(parcelPom);
        }
    });
    return suffixedParcels;
}



// 4 bodu
/// Vratte celkovou vahu vsech baliku.
/// Pouzije STL algoritmus a lambda vyraz.
float PostOffice::getTotalWeight()const{
    float total=0.0;
std::for_each(m_parcels.begin(), m_parcels.end(),[&total](Parcel parcelPom){
    total+=parcelPom.getWeight();
});
    return total;
}


// 6 body
/// Vraťte std::map, kde klicem bude posledni cast cisla baliku (sekvence znaku za posledni pomlckou) a hodnotou bude balik.
std::map<std::string, Parcel> PostOffice::getParcelsMap() const{
    std::map<std::string,Parcel> parcelsMap;
    std::for_each(m_parcels.begin(), m_parcels.end(),[&parcelsMap](Parcel parcelPom){
    std::size_t foundLast = parcelPom.getNumber().find_last_of("-");
    std::size_t size=parcelPom.getNumber().size();
    std::string gettingString= parcelPom.getNumber();
    std::string compareString= gettingString.substr(foundLast+1,size);
        std::pair<std::string, Parcel> input{compareString,parcelPom};
        parcelsMap.insert(input);
    });
    return parcelsMap;
}


// 5 bodu
/// Vratte vahu baliku, jehoz ID odpovida parametru.
/// Pouzije STL algoritmus a lambda vyraz.
/// Pokud ID neexistuje, vyhodte vyjimku.
float PostOffice::getWeightByNumber(const std::string number) const{
    float weight=0.0;
    auto it= std::find_if(m_parcels.begin(),m_parcels.end(),[&weight,&number](Parcel parcelPom)->float{
        if(parcelPom.getNumber()==number){
            weight=parcelPom.getWeight();
            return weight;
        }else{
            return weight;
        }
    });
    
    if(it!=m_parcels.end()){
        return weight;
    }else{
        throw std::out_of_range("Invalid number of Parcel");
    }

    

}
