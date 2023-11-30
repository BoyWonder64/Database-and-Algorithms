#pragma once
#include <iostream>
#include <memory>
#include <cmath>

using namespace std;

template<class Type>
struct Bucket { //Each item has its own container
	Type data;
	bool empty = true;
    //struct allows me to know if the bucket is empty or full
};

template<class Type>
class Hashtable;

template<class Type>
ostream& operator<< (ostream &, Hashtable<Type>&);


template<class Type>
class Hashtable
{
public:
	Hashtable();
    Hashtable(int cap); //Constructs an empty hash table with the given capacity and a default load factor threshold of .65
    Hashtable(int, double); //Constructs an empty hash table with the given capacity and load factor threshold values
	Hashtable(const Hashtable<Type>& other);
	Hashtable& operator=(const Hashtable<Type>& other);
	int getSize() const; //access the size (how many it can hold)
	int getCapacity() const; //access the capacity (how many are in there)
    double getLoadFactorThreshold() const; //returns the load factor threshold
	bool empty() const; //is it empty?
	void insert(const Type); //add to bucket

    void rehash(); //Resize the table

    static bool isPrime(int); //Determines if number is prime
    static int nextPrime(int); //Takes an int value and returns the next prime number.
	void remove(int); //remove from bucket
	bool contains(int) const; //verify if it holds a specific value

    int indexOf(int) const; //Returns the index of a given value

	void clear(); //empty the bucket
	friend ostream& operator<< <>(ostream &, Hashtable<Type>&);

private:
	int hash(Type v) const; //private function
	int capacity;
	int size;
    unique_ptr<Bucket<Type> []> htable;
    double loadFactorThreashold;
};



template<class Type>
Hashtable<Type>::Hashtable()
{
	size = 0;
	capacity = 17; //default capacity
	htable = make_unique<Bucket<Type>[]>(capacity); //places the capacity
    loadFactorThreashold = .65; //default load threshold
}


template<class Type>
Hashtable<Type>::Hashtable(int capacity) : capacity(capacity)
{
	size = 0;
	htable = make_unique<Bucket<Type>[]>(capacity);
    loadFactorThreashold = .65;
}

template<class Type>
Hashtable<Type>::Hashtable(int capacity, double loadFactorThreashold) : capacity(capacity), loadFactorThreashold(loadFactorThreashold)
{
    size = 0;
    htable = make_unique<Bucket<Type>[]>(capacity);
}


template<class Type>
Hashtable<Type>::Hashtable(const Hashtable<Type>& other)
{
    capacity = other.capacity;
    size = other.size;
    htable = make_unique<Bucket<Type>[]>(capacity);
    for(int i = 0; i < capacity; i++){
        htable[i] = other.htable[i];
    }
}


template<class Type>
Hashtable<Type>& Hashtable<Type>::operator=(const Hashtable<Type>& other)
{
    capacity = other.capacity;
    size = other.size;
    htable = make_unique<Bucket<Type>[]>(capacity);
    for(int i = 0; i < capacity; i++){
        htable[i] = other.htable[i];
    }
	return *this;
}


template<class Type>
int Hashtable<Type>::hash(Type value) const { //private function
	return fmod(value, capacity);
}

template<class Type>
int Hashtable<Type>::getSize() const
{
	return size;
}

template<class Type>
double Hashtable<Type>::getLoadFactorThreshold() const {
    return loadFactorThreashold;
}


template<class Type>
int Hashtable<Type>::getCapacity() const
{
	return capacity;
}


template<class Type>
bool Hashtable<Type>::empty() const
{
	if (size == 0) {
		return true;
	}
	return false;
}

template<class Type>
void Hashtable<Type>::rehash() {
   // Resize the table using the following algorithm....
   //   double the capacity of the list and then find the next prime number to determine the size of the new capacity.
   //   Rehash all the items according to the new hash algorithm.

    //use copy constructor to make a copy of htable into tempArr
    unique_ptr<Bucket<Type>[]> tempArr = move(htable);

    size = 0; //set size to 0
    int oldCapacity = capacity; //capture capacity before change
    capacity = nextPrime(capacity* 2 ); //set capacity to the next prime number

    //resize htable to new capacity
    htable = make_unique<Bucket<Type>[]>(capacity);

    //iterate though, if its empty, place the slot
    for(int i = 0; i < oldCapacity; i++){
        if(!tempArr[i].empty){
            insert(tempArr[i].data);
        }
    }
}






//std::unique_ptr<int> p2 = std::move(p1);

// Change to Quadratic probing
//Inserts the given value into the hashtable.  When there are collisions, quadratic hashing is used instead of linear.
//Rehash() the table when the percent full reaches the loadFactorThreashold.
template<class Type>
void Hashtable<Type>::insert(Type value)
{

    int i = 0;
    while(!htable[hash(value + pow(i , 2))].empty ){
        i++;
    }

    htable[hash(value + pow(i,2))] = {value, false};
    size++;

    if(size/(double)capacity >= getLoadFactorThreshold()){
        rehash();
    }
}

template<class Type>
bool Hashtable<Type>::isPrime(int num) {

    if(num <= 1){
        return false;
    }

    for(int i = 2; i < num; i++){ //formula from 2130 discrete Math
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

template<class Type>
int Hashtable<Type>::nextPrime(int num) {
    int checkPrime = num;
    bool flag = false;

    //I had help from online for this function. However, I understand what is happening and will explain everything

    //This is a base case that covers all numbers less than or = to 1. If they are than the next prime number will always be 2
    if (num <= 1)
        return 2;

    //This will loop until isPrime finds the next prime number
    while (!flag) { //while flag != true
        checkPrime++; //add 1 to the prime number

        if (isPrime(checkPrime)) //check if its indeed prime
            flag = true; //if it is, end the loop // otherwise start over
    }
    return checkPrime;
}


template<class Type>
void Hashtable<Type>::remove(int value)
{

    int i = 0;
    while(htable[hash(value + pow(i,2))].data != value && i < capacity){
        i++;
    }
    if(i == capacity){
        return;
    }
    htable[hash(value + pow(i,2))] = {0, true};
    size--;

}


template<class Type>
bool Hashtable<Type>::contains(int value) const {

    int i = 0;
    while(htable[hash(value + pow(i,2))].data != value && i < capacity){
        i++;
    }
    if(htable[hash(value + pow(i,2))].data == value){
        return true;
    }

	return false;
}


template<class Type>
void Hashtable<Type>::clear()
{
	size = 0;
    loadFactorThreashold = .65;
	htable = make_unique<Bucket<Type>[]>(capacity);
}

template<class Type>
int Hashtable<Type>::indexOf(int num) const {
    //Returns the index of the given value. If the value is not in the hashtable, returns -1.
    // This is not a normal method for a hashtable and is here solely to test that your hashtable does quadratic probing.
    for(int i = 0; i < capacity; i++){
        if(htable[i].data == num){
            return i;
        }
    }
    return -1;
}


template<class Type>
ostream& operator<< (ostream & out, Hashtable<Type>& h) {
	out << "\nCapacity: " << h.capacity << "\n";
	for (int i = 0; i < h.capacity; i++) {

		if (h.htable[i].empty == false) {
			out << i << ": " << h.htable[i].data << endl;
		}

	}
	return out;
}