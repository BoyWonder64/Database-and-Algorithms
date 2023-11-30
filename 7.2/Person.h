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
    bool operator> (const Person &g);
    bool operator== (const Person &g);
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
    string name;
    int amount;
};


bool Person::operator>(const Person &g) {
    return amount > g.amount;
}

bool Person::operator== (const Person &g) {
    return g.amount;
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
    return amount;
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


int Person::getAmount() const {
    return amount;
}


ostream& operator <<(ostream &out, const Person &g) {
    out << g.name << ": " << g.amount;
    return out;
}


