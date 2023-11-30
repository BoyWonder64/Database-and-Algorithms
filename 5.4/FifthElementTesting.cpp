#include <iostream>
#include <sstream>
#include <memory>
#include "FifthElement.h"



using namespace std;


void  testGetFifthElement();
void  testInsertNewFifthElement();
void  testDeleteFifthElement();
void  testSwapFourthAndFifthElement();

bool checkTest(string testName, string whatItShouldBe, string whatItIs);
bool checkTest(string testName, int whatItShouldBe, int whatItIs);
bool checkTestMemory(string testName, int whatItShouldBe, int whatItIs);

int main()
{
   testGetFifthElement();
   testInsertNewFifthElement();
   testDeleteFifthElement();
   testSwapFourthAndFifthElement();

    return 0;
}



//This helps with testing, do not modify.
bool checkTest(string testName, string whatItShouldBe, string whatItIs) {

  if (whatItShouldBe == whatItIs) {
    cout << "Passed " << testName << endl;
    return true;
  }
  else {
    cout << "****** Failed test " << testName << " ****** " << endl << "     Output was " << whatItIs << endl << "     Output should have been " << whatItShouldBe << endl;
    return false;
  }
}

//This helps with testing, do not modify.
bool checkTest(string testName, int whatItShouldBe, int whatItIs) {

  if (whatItShouldBe == whatItIs) {
    cout << "Passed " << testName << endl;
    return true;
  }
  else {
    cout << "****** Failed test " << testName << " ****** " << endl << "     Output was " << whatItIs << endl << "     Output should have been " << whatItShouldBe << endl;
    return false;
  }
}

//This helps with testing, do not modify.
bool checkTestMemory(string testName, int whatItShouldBe, int whatItIs) {

  if (whatItShouldBe == whatItIs) {
    cout << "Passed " << testName << endl;
    return true;
  }
  else {
    cout << "***Failed test " << testName << " *** " << endl << "  You lost track of " << whatItIs << " bytes in memory!" << endl;
    return false;
  }
}



//This helps with testing, do not modify.
void testGetFifthElement() {

  auto si = make_shared<FifthElement<int>>();
  for (int i = 10; i < 20; i++) {
    si->insert(i);
  }


   stringstream sstream;
   sstream << *si;
  //Test just to make sure the data went in the list.
  checkTest("test #1: adding elements", "10 11 12 13 14 15 16 17 18 19", sstream.str());

  //Test retrieving item.
  int item = si->getFifthElement();
  checkTest("test #2: checking 5th element", 14, item);
  si.reset();

  si = make_shared<FifthElement<int>>();
  for (int i = 10; i < 15; i++) {
    si->insert(i);
  }


  sstream.str("");
  sstream << *si;

  //Test just to make sure the data went in the list.
  checkTest("test #3: adding only 5 elements", "10 11 12 13 14", sstream.str());

  //Test retrieving item.
  item = si->getFifthElement();
  checkTest("test #4: checking 5th at end", 14, item);
  si.reset();


  si = make_shared<FifthElement<int>>();
  for (int i = 10; i < 14; i++) {
    si->insert(i);
  }
  sstream.str("");
  sstream << *si;
  //Test just to make sure the data went in the list.
  checkTest("test #5: adding 4 elements", "10 11 12 13", sstream.str());

  //Try to access out of bounds.
  string caughtError = "";
  try {
    item = si->getFifthElement();
  }
  catch (exception &e) {
    caughtError = "caught";
  }
  checkTest("test #6: testing exception ", "caught", caughtError);
  si.reset();

  auto ss = make_shared< FifthElement<string> >();
  ss->insert("Multi Pass");
  ss->insert("Lelu Dallas");
  ss->insert("BIG BADA BOOM");
  ss->insert("Bruce Willis");
  ss->insert("Fried Chicken");
  ss->insert("EEEAAAAAAAeeeaaaaaEEeeAAAEEaaaaAA");
  checkTest("test #7: testing strings", "Fried Chicken", ss->getFifthElement());
  ss.reset();


}

//This helps with testing, do not modify.
void testInsertNewFifthElement() {

  auto si = make_shared<FifthElement<int>>();
  for (int i = 10; i < 20; i++) {
    si->insert(i);
  }
  stringstream sstream;
    sstream.str("");
    sstream << *si;
  //Test just to make sure the data went in the list.
  checkTest("add test #1: int test", "10 11 12 13 14 15 16 17 18 19", sstream.str());

  //Test inserting an item
  si->insertNewFifthElement(97);

  sstream.str("");
  sstream << *si;

  checkTest("add test #2: adding 5th in middle", "10 11 12 13 97 14 15 16 17 18 19", sstream.str());

  si = make_shared<FifthElement<int>>();
  for (int i = 10; i < 15; i++) {
    si->insert(i);
  }

   sstream.str("");
   sstream << *si;
  //Test just to make sure the data went in the list.
  checkTest("add test #3: adding 5 values", "10 11 12 13 14", sstream.str());

  //Test inserting an item
  si->insertNewFifthElement(97);

  sstream.str("");
  sstream << *si;
  checkTest("add test #4: adding 5th near end", "10 11 12 13 97 14", sstream.str());

  si = make_shared<FifthElement<int>>();
  for (int i = 10; i < 14; i++) {
    si->insert(i);
  }
  sstream.str("");
  sstream << *si;

  //Test just to make sure the data went in the list.
  checkTest("add test #5: adding only 4 values", "10 11 12 13", sstream.str());

  //Test inserting an item
  si->insertNewFifthElement(97);
  sstream.str("");
  sstream << *si;

  checkTest("add test #6: adding to end", "10 11 12 13 97", sstream.str());

}


//This helps with testing, do not modify.
void testDeleteFifthElement() {
  // Note from the instructor: Please do not delete the actual movie.  It's very good and shouldn't be removed.

  auto si = make_shared<FifthElement<int>>();
  for (int i = 10; i < 20; i++) {
    si->insert(i);
  }
  stringstream sstream;
  sstream << *si;
  //Test just to make sure the data went in the list.
  checkTest("delete test #1: adding int values", "10 11 12 13 14 15 16 17 18 19", sstream.str());

  //Test deleting an item
  si->deleteFifthElement();
  sstream.str("");
  sstream << *si;

  checkTest("delete test #2: delete 5th value", "10 11 12 13 15 16 17 18 19", sstream.str());

  si = make_shared<FifthElement<int>>();
  for (int i = 10; i < 16; i++) {
    si->insert(i);
  }
  //Test just to make sure the data went in the list.
  sstream.str("");
  sstream << *si;
  checkTest("delete test #3: adding 6 values", "10 11 12 13 14 15", sstream.str());

  //Test deleting an item
  si->deleteFifthElement();
  sstream.str("");
  sstream << *si;
  checkTest("delete test #4: delete 5th item", "10 11 12 13 15", sstream.str());

  si = make_shared<FifthElement<int>>();
  for (int i = 10; i < 15; i++) {
    si->insert(i);
  }
  //Test just to make sure the data went in the list.
  sstream.str("");
  sstream << *si;
  checkTest("delete test #5: adding only 5", "10 11 12 13 14", sstream.str());

  //Test deleting an item
  si->deleteFifthElement();
  sstream.str("");
  sstream << *si;
  checkTest("delete test #6: delete last item", "10 11 12 13", sstream.str());

}


//This helps with testing, do not modify.
void testSwapFourthAndFifthElement() {
  // Note from the instructor: Please do not delete the actual movie.  It's very good and shouldn't be removed.

  auto si = make_shared<FifthElement<int>>();
  for (int i = 10; i < 20; i++) {
    si->insert(i);
  }
  stringstream sstream;
  sstream.str("");
  sstream << *si;
  //Test just to make sure the data went in the list.
  checkTest("swap test #1", "10 11 12 13 14 15 16 17 18 19", sstream.str());

  //Test swapping an item

  si->swapFourthAndFifthElement();
  sstream.str("");
  sstream << *si;
  checkTest("swap test #2", "10 11 12 14 13 15 16 17 18 19", sstream.str());

}

