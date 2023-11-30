#include <iostream>
#include <string>
#include <queue>
#include <memory>

using std::shared_ptr;
using std::ostream;
using std::make_shared;
using std::runtime_error;

template<class Type>
struct Node{
    Node(Type data): data(data), next(nullptr){}
    Type data;
    //Node<Type>*next;
    shared_ptr<Node<Type>> next;
};

template<class Type>
class Queue;

template<class Type>
ostream &operator<<(ostream &out, const Queue<Type> &q);



template<class Type>
class Queue {
public:
    Queue(); //Constructor to create an empty queue
    Queue(const Queue<Type>&q); // Copy constructor to create a deep copy of the queue
    Queue<Type> & operator=(const Queue<Type>&q); // Allows the user to create a deep copy of the queue
    void enqueue(Type data); // Inserts data at the back of the queue
    Type peek(int i); // Looks at the value at the front of the queue
    void dequeue(); // removes the front of the queue.
    bool isEmpty(); // returns true if the queue is empty
    void clear(); // empties everything out of the queue
    friend ostream& operator << <>(ostream& out, const Queue<Type> &q); // returns a stream containing all the items in the Queue
private:
    shared_ptr<Node<Type>> top;
    shared_ptr<Node<Type>> back;
    int count;
};

template <class Type>
Queue<Type>::Queue() {
    top = nullptr;
    back = nullptr;
    count = 0;
}

//Queue Copy Constructor
template <class Type>
Queue<Type>::Queue(const Queue<Type> &q) {

    auto curr = q.top;
    count = 0;
    shared_ptr<Node<Type>> currList;
    for (int i = 0; i < q.count; i++) {


        if(count == 0){
            top = make_shared<Node<Type>>(curr->data); //
            currList = top;

        } else {
            currList->next = make_shared<Node<Type>>(curr->data);
            currList = currList->next;
        }
        curr = curr->next;
        count++;
        } //end of for
    back = currList;
    }


//enqueue
template <class Type>
void Queue<Type>:: enqueue(Type data){
    auto temp = make_shared<Node<Type>>(data);
    if(count == 0){
        top = temp;
        back = temp;
    } else {
        back->next = temp;
    }
    back = temp;
    count++;
}

//peek
template <class Type>
Type Queue<Type>::peek(int i) {
    if(top == nullptr || count == 0){
        throw runtime_error("Empty Queue from peek!");
    }
    return top->data;
}

//dequeue
template <class Type>
void Queue<Type>:: dequeue(){
    if(top == nullptr){
        throw runtime_error("Empty Queue from Dequeue");
    }
    top = top->next;
    count --;
}

//isEmpty
template <class Type>
bool Queue<Type>::isEmpty() {
    if(count == 0){
        return true;
    } else {
        return false;
    }
}

//clear
template <class Type>
void Queue<Type>::clear() {
    top = nullptr;
    back = nullptr;
    count = 0;
}

//overloaded operator
template <class Type>
Queue<Type> & Queue<Type>::operator=(const Queue<Type>&q) {
    clear();
    auto curr = q.top;
    top = make_shared<Node<Type>>(curr->data);
    back = make_shared<Node<Type>>(curr->data);
    count = 0;

    for(int i = 0; i < q.count; i++){
        auto currList = make_shared<Node<Type>>(curr->data);

        if(top == nullptr){
            top = curr;
        } else {
            back = curr;
        }

        if(i == q.count-1){
            back = curr;
        }
        curr = curr->next;
        count++;
    }



    return *this;
}


template <class Type>
ostream& operator<<(ostream& out, const Queue<Type>& q)
{
    auto temp = q.top;
    while (temp) {
        out << temp->data;
        if (temp->next) out << " ";
        temp = temp->next;
    }
    return out;
}
