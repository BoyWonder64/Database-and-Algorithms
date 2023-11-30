#include<iostream>
#include <sstream>
#include "LinkedList.h"

using std::exception;

void testNumbers();
void testException();
void testStrings();
void testDelete();

bool checkTest(std::string testName, std::string whatItShouldBe, std::string whatItIs);
bool checkTest(std::string testName, int whatItShouldBe, int whatItIs);
bool checkTestMemory(std::string testName, int whatItShouldBe, int whatItIs);

int main()
{
   testNumbers();
   testException();
   testStrings();
   testDelete();
   return 0;
}



//This helps with testing, do not modify.
void testNumbers() {

  LinkedList<int> si;
  for (int i = 10; i < 20; i++) {
    si.insert(i);
  }
  std::ostringstream out;
  out << si;
  //Test just to make sure the data went in the list.
  checkTest("test #1: adding elements", "10 11 12 13 14 15 16 17 18 19", out.str());

  //Test retrieving item.
  int item = si.peek(0);
  checkTest("test #2: checking first element", 10, item);
  item = si.peek(3);
  checkTest("test #3: checking middle element", 13, item);
  item = si.peek(9);
  checkTest("test #4: checking last element", 19, item);


}

void testException(){
 LinkedList<int> si;
  for (int i = 1; i < 4; i++) {
    si.insert(i);
  }

  //Try to access out of bounds.
  std::string caughtError = "";
  try {
    int item = si.peek(3);
    item = item;

  }
  catch (std::exception& e) {
    caughtError = "caught";
  }
  checkTest("test #5: checking exception ", "caught", caughtError);
}

void testStrings(){

  LinkedList<std::string> ss;
  ss.insert("Multi Pass");
  ss.insert("Lelu Dallas");
  ss.insert("BIG BADA BOOM");
  ss.insert("Bruce Willis");
  ss.insert("Fried Chicken");
  ss.insert("EEEAAAAAAAeeeaaaaaEEeeAAAEEaaaaAA");
  checkTest("test #6: testing strings", "Bruce Willis", ss.peek(3));

}


void testDelete(){
  LinkedList<int> si;
  for (int i = 10; i < 20; i++) {
    si.insert(i);
  }

  si.remove(0);
  std::ostringstream out;
  out << si;
  //Test just to make sure the data went in the list.
  checkTest("test #7: deleting first item", "11 12 13 14 15 16 17 18 19", out.str());
  si.remove(8);
  out.str("");
  out.clear();
  out << si;
  checkTest("test #8: deleting last item", "11 12 13 14 15 16 17 18", out.str());
  si.insert(20);
  out.str("");
  out.clear();
  out << si;
  checkTest("test: #9: adding after deleting last item", "11 12 13 14 15 16 17 18 20", out.str());
  bool test = true;
  try{
    test = true;
    si.remove(22);
  }
  catch(exception &e){
    test = false;
  }
  checkTest ("test #10: exceeding the list", test, false);
}


//******************
//The IntWrapper class: for testing purposes
//******************
class IntWrapper {
  friend std::ostream& operator<<(std::ostream& out, const IntWrapper& rhs);
public:
  IntWrapper() {}
  // Constructor
  IntWrapper(int value) { this->value = value; }
  // Copy constructor
  IntWrapper(const IntWrapper& obj) {
    std::cerr << "Error: You hit a copy constructor, you need to rearrange node pointers, not the values in the nodes." << std::endl;
  }
  // Copy assignment
  bool operator=(const IntWrapper& obj) {
    std::cerr << "Error: You hit a assignment operator, you need to rearrange node pointers, not the values in the nodes." << std::endl;
    return false;
  }
  // Move constructor
  IntWrapper(IntWrapper&& obj) {
    this->value = std::move(obj.value);
  }
  // Move assignment
  bool operator=(IntWrapper&& obj) {
    this->value = std::move(obj.value);
    return true;
  }
  int value;
};
std::ostream& operator<<(std::ostream& out, const IntWrapper& rhs) {
  out << rhs.value;
  return out;
}
//******************
//The Node cl


//This helps with testing, do not modify.
bool checkTest(std::string testName, std::string whatItShouldBe, std::string whatItIs) {

  if (whatItShouldBe == whatItIs) {
    std::cout << "Passed " << testName << std::endl;
    return true;
  }
  else {
    std::cout << "****** Failed test " << testName << " ****** " << std::endl << "     Output was " << whatItIs << std::endl << "     Output should have been " << whatItShouldBe << std::endl;
    return false;
  }
}

//This helps with testing, do not modify.
bool checkTest(std::string testName, int whatItShouldBe, int whatItIs) {

  if (whatItShouldBe == whatItIs) {
    std::cout << "Passed " << testName << std::endl;
    return true;
  }
  else {
    std::cout << "****** Failed test " << testName << " ****** " << std::endl << "     Output was " << whatItIs << std::endl << "     Output should have been " << whatItShouldBe << std::endl;
    return false;
  }
}

//This helps with testing, do not modify.
bool checkTestMemory(std::string testName, int whatItShouldBe, int whatItIs) {

  if (whatItShouldBe == whatItIs) {
    std::cout << "Passed " << testName << std::endl;
    return true;
  }
  else {
    std::cout << "***Failed test " << testName << " *** " << std::endl << "  You lost track of " << whatItIs << " bytes in memory!" << std::endl;
    return false;
  }
}

