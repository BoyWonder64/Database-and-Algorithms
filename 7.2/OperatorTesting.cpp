#include <iostream>
#include "Person.h"


using namespace std;


int main() {
    Person bt("Bart", 10);
    Person hm("Homer", 42);
    Person mg("Marge", 42);
    Person ls("Lisa", 9);
    Person ma("Maggie", 1);


    //Comparing using >
    if (hm > bt) {
        cout << "--- >: ---" << endl;
        cout << "Older: " << hm << endl;
        cout << "Younger: " << bt << endl;
    }
    //Comparing using ==
    if(hm == mg){
        cout << "---Same Age: ---" << endl;
        cout << hm << endl;
        cout << mg << endl;
    }
    //Comparing using >=
    if(hm >= bt){
        cout << "---Same Age or >= : ---" << endl;
        cout << "Older " << hm << endl;
        cout << "Younger "<< bt << endl;
    }
    //Comparing using <
    if(ma < hm){
        cout << "--- < : ---" << endl;
        cout << "Older: " << hm << endl;
        cout << "Younger: " << ma << endl;

    }
    //Comparing using <=
    if(hm <= mg){
        cout << " --- <= : --- " << endl;
        cout << hm << endl;
        cout << mg << endl;
    }
    //Comparing using !=
    if(hm != bt){
        cout << "--- != ---" << endl;
        cout << hm << endl;
        cout << bt << endl;
    }

    if (bt < 21) {
        cout << bt << "  too young for Moes" << endl;
    }

    if (hm > 21) {
        cout << hm << "  just right for Moes" << endl;
    }

    if (hm != 21) {
        cout << hm << "  Is not young(21) anymore" << endl;
    }

    if (mg >= 21) {
        cout << mg << "Is older than 21"<< endl;
    }

    if (ls <= 50) {
        cout << ls << "  less than or equal to 50 " << endl;
    }

    if (ls == 9) {
        cout << ls << " Lisa is 9 "<< endl;
    }

    if (21 > bt) {
        cout << bt << " less than 21" << endl;
    }


}

