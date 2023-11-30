#include "LinkedList.h"


using namespace std;
int main() {
    //List 1
    LinkedList<int> one;
    one.insert(1);


    //List 2
    LinkedList<int> two = one;
    two.insert(42);


    //Operator Equals Test
    two = one;
    two.insert(60);


    //Display both Lists
    cout << one << endl;
    cout << two << endl;


}
