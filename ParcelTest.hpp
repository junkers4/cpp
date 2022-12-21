#ifndef cpp_tst_priklad2_h
#define cpp_tst_priklad2_h

#include "TestSuite/Test.h"
#include "Parcel.hpp"

// 4 body
class ParcelTest:public TestSuite::Test{
private:
    
    // 2 body
    /// Otestujte vytvoreni baliku pri zadani spravnych parametru. Otestujte nevyhozeni vyjimky.
    void testCreateParcel() {
        
        try{
            Parcel newParcel("1234-12344-1233",22);
            succeed_();
        }catch(...){
            fail_("mistake");
        }
     

        
    }
    
    // 2 body
    /// Otestujte vyhozeni vyjimky pri zadani nespravnych parametru.
    void testCreateParcelWithInvalidNumber() {
        try{
            Parcel newParcel("123444-12344-1233",22);
            fail_("mistake");
        }catch(...){
            succeed_();
        }
     
    }
    
public:
    void run(){
        testCreateParcel();
        testCreateParcelWithInvalidNumber();
    }
};
#endif
