#include <iostream>
#include <string>
using namespace std;


class Person;


ostream& operator <<(ostream &out, const Person &g);
bool operator >(int amount, const Person &g);
bool operator< (int amount, const Person &g);
bool operator== (int amount, const Person &g);
bool operator!= (int amount, const Person &g);
bool operator>= (int amount, const Person &g);
bool operator<= (int amount, const Person &g);

class Person {
public:
    Person(string name, int amount) : name(name), amount(amount) {}
    bool operator> (const Person &g) const;
    bool operator== (const Person &g) const;
    bool operator< (const Person &g);
    bool operator>= (const Person &g);
    bool operator!= (const Person &g);
    bool operator<= (const Person &g);

    bool operator< (int amt);
    bool operator> (int amt);
    bool operator== (int amt);
    bool operator>= (int amt);
    bool operator!= (int amt);
    bool operator<= (int amt);

    int getAmount() const;
    friend ostream& operator <<(ostream &out, const Person &g);
    friend bool operator> (int amount, const Person &g);
    friend bool operator< (int amount, const Person &g);
    friend bool operator== (int amount, const Person &g);
    friend bool operator!= (int amount, const Person &g);
    friend bool operator>= (int amount, const Person &g);
    friend bool operator<= (int amount, const Person &g);
private:
    string name; //Person
    int amount; //Person
};


bool Person::operator>(const Person &g) const {
    return amount > g.amount;
}

bool Person::operator== (const Person &g) const {
    return g.amount == amount;
}

bool Person::operator< (const Person &g) {
    return amount < g.amount;

}



bool Person::operator>= (const Person &g){
    return g.amount;
}

bool Person::operator<= (const Person &g){
    return g.amount;
}

bool Person::operator!= (const Person &g){
    return g.amount;
}





bool Person:: operator< (const int amt) {
    return amount < amt;
}

bool Person:: operator>(const int amt) {
    return amount > amt;
}

bool Person::operator== (int amt) {
    return amount == amt;
}

bool Person::operator>= (int amt){
    return amount >= amt;
}

bool Person::operator<= (int amt){
    return amount <= amt;
}

bool Person::operator!= (int amt){
    return amount != amt;
}




bool operator > (int amount, const Person &g){
    return   amount > g.amount;
}

bool operator < (int amount, const Person &g){
    return   amount < g.amount;
}

bool operator != (int amount, const Person &g){
    return   amount != g.amount;
}

bool operator == (int amount, const Person &g){
    return   amount == g.amount;
}

bool operator >= (int amount, const Person &g){
    return   amount >= g.amount;
}

bool operator <= (int amount, const Person &g){
    return   amount <= g.amount;
}

//Need to use
int Person::getAmount() const {
    return amount;
}


ostream& operator <<(ostream &out, const Person &g) {
    out << g.name << ": " << g.amount;
    return out;
}


