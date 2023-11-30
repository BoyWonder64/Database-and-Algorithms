
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
bool testDeepCopy();

int main()
{
	int passed = 0;
	passed += testConstructor();
	passed += testInsert();
	passed += testRemove();
	passed += testClear();
	passed += testDeepCopy();


	if (passed == 5) {
		cout << "You have passed all five sections" << endl;
	}
	else {
		cout << "Oops, keep trying " << endl;
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

	Hashtable<int> table2(13);
	passed &= checkTest("Constructor 4", table2.getSize(), 0);
	passed &= checkTest("Constructor 5", table2.getCapacity(), 13);
	passed &= checkTest("Constructor 6", table2.empty(), true);

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