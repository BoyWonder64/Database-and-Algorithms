#include <iostream>
#include "Date.h"
using namespace std;


void testConstructor();
void testAddOperators();
void testExtractionOperators();
bool checkCase(string name, bool condition);

int main()
{
    cout << "Date Class Testing!" << endl;
    testConstructor();
    testAddOperators();
    testExtractionOperators();
    return 0;
}


void testConstructor()
{
    checkCase("One Argument Constructor", Date(2018).toString() == "Jan 1, 2018");
    checkCase("Two Argument Constructor", Date(2018, 7).toString() == "Jul 1, 2018");

}
void testAddOperators(){
    Date dd(2018, 9, 10);
    Date d = dd;

    d = dd; checkCase("Operator+ test 1", (d + 23).toString() == "Oct 3, 2018");
    d = dd; checkCase("Operator+ test 2", (d + 38).toString() == "Oct 18, 2018");
    d = dd; checkCase("Operator+ test 3", (d + 56).toString() == "Nov 5, 2018");
    d = dd; checkCase("Operator+ test 4", (d + 91).toString() == "Dec 10, 2018");
    d = dd; checkCase("Operator+ test 5", (d + 134).toString() == "Jan 22, 2019");
}

void testExtractionOperators(){
    Date dd(2018, 9, 10);
    stringstream sout;
    sout << dd;

    checkCase("Text Extraction Operator", sout.str() == "Sep 10, 2018");
}
bool checkCase(string name, bool condition)
{
    if(!condition)
    {
        cout << "Failed: " << name << endl;
    }
    else{
        cout << name << ": passed" << endl;
    }

    return condition;
}


