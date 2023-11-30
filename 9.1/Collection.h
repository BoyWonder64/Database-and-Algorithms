#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

using namespace std;

template<typename Item>
class Collection {
public:
  Collection();
  Collection(int size);
  Collection(Collection<Item>& a);
  virtual int size();
  virtual Item get(int ndx) const;
  virtual void add(Item e);
  virtual void removeEnd();
  virtual Collection<Item>& operator=(Collection<Item>& a);
  virtual Item& operator[](int ndx);


  virtual Collection<Item>& operator+(Item e){ add(e); return *this;}
  virtual Collection<Item>& operator-(Item e){ for(int i = 0; i < e; i++)removeEnd(); return *this;}
  virtual Collection<Item>& operator<<(Item e);
  friend ostream& operator<<(ostream& out, const Collection& c){
     for (int i = 0; i < c.curSize; i++) {
        out << c.elements[i];
        if(i<c.curSize-1) out << " ";
    }
    return out;
  }
  void swap(int, int);
  void sortByBubble();
  void sortBySelection();
  void sortByInsertion();
  void sortByQuick(){
        quicksort(0, curSize-1);
  }
  void quicksort(int start, int end);
  int partition(int start, int end);
  Item findMinInRange(int start);

protected:
  int capacity;
  int curSize;
  std::unique_ptr<Item[]> elements;
  static const int INITIAL_CAPACITY = 8;
  void expand();

};
template<typename Item>
Collection<Item>::Collection(){
    capacity = INITIAL_CAPACITY;
    curSize = 0;
    elements=make_unique<Item[]>(capacity);
}
template<typename Item>
Collection<Item>::Collection(int size){
    capacity = size;
    curSize = 0;
    elements = make_unique<Item[]>(capacity);
}
template<typename Item>
Collection<Item>::Collection(Collection<Item>& a){
    capacity = a.capacity;
    curSize = a.curSize;
    elements = make_unique<Item[]>(capacity);
    for (int i = 0; i < a.curSize; i++) {
        elements[i] = a.elements[i];
    }
  }

template<typename Item>
int Collection<Item>::size() {
   return curSize;
}
template<typename Item>
Item Collection<Item>::get(int ndx) const {
      return elements[ndx];
}

template<typename Item>
void Collection<Item>::add(Item e) {
    if (curSize == capacity) {
      expand();
    }

    elements[curSize] = e;
    curSize++;
}

template<typename Item>
void Collection<Item>::removeEnd() {
    curSize--;
    if(curSize < 0){
        throw runtime_error("Empty List");
    }
}
template<typename Item>
Item& Collection<Item>::operator[](int ndx) {
    return elements[ndx];
}
template<typename Item>
Collection<Item>&  Collection<Item>::operator=(Collection<Item>& a) {
    auto newElements = std::make_unique<Item[]>(a.capacity);
    for (int i = 0; i < a.curSize; i++){
        newElements[i] = a.elements[i];
    }
    elements = move(newElements);
    capacity = a.capacity;
    curSize = a.curSize;

    return *this;
 }
template<typename Item>
Collection<Item>& Collection<Item>::operator<<(Item e) {
    add(e);
    return *this;
  }
template<typename Item>
void Collection<Item>::expand() {
    auto newElements = std::make_unique<Item[]>(capacity * 2);
    for (int i = 0; i < capacity; i++) newElements[i] = elements[i];
    elements = std::move(newElements);
    capacity *= 2;
}


/***************************************************************
TODO:  Complete the swap method so it takes two positions of the
       elements array and swaps those positions in the array
       Given a list {12, 34, 56, 78} and a call to swap (1, 2)
       would be {12, 56, 34, 78}
***************************************************************/
template<typename Item>
void Collection<Item>:: swap(int first, int second){

    Item temp = elements[first];
    elements[first]  = elements [second];
    elements[second] = temp;

}

/***************************************************************
TODO:  Complete the Bubble Sort
***************************************************************/
template<typename Item>
void Collection<Item>::sortByBubble(){
    for (int i = 0; i < curSize - 1; i++){
        for(int j = 1; j < curSize - i; j++){
            if(elements[j] < elements[j-1]){
                swap(j, j-1);
            }
        }
    }


}


/***************************************************************
TODO:  Complete the Insertion Sort
***************************************************************/
template<typename Item>
void Collection<Item>::sortByInsertion(){
    for(int i = 1; i < curSize; i++){
        for(int j = i; j >= 1 && elements[j] < elements[j-1]; j--){
            swap(j, j-1);
        }
    }
}


/***************************************************************
TODO:  Complete the Partition Method.  Starting at the position
        start and ending in position end, this method will create a
        pivot as the starting position.  It will the pivot to the right
        of every element smaller than it.  For example:
        elements = {99, 99, 5, 2, 6, 3, 7, 4, 90, 91}
        with a call of pivot(2, 7) would give you
        elements {99 99 4 2 3 5 7 6 90 91}
        return the pivot as 5
***************************************************************/
template<typename Item>
int Collection<Item>::partition(int start, int end){
     int pivot = start;
     Item toCompare = elements[start];
     for(int i  = start + 1; i <= end; i++){
         if(elements[i] < toCompare){
             pivot++;
             swap(i, pivot);
         }
     }
     swap(pivot, start);
     return pivot;
}

/***************************************************************
TODO:  Complete the Quick Sort
ALTORITHM: if the start has exceeded the ending position
                return (base case)
           Find a pivot point by and partition the list from that point(call partition)
           Sort the beginning portion of the list up to but not including the pivot (recursive case)
           Sort the ending portion of the list, starting just after the pivot (recursive case)
***************************************************************/
template<typename Item>
void Collection<Item>::quicksort(int start, int end){
    if(start >= end){
        return;
    }

    int pivot = partition(start, end);
    quicksort(start, pivot-1);
    quicksort(pivot + 1, end);
}




/***************************************************************
TODO:  Complete the findMin method starting at position start
        within the list, it finds the position with the smallest
        value.  Note: it does not search the entire list, just from
        position start.  For example given
        elements = {0, 99, 5, 2, 6, 7, 3, 4, 90, 91} a call to
        c.findMinInRange(4);
        would return 6.  As three is the min value and it is located
        at position 6 in the list.
***************************************************************/
template<typename Item>
Item Collection<Item>::findMinInRange(int start){
    Item min = start;

    for(int i = start; i < curSize; i++){
        if(elements[min] > elements[i]){
            min = i;
        }
    }

    return min;
}

/***************************************************************
TODO:  Complete the Selection Sort
*  ALGORITHM:
*       Iterate the entire array using i
*       Find the position of min
        Swap it with the current position i
***************************************************************/
template<typename Item>
void Collection<Item>::sortBySelection() {
    Item min = 0;
    for(int i = 0; i < curSize; i++){
        {
            Item min = findMinInRange(i);
            swap(i,min);
        }
    }
}





