#include <iostream>
#include "SortedCollection.h"
using namespace std;

void TestSortedCollection();
void TestSortedCollectionConstructors();
void TestAddToOperatorCollection();
void TestRemoveCollection();
bool checkCase(string name, bool condition);

int main()
{
    TestSortedCollection();
    TestSortedCollectionConstructors();
    TestAddToOperatorCollection();
    TestRemoveCollection();
    return 0;
}
void TestSortedCollection(){
    SortedCollection<int>one;
     one << 19 << 9 << 2 << 8 << 7 << 12
      << 17 << 0 << 11 << 6 << 3 << 1;
    checkCase("In Order 1", one[0] == 0);
    checkCase("In Order 2", one[11] == 19);
    checkCase("Check Size", (one << 13).size()== 13);
}
void TestSortedCollectionConstructors(){
    SortedCollection<double>one(10);
    for(double i = 0.0; i < 5; i+=.5){
        one << i;
    }
    SortedCollection<double>two(one);
    checkCase("Constructor Test", two[0] == 0);

}

void TestAddToOperatorCollection(){
    SortedCollection<int> one;
    one + 19 + 9 + 2 + 8 + 7 + 12  + 17 + 0 + 11 + 6 + 3 + 1;
    checkCase("Add In Order 1", one[0] == 0);
    checkCase("Add In Order 2", one[11] == 19);
    checkCase("Add Check Size", (one << 13).size()== 13);
}
void TestRemoveCollection(){
    SortedCollection<int> one;
    one + 19 + 9 + 2 + 8 ;

    checkCase("Original Size", one.size() == 4);
    one -2;
    checkCase("Remove 2 Size", one.size() == 2);
    checkCase("Still In Order", one[1] == 8);
    bool exception_caught = true;
    try{
       one - 3;
       exception_caught = false;
    }
    catch (exception& a){
        exception_caught = true;
    }
    checkCase("Exception Caught", exception_caught);
}
bool checkCase(string name, bool condition){
    if(!condition){
            cout << "Failed: " << name << endl;
    }
    else{
            cout << name << ": passed" << endl;
    }
    return condition;
}
