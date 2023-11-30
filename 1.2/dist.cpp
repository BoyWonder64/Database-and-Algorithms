#include <iostream>
using namespace std;


class Distance {
  private:
     int feet;             
     int inches;         
     void adjustDist();


  public:
     //Default Constructor
     Distance() ;  
     //Overloaded Constructor                 
     Distance(int f, int i = 0);
     //Overloaded Operator    
     Distance operator+(const Distance&);
     Distance operator-(const Distance&);
     //Insertion Operator
     friend ostream &operator<<( ostream &output, const Distance &D );
     //Extraction Operator
     friend istream &operator>>( istream  &input, Distance &D );
};


Distance::Distance() {
    feet = 0;
    inches = 0;
}
Distance::Distance(int f, int i) {
   feet = f;
   inches = i;
   adjustDist();
}
void Distance::adjustDist(){
 if(inches > 12){
   int addFeet = inches / 12;
   feet += addFeet;
   inches %= 12;
 }
}
Distance Distance::operator+(const Distance& d){
 Distance dist;
 dist.inches = inches + d.inches;
 dist.feet = feet + d.feet;
 adjustDist();
 return dist;
}

Distance Distance::operator-(const Distance& d){
 Distance dist;
 dist.inches = inches - d.inches;
 dist.feet = feet - d.feet;
 adjustDist();
 return dist;
}
ostream &operator<<( ostream &out, const Distance &d ) {
   out << "Feet: " << d.feet << " Inches : " << d.inches;
   return out;           
}


istream &operator>>( istream  &input, Distance &d ) {
   input >> d.feet >> d.inches;
   return input;           
}

int main (){
Distance d1;
cout << "Please enter a distance" << endl;
cin >> d1;

cout << "Distance 1: " << d1  << endl;
Distance d2(1, 15);
cout << "Distance 2: " << d2 << endl;
Distance d3(5);
cout << "Distance 3: " << d3 << endl;
Distance d4 = d2 + d3;
cout << "Distance 4: " << d4 << endl;
Distance d5 = d2 - d3;
cout << "Distance 5: " << d5 << endl;
}


