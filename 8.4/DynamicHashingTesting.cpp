
#include "Hashtable.h"
#include<iostream>
#include<string>
#include<stdexcept>
#include<sstream>

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using std::logic_error;


template <typename elemType>
bool checkTest(string testName, elemType whatItShouldBe, elemType whatItIs);
bool testConstructor();
bool testInsert();
bool testRemove();
bool testClear();
bool testResize();
bool testIndexOf();
bool testQuadraticProbing();
bool testDeepCopy();
bool testRemoveAdvanced();

int main()
{
	int passed = 0;
	passed += testConstructor();
	passed += testInsert();
	passed += testRemove();
	passed += testClear();
	passed += testResize();
	passed += testIndexOf();
	passed += testQuadraticProbing();
	passed += testDeepCopy();
	passed += testRemoveAdvanced();

	if (passed == 9) {
		cout << "You have passed " << passed << "/9 tests" << endl;
	}
	else {
		cout << "Oops, keep trying, " << passed << "/9 tests passed" << endl;
	}
	system("pause");
	return 0;
}

bool testConstructor() {
	bool passed = true;
	cout << "-------------Test Constructor--------------" << endl;

	Hashtable<int> table1;
	passed &= checkTest("Constructor 1", table1.getSize(), 0);
	passed &= checkTest("Constructor 2", table1.getCapacity(), 17);
	passed &= checkTest("Constructor 3", table1.empty(), true);
	passed &= checkTest("Constructor 4", table1.getLoadFactorThreshold(), .65);
	Hashtable<int> table2(13);
	passed &= checkTest("Constructor 5", table2.getSize(), 0);
	passed &= checkTest("Constructor 6", table2.getCapacity(), 13);
	passed &= checkTest("Constructor 7", table2.empty(), true);
	passed &= checkTest("Constructor 8", table2.getLoadFactorThreshold(), .65);
	Hashtable<int> table3(19, .5);
	passed &= checkTest("Constructor 9", table3.getSize(), 0);
	passed &= checkTest("Constructor 10", table3.getCapacity(), 19);
	passed &= checkTest("Constructor 11", table3.empty(), true);
	passed &= checkTest("Constructor 12", table3.getLoadFactorThreshold(), .5);
	return passed;
}

bool testInsert() {
	bool passed = true;
	cout << "-------------Test Insert--------------" << endl;
	Hashtable<int> table;
	table.insert(2);
	passed &= checkTest("Insert 1", table.getSize(), 1);
	passed &= checkTest("Insert 2", table.contains(2), true);
	passed &= checkTest("Insert 3", table.contains(12), false);
	passed &= checkTest("Insert 4", table.empty(), false);
	table.insert(5);
	passed &= checkTest("Insert 5", table.getSize(), 2);
	passed &= checkTest("Insert 6", table.contains(5), true);
	table.insert(64);
	passed &= checkTest("Insert 7", table.getSize(), 3);
	passed &= checkTest("Insert 8", table.contains(64), true);
	passed &= checkTest("Insert 9", table.contains(13), false);
	table.insert(13);
	passed &= checkTest("Insert 10", table.contains(13), true);
	passed &= checkTest("Insert 11", table.contains(64), true);
	table.insert(30);
	passed &= checkTest("Insert 12", table.contains(30), true);
	table.insert(47);
	passed &= checkTest("Insert 13", table.contains(47), true);
	passed &= checkTest("Insert 14", table.contains(13), true);
	passed &= checkTest("Insert 15", table.contains(64), true);
	return passed;
}

bool testRemove() {
	bool passed = true;
	cout << "-------------Test Remove--------------" << endl;
	Hashtable<int> table;
	table.insert(3);
	table.remove(3);
	passed &= checkTest("Remove 1", table.getSize(), 0);
	passed &= checkTest("Remove 2", table.empty(), true);
	passed &= checkTest("Remove 3", table.contains(3), false);
	table.insert(6);
	table.insert(1);
	table.insert(20);
	passed &= checkTest("Remove 4", table.contains(6), true);
	passed &= checkTest("Remove 5", table.contains(1), true);
	passed &= checkTest("Remove 6", table.contains(20), true);
	table.remove(6);
	table.remove(1);
	table.remove(20);
	passed &= checkTest("Remove 7", table.contains(6), false);
	passed &= checkTest("Remove 8", table.contains(1), false);
	passed &= checkTest("Remove 9", table.contains(20), false);
	passed &= checkTest("Remove 10", table.getSize(), 0);
	passed &= checkTest("Remove 11", table.empty(), true);
	table.insert(4);
	table.insert(21);
	table.insert(38);
	table.insert(55);
	table.remove(21);
	passed &= checkTest("Remove 12", table.contains(4), true);
	passed &= checkTest("Remove 13", table.contains(38), true);
	passed &= checkTest("Remove 14", table.contains(55), true);
	passed &= checkTest("Remove 15", table.contains(21), false);
	return passed;
}

bool testClear() {
	bool passed = true;
	cout << "-------------Test Clear--------------" << endl;
	Hashtable<int> table;
	table.insert(5);
	table.clear();
	passed &= checkTest("Clear 1", table.getSize(), 0);
	passed &= checkTest("Clear 2", table.empty(), true);
	table.insert(374);
	table.insert(234);
	table.clear();
	passed &= checkTest("Clear 3", table.getSize(), 0);
	passed &= checkTest("Clear 4", table.empty(), true);
	table.insert(4);
	table.insert(374);
	table.remove(374);
	table.clear();
	passed &= checkTest("Clear 5", table.getSize(), 0);
	passed &= checkTest("Clear 6", table.empty(), true);
	passed &= checkTest("Clear 7", table.contains(4), false);
	passed &= checkTest("Clear 8", table.contains(5), false);
	passed &= checkTest("Clear 9", table.contains(374), false);
	return passed;
}

bool testIndexOf() {
	bool passed = true;
	cout << "-------------Test IndexOf--------------" << endl;
	Hashtable<int> table;
	table.insert(5);
	passed &= checkTest("IndexOf 1", table.indexOf(5), 5);
	passed &= checkTest("IndexOf 2", table.indexOf(3), -1);
	table.insert(18);
	passed &= checkTest("IndexOf 3", table.indexOf(18), 1);
	table.insert(1);
	passed &= checkTest("IndexOf 4", table.indexOf(1), 2);

	return passed;
}

bool testResize() {
	bool passed = true;
	cout << "-------------Test Resize--------------" << endl;
	Hashtable<int> table(7);
	table.insert(5);
	table.insert(15);
	table.insert(23);
	table.insert(34);
	passed &= checkTest("Resize 1", table.getCapacity(), 7);

	table.insert(18);
	passed &= checkTest("Resize 2", table.getCapacity(), 17);
	passed &= checkTest("Resize 3", table.indexOf(5), 5);
	passed &= checkTest("Resize 4", table.indexOf(15), 15);
	passed &= checkTest("Resize 5", table.indexOf(34), 0);
	passed &= checkTest("Resize 6", table.indexOf(18), 1);

	for (int i = 50; i < 60; i++) {
		table.insert(i);
	}



	passed &= checkTest("Resize 7", table.getCapacity(), 37);
	
	bool allFound = true;
	for (int i = 50; i < 60; i++) { //Make sure you can still find them
		allFound &= table.contains(i);
	}
	passed &= checkTest("Resize 8", allFound, true);
	for (int i = 150; i < 170; i++) {
		table.insert(i);
	}
	passed &= checkTest("Resize 9", table.getCapacity(), 79);
	allFound = true;
	for (int i = 150; i < 160; i++) { //Make sure you can still find them
		allFound &= table.contains(i);
	}
	passed &= checkTest("Resize 10", allFound, true);
	Hashtable<int> table1(7, .5);
	table1.insert(5);
	table1.insert(15);
	table1.insert(23);
	passed &= checkTest("Resize 11", table1.getCapacity(), 7);
	table1.insert(34);
	passed &= checkTest("Resize 12", table1.getCapacity(), 17);
	return passed;
}

bool testQuadraticProbing() {
	bool passed = true;
	cout << "-------------Test Quadratic Probing --------------" << endl;
	Hashtable<double> table(17);
	table.insert(4);	// 4 + 0^2
	table.insert(21);	// 4 + 1^2
	table.insert(38);	// 4 + 2^2
	table.insert(55);	// 4 + 3^2
	table.insert(72);	// 4 + 4^2
	passed &= checkTest("Quadratic Probing 1", table.indexOf(4), 4);
	passed &= checkTest("Quadratic Probing 2", table.indexOf(21), 5);
	passed &= checkTest("Quadratic Probing 3", table.indexOf(38), 8);
	passed &= checkTest("Quadratic Probing 4", table.indexOf(55), 13);
	passed &= checkTest("Quadratic Probing 5", table.indexOf(72), 3);

	return passed;
}



bool testDeepCopy() {
	bool passed = true;
	cout << "-------------Test Deep Copy--------------" << endl;
	Hashtable<int> table;
	table.insert(12);
	table.insert(2);
	table.insert(15);
	Hashtable<int> copiedTable(table);
	passed &= checkTest("Deep Copy 1", table.getSize(), 3);
	passed &= checkTest("Deep Copy 2", copiedTable.getSize(), 3);
	passed &= checkTest("Deep Copy 3", copiedTable.contains(12), true);
	table.insert(8);
	passed &= checkTest("Deep Copy 4", copiedTable.contains(8), false);
	table.insert(18);
	copiedTable = table;
	passed &= checkTest("Deep Copy 5", copiedTable.contains(18), true);
	passed &= checkTest("Deep Copy 6", table.getSize(), 5);
	passed &= checkTest("Deep Copy 7", copiedTable.getSize(), 5);
	copiedTable.remove(18);
	passed &= checkTest("Deep Copy 8", table.contains(18), true);
	return passed;
}

bool testRemoveAdvanced() {
	int passed = 0;
	cout << "-------------Test Other--------------" << endl;
	Hashtable<int> table;
	table.insert(9);
	table.remove(8); //Remove non-existing value
	passed += checkTest("Other 1", string("No errors"), string("No errors"));
	passed += checkTest("Other 2", table.getSize(), 1);
	passed += checkTest("Other 3", table.empty(), false);
	table.remove(26); //Remove non-existing value that collides with existing value
	passed += checkTest("Other 4", string("No errors"), string("No errors"));
	passed += checkTest("Other 5", table.contains(9), true);
	passed += checkTest("Other 6", table.getSize(), 1);

	//Boundary cases
	table.clear();
	table.clear(); //clear an empty table
	passed += checkTest("Other 7", string("No errors"), string("No errors"));
	table.remove(15); //remove from empty table
	passed += checkTest("Other 8", string("No errors"), string("No errors"));
	passed += checkTest("Other 9", table.getSize(), 0);
	passed += checkTest("Other 10", table.empty(), true);

	passed += checkTest("Other 11", Hashtable<int>::isPrime(349), true);
	passed += checkTest("Other 12", Hashtable<int>::isPrime(343), false);
	passed += checkTest("Other 13", Hashtable<int>::isPrime(5), true);
	passed += checkTest("Other 14", Hashtable<int>::isPrime(2017), true);
	passed += checkTest("Other 15", Hashtable<int>::isPrime(993), false);
	passed += checkTest("Other 16", Hashtable<int>::isPrime(101), true);
	passed += checkTest("Other 17", Hashtable<int>::nextPrime(93), 97);
	passed += checkTest("Other 18", Hashtable<int>::nextPrime(102), 103);
	passed += checkTest("Other 19", Hashtable<int>::nextPrime(984), 991);
	passed += checkTest("Other 20", Hashtable<int>::nextPrime(258), 263);

	if (passed == 20) {
		return true;
	}
	return false;
}

//This helps with testing, do not modify.
template<class elemType>
bool checkTest(string testName, elemType actual, elemType expected) {

	if (actual == expected) {
		cout << "Passed " << testName << endl;
		return true;
	}
	else {
		cout << "***Failed test " << testName << " ** " << endl << "   output was " << actual << endl << "   output should have been " << expected << endl;
		return false;
	}
}