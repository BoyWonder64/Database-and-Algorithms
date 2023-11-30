#pragma once
#include <iostream>
#include <sstream>
#include <memory>
#include "LinkedList.h"


using std::ostream;
using std::shared_ptr;
using std::make_shared;
using std::runtime_error;

using namespace std;

template<class Type>
class FifthElement;


template<class Type>
class FifthElement: public LinkedList<Type> {
public:
    Type getFifthElement();
    void insertNewFifthElement(const Type&value);
    void deleteFifthElement();
    void swapFourthAndFifthElement();

};


//This method returns the data at the fifth node (not index) of the linked list. It will throw a runtime_error.
// (just like in peek()) if there is no fifth element in the list

template<class Type>
Type FifthElement <Type>::getFifthElement(){

    auto curr = this->front;//set curr to the front of the linked list
    auto backOfNode = this->back;

    int currentNodeNum = 0;

    while(curr->next != backOfNode){
        curr = curr->next;
        currentNodeNum++;

        if(currentNodeNum == 3){
            return curr->next->data;
        }

    }//end of while

        throw runtime_error("Out or range");

}

template<class Type>
void FifthElement<Type>::insertNewFifthElement(const Type &value) {
    auto curr = this->front;//set curr to the front of the linked list
    auto backOfNode = this->back;

    int currentNodeNum = 0;

    auto newNode = make_shared< Node<Type>>();
    newNode->data = value;

    while(curr->next && currentNodeNum < 3){ //
        curr = curr->next;
        currentNodeNum++;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}



template<class Type>
void FifthElement <Type>::deleteFifthElement(){


    auto curr= this->front;
    int currentNodeNum = 0;

    while(curr->next && currentNodeNum < 3){ //
        curr = curr->next;
        currentNodeNum++;
        auto fifth = curr->next;
        if(currentNodeNum == 3){
            curr->next = fifth->next;
        }
    }


}//end of insertNewFifth


template<class Type>
void FifthElement <Type>::swapFourthAndFifthElement(){

    auto curr= this->front;
    auto third = this->front->next->next;
    auto forth = this->front->next->next->next;
    auto fifth = this->front->next->next->next->next;
    auto sixth = this->front->next->next->next->next->next;
    int currentNodeNum = 0;

    while(curr->next && currentNodeNum < 3){
        curr = curr->next;
        currentNodeNum++;

        third->next = fifth;
        forth->next = sixth;
        fifth->next = forth;


    }//end of while

    //3 point to 5
    //4 point to 6
    //what used to be 5th is what used to be the 4th


}//end of insertNewFifth