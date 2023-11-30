#include <iostream>

using namespace std;
 template <class Type>
 class Point;


template <class Type>
ostream& operator <<(ostream &, const Point<Type> &);

template <class Type>
istream& operator >> (istream &, Point<Type> &);

 template <class Type>
 class Point{
    private:
        Type x;
        Type y;
        Type z;

    public:
        Point(){x = 0; y = 0;} //constructor
        Point(Type x, Type y): x(x), y(y){}  //Overloaded constructor
        Point operator+(const Point<Type> & );
        Point operator+=(const Point<Type> &);
        friend ostream& operator << <>(ostream &, const Point<Type> &);
        friend istream& operator >> <>(istream &, Point<Type> &);
        Point operator-(const Point<Type> & );
        Point operator-=(const Point<Type> &);

};

template <class Type>
Point<Type> Point<Type>::operator+(const Point<Type> &toAdd){
    Point thirdPoint (x + toAdd.x, y + toAdd.y);
    return thirdPoint;
}

template <class Type>
 Point<Type> Point<Type>:: operator+=(const Point<Type> &toAdd){
    x += toAdd.x;
    y += toAdd.y;
    return *this;
 }
template <class Type>
Point<Type> Point<Type>::operator-(const Point<Type> &toSubtract){
   Point fourthPoint (x - toSubtract.x, y - toSubtract.y);
    return fourthPoint;
}
template <class Type>
Point<Type> Point<Type>:: operator-=(const Point<Type> & toSubtract){
    x -= toSubtract.x;
    y -= toSubtract.y;
    return *this;
 }

 template <class Type>
ostream& operator <<(ostream &out, const Point<Type> &point){
    // [4,7]
    out <<"[" << point.x << "," << point.y << "]" << endl;
    return out;
}

template <class Type>
istream& operator >> (istream &in, Point<Type> &point){
cout << "Enter x and y coord" << endl;
in >> point.x >> point.y;
return in;
}

int main()
{
    Point<int> p1;
    cout << "Point 1" << endl;
    cin >> p1;
    Point<int> p2;
    cout << "Point 2" << endl;
    cin >> p2;

    Point<int> p3 = p1 + p2;
    cout << p1 << " + " << p2 << " = " << p3 << endl;
    p1 += p2;
    cout << "Increment p1 by p2 to get " << p1 << endl;

    Point<int> p4 = p2 - p1;
    cout << p1 << " - " << p2 << " = " << p3 << endl;
    p1 -= p2;
    cout << "decrement p1 by p2 to get " << p1 << endl;
    return 0;
}
