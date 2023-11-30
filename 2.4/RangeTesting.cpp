#include <iostream>
#include <vector>
#include <sstream>
#include "Range.h"

using namespace std;
template<class type>
bool checkCase(string, type, type);
void TestCase1();
void TestCase2();
void TestCase3();
void TestCase4();
void TestCase5();

int main()
{
    cout << "Range Class Testing!" << endl;
    TestCase1();
    TestCase2();
    TestCase3();
    TestCase4();
    TestCase5();
    return 0;
}

void TestCase1()
{
    Range<int>r(3, 11);
    stringstream out;
    out << r;
    int cnt = 0;
    int sum = 0;
         
    if(checkCase("Case 1: sum()", r.sum() ,63))cnt++;
    if(checkCase("Case 1: length()", r.length() ,9) )cnt++;
    if(checkCase("Case 1: average()", r.average() , 63 / 9) )cnt++;
    if(checkCase("Case 1: max()", r.max() , 11 ) )cnt++;
    if(checkCase("Case 1: min()", r.min() ,3))cnt++;
    if(cnt == 5){
        cout << "Test Case 1: Passed" << endl;
    }
    else{
        cout << "   Tested with ascending Integers  Range r(3, 11)" << endl;
    }

}
void TestCase2()
{
    Range<int>r(3, 12, 2);
    stringstream out;
    out << r;
    int cnt = 0;
  
    if(checkCase("Case 2: sum()", r.sum(),35))cnt++;
    if(checkCase("Case 2: length()", r.length() , 5) )cnt++;
    if(checkCase("Case 2: average()", r.average() , 35 / 5) )cnt++;
    if(checkCase("Case 2: max()", r.max() , 11 ) )cnt++;
    if(checkCase("Case 2: min()", r.min() , 3))cnt++;
    if(cnt ==5) {
        cout << "Test Case 2: Passed" << endl;
    }
    else{
        cout << "   Tested with ascending Integers and step Range r(3, 12, 2)" << endl;
    }
  
}

void TestCase3()
{
    Range<double>r(7.5, 20.3, 2.5);
    stringstream out;
    out << r;

    int cnt = 0;
    if(checkCase("Case 3: sum()", r.sum() , 82.5))cnt++;
    if(checkCase("Case 3: length()", r.length() , 6) )cnt++;
    if(checkCase("Case 3: average()", r.average() , 82.5 / 6) )cnt++;
    if(checkCase("Case 3: max()", r.max() , 20.0 ) )cnt++;
    if(checkCase("Case 3: min()", r.min() ,7.5))cnt++;
    if(cnt == 5){
        cout << "Test Case 3: Passed" << endl;
    }
    else{
        cout << "   Tested with ascending doubles  Range r(7.5, 20.3, 2.5)" << endl;
    }
}
void TestCase4()
{
    Range<int>r(12, 3, -2);
    stringstream out;
    out << r;
    int cnt = 0;
 
    if(checkCase("Case 4: sum()", r.sum() , 40))cnt++;
    if(checkCase("Case 4: length()", r.length() , 5) )cnt++;
    if(checkCase("Case 4: average()", r.average() , 40 / 5) )cnt++;
    if(checkCase("Case 4: max()", r.max() , 12 ) )cnt++;
    if(checkCase("Case 4: min()", r.min() , 4))cnt++;
    if(cnt == 5){
        cout << "Test Case 4: Passed" << endl;
    }
    else{
        cout << "   Tested with descending integers  Range r(12, 3, -2)" << endl;
    }
    
}
void TestCase5()
{
    Range<double>r(20.0, 4.0, -2.5);
    stringstream out;
    out << r;

    int cnt = 0;
    if(checkCase("Case 5: sum()", r.sum() , 87.5))cnt++;
    if(checkCase("Case 5: length()", r.length() , 7) )cnt++;
    if(checkCase("Case 5: average()", r.average() , 87.5 / 7) )cnt++;
    if(checkCase("Case 5: max()", r.max() , 20.0 ) )cnt++;
    if(checkCase("Case 5: min()", r.min() , 5.0))cnt++;
    if(cnt == 5){
        cout << "Test Case 5: Passed" << endl;
    }
    else{
        cout << "   Tested with descending doubles  Range r(20.0, 4.0, -2.5)" << endl;
    }
   
}

template<class type>
bool checkCase(string name, type is, type shouldBe)
{
    if(is != shouldBe)
    {
        cout << name << "Failed: output was " << is << " should have been " << shouldBe << endl;
    }
    return is == shouldBe;
}
