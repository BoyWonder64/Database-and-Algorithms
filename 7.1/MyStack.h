#include <iostream>
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
class MyStack;

template<class Type>
ostream &operator<<(ostream &out, const MyStack<Type> &q);

template <class Type>
class MyStack
{
public:
	MyStack();					//Constructor
	MyStack(const MyStack &);	//Copy Constructor
	//~Queue();					//Destructor if using raw pointers
	void push(Type item);		//Adds an item 
	void pop();					//Removes an item 
	Type peek();				//Returns the top value
	int size();					//Returns the size
	bool isEmpty();				//Returns true if empty
	void clear();				//Erases all the items
	MyStack<Type>& operator=(const MyStack<Type>& other);	//Deep copy
	friend ostream &operator<< <>(ostream &out, const MyStack<Type> &q);  //Displays all the items

private:
    //Node<Type>*top;
    shared_ptr<Node<Type>> top;
    int cnt;

};
template <class Type>
MyStack<Type>::MyStack() {
    top = nullptr;
    cnt = 0;
}
template <class Type>
MyStack<Type>::MyStack(const MyStack<Type> &other) {
	cnt = 0;
    auto temp = other.front;
    top = make_shared<Node<Type>>(temp->data);
    cnt++;
    auto curr = top;
	for(int i = 0; i < other.cnt; i++){
        auto newPtr = make_shared<Node<Type>>(temp->data);
        curr->next = newPtr;
        curr = curr->next;
        temp = temp->next;
        cnt++;
    }
}



template <class Type>
void MyStack<Type>::push(Type item) {
    auto temp = make_shared<Node<Type>>(item);

    if(cnt == 0){
        top = temp;
    } else {
        temp->next = top;
        top = temp;
    }
    cnt++;
}

template <class Type>
Type MyStack<Type>::peek() {

    if(top == nullptr || cnt == 0){
        throw runtime_error("Empty Stack");
    }
    return top->data;
}

template <class Type>
int MyStack<Type>::size() {
	return cnt;
}
template <class Type>
bool MyStack<Type>::isEmpty() {
	return cnt == 0;
}

template <class Type>
void MyStack<Type>::clear() {
    top = nullptr;
    cnt = 0;
}

template <class Type>
void MyStack<Type>::pop() {
    if(top == nullptr){
        throw runtime_error("Empty Stack");
    }
    top = top->next;
    cnt--;

}

template <class Type>
MyStack<Type>& MyStack<Type>::operator=(const MyStack& other) {
    clear();

    cnt = 0;
    auto temp = other.front;
    top = make_shared<Node<Type>>(temp->data);
    cnt++;
    auto curr = top;
    for(int i = 0; i < other.cnt; i++){
        auto newPtr = make_shared<Node<Type>>(temp->data);
        curr->next = newPtr;
        curr = curr->next;
        temp = temp->next;
        cnt++;
    }


	return *this;
}

template <class Type>
ostream& operator<<(ostream& out, const MyStack<Type>& q)
{
	auto temp = q.top;
	while (temp) {
		out << temp->data;
		if (temp->next) out << " ";
		temp = temp->next;
	}
	return out;
}
