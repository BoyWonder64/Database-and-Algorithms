#pragma once
#include <memory>

//using namespace std;    //Catch all <---
using std::ostream;
using std::shared_ptr;
using std::make_shared;
using std::runtime_error;
using namespace std;
template<class Type>
struct Node {
    Type data;
    //Node <Type> *next;    <--- raw pointer
    shared_ptr <Node<Type> > next;
};

template<class Type>
class LinkedList;

template<class Type>
ostream& operator<< (std::ostream& out, const LinkedList<Type>& list);



template<class Type>
class LinkedList{
    public:
        LinkedList(): front(nullptr), back(nullptr), count(0) {}// Default constructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
        //~LinkedList();           //Destructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
        void insert(Type data);  //Adds to the back of the list
        Type peek(int ndx)const;//Looks at an element at the given ndx value
        void remove(int ndx);    //Removes an element at the given ndx position
        friend ostream& operator<< <>(std::ostream& out, const LinkedList<Type>& list);// Returns an output stream for displaying the LinkedList

        void pointerPractice(Type, Type);

protected:
        int count; //Number of nodes in list
        //Node <Type> *front;    <--- raw pointer
        //Node <Type> *back;    <--- raw pointer
        shared_ptr <Node<Type> > front;
        shared_ptr <Node<Type> > back;

};

template<class Type>
void LinkedList <Type>::insert(Type data){
    //auto temp = new Node <Type>();
    auto temp = make_shared<Node<Type>> ();
    temp->data = data;
    temp->next = nullptr;
    if(!front){
        front = temp;
        back = temp;
    } else {
        back->next = temp;
        back = temp;
    }
    count++;
}

template<class Type>
Type LinkedList<Type>::peek(int ndx)const{
    if(ndx >= count || ndx < 0){
        throw runtime_error("Out or range");
    }

    int currNodeNum = 0;
    auto currentNode = front;

    while(currNodeNum < ndx){
        currNodeNum++;
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

template<class Type>
void LinkedList<Type>::remove(int ndx){
    if(ndx >= count || ndx < 0){
        throw runtime_error("Out or range");
    }
    //If removing the front
    if(ndx == 0){
        auto toDelete = front;
        front = toDelete->next;
        return;
    }//End if

    int currNodeNum = 0;
    auto currentNode = front;

    while(currNodeNum < ndx-1){//Modify the node that is right before the ending
        currNodeNum++;
        currentNode = currentNode->next;
    }
    auto toDelete = currentNode->next;
    //Deleting from the middle
    if(toDelete->next){
        currentNode->next = toDelete->next;

    } // Delete last node
        else {
            currentNode->next = nullptr;
            back = currentNode;
    }
        count--;
} //end remove


template<class Type>
void LinkedList<Type>::pointerPractice(Type toInsert, Type toRemove)
{
    auto newNode = make_shared< Node<Type>>();
    auto tempNode = make_shared< Node<Type>>();
    newNode->data = toInsert; //4
    tempNode->data = 6; //18


    auto curr = front; //set pointer to front

    while(curr->next->data < 4 && curr != nullptr){ //
//        cout << curr->data;
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;

    while(curr->next->data < 6 && curr != nullptr){
        curr = curr->next;
    }
    curr->next = tempNode->next;
    curr->next = tempNode;

}


template<class Type>
ostream& operator<< (std::ostream& out, const LinkedList<Type>& list){ //list is just parameter
    auto curr = list.front;

    while(curr){
        out << curr->data;
        if(curr->next){
            out << " ";
        }
        curr = curr->next;
    }
    return out;
}//end ostream