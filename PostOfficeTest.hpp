#ifndef cpp_tst_priklad1_h
#define cpp_tst_priklad1_h

#include "TestSuite/Test.h"
#include "PostOffice.hpp"

// 10 bodu
class PostOfficeTest:public TestSuite::Test{
public:
    // 4 body
    /// Pripravte si nekolik baliku s ruznymi cisly.
    /// Kriticky otestujte, zda metoda vrati spravne baliky.
    void testGetParcelsWithSuffix(){
        Parcel newParcel("1234-1234-1234",2);
        Parcel newParcel1("1234-1234-2222",3);
        Parcel newParcel2("1234-1234-3333",55);
        
        PostOffice newOffice;
        newOffice.insertParcel(newParcel);
        newOffice.insertParcel(newParcel1);
        
        std::vector<Parcel> parcelik= newOffice.getParcelsWithSuffix("1234");
   
        test_(parcelik.at(0).getWeight() == 2);
        test_(parcelik.at(0).getWeight() == 3);
        //fail
    }
    
    // 3 body
    /// Pripravte si nekolik baliku s ruznymi vahami.
    /// Kriticky otestujte, zda metoda vrati spravnou celkovou vahu
    void testGetTotalWeight(){
        Parcel newParcel1("1234-1234-2222",3);
        Parcel newParcel2("1234-1234-3333",55);
        
        PostOffice newOffice;
        
        newOffice.insertParcel(newParcel1);
        newOffice.insertParcel(newParcel2);
        
        auto it=newOffice.getTotalWeight();
        test_(it==58);
        
        test_(it==58.0);
        //fail
        test_(it==-58);
        
        
    }
    
    // 3 body
    /// Pripravte si nekolik baliku s ruznymi cisly.
    /// Kriticky otestujte, zda metoda vrati vahu spravneho baliku.
    ///  Vyjimku zde netestujte.
    void testGetWeightByNumber(){
        Parcel newParcel1("1234-1234-2222",3);
        Parcel newParcel2("1234-1234-3333",55);
        Parcel newParcel3("1234-1234-3311",50);
        Parcel newParcel4("1234-1234-3388",54);
        
        PostOffice newOffice;
        
        newOffice.insertParcel(newParcel1);
        newOffice.insertParcel(newParcel2);
        newOffice.insertParcel(newParcel3);
        newOffice.insertParcel(newParcel4);
        
        
        float l= newOffice.getWeightByNumber("1234-1234-3311");
        
        test_(l==50);
        
        //fail
        test_(l==40);
    }
    
    void run(){
        testGetParcelsWithSuffix();
        testGetTotalWeight();
        testGetWeightByNumber();
    }
};

#endif
