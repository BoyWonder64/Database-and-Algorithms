#pragma once


#include <iostream>
#include <memory>

using std::ostream;
using std::shared_ptr;
using std::make_shared;
using std::runtime_error;

template<class Type>
struct Node {
	Type data;
	//Node<Type> *next;
	shared_ptr <Node<Type> > next;
};


/*
	LinkedListIterator is used for writing the test cases for the merge sort.  Do not remove.
*/
template<typename Type>
class LinkedListIterator {
public:
	LinkedListIterator(shared_ptr<Node <Type> > ptr) : current(ptr) {}
	LinkedListIterator<Type>& operator++() { current = current->next; return *this; }
	Type operator*() { return current->data; }
	bool operator==(const LinkedListIterator<Type>& rhs) const { return current == rhs.current; }
	bool operator!=(const LinkedListIterator<Type>& rhs) const { return current != rhs.current; }
	shared_ptr<Node <Type> > getNode() { return current; }

private:
	shared_ptr < Node<Type> >  current; // shared pointer at current
};


template<class Type>
class LinkedList;

template<class Type>
ostream& operator<< (ostream& out, const LinkedList<Type>& list);


template<class Type>
class LinkedList {
public:
	LinkedList() : front(nullptr), back(nullptr), count(0) {}// Default constructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
	//~LinkedList();           //Destructor for the LinkedList.  Creates an empty list by setting front and back of the list to nulllptr
	void insert(Type data);  //Adds to the back of the list
	Type peek(int ndx)const;//Looks at an element at the given ndx value
	void remove(int ndx);    //Removes an element at the given ndx position
	friend ostream& operator<< <>(ostream& out, const LinkedList<Type>& list);// Returns an output stream for displaying the LinkedList
	

	void mergeSort();
	LinkedListIterator<Type> begin() { return LinkedListIterator<Type>(front); }

	void mergeSort(shared_ptr<Node <Type> > &head);
	shared_ptr<Node <Type> >  getMiddle(shared_ptr<Node <Type> > head);
	shared_ptr<Node <Type> > mergeInOrder(shared_ptr<Node <Type> > a, shared_ptr<Node <Type> > b);


protected:
	shared_ptr <Node<Type> > front;
	shared_ptr <Node<Type> > back;

	int count;//Number of nodes in list
};

template<class Type>
void LinkedList<Type>::insert(Type data) {
	auto temp = make_shared<Node<Type>>();
	temp->data = data;
	temp->next = nullptr;
	if (!front) {
		front = temp;
		back = temp;
	}
	else {
		back->next = temp;
		back = temp;
	}
	count++;
}
template<class Type>
Type LinkedList<Type>::peek(int ndx)const {
	if (ndx >= count || ndx < 0) {
		throw runtime_error("Out of range");
	}

	int currNodeNum = 0;
	auto currentNode = front;

	while (currNodeNum < ndx) {
		currNodeNum++;
		currentNode = currentNode->next;
	}
	return currentNode->data;
}

template<class Type>
void  LinkedList<Type>::remove(int ndx) {
	if (ndx >= count || ndx < 0) {
		throw runtime_error("Out of range");
	}

	//If removing the front
	if (ndx == 0) {
		auto toDelete = front;
		front = toDelete->next;
		//delete toDelete;
		return;
	}//end if
	int currNodeNum = 0;
	auto currentNode = front;

	while (currNodeNum < ndx - 1) {
		currNodeNum++;
		currentNode = currentNode->next;
	}
	auto toDelete = currentNode->next;
	//Deleting from middle
	if (toDelete->next) {
		currentNode->next = toDelete->next;
	}
	//Delete last node
	else {
		currentNode->next = nullptr;
		back = currentNode;
	}
	count--;
	//delete toDelete;
}//end remove

template<class Type>
ostream& operator<< (ostream& out, const LinkedList<Type>& list) {
	auto curr = list.front;

	while (curr) {
		out << curr->data;
		if (curr->next) {
			out << " ";
		}
		curr = curr->next;
	}
	return out;
}





template<class Type>
void  LinkedList<Type>::mergeSort() {
	mergeSort(front);
}

/*************************************************************************
*  TODO:  Complete the mergeSort(head) method.  This method should return
*           a sorted version of the list using the merge sort. For example...
*           head = { 5, 3, 1, 2, 4} will return
*           head should be {1, 2, 3, 4, 5 }
*  HINT:
*       You will use the getMiddle() and mergeInOrder() methods in this sort, so 
*       code them first
*
*  ALGORITHM:
*       If there is 0 or 1 node in the list,
*           exit the method (return;)
*       Find the middle Node (mid)
*       let left = the head pointer of the first partition (the head)
*       let right = the head pointer of the second half of the list (to the right of mid)
*       Split the list by setting the mid->next to null
*
*       Sort the left side (hint, use recursion)
*       Sort the right side (hint, more recursion)
*       set the head to be the list merged in order
*************************************************************************/
template<class Type>
void  LinkedList<Type>::mergeSort(shared_ptr<Node <Type> > &head) {
    auto mid = getMiddle(head);
    auto left = head;
    auto right = mid->next;

      if (head == nullptr || head->next == nullptr) {
          return;
      }
      mid->next = nullptr;
      mergeSort(left);
      mergeSort(right);

      head = mergeInOrder(left, right);


} // end of MergeSort

/*************************************************************************
*  TODO:  Complete the getMiddle(head) method.  It should return the middle Node
*          in the linked list.  If there is not an exact middle, it should return
*          the value to the left of the middle point
*          {1, 2, 3, 4, 5}:  3 would be the middle
*          {1, 2, 3, 4}:  Should return 2
*************************************************************************/
template<class Type>
shared_ptr<Node <Type> > LinkedList<Type>::getMiddle(shared_ptr<Node <Type> > head) {

    auto fastPtr  = head;
    auto slwPtr  = head;

    while(fastPtr->next != nullptr && fastPtr->next != nullptr){
        if(fastPtr->next->next == nullptr){
            return slwPtr;
        } else {
            fastPtr = fastPtr->next->next;
            slwPtr = slwPtr->next;
        }

    }

    return slwPtr;

}

/*************************************************************************
*  TODO:  Complete the mergeInOrder(a, b) method.  Given two node heads, a and b
*         This method should return the head node of the two lists combined in
*         The correct order.  For example
*         a = { 1, 3, 5, 7 }
*         b = { 2, 4, 6, 8}
*         c should be returned as { 1, 2, 3, 4, 5, 6, 7, 8}
* Algorithm:
*       If a is null, return b
*       IF b is null, return a
*
*       Create a head pointer for the new list set to nullptr
*       If the data in a is less than the data in b
*           set the head pointer to a
*           set the next of the head pointer to the list merged in order with a->next as the first list and b as the second list
*       Else
*           set the head pointer to b
*           set the next of the head pointer to the list merged in order with a as the first list and b->next as the second list
*************************************************************************/
//perform first
template<class Type>
shared_ptr<Node <Type> > LinkedList<Type>::mergeInOrder(shared_ptr<Node <Type> > a, shared_ptr<Node <Type> > b) {

    shared_ptr<Node <Type> > head = nullptr;
    if(a == nullptr){
        return b;
    }

    if(b == nullptr){
        return a;
    }


    if(a->data < b->data){
        head = a;
        head->next = mergeInOrder(a->next, b);
    } else {
            head = b;
            head->next = mergeInOrder(a,b->next);
        }

    return head;

}

