#include "Collection.h"

using namespace std;

template<typename Item>
class SortedCollection;

//1)
// Create an additional overload operator for the + operator.  This time we will use it to add and Item to the
// Collection class (and thus SortedCollection class). When implementing the operator, you are welcome to call the add
// method that has already been coded.

//2)
// Create an additional overload operator for the << operator. This time we will use it to add and Item to the
// Collection class (and thus SortedCollection class).  This will NOT be a friend function.
// Watch out, there will be different parameters than the operater<< used to display the object.
// When implementing the operator, you are welcome to call the add method that has already been coded.

//3)
// Overload the three constructors such that you can make a call to SortedCollection using no parameters,
// a single int parameter to specify the max size, and with a parameter of another SortedCollection
// to start with a given collection.


template<typename Item>
class SortedCollection: public Collection<Item>{
    public:
      SortedCollection(): Collection<Item>(){}
      SortedCollection(int size): Collection<Item>(size){}
      SortedCollection(SortedCollection<Item>& a):Collection<Item>(a){}
      void add(Item);

      SortedCollection<Item>& operator+(Item num); //why are we using virtual
      SortedCollection<Item>& operator<<(Item num);
};

template<typename Item>
void SortedCollection<Item> ::add(Item num) {
    Collection<Item>::add(num);
    // for(int i = ; i > curSize; i++){

    //}

    //start at the end of the list
    //FOR LOOP
    //Temp value used
    //ADD ADDITIONAL CODE INTO ENDING VALUE

}

template<typename Item>
 SortedCollection<Item>& SortedCollection<Item> ::operator+(Item num){
    add(num);
    return (*this);
}//end of Operator+

template<typename Item>
SortedCollection<Item>& SortedCollection<Item>::operator<<(Item num){
    add(num);
    return(*this);
}//end of Operator <<
